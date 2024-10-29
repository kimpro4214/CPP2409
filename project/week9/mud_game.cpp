#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
const int initialHP = 20; // 초기 체력

// 사용자 정의 함수
bool checkXY(int x, int y);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, int &hp, bool &isGameOver); 


// 메인 함수
int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = { 
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2} 
    };

    int user_x = 0; // 플레이어의 가로 위치
    int user_y = 0; // 플레이어의 세로 위치
    int hp = initialHP; // 초기 체력 설정
    bool firstMove = true; // 첫 명령어 입력 여부
    bool isGameOver = false; // 게임 종료 여부 플래그


    while (!isGameOver) { // 게임 루프
        string user_input;

        cout << "명령어를 입력하세요 {상(up), 하(down), 좌(left), 우(right), 지도(map), 종료(stop)}: ";
        cin >> user_input;

        // 첫 명령어 입력 시 HP 출력
        if (firstMove) {
            cout << "현재 체력: " << hp << endl;
            firstMove = false;
        }

        // 이동 처리
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
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // 맵 경계 검증
        if (checkXY(new_x, new_y)) {
            user_x = new_x;
            user_y = new_y;
            if (user_input == "up") cout << "위로 이동합니다." << endl;
            else if (user_input == "down") cout << "아래로 이동합니다." << endl;
            else if (user_input == "left") cout << "왼쪽으로 이동합니다." << endl;
            else if (user_input == "right")  cout << "오른쪽으로 이동합니다." << endl;

             // 이동 시 체력 1 감소
            hp -= 1;
            cout << "체력이 1 감소했습니다. 현재 체력: " << hp << endl;

            // 현재 위치 상태 확인 (checkState 함수 호출)
            checkState(map, user_x, user_y, hp, isGameOver);

        } else {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        }

        // 체력 0 이하일 경우 게임 종료
        if (hp <= 0) {
            cout << "실패! 체력이 0이 되었습니다." << endl;
            isGameOver = true; // 게임 종료 플래그 설정
        }

        // 현재 맵 상태 출력
        displayMap(map, user_x, user_y);

        // 목적지 도달 여부 체크
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }

    return 0;
}

// 맵과 사용자 위치 상태 확인 함수
void checkState(int map[][mapX], int user_x, int user_y, int &hp, bool &isGameOver) {
    switch (map[user_y][user_x]) {
        case 1: // 아이템
            cout << "아이템을 발견했습니다!" << endl;
            break;
        case 2: // 적
            hp -= 2;
            cout << "적을 만났습니다! 체력이 2 감소합니다. 현재 체력: " << hp << endl;

            if (hp <= 0) {
                cout << "체력이 0이 되었습니다. 실패!" << endl;
                isGameOver = true; // 게임 종료 플래그 설정
            }
            break;
        case 3: // 포션
            hp += 2;
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다. 현재 체력: " << hp << endl;
            break;
    }
}

// 맵과 사용자 위치 출력
void displayMap(int map[][mapX], int user_x, int user_y) {
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

// 맵 경계 확인 함수
bool checkXY(int x, int y) {
    return (x >= 0 && x < mapX && y >= 0 && y < mapY);
}

// 목적지 도달 여부 확인 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return (map[user_y][user_x] == 4);
}
