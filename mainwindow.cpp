#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::buildNode(QTreeWidgetItem *root, QMap<int, QString> nodes)
{
    foreach (const int &key, nodes.keys())
    {
         QTreeWidgetItem *node = new QTreeWidgetItem(root);
         node->setText(0, nodes.value(key));
         buildNode(node, db->getChilds(key));
    }
}

void MainWindow::buildTree(QTreeWidget *widget)
{
    widget->clear();

    QMap<int, QString> nodes = db->getChilds(0);

    foreach (const int &key, nodes.keys())
    {
         QTreeWidgetItem *node = new QTreeWidgetItem(widget);
         node->setText(0, nodes.value(key));
         buildNode(node, db->getChilds(key));
    }
}

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new SQLite();

    if (!db->init("base.db"))
    {
        buildTree(ui->tw);
    }
    else
    {
        QApplication::closeAllWindows();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete db;
}
