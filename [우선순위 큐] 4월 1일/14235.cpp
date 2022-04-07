#include <iostream>
#include <queue>

using namespace std;

/**
 * [ũ�������� ����] - �ܼ� ���� ����
 *
 * - 0�� ���� ������, ������ �ִ� ���� �� ���� ��ġ�� ū ���� ���� & ��� -> �ִ� �� �ʿ�
 */

int main() {
    int n, a, input;
    priority_queue<int> pq; //�ִ� ��

    //�Է�
    cin >> n; //���̵�� �������� �湮�� Ƚ��
    while (n--) {
        cin >> a;
        if (!a) { //���̵��� ���� ���
            if (pq.empty()) { //�� ������ ���ٸ�
                cout << "-1\n"; //-1 ���
            }
            else { //�� ������ �ִٸ�
                cout << pq.top() << '\n'; //�ִ� ���� top�� ��� ��
                pq.pop(); //pop
            }
        }
        else { //������ �����ϴ� ���
            while (a--) {
                cin >> input;
                pq.push(input); //��������pq�� push
            }
        }
    }
    return 0;
}