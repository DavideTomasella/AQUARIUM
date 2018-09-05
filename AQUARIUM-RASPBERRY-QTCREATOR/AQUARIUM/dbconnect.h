#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QtGlobal>

QT_BEGIN_NAMESPACE
class QtSql;
class QDebug;
class QDateTime;
class QStringList;
class QtSql;
QT_END_NAMESPACE

extern bool addMisure(const QString &time, double temperatura, double ph,
               int livello, double luci, bool ventole, bool potassio, bool co2);

extern bool addNULLMisure(const QString &time);

extern int getLastMisureId();

extern bool addErrori(int errore, bool NOTMISURE = false);

extern bool getLastError(int nE, QStringList* res);

extern void initDB();

#endif // DBCONNECT_H
