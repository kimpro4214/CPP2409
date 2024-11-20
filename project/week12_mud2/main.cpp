#include <iostream>
#include <vector>
#include <string>
#include "user.h"

using namespace std;

const int map_x = 5;
const int map_y = 5;

// 사용자 정의 함수
bool CheckXY(int x, int y);
void DisplayMap(vector<vector<int>>& map, int user1_x, int user1_y, int user2_x, int user2_y);
bool CheckGoal(vector<vector<int>>& map, int user_x, int user_y);
void CheckState(vector<vector<int>>& map, int user_x, int user_y, User &user, bool &is_gameover, int turn);
bool CheckUser(const User& user); // 체력 상태를 확인하는 함수

int main() {
    vector<vector<int>> map ={ 
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2} 
    };

    int user_x[2] = {0, 0};  // 두 유저의 위치 (x 좌표)
    int user_y[2] = {0, 0};  // 두 유저의 위치 (y 좌표)

    Magician magician; // Magician 객체 생성
    Warrior warrior;   // Warrior 객체 생성
    User* users[2] = {&magician, &warrior}; // 두 유저를 포인터 배열로 관리

    bool first_move[2] = {true, true}; // 각 유저의 첫 이동 여부 확인
    bool is_gameover = false;

    int turn = 0; // 0: Magician, 1: Warrior

    while (!is_gameover) {
        string user_input;
        cout << "현재 턴: " << (turn == 0 ? "Magician" : "Warrior") << endl;
        cout << "명령어를 입력하세요 {상(up), 하(down), 좌(left), 우(right), 지도(map), 정보(info), 종료(stop)}: ";
        cin >> user_input;

        if (first_move[turn]) {
            cout << "현재 체력: " << users[turn]->GetHP() << endl;
            first_move[turn] = false;
        }

        int new_x = user_x[turn];
        int new_y = user_y[turn];

        if (user_input == "up") new_y -= 1;
        else if (user_input == "down") new_y += 1;
        else if (user_input == "left") new_x -= 1;
        else if (user_input == "right") new_x += 1;
        else if (user_input == "map") {
            DisplayMap(map, user_x[0], user_y[0], user_x[1], user_y[1]);
            continue;
        } 
        else if (user_input == "stop") {
            cout << "게임을 종료합니다." << endl;
            break;
        }
        else if (user_input == "info") {
            cout << *(users[turn]) << endl;
            continue;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (CheckXY(new_x, new_y)) {
            user_x[turn] = new_x;
            user_y[turn] = new_y;
            cout << "이동 완료. 체력이 1 감소합니다." << endl;
            users[turn]->DecreaseHP(1);
            cout << "현재 체력: " << users[turn]->GetHP() << endl;

            CheckState(map, user_x[turn], user_y[turn], *(users[turn]), is_gameover, turn);
        } else {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        }

        if (!CheckUser(*(users[turn]))) {
            cout << (turn == 0 ? "Magician" : "Warrior") << "의 체력이 0이 되었습니다. 게임 종료!" << endl;
            is_gameover = true;
        }

        DisplayMap(map, user_x[0], user_y[0], user_x[1], user_y[1]);

        if (CheckGoal(map, user_x[turn], user_y[turn])) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }

        turn = (turn + 1) % 2; // 턴을 번갈아 가며 바꿈 (0 -> 1, 1 -> 0)
    }

    return 0;
}

void CheckState(vector<vector<int>>& map, int user_x, int user_y, User &user, bool &is_gameover, int turn) {
    switch (map[user_y][user_x]) {
        case 1:
            cout << "아이템을 발견했습니다!" << endl;
            user.IncreaseItemCnt(1);
            break;
        case 2:
            // 턴에 따라 Magician 또는 Warrior의 공격 호출
            if (turn == 0) {
                static_cast<Magician&>(user).doAttack(); // Magician의 공격 호출, 형변환으로 Magician의 마법 사용이 출력되게 했습니다.
            } else if (turn == 1) {
                static_cast<Warrior&>(user).doAttack(); // Warrior의 공격 호출, 형변환으로 Warrior의 베기 사용이 출력되게 했습니다.
            }
            user.DecreaseHP(2);
            cout << "적을 만났습니다! 체력이 2 감소합니다. 현재 체력: " << user.GetHP() << endl;
            if (!CheckUser(user)) {
                cout << "체력이 0이 되었습니다. 실패!" << endl;
                is_gameover = true;
            }
            break;
        case 3:
            user.IncreaseHP(2);
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다. 현재 체력: " << user.GetHP() << endl;
            break;
    }
}


bool CheckUser(const User& user) {
    return user.GetHP() > 0;
}

void DisplayMap(vector<vector<int>>& map, int user1_x, int user1_y, int user2_x, int user2_y) {
    for (int i = 0; i < map_y; i++) {
        for (int j = 0; j < map_x; j++) {
            if (i == user1_y && j == user1_x && i == user2_y && j == user2_x) {
                cout << " M/W |"; // 두 유저가 같은 위치에 있을 경우
            } else if (i == user1_y && j == user1_x) {
                cout << "  M   |"; // Magician 위치
            } else if (i == user2_y && j == user2_x) {
                cout << "  W   |"; // Warrior 위치
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

bool CheckXY(int x, int y) {
    return (x >= 0 && x < map_x && y >= 0 && y < map_y);
}

bool CheckGoal(vector<vector<int>>& map, int user_x, int user_y) {
    return (map[user_y][user_x] == 4);
}
