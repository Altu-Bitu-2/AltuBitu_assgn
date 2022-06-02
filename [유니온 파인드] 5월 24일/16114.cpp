#include <iostream>
#include <string>

using namespace std;

string solution(int x, int n) {
    if (n > 1 && n % 2 == 1) { //n�� 1���� ũ�� Ȧ���� ���
        return "ERROR";
    }
    if (n == 1 && x < 0) { //n�� 1�̰� x�� ������ ���
        return "INFINITE";
    }
    if (n == 1 || x <= 0) { //n�� 1�̰ų� x�� ������ ���
        return "0";
    }
    if (n == 0) { //n�� 0�� ���
        return "INFINITE";
    }
    return to_string((x - 1) / (n / 2)); //������ ���
}

/**
 * [ȭ��ǥ ������]
 *
 * 1. n�� 1���� ū Ȧ���� ��� -> ERROR
 * 2. n�� 1�ε� x�� ������ ��� -> while�� ���� �׻� �� -> INFINITE
 * 3. n�� 1�ε� x�� ����� ��� or x�� 0���� �۰ų� ���� ��� -> while���� ���� ���� -> 0
 * 4. n�� 0�ε� x�� ����� ��� -> while�� ���� �׻� �� -> INFINITE
 * 5. ������ ��쿣 (x - 1)�� (n / 2)�� ���� ���� ���
 *    - �������� �� 1 �̻��� ���� �������� ����� �� �� �����Ƿ� 1�� �� ������ ���� ����
 */

int main() {
    int x, n;

    //�Է�
    cin >> x >> n; //���� x�� �ʱⰪ ȭ��ǥ ����

    //���� & ���
    cout << solution(x, n);
    return 0;
}