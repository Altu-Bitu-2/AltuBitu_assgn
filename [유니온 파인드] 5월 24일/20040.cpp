#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find ����
int findParent(int node) { //�θ� ��带 Ȯ��
    if (parent[node] < 0) { //�θ� ��尡 ������ �� ������ ����Լ�
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

//Union ����
bool unionInput(int x, int y) {
    int xp = findParent(x); //x�� �θ�
    int yp = findParent(y); //y�� �θ�

    if (xp == yp) { //�θ� ��尡 ������ ����Ŭ�� ����
        return false; //false ��ȯ
    }
    if (parent[xp] < parent[yp]) { //xp�� root�� �ϴ� ��尡 �� ������
        parent[xp] += parent[yp];
        parent[yp] = xp; //xp�� ���� yp��
    }
    else { //yp�� root�� �ϴ� ��尡 �� ������
        parent[yp] += parent[xp];
        parent[xp] = yp; //yp�� ���� xp��
    }
    return true;
}

/**
 * [����Ŭ ����]
 *
 * ����Ŭ�� �߻��� ���� = ���� ���տ� �ִ� ���� �� ���� ���Ͽ��Ϸ� �� ��
 * unionInput �Լ��� ��ȯ���� bool�� �����Ͽ� cycle�� �����Ǵ� ���� �߰��ϱ�
 */

int main() {
    int n, m, x, y;

    //�Է�
    cin >> n >> m; //���� ����, ����� ������ ��
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //�÷��̾ ������ �� ���� ��ȣ

        //���� & ���
        if (!unionInput(x, y)) { //����Ŭ�� ������
            cout << i + 1; //����Ŭ�� ó������ ������� ������ ��ȣ ���
            return 0;
        }
    }
    cout << 0; //������� �ʾҴٸ� 0 ���
    return 0;
}