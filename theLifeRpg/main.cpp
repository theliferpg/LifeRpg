#include "mainwindow.h"
#include "Role.h"
#include "player.h"
#include "monster.h"
#include "view.h"

#include <QApplication>

Player player;
int map[20][15][10];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
