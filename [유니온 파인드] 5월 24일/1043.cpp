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

int liarParty(vector<int>& parties) {
    int cnt = 0;
    for (int i = 0; i < parties.size(); i++) { //���� ������ ù��° ����� üũ
        if (findParent(parties[i]) != findParent(0)) { 
            cnt++;
        }
    }
    return cnt;
}

/**
 * [������]
 *
 * 1. �� ������� �پ��� ��Ƽ�� ���� ����ƴٰ� �� �� ����
 * 2. ����� ������� ���� ���տ� ����
 * 3. �� ���տ� ���� ����� �� �� ���̶� ������ �ȴٸ� �� ������ ������� ���� ��Ƽ���� �������� �� �� ����
 * -> ���Ͽ� ���ε�� ������� �������� ���� ��, ��Ƽ���� �������� �� �� �ִ��� Ȯ���ϱ�
 * -> �̶�, ������ �ƴ� ������� ��Ʈ ������ 0���� �����ؼ� ���Ͽ� ���ε带 ���� �������� ���� ����
 * -> 0�� ���� ������ �ƴϾ�� �������� �� �� ����
 *
 * !����! ��Ƽ ������ �Է¹����� �ٷ� ������ ���� ���θ� �Ǵ��� �� ���� (���� �Է� 4)
 *       �� ��Ƽ���� �� ����� �����ص� ��, �������� ������ ���� ���� �� ���� �Ǵ�
 */

int main() {
    int n, m;

    //�Է�
    cin >> n >> m; //����� ��, ��Ƽ�� ��
    parent.assign(n + 1, -1);

    int init, p;
    cin >> init; //������ �ƴ� ����� ��
    while (init--) { //������ �ƴ� �����
        cin >> p; //������ �ƴ� ����� ��ȣ
        unionInput(0, p);
    }

    int cnt, first_person, person;
    vector<int> parties;
    while (m--) {
        cin >> cnt >> first_person; //�� ��Ƽ���� ���� ����� ��, ù��° ����� ��ȣ

        //����
        parties.push_back(first_person); //��Ƽ ������ �� ��Ƽ�� ù��° ����� ����
        while (--cnt) {
            cin >> person; //�� ��Ƽ���� ���� ����� ��ȣ
            unionInput(first_person, person);
        }
    }

    //���� & ���
    cout << liarParty(parties); //��Ƽ�� ������ �ִ�
    return 0;
}