#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //ģ�� ���谡 ��� �ٸ� ����ڷ� ������ ���� ���� �ִ�

vector<int> parent(MAX + 1, -1);
map<string, int> people; //�� �̸��� intó�� ���

//Find ����
int findParent(int node) { //�θ� ã�� �Լ�
    if (parent[node] < 0) { //����� �θ� ������ �� ������ ���
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

//Union ����
void unionInput(int x, int y) {
    int xp = findParent(x); //x�� �θ�
    int yp = findParent(y); //y�� �θ�

    if (xp == yp) { //���� ����
        return;
    }
    if (parent[xp] < parent[yp]) { //xp�� root�� �ϴ� ��尡 �� ������
        parent[xp] += parent[yp];
        parent[yp] = xp; //xp�� ���� yp��
    }
    else { //yp�� root�� �ϴ� ��尡 �� ������
        parent[yp] += parent[xp];
        parent[xp] = yp; //yp�� ���� xp��
    }
}

/**
 * [ģ�� ��Ʈ��ũ]
 *
 * 1. weighted union find -> ��Ʈ ������ ģ���� ��(���� ���� ��) ����
 * 2. ģ�� ��Ʈ��ũ�� �� �� �ִ��� ���ϱ� -> ��Ʈ ������ parent�� ����
 *
 * !����! ������ ���ڿ��� �����Ƿ� map�� Ȱ���� string�� int�� ����
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, f;
    string a, b;

    //�Է�
    cin >> t; //�׽�Ʈ ���̽��� ����
    while (t--) {
        int idx = 1; //������ ������ ��
        parent.assign(MAX + 1, -1); //�ִ� �ο��� ��

        cin >> f; //ģ�� ������ ��
        while (f--) {
            cin >> a >> b; //�� ������� ���̵�
            if (!people[a]) { //map�� ���̵� ������
                people[a] = idx++; //idx ����
            }
            if (!people[b]) { //map�� ���̵� ������
                people[b] = idx++; //idx ����
            }

            //����
            int x = people[a], y = people[b];
            unionInput(x, y); //���Ͽ� ����

            //���
            cout << -parent[findParent(x)] << '\n'; //�� �����ģ�� ��Ʈ��ũ�� �� ���� �ִ���
        }
    }
    return 0;
}