#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N��° ū ��]
 *
 * �޸� ������ �����Ƿ�, �Է°��� ��� �����ϸ� �ȵȴ�.
 * ���� n���� �����ϴ� "�ּ�" ���� ���� heap[0]�� ��������� N��° ū���� �����ϴ� Ǯ��
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    priority_queue<int, vector<int>, greater<>> pq; //�ּ� ��, �����̶� �ݴ�

    cin >> n; //NXN �Է�
    int size = n * n; //������ ����
    while (size--) {
        //�Է�
        cin >> input; //n���� ��

        //����
        pq.push(input); //pq�� input push
        if (pq.size() > n) { //�ּ� ���� ũ�Ⱑ n �̻��̶��
            pq.pop(); //���� ���� �� ����
        }
    }

    //���
    cout << pq.top(); //n��° ū �� ���
    return 0;
}