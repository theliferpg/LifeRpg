#include "player.h"

void Player::ChooseVocation(int vocation){
    // 职业选择，暂时就设定单职业
    if (vocation == 1) {
        setHp(150);
        setAttack(14);
        setCrit(93);
    }
    setDefend(10);
    setMoney(0);
    setExp(0);
    this->level = 0;
    this->posx = 6;
    this->posy = 12;
    this->floor = 0;
    this->toward = 3;
    this->need = 5;
}

void Player::LevelUp(){
    level += 1;
    setHp(getHp() + 10);
    setAttack(getAttack() + 1);
    setDefend(getDefend() + 1);
    setExp(0);
}
