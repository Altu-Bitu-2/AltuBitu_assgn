#include <vector>
#include <iostream>

using namespace std;
const int SIZE = 10;

vector<int> answer = { -1 }; //���̾��� ���� ū ���� ���̷� ����ϴ� ���
int max_diff = 0; //���� ū ���� ����

//���̾��� ���� ū ���� ���̷� ����ϴ� ����� ����������
//���� ���� ������ �� ���� ���� ��츦 ����
bool cmp(vector<int>& ryan) { ///���� ������ ȭ���� �� ���� �����Ǿ� �ִ���
    for (int i = SIZE; i >= 0; i--) {
        if (answer[i] > ryan[i]) { //���� ���� ������ �ִ� ������ �־��� ���̾��� �������� ������
            return false;
        }
        else if (answer[i] < ryan[i]) { //���� ���� ������ �ִ� ������ �־��� ���̾��� �������� ������
            return true;
        }
    }
}

int calcDiff(vector<int>& ryan, vector<int>& apeach) { //ȭ���� ���� ���
    int score_r = 0, score_a = 0;
    for (int i = 0; i <= SIZE; i++) {
        int score = SIZE - i;
        if (ryan[i] > apeach[i]) { //���̾� > ����ġ
            score_r += score; //���̾��� ���� ȹ��
        }
        else if (ryan[i] < apeach[i]) { //���̾� < ����ġ
            score_a += score; //����ġ�� ���� ȹ��
        }
    }
    return score_r - score_a; //���̾�� ����ġ�� ���� ���� ����
}

void backtracking(int cnt, int extra_arrows, vector<int>& ryan, vector<int>& apeach) { //���� Ž��
    if (cnt == SIZE + 1 || extra_arrows == 0) { //(��������) 0�� ������� Ž�� or ���� ȭ�� ����
        ryan[SIZE] = extra_arrows; //ȭ�� �������� �� �����Ƿ�
        int curr_diff = calcDiff(ryan, apeach); //ȭ�� ���� ��� ��� ����
        if (max_diff < curr_diff) { //�ִ� ���� < ���� ����
            max_diff = curr_diff; //�ִ� ������ ���� ������ ����
            answer = ryan;
        }
        // ���� ������ 0�� �ƴϰ� �ִ� ������ ���� ������ ���� ���̾��� ������ ũ��
        else if (curr_diff != 0 && max_diff == curr_diff && cmp(ryan)) {
            answer = ryan;
        }
        return;
    }
    if (extra_arrows > apeach[cnt]) { //���� ȭ��� ���̾��� ������ ���� �� �ִٸ�
        ryan[cnt] = apeach[cnt] + 1; //����ġ���� �� �� �� ���߱�
        backtracking(cnt + 1, extra_arrows - apeach[cnt] - 1, ryan, apeach);
        ryan[cnt] = 0;
    }
    backtracking(cnt + 1, extra_arrows, ryan, apeach); //���� �ʰ� ���� ��������
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(SIZE + 1, 0); //���̾��� ���� ����
    backtracking(0, n, ryan, info); //����
    return answer; //���̾��� ���� ū �������� ����ϴ� ��� ����
}

/**
 * [��ô�ȸ]
 *
 * 1. ������ ��� ��츦 ��Ʈ��ŷ Ž���� ���� �˻�
 * -> ���̾��� ������ ������ ����ġ���� 1�� �� ��� ��찡 ����. ����ġ���� ���� ȭ�� ��� �� ���� �� ���Ƿ� ������ �ǹ̰� ����.
 * -> ���� ���̾��� �� ������ ȭ���� �Ʒ��� ���� ��� 2���� ��츸 ����ؼ� ��������� ��� ��츦 ��Ʈ��ŷ���� Ž��
 *    - ����ġ�� ���� ȹ���� �ϴ� ���: �ش� �������� ȭ���� �� �ߵ� ���� �ʴ� ���� �̵�
 *    - ���̾��� ���� ȹ���� �ϴ� ���: �ʿ��� �ּ� ȭ���� ����ϴ� ���� �̵��̹Ƿ� ����ġ���� ��Ȯ�� �� �� �� ��
 *
 * 2. ���� ū ���� ���̰� ������ ���, ���� ������ �� ���� ���� ��츦 ���ǹ����� ���� �ذ�
 * -> �ܼ� Ž���ϴٰ� ���ŵǴ� ������ �ϸ� �ڳ����̽� ����
 * -> ���� 0�� ������� ���� ���ؼ� ���� ���� ������ �� ���� ���� ��� ������ �� �ֵ��� ��
 *
 * !����! 0�� �ε����� 10�� �������� ����
 */

 //������� ���� ���� �ڵ� - ���α׷��ӽ����� ���� X
int main() {
    int n = 5; //ȭ���� ����
    vector<int> info = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }; //����ġ�� ���� ���� ������ ����
    vector<int> result = solution(n, info); //�󸮾��� ���� ū ���� ���� ����ϴ� ��� ����
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' '; //����ġ�� ���� ū ���� ���̷� �̱�� ���� ���̾��� ������ϴ� ���� ����
    }
    return 0;
}