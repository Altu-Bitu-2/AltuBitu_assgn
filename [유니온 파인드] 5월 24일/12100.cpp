#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

int n, ans = 0;

int getMaxBlock(matrix& board) { //board���� �ִ� �� ���ϴ� �Լ�
    int max_block = 0;
    for (int i = 0; i < n; i++) { //n��ŭ �ݺ�
        for (int j = 0; j < n; j++) { //n��ŭ �ݺ�
            max_block = max(max_block, board[i][j]); //board���� �ִ� ����
        }
    }
    return max_block; //�ִ� return
}

matrix transposeMatrix(matrix& board) { //matrix�� ��� ���� �ٲٴ� �Լ�
    matrix board_t(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board_t[i][j] = board[j][i]; //matrix�� ��� �� �ݴ�� ����
        }
    }
    return board_t;
}

/**
 * ������ �̵��ϴ� �Լ�
 * - �� ���� �˻��ϸ鼭 ���� ����� 2���� ���� �� �ִٸ� ��ġ��
 * - �̶� ��� ���� �κ��� �Ѿ��, ����� �����ߴ� ���� �����ؼ� ���ϴ� ���� �߿�!
 */

matrix upMove(matrix board) { //���� �̵��ϴ� �Լ�
    matrix temp(n, vector<int>(n, 0)); //���Ӱ� ��� ������ �迭
    for (int j = 0; j < n; j++) {
        int idx = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (!board[i][j]) { //���忡 ����� ���� �κ�, ��ĭ�� ���
                continue; //continue
            }
            if (board[i][j] == prev) { //��ĭ�� �ƴϰ� ���ڰ� ���� ���
                temp[idx - 1][j] *= 2; //��ġ��
                prev = 0;
            }
            else { //��ĭ�� �ƴϰ� ���ڰ� �ٸ� ���
                temp[idx++][j] = board[i][j]; //�״��
                prev = board[i][j]; //prev ���� ����
            }
        }
    }
    return temp;
}

//��Ʈ��ŷ Ž��
void backtracking(int cnt, matrix board) {
    if (cnt == 5) {
        ans = max(ans, getMaxBlock(board));
        return;
    }
    //Transpose matrix ���ϱ� (��->��)
    //������ �����ϴ� ���� ���� �����ϴ� ��찡 �����ϱ� ������
    matrix board_t = transposeMatrix(board);
    //��
    backtracking(cnt + 1, upMove(board)); //���� ����
    //��
    reverse(board.begin(), board.end());
    backtracking(cnt + 1, upMove(board)); //���� ����
    //��
    backtracking(cnt + 1, upMove(board_t)); //������ ����
    //��
    reverse(board_t.begin(), board_t.end());
    backtracking(cnt + 1, upMove(board_t)); //������ ����
}

/**
 * [2048 (Easy)]
 *
 * - ��, ��, ��, ��� �̵��ϴ� ��쿡 ���� �ִ� 5�� �̵���Ű�� ��� ��츦 ���� ��, ���� ū ��� ã�� ���� - ��Ʈ��ŷ
 * - �����̴� �Լ��� �ϳ��� ¥��, ���带 �������鼭 ��, ��, ��, �� ��� ������ �������� ����
 *
 * - �� <-> ��: �� ������ ����� �ذ�
 * - ��/�� <-> ��/��: Transpose Matrix Ȱ��
 *
 * - ex. 2 2 1 �� ��, ��, ��, ��� �̵��ϴ� ��� ���ϴ� ��
 *       2 2 2
 *       4 4 4
 *  -��: ���� �迭���� ������ �����̴� �Լ� ����
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -��: ���� �迭�� �� ������ ������ ��, ������ �����̴� �Լ� ����
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -��: ���� �迭�� ��ġ ����� ���� ��, ������ �����̴� �Լ� ����
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -��: ���� �迭�� ��ġ ��Ŀ��� �� ������ ������ ��, ������ �����̴� �Լ� ����
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    //�Է�
    cin >> n; //������ ũ��
    matrix board(n, vector<int>(n, 0)); //������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //������ �Է¹ޱ�
        }
    }

    //����
    backtracking(0, board);

    //���
    cout << ans; //�ִ� 5�� �̵����Ѽ� ���� �� �ִ� ���� ū ���� �� ���
    return 0;
}