#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//���� ���ϸ����� ���Ե�� ������� ����
int maxClass(int m, priority_queue<int, vector<int>, greater<>>& pq) {
    int result = 0;
    //���̻� ���� ������ ���ų�, ���ϸ����� ���ڸ��� �ݺ��� Ż��
    while (!pq.empty() && pq.top() <= m) { 
        m -= pq.top(); //pq�� top��ŭ ���ϸ������� ����
        pq.pop(); //pop
        result++; //�־��� ���ϸ����� �ִ�� ���� �� �ִ� ���� ������ ���ϱ�
    }
    return result;
}

/**
 * [Yonsei TOTO]
 *
 * ���� �ο��� �̴��� �� �ʿ��� ���ϸ����� 0�� �ƴ϶� 1
 * 1. �� ������ ��� ���� �ʿ��� �ּ� ���ϸ����� ��� (����)
 * 2. ���� ���ϸ����� ���� ��� ������� ���� ��û (�켱���� ť or ����)
 */
int main() {
    int n, m, p, l;
    priority_queue<int, vector<int>, greater<>> pq; //�ּ� ��

    cin >> n >> m; //���� ���� �־��� ���ϸ���
    while (n--) {
        //�Է�
        cin >> p >> l; //�� ���� ��û�� ��� ��, ������ �����ο�
        vector<int> arr(p);
        for (int i = 0; i < p; i++) {
            cin >> arr[i]; //���ϸ��� �󸶳� �־����� arr�� ����
        }

        //����
        if (p < l) { //�����ο��� �̴��̶��
            pq.push(1); //���ϸ����� 1�� �־ ��
            continue;
        }
        sort(arr.begin(), arr.end(), greater<>()); //�������� ����
        //l��°�� ���ϸ����� ���� ���� ����� ���� ���� ���ϸ����� �־�� ���� ����
        pq.push(arr[l - 1]); 
    }

    //���
    cout << maxClass(m, pq);
}