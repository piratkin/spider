#ifndef SQLITE_H
#define SQLITE_H

#include <QObject>
#include <QtSql>
#include <QMap>

class SQLite : public QObject
{
    Q_OBJECT

public:
    explicit SQLite(QObject *parent = nullptr);
    ~SQLite();
    bool init(QString filename);
    QMap<int, QString> getChilds(int id);

private:
    QSqlDatabase db;

signals:

public slots:

};

#endif // SQLITE_H
