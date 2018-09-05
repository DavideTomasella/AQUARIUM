#include "dbconnect.h"
#include <QtSql>
#include <QDebug>
#include <QDateTime>

bool addMisure(const QString &time, double temperatura, double ph,
               int livello, double luci, bool ventole, bool potassio, bool co2) //QSqlQuery &q,
{
    QSqlQuery q;
    if (!q.prepare(QLatin1String("insert into valori(time, temperatura, ph, livello, luci,ventole,potassio,co2) values(?, ?, ?, ?, ?, ?, ?, ?)")))
        return false;//q.lastError();
    q.addBindValue(time);
    q.addBindValue(temperatura);
    q.addBindValue(ph);
    q.addBindValue(livello);
    q.addBindValue(luci);
    q.addBindValue(ventole);
    q.addBindValue(potassio);
    q.addBindValue(co2);
    return q.exec();
}

bool addNULLMisure(const QString &time){
    QSqlQuery q;
    if (!q.prepare(QLatin1String("insert into valori(time) values(?)")))
        return false;//q.lastError();
    q.addBindValue(time);
    return q.exec();
}

int getLastMisureId(){
    QSqlQuery q1(QLatin1String("select max(idValore) from valori"));
    if(!q1.next())
        return 0;
    return q1.value(0).toInt();
}

bool addErrori(int errore, bool notConnectToMisure){
    if(notConnectToMisure)
        addNULLMisure(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));

    int id = getLastMisureId();

    QSqlQuery q2;
    if (!q2.prepare(QLatin1String("insert into erroripervalore(valore,errore) values(?, ?)")))
        return false;
    q2.addBindValue(id);
    q2.addBindValue(errore);
    return q2.exec();
}

bool getLastError(int nErrors, QStringList* res){
    QSqlQuery q1;
    if(!q1.prepare(QLatin1String("select errore,descrizione,time from errori,erroripervalore,valori where valore=idValore and errore=idErrore order by iderrorePerValore desc limit ?")))
        return false;
    q1.addBindValue(nErrors);
    bool r = q1.exec();
    res->clear();
    while(q1.next()){
        res->append(q1.value(2).toString()+" : "+q1.value(0).toString()+" = "+q1.value(1).toString());
    }
    return r;
}

void initDB(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("misureacquario");
    db.setUserName("interfacciaTouch");
    db.setPassword("touch");

    if (!db.open())
        qDebug()<<db.lastError();
}
