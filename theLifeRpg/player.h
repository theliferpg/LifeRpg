#ifndef PLAYER_H
#define PLAYER_H

#include "Role.h"
#include <QString>

class Player : public Role
{
public:
    Player() {}
    ~Player() {}
    int GetLevel() { return level; }
    int GetPosx() { return posx; }
    int GetPosy() { return posy; }
    int GetFloor() {return floor; }
    int GetToward() {return toward; }
    int GetVocation() {return vocation; }

    void SetLevel(int level) { this->level = level; }
    void SetPosx(int posx) { this->posx = posx; }
    void SetPosy(int posy) { this->posy = posy; }
    void SetFloor(int floor) { this->floor = floor; }
    void SetToward(int toward) { this->toward = toward; }
    void SetVocation(int vocation) { this->vocation = vocation; }
    void ChooseVocation(int vocation);
    void LevelUp();

private:
    int level;  // 等级
    int need;   // 下一级所需经验-是否需要待定
    int posx;   // 当前x坐标
    int posy;   // 当前y坐标
    int floor;  // 目前所处位置
    int toward; // 朝向
    int vocation;   // 职业，待定

};

#endif // PLAYER_H
