#include <iostream>
#include <vector>
#include <string>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int x, int y);
void displayMap(vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y);
void checkState(vector<vector<int>>& map, int user_x, int user_y, User &user, bool &isGameOver);
bool checkUser(User user); // 체력 상태를 확인하는 함수

int main() {
    vector<vector<int>> map ={ 
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2} 
    };



    int user_x = 0;
    int user_y = 0;
    User user; // User 객체 생성
    bool firstMove = true;
    bool isGameOver = false;

    while (!isGameOver) {
        string user_input;
        cout << "명령어를 입력하세요 {상(up), 하(down), 좌(left), 우(right), 지도(map), 정보(info), 종료(stop)}: ";
        cin >> user_input;

        if (firstMove) {
            cout << "현재 체력: " << user.GetHP() << endl;
            firstMove = false;
        }

        int new_x = user_x;
        int new_y = user_y;

        if (user_input == "up") new_y -= 1;
        else if (user_input == "down") new_y += 1;
        else if (user_input == "left") new_x -= 1;
        else if (user_input == "right")  new_x += 1;
        else if (user_input == "map") {
            displayMap(map, user_x, user_y);
            continue;
        } 
        else if (user_input == "stop") {
            cout << "게임을 종료합니다." << endl;
            break;
        }
        else if (user_input == "info") {
            cout << user << endl;
            continue;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (checkXY(new_x, new_y)) {
            user_x = new_x;
            user_y = new_y;
            cout << "이동 완료. 체력이 1 감소합니다." << endl;
            user.DecreaseHP(1);
            cout << "현재 체력: " << user.GetHP() << endl;

            checkState(map, user_x, user_y, user, isGameOver);
        } else {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        }

        if (!checkUser(user)) {
            cout << "실패! 체력이 0이 되었습니다." << endl;
            isGameOver = true;
        }

        displayMap(map, user_x, user_y);

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }
    }

    return 0;
}

void checkState(vector<vector<int>>& map, int user_x, int user_y, User &user, bool &isGameOver) {
    switch (map[user_y][user_x]) {
        case 1:
            cout << "아이템을 발견했습니다!" << endl;
            user.IncreaseItemCnt(1);
            break;
        case 2:
            user.DecreaseHP(2);
            cout << "적을 만났습니다! 체력이 2 감소합니다. 현재 체력: " << user.GetHP() << endl;
            if (!checkUser(user)) {
                cout << "체력이 0이 되었습니다. 실패!" << endl;
                isGameOver = true;
            }
            break;
        case 3:
            user.IncreaseHP(2);
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다. 현재 체력: " << user.GetHP() << endl;
            break;
    }
}

bool checkUser(User user) {
    return user.GetHP() > 0;
}

void displayMap(vector<vector<int>>& map, int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl << " -------------------------------- " << endl;
    }
}

bool checkXY(int x, int y) {
    return (x >= 0 && x < mapX && y >= 0 && y < mapY);
}

bool checkGoal(vector<vector<int>>& map, int user_x, int user_y) {
    return (map[user_y][user_x] == 4);
}
 