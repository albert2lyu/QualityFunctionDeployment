#ifndef ENTITY_STEP6_1_H
#define ENTITY_STEP6_1_H
#include<QString>

class Entity_Step6_1
{
public:
    Entity_Step6_1();
    //CREATE TABLE `Step6_1` ( `row` varchar(255), `qualityParameterName` varchar(255), `value` double )
    QString row;
    QString qualityParameterName;//列名==》质量参数
    double value;
};

#endif // ENTITY_STEP6_1_H
