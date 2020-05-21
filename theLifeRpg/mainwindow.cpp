
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include "monster.h"

// Constants
const int kPixlen = 32;           // 图块像素大小
const int kOffsetX = 0;           // x轴偏移量
const int kOffsetY = 0;           // y轴偏移量
const int kDecimal = 10;          // 十进制系统设定

extern Player player;   // 玩家
extern int map[20][15][10]; // 地图，横坐标，纵坐标，地图编号


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->hide();

    scene = new QGraphicsScene;
    view = new View(this);

    scene->setSceneRect(0,0,681,521); // 设置画布
    scene->addPixmap(QPixmap(":/map/Image/Map/test.png"));
    view->setScene(scene);
    view->setMinimumSize(400,400);
    view->SetStatus("main");

    connect(view, SIGNAL(move(int, int)), this, SLOT(slotMovePlayerItem(int, int)));    // 移动连接槽

    AddPlayerItem(0,0,0);

    setCentralWidget(view);
    resize(683,524);
    setWindowTitle(tr("The Life RPG"));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotMovePlayerItem(int x, int y) {             // 移动玩家图像
    if (playerItem->zValue() == 0) {
        playerItem->moveBy(x*kPixlen, y*kPixlen);
        player.SetPosx(player.GetPosx() + x);
        player.SetPosy(player.GetPosy() + y);
        map[player.GetPosx()][player.GetPosy()][player.GetFloor()] = 0;
    }
}

void MainWindow::AddMapItem(int x, int y, int num) {            // 添加地图物块
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap(":/images/" ));
    //item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos(x*kPixlen-kOffsetX,y*kPixlen-kOffsetY);
}

void MainWindow::AddPictureItem(int x, int y, QString str) {    // 添加一些可能需要的物块
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap(":/images/" + str));
    //item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos(x-kOffsetX,y-kOffsetY);
}

void MainWindow::AddPlayerItem(int x, int y, int toward) {      // 添加玩家物体
    QString str = ":/role/Image/Role/1.png";
    playerItem = scene->addPixmap(QPixmap(str));
    playerItem->setPos(x*kPixlen-kOffsetX, y*kPixlen-kOffsetY);
}

void MainWindow::Clear() {              // 清空界面
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty()) {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}
