#include <iostream>
using namespace std;


int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100): ";
    cin >> floor;
    /*
    for (int i =floor; i >0 ; i--){
        for(int j =0; j<floor -i; j++){
            cout << " ";
        }
        for(int k = 0; k < i*2-1; k++){
            cout << "*";
        }
        cout << endl;
    }
    */

    for (int i = floor; i > 0 ; i--){
        for(int j =0; j <= floor - i - 1; j++){ //부등호를 추가
            cout << " ";
        }
        for(int k = 0; k < i*2-1; k++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;

}