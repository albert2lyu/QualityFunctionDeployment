#ifndef ENTITY_STEP5_H
#define ENTITY_STEP5_H
#include<QString>

class Entity_Step5
{
public:
    Entity_Step5();

    //CREATE TABLE "Step5_1" ( `qualityParameterName` varchar ( 255 ), `dataType` varchar ( 255 ), `upperBoundValue` double, `lowerBoundValue` double )
    QString qualityParameterName;
    QString dataType;
    double  lowerBoundValue;
    double  upperBoundValue;
    QString Unit;


};

#endif // ENTITY_STEP5_H
