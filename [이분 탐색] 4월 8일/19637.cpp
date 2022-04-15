#include <iostream>
#include <map>

using namespace std;

/**
 * [IF�� �� ��� ����]
 *
 * ��� ĳ���Ϳ� Īȣ�� ��Ī�ϴ� ���Ʈ ������ ����ϱ⿣ �ִ� ���� Ƚ�� 10^5 * 10^5 -> 100��!
 * Ư�� ������ '����'���� �ش��ϴ� Īȣ�� ���� �� ����
 * -> �̺� Ž��
 *
 * �ʰ� ���� ���Ҹ� ���ĵ� ���·� �����ϱ� ������ 
 * �˰��� ��� ���� ��ü������ �̺� Ž�� �Լ��� ����� �� ����
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //Īȣ�� ������ ���Ѱ�, �� Īȣ�� �̸�

    int n, m, power; //Īȣ�� ����, Īȣ�� ����ؾ� �ϴ� ĳ���͵��� ����, Īȣ�� ������ ���Ѱ�
    string name; //Īȣ�� �̸�

    //�Է�
    cin >> n >> m;
    while (n--) { //n���� �ٿ�
        cin >> name >> power; //Īȣ�� �̸�, Īȣ�� ������ ���Ѱ�
        if (title[power].empty()) { //Īȣ�� ������ ���Ѱ��� ���������
            title[power] = name; //Īȣ�� ������ ���Ѱ��� Īȣ�� �̸����� ó��
        }
    }

    //���
    while (m--) {
        cin >> power; //ĳ������ ������
        //power���� title�� �־��� ��, �� ��� �־��� power���� ���ų� ���� ū ���� iterator�� ����
        cout << title.lower_bound(power)->second<< '\n';
    }
}