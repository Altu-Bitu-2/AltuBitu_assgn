#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

vector<ci> parent;

int knapsack(int n, int k) {
    vector<ci> cnt; //first: ���̵��� ��, second: ���� ����
    for (int i = 1; i <= n; i++) {
        if (parent[i].first < 0) {
            cnt.push_back({ -parent[i].first, parent[i].second });
        }
    }
    vector<int> dp(k, 0); //1���� k-1����
    for (int i = 0; i < cnt.size(); i++) {
        for (int j = k - 1; j >= cnt[i].first; j--) {
            dp[j] = max(dp[j], dp[j - cnt[i].first] + cnt[i].second);
        }
    }
    return dp[k - 1];
}

//Find ����
int findParent(int node) { //�θ� ã�� �Լ�
    if (parent[node].first < 0) { //����� �θ� ������ �� ������ ���
        return node;
    }
    return parent[node].first = findParent(parent[node].first);
}

//Union ����
void unionInput(int x, int y) {
    int xp = findParent(x); //x�� �θ�
    int yp = findParent(y); //y�� �θ�

    if (xp == yp) { //���� ����
        return;
    }
    if (parent[xp].first < parent[yp].first) { //xp�� root�� �ϴ� ��尡 �� ������
        parent[xp].first += parent[yp].first;
        parent[yp].first = xp; //xp�� ���� yp�� first��
        parent[xp].second += parent[yp].second; 
    }
    else { //yp�� root�� �ϴ� ��尡 �� ������
        parent[yp].first += parent[xp].first;
        parent[xp].first = yp; //yp�� ���� xp�� first��
        parent[yp].second += parent[xp].second;
    }
}

/**
 * [�ҷ����� ���ġ]
 *
 * - weighted union find -> ��Ʈ ������ ���̵��� ��(���� ���� ��)�� ���� �������� pair ������ �����ϱ�
 * - dp(����)���� K�� �̸��� ���̵鿡�Լ� ���� �� �ִ� �ִ� ���� �� ���ϱ�
 */

int main() {
    int n, m, k, a, b;

    //�Է�
    cin >> n >> m >> k; //���̵��� ��, ���̵��� ģ�� ���� ��, ���� �Ҹ��� �����ϱ� ���� �ּ� ������ ��
    parent.assign(n + 1, { -1, 0 }); //first: ���̵��� ��, second: ���� ����
    for (int i = 1; i <= n; i++) {
        cin >> parent[i].second; //���̵��� ���� ������ ��
    }
    while (m--) {
        cin >> a >> b; //a�� b�� ģ��
        unionInput(a, b);
    }

    //���� & ���
    cout << knapsack(n, k); //��鿡�� ��Ű�� �ʰ� ���̵�κ��� ���� �� �ִ� �ִ� ������ ��
    return 0;
}