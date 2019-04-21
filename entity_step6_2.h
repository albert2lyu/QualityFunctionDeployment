#ifndef ENTITY_STEP6_2_H
#define ENTITY_STEP6_2_H
#include<QString>

class Entity_Step6_2
{
public:
    Entity_Step6_2();
    //CREATE TABLE `Step6_2` ( `qualityParameterNameRow` varchar(255), `qualityParameterNameRank` varchar(255), `valueQualityType` varchar(255), `BValue` double )
    QString qualityParameterNameRow;
    QString qualityParameterNameRank;
    QString valueQualityType;
    double BValue;
};

#endif // ENTITY_STEP6_2_H
