#include "view.h"
#include "player.h"
#include <QKeyEvent>

extern Player player;
extern int map[20][15][10];

View::View(QWidget *parent) : QGraphicsView(parent) {         // 初始化为main，status后续可变动为其他界面
    status = "main";
    next_step = 0;
}

View::~View() {         // 退出的话清空内容
    status = "";
    next_step = 0;
}

void View::keyPressEvent(QKeyEvent * event) {         // 检测什么时候进行了按键
    if (status == "main") {         // 如果是主界面【地图】那就进行移动
        keyMain(event);
        action();         // 检测一下地图上的内容
    }
}

void View::keyMain(QKeyEvent * event) {
    switch (event->key()) {
        case Qt::Key_Up:        // 向上移动
            if (access(player.GetPosx(), player.GetPosy()-1))
                emit move(0, -1);
            player.SetToward(4);
            break;
        case Qt::Key_Down:      // 向下移动
            if (access(player.GetPosx(), player.GetPosy()+1))
                emit move(0, +1);
            player.SetToward(1);
            break;
        case Qt::Key_Left:      // 向左移动
            if (access(player.GetPosx()-1, player.GetPosy()))
                emit move(-1, 0);
            player.SetToward(2);
            break;
        case Qt::Key_Right:     // 向右移动
            if (access(player.GetPosx()+1, player.GetPosy()))
                emit move(+1, 0);
            player.SetToward(3);
            break;

        default:
            break;
    }
}

void View::action() {
    switch (next_step) {    // 检测下一步会遇到什么，暂时为空

    }
    if (status == "main")
        emit change();
}

int View::access(int x, int y) {          // 检查一下是否可以达到，后续会添加一下内容
    if(x < 0 || x > 20 || y < 0 || y > 15) return 0;
    int tmp = map[x][y][player.GetFloor()];
    next_step = tmp;
    if (true) {
        map[x][y][player.GetFloor()] = 0;
        return 1;
    } else
        return 0;
}
