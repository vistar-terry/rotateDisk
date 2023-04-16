#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "disk.h"
#include <QPainter>
#include <QDebug>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(684, 684);
    this->setWindowTitle("律盘 - 2.0.1");
    setWindowIcon(QIcon(":/resource/icon.png"));

    ui->stackedWidget->setFixedSize(this->size());
    ui->stackedWidget->move((this->width() - ui->stackedWidget->width())/qreal(2), (this->height() - ui->stackedWidget->height())/qreal(2));
    ui->widget->setFixedSize(this->size());
    ui->widget->move((this->width() - ui->widget->width())/qreal(2), (this->height() - ui->widget->height())/qreal(2));
    ui->widget_2->setFixedSize(this->size());
    ui->widget_2->move((this->width() - ui->widget_2->width())/qreal(2), (this->height() - ui->widget_2->height())/qreal(2));

    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    QAction * lvPanMenu = bar->addAction("律盘(L)");
    QAction * dingXianMenu = bar->addAction("定弦(D)");
    QAction * aboutMenu = bar->addAction("关于(A)");

    connect(lvPanMenu, &QAction::triggered, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(dingXianMenu, &QAction::triggered, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(aboutMenu, &QAction::triggered, [=](){
        QString str("律盘 V2.0.1\n\r鼠标拖动旋转      \n\r --by 万俟淋曦        ");
        QMessageBox::about(this, "关于", str);
    });

    qreal y = -10;
    QWidget * lvPanParent = ui->stackedWidget->widget(0);
    QWidget * dingXianParent = ui->stackedWidget->widget(1);
    Disk * disk1 = new Disk(":/resource/1.png");
    disk1->setParent(lvPanParent);
    disk1->move((this->width() - disk1->width())/qreal(2), (this->height() - disk1->height())/qreal(2)+y);

    Disk * disk2 = new Disk(":/resource/2.png");
    disk2->setParent(lvPanParent);
    disk2->move((this->width()-disk2->width())/qreal(2), (this->height()-disk2->height())/qreal(2)+y);

    Disk * disk3 = new Disk(":/resource/3.png");
    disk3->setParent(lvPanParent);
    disk3->move((this->width()-disk3->width())/qreal(2), (this->height()-disk3->height())/qreal(2)+y);

    Disk * disk4 = new Disk(":/resource/4.png");
    disk4->setParent(lvPanParent);
    disk4->move((this->width()-disk4->width())/qreal(2), (this->height()-disk4->height())/qreal(2)+y);

    Disk * disk5 = new Disk(":/resource/5.png");
    disk5->setParent(lvPanParent);
    disk5->move((this->width()-disk5->width())/qreal(2), (this->height()-disk5->height())/qreal(2)+y);


    Disk * disk6 = new Disk(":/resource/6.png");
    disk6->setParent(dingXianParent);
    disk6->move((this->width()-disk6->width())/qreal(2), (this->height()-disk6->height())/qreal(2)+y);

    Disk * disk7 = new Disk(":/resource/7.png");
    disk7->setParent(dingXianParent);
    disk7->move((this->width()-disk7->width())/qreal(2), (this->height()-disk7->height())/qreal(2)+y);

    Disk * disk8 = new Disk(":/resource/8.png");
    disk8->setParent(dingXianParent);
    disk8->move((this->width()-disk8->width())/qreal(2), (this->height()-disk8->height())/qreal(2)+y);

    Disk * disk9 = new Disk(":/resource/9.png");
    disk9->setParent(dingXianParent);
    disk9->move((this->width()-disk9->width())/qreal(2), (this->height()-disk9->height())/qreal(2)+y);

    Disk * disk10 = new Disk(":/resource/10.png");
    disk10->setParent(dingXianParent);
    disk10->move((this->width()-disk10->width())/qreal(2), (this->height()-disk10->height())/qreal(2)+y);
}

MainWindow::~MainWindow()
{
    delete ui;
}

