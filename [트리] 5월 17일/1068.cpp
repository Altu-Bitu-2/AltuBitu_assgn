#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//�־��� ������ ������ ���� ���� ����� ��
int eraseLeafCnt(int node, int& erase_node) {
    if (node == erase_node) { //�־��� ����� ��ȣ�� ���� ����� ��ȣ�� ���� ���
        return 0;
    }
    //��尡 ����ְų� ����� ũ�Ⱑ 1�̰� ���� ����� ��ȣ�� tree node�� 0��°�� ���
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1;
    }
    int cnt = 0; //���� ����� ����
    for (int i = 0; i < tree[node].size(); i++) {
        cnt += eraseLeafCnt(tree[node][i], erase_node); //��������� ���� cnt 1�� ����
    }
    return cnt; //cnt return
}

/**
 * [Ʈ��]
 *
 * ���� ���� ��� ������ ���� dfs Ž������ ����� ������ ������ 
    �� �̻� Ž������ �ʰ� 0�� ����
 *
 * !����! ����� ������ �ش� �θ� ����� ������ �ڽ� ��忴�� ���, 
    �ش� ������ ����� �θ� ��尡 ���� ��尡 �ż� ������ 1 �������� ����
 * !����! ��Ʈ ��尡 �׻� 0�� �ƴ��� ����
 */

int main() {
    int n, par, root, erase_node;

    //�Է�
    cin >> n; //����� ����
    tree.assign(n, vector<int>(0));
    for (int i = 0; i < n; i++) { //0�� ������ n-1 ������
        cin >> par; //�� ����� �θ�
        if (par == -1) { //�θ� ���ٸ�
            root = i; //root ����
            continue;
        }
        tree[par].push_back(i); //tree�� �Է�
    }
    cin >> erase_node; //���� ����� ��ȣ

    //���� & ���
    cout << eraseLeafCnt(root, erase_node); //���� ����� ���� ���
    return 0;
}