#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMap>
#include <QTreeWidgetItem>
#include <QMainWindow>
#include "sqlite.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void buildNode(QTreeWidgetItem *root, QMap<int, QString> nodes);
    void buildTree(QTreeWidget *widget);

private:
    Ui::MainWindow *ui;
    SQLite *db;
};

#endif // MAINWINDOW_H
