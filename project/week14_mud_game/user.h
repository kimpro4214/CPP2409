#include<iostream>
using namespace std;

class User {
private:
    int hp;
    int item;

public:
    virtual ~User() {} // 가상 소멸자
    virtual void DecreaseHP(int dec_hp) = 0; // 체력 감소 함수 (순수 가상 함수)
    virtual void IncreaseHP(int inc_hp) = 0; // 체력 증가 함수 (순수 가상 함수)
    virtual int GetHP() const = 0; // 체력 반환 함수 (순수 가상 함수)
    virtual int itemCnt() const = 0; // 아이템 개수 반환 함수 (순수 가상 함수)
    virtual void IncreaseItemCnt(int inc_item) = 0; // 아이템 개수 증가 함수 (순수 가상 함수)
    virtual void doAttack() const = 0; // 공격 함수 (순수 가상 함수)

    friend ostream& operator<<(ostream& os, const User& user) {
        os << "현재 체력 : " << user.GetHP() << " , " << "획득 아이템 개수 : " << user.itemCnt() << endl;
        return os;
    }
};

// Magician 클래스 (User를 상속)
class Magician : public User {
private:
    int hp;
    int item;

public:
    Magician() : hp(20), item(0) {} // 생성자 구현
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    int GetHP() const override;
    int itemCnt() const override;
    void IncreaseItemCnt(int inc_item) override;
    void doAttack() const override;
};

// Warrior 클래스 (User를 상속)
class Warrior : public User {
private:
    int hp;
    int item;

public:
    Warrior() : hp(20), item(0) {} // 생성자 구현
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    int GetHP() const override;
    int itemCnt() const override;
    void IncreaseItemCnt(int inc_item) override;
    void doAttack() const override;
};