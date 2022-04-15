#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�̴��� �ٲ� �����Ǵ� ����̹Ƿ� ���������� ó��
int score, player; //����, Ÿ��
vector<int> entry = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }; //���� ����
vector<vector<int>> board; //���ǥ

/**
 * ���ڵ� ����ó�� (�� �÷���Ʈ�� ������ �ִ��� ������ üũ)
 * ��Ʈ ����ŷ�� ���� Ÿ�� �̵� ���� ó��
 *
 * 1110 : 1, 2, 3�翡 ���� ����
 * 0100 : 2�翡 ���� ����
 * 1010 : 1, 3�翡 ���� ����
 */
void running(int& run, int num) {
    run |= (1 << 0); //0�� �÷���Ʈ�� Ÿ�� ǥ��
    for (int i = (4 - num); i < 4; i++) { //Ȩ���� ������ �� �ִ� ���ڵ�
        if (run & (1 << i)) { //���ڰ� �ִٸ�
            run &= ~(1 << i); //���ڰ� Ȩ�� �߱� ������ �÷���Ʈ�� �����
            score++; //���� +1
        }
    }
    run = run << num; //���ڵ� �̵�
}

//idx �̴� �÷���
void playGame(int idx) {
    int out = 0, run = 0; //�ƿ�ī��Ʈ, ���� ����
    while (out != 3) { //�ƿ�ī��Ʈ�� 3 �̸��� ����
        int hit = board[idx][entry[player]]; //�̹� ������ ���
        if (!hit) { //�ƿ�
            out++; //�ƿ�ī��Ʈ +1
        }
        else { //�����ϴ� ��� ���� ����
            running(run, hit); //running �Լ� ȣ��
        }
        player = (player + 1) % 9; //���� ����
    }
}

/**
 * ����, ��Ʈ����ŷ Ǯ��
 * 1. ������ ������ ��� Ÿ���� ���Ѵ�. (����)
 *    4�� Ÿ�ڴ� �׻� 1�� �������� �ϱ� ������ 2�� ~ 9�� ������ ���ؼ��� ������ ������.
 * 2. ��Ʈ���� ���� ������ ����Ѵ�. 1~3��� Ȩ���̽� �� 4���� �÷���Ʈ�� ���� ������ ���翩�θ� ��Ʈ�� ǥ���Ѵ�.
 *
 * �ؼ� : https://myunji.tistory.com/439?category=1154147
 */

int main() {
    int n, ans = 0; //�̴� ��, ���� �� �ִ� �ִ� ����

    //�Է�
    cin >> n; //�̴� ��
    board.assign(n, vector<int>(9)); //���ǥ board�� vector<int>(9)fmf n�� ������ ���ͷ� �����
    for (int i = 0; i < n; i++) { //n���� ��
        //��Ÿ: 1, 2��Ÿ: 2, 3��Ÿ: 3, Ȩ��:4, �ƿ�: 0
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j]; //�� ������ �� �̴׿��� ��� ���
        }
    }

    //����
    do {
        //2-9�� �����鿡 ���ؼ��� ���� ���� �� 
        swap(entry[0], entry[3]); //1�� ���� 4�� Ÿ�� �ǵ��� �ٲ��ش�
        score = player = 0; //�ʱ�ȭ
        for (int i = 0; i < n; i++) { //�� n�� �̴� �÷���
            playGame(i);
        }
        ans = max(ans, score); //�ִ� ����
        swap(entry[3], entry[0]); //������� ����
    } while (next_permutation(entry.begin() + 1, entry.end())); //��� ������ ���� ��

    //���
    cout << ans; //�ִ� ���
    return 0;
}