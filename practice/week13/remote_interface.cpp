#include <iostream>
using namespace std;

class RemoteControl {
public:
    //순수 가상 함수 정의
    virtual void TurnON() = 0;
    virtual void TurnOFF() = 0;
};

class Television : public RemoteControl{
public:
    void TurnON() override{
        cout << "TV를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "TV를 끕니다." << endl;
    }
};

class Refrigerator : public RemoteControl {
public:
    void TurnON() override{
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "냉장고를 끕니다." << endl;
    }
};

int main(){
    // TV를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl * remoteTV = new Television();
    remoteTV -> TurnON(); // TV를 켬
    remoteTV -> TurnOFF(); // TV를 끔

    RemoteControl * remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON(); // 냉장고를 켬
    remoteRefrigerator->TurnOFF(); // 냉장고를 끔

    delete remoteTV, remoteRefrigerator;
    return 0;
}