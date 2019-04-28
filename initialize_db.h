#ifndef INITIALIZE_DB_H
#define INITIALIZE_DB_H
#include <QString>

class Initialize_DB
{
public:
    Initialize_DB();
    bool Initialize_QFD(QString dbName);
    bool exportDatabase(QString filePath);

};

#endif // INITIALIZE_DB_H
