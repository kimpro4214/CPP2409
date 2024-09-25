#include <iostream>
#include <time.h>
using namespace std;


int main(){
    // 프로그램을 여러 번 실행 했을 때 계속해서 같은 문제가 나와 srand를 사용.
    srand(time(NULL));
    int i;
    int ans;
    cout << "산수 문제를 자동으로 출제합니다. " << endl;

    while(true){
        int firstNum = rand()%100;
        int secondNum = rand()%100;

        cout << firstNum << "+" << secondNum << "=";
        cin >> ans;
        if (firstNum + secondNum == ans){
            cout << "맞았습니다.\n";
            break;
        }
        else {
            cout << "틀렸습니다.\n";
        }
    }   

}