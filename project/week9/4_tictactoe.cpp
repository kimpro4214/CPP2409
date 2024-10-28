#include <iostream>
#include <string>
using namespace std;

	const int numCell = 4; // 보드판의 가로 세로 길이


bool isValid(int x, int y, char board[numCell][numCell]) {
    if (x < 0 || y < 0 || x >= numCell || y >= numCell) {
        cout << x << "," << y << ": x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return false;
    }
    if (board[x][y] != ' ') {
        cout << x << "," << y << ": 이미 돌이 차있습니다." << endl;
        return false;
    }
    return true;
}

// 승리 체크 함수
bool checkWin(char board[numCell][numCell], char currentUser) {
    // 가로, 세로 체크
    for (int i = 0; i < numCell; i++) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) rowWin = false;
            if (board[j][i] != currentUser) colWin = false;
        }
        if (rowWin || colWin) {
            cout << (rowWin ? "가로" : "세로") << "에 모두 돌이 놓였습니다!!" << endl;
            return true;
        }
    }

    // 대각선 체크
    int leftDiagCount = 0, rightDiagCount = 0;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] == currentUser) leftDiagCount++;
        if (board[i][numCell - i - 1] == currentUser) rightDiagCount++;
    }

    if (leftDiagCount == numCell) {
        cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }
    if (rightDiagCount == numCell) {
        cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }

    return false;
}

int main() {
	// 게임을 진행하는 데 필요한 변수 선언

	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		currentUser = (k % 3 == 0) ?  'X' : (k % 3 == 1) ? 'O' : 'V';
		cout << (currentUser == 'X' ? "첫 번째 유저(X)" : currentUser == 'O' ? "두 번째 유저(O)" : "세 번째 유저(V)") << "의 차례입니다. --> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		if (!isValid(x, y, board)) {
            continue;
        }



		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) {
			for(int k = 0; k < numCell-1; k ++){
				cout << "---|";
			}
			cout << "---" << endl;

			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		for(int k = 0; k < numCell - 1; k ++){
				cout << "---|";
		}
		cout << "---" << endl;



		bool isWin = false; // 승리 여부
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		if (checkWin(board, currentUser)) {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}