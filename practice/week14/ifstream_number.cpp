#include <iostream>
#include <fstream>
using namespace std;

int main(){ // 파일의 출력 스트림 생성 및 초기화
    ifstream is{"numbers.txt"};
    if(!is){
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    int number;
    while(is) {
        is >> number; // 파일 데이터 변수에 저장
        cout << number << " ";
    }
    cout << endl;
    return 0;

}
