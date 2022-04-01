#include <iostream>

using namespace std;

const int MAX = 9; //������ �� �� ������

int sudoku[MAX][MAX];         //������ ����
bool check_row[MAX][MAX + 1]; //�� ���� ���� ���� ���� üũ
bool check_col[MAX][MAX + 1]; //�� ���� ���� ���� ���� üũ
bool check_3x3[MAX][MAX + 1]; //�� 3x3 �簢���� ���� ���� ���� üũ

bool fillSudoku(int idx) {
    if (idx == MAX * MAX) { //������ ��� ä�� (���� ����)
        return true;
    }
    int row = idx / MAX; //��
    int col = idx % MAX; //��

    if (sudoku[row][col]) { //�̹� ���ڰ� ä���� ĭ�̶�� ���� ĭ���� �Ѿ
        return fillSudoku(idx + 1);
    }

    for (int i = 1; i <= MAX; i++) { //1~9���� �־��
        //�� ���� ���� ���� X, �� ���� ���� ���� ���� X, �� 3x3 �簢���� ���� ���� X
        if (!check_row[row][i] && !check_col[col][i] && !check_3x3[(row / 3) * 3 + col / 3][i]) {
            check_row[row][i] = true; //i��° �� ���� ����
            check_col[col][i] = true; //i��° �� ���� ����
            check_3x3[(row / 3) * 3 + col / 3][i] = true; //i��° 3x3 �簢���� ���� ����
            sudoku[row][col] = i;
            if (fillSudoku(idx + 1)) {
                return true; //ù��°�� ������ true
            }
            check_row[row][i] = false; //i��° �� ���� ���� X
            check_col[col][i] = false; //i��° �� ���� ���� X
            check_3x3[(row / 3) * 3 + col / 3][i] = false; //i��° 3x3 �簢���� ���� ���� X
            sudoku[row][col] = 0;
        }
    }
    return false;
}

/**
 * ����ġ�� ȿ��: 80ms
 *
 * 9X9�� �������� �� ��, ��, 3x3 �簢���� 1~9�� �����ϴ��� üũ�ϴ� 2���� �迭 Ȱ��
 * �� 2���� �迭�� ��: ��� �κп� ���� üũ����(��, ��, 3x3), 0�� �ε������� ����
 * �� 2���� �迭�� ��: 1 ~ 9 ���� üũ
 *
 * ��� ���� �ٷ� ����ϸ� ��
 * (ex) check_row[3][2] = true;  //3�࿡ 2��� ���ڰ� �����Ѵٴ� ��
 *      check_col[8][9] = false; //8���� 9��� ���ڰ� �������� �ʴ´ٴ� ��
 *
 * 3x3 �簢�� (�ϳ��� �� �����̶�� ǥ��)
 * -> ���� 3���� ���� ��� ���� 3���� ���� ������ ���� 0���� 8���� ������ ���� ��Ÿ�� �� ����
 * (0,0) (0,1) (0,2)
 * (1,0) (1,1) (1,2)
 * (2,0) (2,1) (2,2)
 * -> 1���� �迭 �ε����� �����ϱ� ���� �� (�� / 3)���� 3�� ���� �� (�� / 3)�� ����
 * -> ���� 3x3 �簢���� ������ (row / 3) * 3 + (col / 3) = 0 ~ 8�� �������� ���� �� ����
 */

int main() {
    //�Է�
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j]) { //������ ���� ����, check�迭�� �ʱ�ȭ
                check_row[i][sudoku[i][j]] = true;
                check_col[j][sudoku[i][j]] = true;
                check_3x3[(i / 3) * 3 + j / 3][sudoku[i][j]] = true;
            }
        }
    }

    //����
    fillSudoku(0);

    //���
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}