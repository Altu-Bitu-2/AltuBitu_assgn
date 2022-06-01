#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

int n, ans = 0;

int getMaxBlock(matrix& board) { //board에서 최대 값 구하는 함수
    int max_block = 0;
    for (int i = 0; i < n; i++) { //n만큼 반복
        for (int j = 0; j < n; j++) { //n만큼 반복
            max_block = max(max_block, board[i][j]); //board에서 최댓값 저장
        }
    }
    return max_block; //최댓값 return
}

matrix transposeMatrix(matrix& board) { //matrix의 행과 열을 바꾸는 함수
    matrix board_t(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board_t[i][j] = board[j][i]; //matrix의 행과 열 반대로 저장
        }
    }
    return board_t;
}

/**
 * 상으로 이동하는 함수
 * - 한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
 * - 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
 */

matrix upMove(matrix board) { //위로 이동하는 함수
    matrix temp(n, vector<int>(n, 0)); //새롭게 블록 저장할 배열
    for (int j = 0; j < n; j++) {
        int idx = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (!board[i][j]) { //보드에 블록이 없는 부분, 빈칸일 경우
                continue; //continue
            }
            if (board[i][j] == prev) { //빈칸이 아니고 숫자가 같을 경우
                temp[idx - 1][j] *= 2; //합치기
                prev = 0;
            }
            else { //빈칸이 아니고 숫자가 다를 경우
                temp[idx++][j] = board[i][j]; //그대로
                prev = board[i][j]; //prev 새로 설정
            }
        }
    }
    return temp;
}

//백트래킹 탐색
void backtracking(int cnt, matrix board) {
    if (cnt == 5) {
        ans = max(ans, getMaxBlock(board));
        return;
    }
    //Transpose matrix 구하기 (상->좌)
    //행으로 조사하는 경우와 열로 조사하는 경우가 존재하기 때문에
    matrix board_t = transposeMatrix(board);
    //상
    backtracking(cnt + 1, upMove(board)); //열로 조사
    //하
    reverse(board.begin(), board.end());
    backtracking(cnt + 1, upMove(board)); //열로 조사
    //좌
    backtracking(cnt + 1, upMove(board_t)); //행으로 조사
    //우
    reverse(board_t.begin(), board_t.end());
    backtracking(cnt + 1, upMove(board_t)); //행으로 조사
}

/**
 * [2048 (Easy)]
 *
 * - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 * - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦
 *
 * - 상 <-> 하: 행 순서를 뒤집어서 해결
 * - 상/하 <-> 좌/우: Transpose Matrix 활용
 *
 * - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
 *       2 2 2
 *       4 4 4
 *  -상: 원래 배열에서 상으로 움직이는 함수 실행
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    //입력
    cin >> n; //보드의 크기
    matrix board(n, vector<int>(n, 0)); //보드판
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //보드판 입력받기
        }
    }

    //연산
    backtracking(0, board);

    //출력
    cout << ans; //최대 5번 이동시켜서 얻을 수 있는 가장 큰 블럭의 값 출력
    return 0;
}