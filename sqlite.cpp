#include <QFileInfo>
#include "sqlite.h"

SQLite::SQLite(QObject *parent) : QObject(parent)
{
  db = QSqlDatabase::addDatabase("QSQLITE");
}

SQLite::~SQLite()
{
    if (db.isOpen()) db.close();
}

bool SQLite::init(QString filename)
{
    QString path = QCoreApplication::applicationDirPath() +
        QDir::separator() +
        filename;

    if (!QFileInfo::exists(path) ||
        !QFileInfo(path).isFile())
        return false;

    db.setDatabaseName(path);

    return db.open();
}

QMap<int, QString> SQLite::getChilds(int id)
{
    QMap<int, QString> nodes;

    if (db.isOpenError()) return nodes;

    QSqlQuery query("SELECT id, name, parent FROM nodes WHERE parent = " +
                    QString::number(id));

    QSqlRecord rec = query.record();

    if (0 == rec.count()) return nodes;

    int name_id = rec.indexOf("name");
    int index_id = rec.indexOf("id");

    while (query.next())
    {
        nodes.insert(query.value(index_id).toInt(),
                     query.value(name_id).toString());
    }

    return nodes;
}
