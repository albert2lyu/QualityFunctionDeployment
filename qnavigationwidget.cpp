#include "qnavigationwidget.h"
#include <QPainter>
#include <QDebug>

QNavigationWidget::QNavigationWidget(QWidget *parent) : QWidget(parent)
{
    backgroundColor = "#E4E4E4";
    selectedColor = "#2CA7F8";
    rowHeight = 30;
    currentIndex = 0;
    currentIndex2 = 0;

    setMouseTracking(true);
    setFixedWidth(80);
}

QNavigationWidget::~QNavigationWidget()
{
}

void QNavigationWidget::addItem(const QString &title)
{
    listItems << title;

    update();
}

void QNavigationWidget::setWidth(const int &width)
{
    setFixedWidth(width);
}

void QNavigationWidget::setBackgroundColor(const QString &color)
{
    backgroundColor = color;

    update();
}

void QNavigationWidget::setSelectColor(const QString &color)
{
    selectedColor = color;

    update();
}

void QNavigationWidget::setRowHeight(const int &height)
{
    rowHeight = height;

    update();
}

void QNavigationWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Draw background color.
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(backgroundColor));
    painter.drawRect(rect());

    // Draw Items
    int count = 0;
    for (const QString &str : listItems) {
        QPainterPath itemPath;
        itemPath.addRect(QRect(0, count * rowHeight, width(), rowHeight));

        if (currentIndex == count) {
            painter.setPen("#FFFFFF");
            painter.fillPath(itemPath, QColor(selectedColor));
        }else {
            painter.setPen("#202020");
            painter.fillPath(itemPath, QColor(backgroundColor));
        }
        painter.drawText(QRect(0, count * rowHeight, width(), rowHeight), Qt::AlignVCenter | Qt::AlignHCenter, str);
        QString Str2;
        if(currentIndex2==9)
        {
            Str2="Step10";
        }
        else{
            Str2="Step";
            Str2.append((char)(currentIndex2+49));
        }
        painter.fillRect(QRect(0, currentIndex2 * rowHeight, width(), rowHeight), QColor("#56cff2"));
        painter.drawText(QRect(0, currentIndex2 * rowHeight, width(), rowHeight), Qt::AlignVCenter | Qt::AlignHCenter, Str2);


        ++count;
    }
}

void QNavigationWidget::mouseMoveEvent(QMouseEvent *e)
{

    if (e->y() / rowHeight < listItems.count()) {
        currentIndex2 = e->y() / rowHeight;
        update();
    }
}


void QNavigationWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->y() / rowHeight < listItems.count()) {
        currentIndex = e->y() / rowHeight;

        emit currentItemChanged(currentIndex);

        update();
    }
}
void QNavigationWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

}

