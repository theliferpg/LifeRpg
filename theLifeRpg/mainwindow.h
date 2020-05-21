#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "view.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Clear();

    void AddMapItem(int x, int y, int num);
    void AddPictureItem(int x, int y, QString str);
    void AddPlayerItem(int x, int y, int toward);

public slots:
    void slotMovePlayerItem(int x, int y);


private:
    Ui::MainWindow *ui;

    View *view;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *playerItem;
};
#endif // MAINWINDOW_H
