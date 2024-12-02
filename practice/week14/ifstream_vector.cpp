#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TempData {
public:
    int hour;
    double temperature;
};

int main(){ // 파일의 출력 스트림 생성 및 초기화
    ifstream is{"temp.txt"};
    if(!is){
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }

    vector<TempData> temps;
    int hour;
    double temperature;

    while(is >> hour >> temperature) {
        temps.push_back(TempData{hour, temperature});
    }
    for( TempData t : temps){
        cout << t.hour << "시 : 온도 " << t.temperature << endl;
    }
    return 0;

}
