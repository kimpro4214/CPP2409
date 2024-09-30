#include <iostream>
#include <string>
using namespace std;


int main(){
    const int maxPeople = 2;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++){
        cout << "사람" << i+1 << "의 이름 : ";
        cin >> names[i];
        cout << "사람" << i+1 << "의 나이 : ";
        cin >> ages[i];

    }

    int ageThreshold;
    int max = 0;
    string maxname;
    int min = 9999;
    string minname;

    for(int i = 0; i < maxPeople; i++){
            if(ages[i] > max){
                max = ages[i];
                maxname = names[i];
            }
        }

    for(int i = 0; i < maxPeople; i++){
            if(ages[i] < min){
                min = ages[i];
                minname = names[i];
            }
        }


    do {
    cout << "1. 나이가 많은 사람, 2. 나이가 적은 사람, 3. 종료 : " ;
    cin >> ageThreshold;
    switch (ageThreshold) {
        case 1 :
        cout << "나이가 가장 많은 사람은 " << maxname << "입니다." << endl;
        break;

        case 2 :
        cout << "나이가 가장 적은 사람은 " << minname << "입니다." << endl;
        break;

        case 3 :
        cout << "종료합니다. " << endl;
        break;

        default :
        cout << "잘못입력하셨습니다." << endl;
        break; } 
    } while(ageThreshold == 1 || ageThreshold == 2);
    

}

/*
1. 가장 나이가 많은 사람 출력
2. 가장 나이가 적은 사람 출력
3. 종료
그 외 숫자 입력시 메시지 띄우고 종료
*/