#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    vector<int> scores;
    int score;


    while(true){
        cout << "성적을 입력하세요 (종료는 -1) : ";
        cin >> score;

        if(score == -1 ){
            break;
        }
        scores.push_back(score);
    }
    int sum, average;

    for (int s : scores){
        sum += s;
    }
    average = sum / scores.size();
    cout << average << endl;

}