#include "user.h"

User::User() {
    hp = 20; // 초기 체력 설정
    item = 0; // 초기 아이템 개수 설정
}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0; // 체력이 0 이하가 되지 않도록
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() const {
    return hp;
}

int User::itemCnt() const{
    return item;
}

void User::IncreaseItemCnt(int inc_item){
    item += inc_item;
}
 
