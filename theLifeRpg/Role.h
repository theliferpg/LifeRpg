#ifndef ROLE_H
#define ROLE_H

class Role{

public:
    Role(){}
    ~Role(){}
    // 设置属性
    void setHp(int hp){this->hp = hp;}
    void setAttack(int attack){this->attack = attack;}
    void setDefend(int defend){this->defend = defend;}
    void setExp(int exp){this->exp = exp;}
    void setCrit(int crit){this->crit = crit;}
    void setMoney(int money){this->money = money;}
    // 获取属性
    int getHp(){return hp;}
    int getAttack(){return attack;}
    int getDefend(){return defend;}
    int getExp(){return exp;}
    int getCrit(){return crit;}
    int getMoney(){return money;}

private:
    int hp;     // 生命值
    int attack; // 攻击力
    int defend; // 防御力
    int exp;    // 经验值
    int crit;   // 暴击率
    int money;  // 金钱数量
};

#endif // ROLE_H
