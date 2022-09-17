#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int>& tree) {
    ll sum = 0; //���� sum �ʱ�ȭ
    for (int i = 0; i < tree.size(); i++) { //������ ����ŭ �ݺ�
        if (height >= tree[i]) { //���� height(mid)�� tree[i]���� ũ�ų� ������
            return sum; //sum�� ����
        }
        sum += (tree[i] - height); //tree[i]���� height(mid)�� �� ���� sum�� ���ϱ�
    }
    return sum; //sum�� ����
}

int upperSearch(int left, int right, int target, vector<int>& tree) {
    while (left <= right) { //left�� right���� �۰ų� ������
        int mid = (left + right) / 2; //left�� right�� �߰��� ����
        ll tree_cnt = cntTree(mid, tree); //cntTree �Լ��� ���ϰ� ����

        if (tree_cnt >= target) { //tree_cnt���� target(�־��� ������ ����)���� ũ�ų� ������
            left = mid + 1; //left�� mid + 1 ���� ����
        }
        else { //tree_cnt���� targer(�־��� ������ ����)���� ������
            right = mid - 1; //right�� mid -1 ���� ����
        }
    }
    return left - 1; //left - 1���� ����
}

/**
 * [���� �ڸ���]
 *
 * ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ���?
 * -> ���ܱ��� ���̰� k(������ ��)�� ��, M������ ������ ���� ������ �� �ִ°�?
 *
 * left: ���ܱ��� �ּ� ���� -> 0
 * right: ���ܱ��� �ִ� ���� -> �־��� ���� �� ���� ���� ���� ����
 *
 * !����! int �ڷ��� ������ �Ѿ�Ƿ� long long��� ��
 */

int main() {
    int n, m; //������ ��, ������ ����

    //�Է�
    cin >> n >> m; //������ ��, ������ ����
    vector<int> tree(n, 0); //n���� ������ ���̸� �����ϴ� vector
    for (int i = 0; i < n; i++) {
        cin >> tree[i]; //������ ����
    }

    sort(tree.begin(), tree.end(), greater<>()); //������ ���� �������� ����

    //���� & ���
    cout << upperSearch(0, tree[0], m, tree); //���ܱ⿡ ������ �� �ִ� ������ �ִ�
    return 0;
}