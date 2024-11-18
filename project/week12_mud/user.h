#include<iostream>
using namespace std;

class User {
private:
    int hp; // 체력
    int item;

public:
    User(); // 생성자
    void DecreaseHP(int dec_hp); // 체력 감소 함수
    void IncreaseHP(int inc_hp); // 체력 증가 함수
    int GetHP() const; // 체력 반환 함수
    int itemCnt() const; // 아이템 개수 반환 함수
    void IncreaseItemCnt(int inc_item); // 아이템 개수 증가 함수
   
    friend ostream& operator<<(ostream& os, const User& itemCnt){
        os<<"현재 체력 : " << itemCnt.hp << " , " << "획득 아이템 개수 : " << itemCnt.item << endl;
        return os;
    }
};
 
