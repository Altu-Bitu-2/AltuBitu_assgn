#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//n���� �ڿ��� �߿��� m���� �� ����

const int SIZE = 8; //�迭 ũ��

int n, m;
vector<int> num(SIZE); //�Է¹޴� n���� �� ����
vector<int> ans(SIZE); //��� ���� ����
vector<bool> check(SIZE); //�ߺ� �����ϱ� ���� üũ �迭

void backtracking(int cnt) {
    if (cnt == m) { //���� m �̶�� (��������)
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' '; //���� ���
        }
        cout << '\n';
        return;
    }
    int prev = 0; //������ ������ ��
    for (int i = 0; i < n; i++) {
        if (!check[i] && prev != num[i]) { //�� ��ġ �ߺ� üũ && ������ Ž���� ���� �ƴ϶��
            //���� ���� ������ ����
            prev = num[i];
            ans[cnt] = num[i];
            check[i] = true; //���� ��ġ�� ���� �� �������� �ʵ���
            backtracking(cnt + 1);
            check[i] = false;
        }
    }
}

/**
 * 1. �켱 ������ ���� ������ �����ϴ� ������ ����ؾ� �ϹǷ� �־��� ������ �������� ����
 * 2. �� ���¿��� �켱, ���� ��ġ�� ���� �� �������� �ʵ��� �ߺ����� (check �迭 ���)�� ����
 * 3. �� ��, �ߺ��Ǵ� "����"�� �Ÿ��� ����� ������ ������ ���� ������ �����ؼ�, 
      ������ ����� �ٽ� ��Ʈ ���� ���ƿ��� ��
 *    ������ ������ ���� ���� ���̸� �Ѿ�� ��! -> ������ ���� ���̹Ƿ� ���� ���� �ݺ��ؼ� �Ȱ��� ������ ���� ��
 */

int main() {
    //�Է�
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    //����
    sort(num.begin(), num.begin() + n); //�������� ����

    //��Ʈ��ŷ & ���
    backtracking(0);
    return 0;
}