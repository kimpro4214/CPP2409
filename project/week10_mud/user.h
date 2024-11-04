#include <iostream>
#include <string>
using namespace std;

class User {
private :
    int hp;
public :
    void DecreaseHp(int dec_hp);
    void IncreaseHp(int inc_hp);
    int GetHP() { return hp; }
    User() { return; }
}
