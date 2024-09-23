#include <iostream>
using namespace std;


int main(){
    int number;
    cout << "숫자를 입력하시오: ";
    cin >> number;
    //조건문을 switch로 변경
    switch(number){
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout <<"one" << endl;
            break;
        default :
            cout << "many" << endl;
            break;
    }
    return 0;
}