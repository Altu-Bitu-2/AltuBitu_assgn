#include <iostream>
#include <deque>

using namespace std;

string dqToString(deque<char>& dq) {
    string ans = ""; //�ʱ�ȭ
    while (!dq.empty()) { //dq�� ���� ����������
        ans += dq.front(); //ans�� dq�� front �����ֱ�
        dq.pop_front(); //dp�� front pop
    }
    return ans;
}

string findPass(string s) { //��й�ȣ�� ã�� �Լ�
    deque<char> dq_left;  //Ŀ�� ���� ������ ����
    deque<char> dq_right; //Ŀ�� ���� ������ ����

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '-': //���� Ŀ�� �տ� �ִ� ���ڸ� �����.
            if (!dq_left.empty()) { //dq_left�� ������� ������
                dq_left.pop_back(); //���� pop
            }
            break;
        case '<': //Ŀ���� �������� �̵� -> dq_left �� ������ ���Ҹ� dq_right �տ� ����
            if (!dq_left.empty()) { //dq_left�� ������� ������
                dq_right.push_front(dq_left.back()); //dq_left�� �������� dq_right �տ� push
                dq_left.pop_back(); //���� pop
            }
            break;
        case '>': //Ŀ���� ���������� �̵� -> dq_right �� ó�� ���Ҹ� dq_left �� �������� ����
            if (!dq_right.empty()) { //dq_left�� ������� ������
                dq_left.push_back(dq_right.front()); //dq_right�� ó���� dq_left�� �������� push
                dq_right.pop_front(); //���� pop
            }
            break;
        default: //������ ���, �Է��� �ϸ� Ŀ������ ���ʿ� ��ġ�ϹǷ� dq_left�� ����
            dq_left.push_back(s[i]); //string s�� dq_left�� push
            break;
        }
    }

    string pass = dqToString(dq_left);
    pass += dqToString(dq_right);
    return pass;
}

/**
 * [Ű�ΰ�]
 *
 * �ش� Ǯ�̴�, ���� ���� ���� �� �̵���Ű�� �������� ����� �ڳ����̽��� �ذ��ϱ� ���� 
 * Ŀ���� �������� ����, ���������� ������ ���� ������
 * 1. Ŀ�� ���� ���ڸ� ���� ��, ���ڰ� ���� ��� ����
 * 2. Ŀ���� �������� �̵��� ��, �̹� ���� ���ʿ� Ŀ���� �ִ� ��� ����
 * 3. Ŀ���� ���������� �̵��� ��, �̹� ���� �����ʿ� Ŀ���� �ִ� ��� ����
 */

int main() {
    int t;
    string s;

    //�Է�
    cin >> t; //�׽�Ʈ ���̽��� ����
    while (t--) {
        cin >> s; //���ڿ�

        //���� & ���
        cout << findPass(s) << '\n';
    }
    return 0;
}