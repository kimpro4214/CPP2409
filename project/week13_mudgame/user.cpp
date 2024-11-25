#include "user.h"
#include <iostream>

using namespace std;

// Magician 클래스 구현
void Magician::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;
}

void Magician::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int Magician::GetHP() const {
    return hp;
}

int Magician::itemCnt() const {
    return item;
}

void Magician::IncreaseItemCnt(int inc_item) {
    item += inc_item;
}

void Magician::doAttack() const {
    cout << "마법 사용" << endl;
}

// Warrior 클래스 구현
void Warrior::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;
}

void Warrior::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int Warrior::GetHP() const {
    return hp;
}

int Warrior::itemCnt() const {
    return item;
}

void Warrior::IncreaseItemCnt(int inc_item) {
    item += inc_item;
}

void Warrior::doAttack() const {
    cout << "베기 사용" << endl;
}
