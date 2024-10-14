#include <iostream>
#include <string>
using namespace std;

    string s1, s2;
    int count = 0;

string toLowerstr(string str) {
    string newStr = str;
    for(char& c : newStr){
        c=tolower(c);
    }
    return newStr;
}

string toUpperstr(string str) {
    string newStr = str;
    for(char& c : newStr){
        c=toupper(c);
    }
    return newStr;
}

int calcHammingDist(string s1, string s2){
    s1 = toLowerstr(s1);
    s2 = toLowerstr(s2);
    int count = 0;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i])
            count += 1;
    }
    return count;
}

int main(){
    
    while(1){
        //스페이스바를 문자열로 입력받지 못해 수정.
        cout << "DNA1 : ";
        getline(cin, s1);
        cout << "DNA2 : ";
        getline(cin, s2);

        if(s1.length()!= s2.length()){
            cout << "오류 : 길이가 다름" << endl;
            continue;
        }

        else{
            int count = calcHammingDist(s1, s2);
            cout << "해밍 거리는 " << count << endl;
            break;
        }
    }
    
    
    return 0;
}


