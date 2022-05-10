#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
//행과 열을 바꿔줄 것이므로 ROW를 6으로 설정
const int ROW = 6; // row의 크기 설정
const int COL = 12; // col의 크기 설정

//뿌요가 터졌는지 안터졌는지 확인하는 함수
bool bfs(int r, int c, vector<vector<char>>& board) {
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    queue<ci> q;
    queue<ci> puyo; //포함된 좌표 저장할 큐
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

    //시작 초기화
    q.push({ r, c });
    puyo.push({ r, c });
    visited[r][c] = true;
    int cnt = 1; //모여있는 뿌요의 개수
    while (!q.empty()) { //q가 비어있지 않다면
        int cr = q.front().first; //q의 맨 앞 원소의 r값 저장
        int cc = q.front().second; //q의 맨 앞 원소의 c값 저장
        q.pop(); //q의 맨 앞의 원소 삭제

        for (int i = 0; i < 4; i++) { //dr, dc의 크기만큼 반복
            int nr = cr + dr[i]; //cr과 dr[i]의 합 저장
            int nc = cc + dc[i]; //cc와 dc[i]의 합 저장
            //nr의 값이 0보다 작거나 row보다 크거나 같거나
            //nc의 값이 0보다 작거나 col보다 크거나 같거나
            //visited의 값이 true이면
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue; // continue
            }
            if (board[nr][nc] == board[cr][cc]) { //board의 두 값이 같으면
                q.push({ nr, nc }); //q의 값에 r에는 nr저장, c에는 nc저장
                puyo.push({ nr, nc }); //puyo의 값에 r에는 nr저장, c에는 nc저장
                visited[nr][nc] = true; //visited값 true
                cnt++; //모여있는 뿌요의 개수 증가
            }
        }
    }
    if (cnt < 4) { //뿌요 안터짐
        return false; //false return
    }
    while (!puyo.empty()) { //puyo의 값이 비어있지 않으면
        int cr = puyo.front().first; //puyo의 맨 앞 원소의 r값 저장
        int cc = puyo.front().second; //puyo의 맨 앞 원소의 c값 저장
        puyo.pop(); //puyo의 맨 앞 원소 삭제

        board[cr][cc] = '.'; //board의 값 빈 공간으로 저장
    }
    return true; //true return
}

//뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
vector<vector<char>> makeNewBoard(vector<vector<char>>& board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.'));
    for (int i = 0; i < ROW; i++) { // i는 0부터 row의 크기까지 반복
        queue<char> temp; //남아있는 뿌요 모으는 큐
        for (int j = 0; j < COL; j++) { // j는 0부터 col의 크기까지 반복
            if (board[i][j] != '.') { // 만약 board의 값이 빈 공간이면
                temp.push(board[i][j]); //남아있는 뿌요 모으는 큐에 board의 값 push
            }
        }
        int index = 0; //index 변수 설정
        while (!temp.empty()) { // 만약 남아있는 뿌요가 있다면
            new_board[i][index++] = temp.front(); // 남아 있는 뿌요 모으는 큐의 맨 앞 원소를 새로운 board에 넣기
            temp.pop(); //남아 있는 뿌요 모으는 큐의 맨 앞 원소 삭제
        }
    }
    return new_board; //새로운 board return
}

//뿌요가 한번이라도 터졌는지 안터졌는지 확인해서 answer값을 리턴하는 함수
int simulation(vector<vector<char>>& board) {
    int answer = 0; //answer 변수
    while (true) { // while문 반복
        bool flag = false; //뿌요가 터졌는지 확인
        for (int i = 0; i < ROW; i++) { // i는 0부터 row의 크기까지 반복
            for (int j = 0; j < COL; j++) { // j는 0부터 col의 크기까지 반복
                if (board[i][j] == '.') { // 필드가 빈공간이면
                    continue; // for문 continue
                }
                if (bfs(i, j, board)) { //한 번이라도 뿌요 터졌다면
                    flag = true; // flag true로 변경
                }
            }
        }
        if (!flag) { //만약 flag가 false이면, 뿌요가 한 번이라도 터지지 않았다면
            break; // while문 빠져나오기
        }
        board = makeNewBoard(board); //makeNewBoard 함수를 통해서 새 필드를 작성
        answer++; // answer 변수 증가
    }
    return answer; // answer 값 리턴
}

/**
 * [Puyo Puyo] - bfs, 시뮬레이션 문제
 *
 * 1. bfs 탐색을 통해 4개 이상의 뿌요가 모였는지 확인
 * 2. 4개 이상의 뿌요가 모였다면, 해당되는 영역을 '.'으로 바꾸어 비워줌
 * 3. 전체 필드에 대해 1~2를 다 수행한 후, 뿌요를 떨어뜨림
 *    - 바닥부터 시작해서 남아있는 뿌요들을 모으고, 남은 부분은 '.'으로 채우는 방식
 * 4. 터뜨릴 수 없을 때까지 반복
 *
 * 여기서, 3번 과정을 편하게 하기 위해 12*6으로 들어오는 입력을 6*12로 바꾸어준다.
 * 같은 열에 있는 데이터를 다루는 것보다 같은 행에 있는 데이터를 다루는 것이 편하기 때문이다.
 */

int main() {
    //입력
    char input; //input char 변수
    vector<vector<char>> board(ROW, vector<char>(COL)); //필드의 정보를 저장하는 board
    for (int i = 0; i < COL; i++) { // i는 0부터 col의 크기까지 반복
        for (int j = 0; j < ROW; j++) { // j는 0부터 row의 크기까지 반복
            cin >> input; //input 입력받기
            board[j][COL - i - 1] = input; // 같은 행에 있는 데이터를 다루기 위해 input을 반대로 board에 넣음
        }
    }

    //연산 & 출력
    cout << simulation(board);
    return 0;
}