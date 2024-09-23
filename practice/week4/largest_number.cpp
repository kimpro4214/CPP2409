#include <iostream>
using namespace std;


int main(){
    int a,b,c,largest;

    cout << "3개의 정수를 입력하시오 :";
    cin >> a >> b >> c;
    // 조건에 부등호를 넣으면 a,b가 같더라도 a,b보다 작은 c값을 가장 큰 값으로 출력하지 않음.
    if (a >= b && a >= c){
        largest = a;
    }
    else if (b >= a && b >= c) {
        largest = b;
    }
    else {
        largest = c;
    }

    cout << "가장 큰 정수는 " << largest << endl;
    return 0;

}