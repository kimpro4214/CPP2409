#include <iostream>
using namespace std;


int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x,y;

    for (x = 0; x<numCell; x++){
        for(y = 0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }

    int k = 0;
    char currentUser = 'X';
    while(true){
        switch (k % 2){
            case 0:
                cout << "첫 번째 유저(X)의 차례입니다. --> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두 번째 유저(O)의 차례입니다 --> ";
                currentUser = 'O';
                break;
            
        }

        cout << "(x, y) 좌표를 입력하세요 : ";
        cin >> y >> x; // x,y가 거꾸로 되어있어 변경

        if(x >= numCell || y >= numCell){
            cout << y << ", " << x << ": ";
            cout << "정해진 범위를 벗어납니다. x, y 좌표를 0 ~ 2로 설정해주세요." << endl; // 구문 조정
            continue;
        }
        if(board[x][y] != ' '){
            cout << y << ", " << x << ": 이미 돌이 차있습니다." << endl;
            continue;
        }
        board[x][y] = currentUser;

        for(int i = 0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for(int j = 0; j < numCell; j++){
                cout << board[i][j];
                if( j == numCell - 1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;
        //빙고 시 승자 출력
        //빙고 --> [0][0~2] [1][0~2] [2][0~2] [K][K]


        // X 승리 시 출력
        if(board[0][0]=='X'){
            if(board[0][1] == 'X'){
                if(board[0][2] == 'X'){
                    cout << "첫 번째 유저(X)가 승리했습니다!";
                    break;
                }
            }
            if(board[1][1]=='X'){
                if(board[2][2] == 'X'){
                    cout << "첫 번째 유저(X)가 승리했습니다!";
                    break;
                }
            }
            if(board[1][0]=='X'){
                if(board[2][0]=='X'){
                    cout << "첫 번째 유저(X)가 승리했습니다!";
                    break;
                }
            }
        }

        if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
            cout << "첫 번째 유저(X)가 승리했습니다!" << endl;
            break;
        }

        if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
            cout << "첫 번째 유저(X)가 승리했습니다!" << endl;
            break;
        }


        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
            cout << "첫 번째 유저(X)가 승리했습니다!" << endl;
            break;
        }

        // O 승리 시 출력
        if(board[0][0]=='O'){
            if(board[0][1] == 'O'){
                if(board[0][2] == 'O'){
                    cout << "두 번째 유저(O)가 승리했습니다!";
                    break;
                }
            }
            if(board[1][1]=='O'){
                if(board[2][2] == 'O'){
                    cout << "두 번째 유저(O)가 승리했습니다!";
                    break;
                }
            }
            if(board[1][0]=='O'){
                if(board[2][0]=='O'){
                    cout << "두 번째 유저(O)가 승리했습니다!";
                    break;
                }
            }
        }

        if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
            cout << "두 번째 유저(O)가 승리했습니다!" << endl;
            break;
        }

        if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
            cout << "두 번째 유저(O)가 승리했습니다!" << endl;
            break;
        }


        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
            cout << "두 번째 유저(O)가 승리했습니다!" << endl;
            break;
        }

        
        //모든 칸이 차면 종료
        int checkNum = 0;
        for(int i = 0; i < numCell; i++){
            for(int j = 0; j < numCell; j++){
                if(board[i][j]!=' '){
                    checkNum++;
                }
            }
        }

        if(checkNum == 9){
            cout << "모든 칸이 가득 찼습니다! 게임이 종료되었습니다.";
            break;
        }
    }
    return 0;

}