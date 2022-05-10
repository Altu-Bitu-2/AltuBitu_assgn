#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
//��� ���� �ٲ��� ���̹Ƿ� ROW�� 6���� ����
const int ROW = 6; // row�� ũ�� ����
const int COL = 12; // col�� ũ�� ����

//�ѿ䰡 �������� ���������� Ȯ���ϴ� �Լ�
bool bfs(int r, int c, vector<vector<char>>& board) {
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    queue<ci> q;
    queue<ci> puyo; //���Ե� ��ǥ ������ ť
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

    //���� �ʱ�ȭ
    q.push({ r, c });
    puyo.push({ r, c });
    visited[r][c] = true;
    int cnt = 1; //���ִ� �ѿ��� ����
    while (!q.empty()) { //q�� ������� �ʴٸ�
        int cr = q.front().first; //q�� �� �� ������ r�� ����
        int cc = q.front().second; //q�� �� �� ������ c�� ����
        q.pop(); //q�� �� ���� ���� ����

        for (int i = 0; i < 4; i++) { //dr, dc�� ũ�⸸ŭ �ݺ�
            int nr = cr + dr[i]; //cr�� dr[i]�� �� ����
            int nc = cc + dc[i]; //cc�� dc[i]�� �� ����
            //nr�� ���� 0���� �۰ų� row���� ũ�ų� ���ų�
            //nc�� ���� 0���� �۰ų� col���� ũ�ų� ���ų�
            //visited�� ���� true�̸�
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue; // continue
            }
            if (board[nr][nc] == board[cr][cc]) { //board�� �� ���� ������
                q.push({ nr, nc }); //q�� ���� r���� nr����, c���� nc����
                puyo.push({ nr, nc }); //puyo�� ���� r���� nr����, c���� nc����
                visited[nr][nc] = true; //visited�� true
                cnt++; //���ִ� �ѿ��� ���� ����
            }
        }
    }
    if (cnt < 4) { //�ѿ� ������
        return false; //false return
    }
    while (!puyo.empty()) { //puyo�� ���� ������� ������
        int cr = puyo.front().first; //puyo�� �� �� ������ r�� ����
        int cc = puyo.front().second; //puyo�� �� �� ������ c�� ����
        puyo.pop(); //puyo�� �� �� ���� ����

        board[cr][cc] = '.'; //board�� �� �� �������� ����
    }
    return true; //true return
}

//�ѿ並 �Ͷ߸� ������ �� �ʵ带 �ۼ��ϴ� �Լ�
vector<vector<char>> makeNewBoard(vector<vector<char>>& board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.'));
    for (int i = 0; i < ROW; i++) { // i�� 0���� row�� ũ����� �ݺ�
        queue<char> temp; //�����ִ� �ѿ� ������ ť
        for (int j = 0; j < COL; j++) { // j�� 0���� col�� ũ����� �ݺ�
            if (board[i][j] != '.') { // ���� board�� ���� �� �����̸�
                temp.push(board[i][j]); //�����ִ� �ѿ� ������ ť�� board�� �� push
            }
        }
        int index = 0; //index ���� ����
        while (!temp.empty()) { // ���� �����ִ� �ѿ䰡 �ִٸ�
            new_board[i][index++] = temp.front(); // ���� �ִ� �ѿ� ������ ť�� �� �� ���Ҹ� ���ο� board�� �ֱ�
            temp.pop(); //���� �ִ� �ѿ� ������ ť�� �� �� ���� ����
        }
    }
    return new_board; //���ο� board return
}

//�ѿ䰡 �ѹ��̶� �������� ���������� Ȯ���ؼ� answer���� �����ϴ� �Լ�
int simulation(vector<vector<char>>& board) {
    int answer = 0; //answer ����
    while (true) { // while�� �ݺ�
        bool flag = false; //�ѿ䰡 �������� Ȯ��
        for (int i = 0; i < ROW; i++) { // i�� 0���� row�� ũ����� �ݺ�
            for (int j = 0; j < COL; j++) { // j�� 0���� col�� ũ����� �ݺ�
                if (board[i][j] == '.') { // �ʵ尡 ������̸�
                    continue; // for�� continue
                }
                if (bfs(i, j, board)) { //�� ���̶� �ѿ� �����ٸ�
                    flag = true; // flag true�� ����
                }
            }
        }
        if (!flag) { //���� flag�� false�̸�, �ѿ䰡 �� ���̶� ������ �ʾҴٸ�
            break; // while�� ����������
        }
        board = makeNewBoard(board); //makeNewBoard �Լ��� ���ؼ� �� �ʵ带 �ۼ�
        answer++; // answer ���� ����
    }
    return answer; // answer �� ����
}

/**
 * [Puyo Puyo] - bfs, �ùķ��̼� ����
 *
 * 1. bfs Ž���� ���� 4�� �̻��� �ѿ䰡 �𿴴��� Ȯ��
 * 2. 4�� �̻��� �ѿ䰡 �𿴴ٸ�, �ش�Ǵ� ������ '.'���� �ٲپ� �����
 * 3. ��ü �ʵ忡 ���� 1~2�� �� ������ ��, �ѿ並 ����߸�
 *    - �ٴں��� �����ؼ� �����ִ� �ѿ���� ������, ���� �κ��� '.'���� ä��� ���
 * 4. �Ͷ߸� �� ���� ������ �ݺ�
 *
 * ���⼭, 3�� ������ ���ϰ� �ϱ� ���� 12*6���� ������ �Է��� 6*12�� �ٲپ��ش�.
 * ���� ���� �ִ� �����͸� �ٷ�� �ͺ��� ���� �࿡ �ִ� �����͸� �ٷ�� ���� ���ϱ� �����̴�.
 */

int main() {
    //�Է�
    char input; //input char ����
    vector<vector<char>> board(ROW, vector<char>(COL)); //�ʵ��� ������ �����ϴ� board
    for (int i = 0; i < COL; i++) { // i�� 0���� col�� ũ����� �ݺ�
        for (int j = 0; j < ROW; j++) { // j�� 0���� row�� ũ����� �ݺ�
            cin >> input; //input �Է¹ޱ�
            board[j][COL - i - 1] = input; // ���� �࿡ �ִ� �����͸� �ٷ�� ���� input�� �ݴ�� board�� ����
        }
    }

    //���� & ���
    cout << simulation(board);
    return 0;
}