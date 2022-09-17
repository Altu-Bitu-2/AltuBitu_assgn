#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci; //typedef�� ���� pair ������

//Ư�� ȭ��ǥ���� ������ ����� ���� �����ϴ� �Լ�
string arrowStartWheel(int arrow_point, int n, vector<char>& wheel) {
    string ans = ""; //ans �ʱ�ȭ
    int start = arrow_point; //start ������ arrow_point�� ����
    do { //�ݺ�
        ans += wheel[arrow_point]; //ans�� 
        arrow_point = (arrow_point + 1) % n;
    } while (arrow_point != start); //arrow_point�� ���� start�� ���� �ƴ� ������
    return ans; //ans ����
}

//����� ���� ���ϴ� �Լ�
string makeWheel(int n, vector<ci>& record) {
    vector<char> wheel(n, '?'); //������ ����
    vector<bool> is_available(26, false); //���ĺ� �ߺ� üũ

    int idx = 0; //ȭ��ǥ�� ����Ű�� �ε��� �ʱ�ȭ
    for (int i = 0; i < record.size(); i++) {
        int rot = record[i].first; //ȭ��ǥ�� ����Ű�� ���ڰ� �� �� �ٲ������
        char alpha = record[i].second; //ȸ���� ���߾��� �� ����Ű�� ����
        idx = (idx - rot % n + n) % n; //ȭ��ǥ�� ����Ű�� �ε��� �ٲ���
        if (wheel[idx] == alpha) { //������ ȭ��ǥ�� ����Ű�� �ε����� ���߾����� ����Ű�� ���ڿ� ������ 
            continue; //continue
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) { //������� ���̿� �ش��ϴ� ����� ������ ���ٸ�
            return "!"; //! ���
        }
        wheel[idx] = alpha; //�ش� ĭ�� ���� ���
        is_available[alpha - 'A'] = true; //���� ��� ó��
    }
    return arrowStartWheel(idx, n, wheel); //�ε������� ������ ����� ���� ���� �����ϴ� �Լ�
}

/**
 * [����� ����]
 *
 * ������ ���ư� �ʿ� X
 * ȭ��ǥ�� ����Ű�� �ε����� ȸ�� ������ ���� �ٲ���
 *
 * 1. ȭ��ǥ�� ����Ű�� ĭ�� �������� �ʾ����� ���ĺ��� ������ ���´�.
 * 2. �̹� ���ĺ��� �� �ִ� ���, ���� ���ĺ��� �ƴ� ��� 
     ���ǿ� �ش��ϴ� ���� ���� �� ����.
 * 3. ������ �����ִ� ���ĺ��� �ߺ����� �����Ƿ� 
     ������ ���ĺ��� ���� �ڸ��� ���� �� ����.
 */

int main() {
    int n, k; //������ ĭ�� ��, ����̰� ������ ������ Ƚ��

    //�Է�
    cin >> n >> k;
    vector<ci> record(k, { 0, 0 }); //���� ȸ�� ���
    for (int i = 0; i < k; i++) { //k��
        //������ ȸ�������� �� ȭ��ǥ�� ����Ű�� ���ڰ� ��� �ٲ����
        //ȸ���� ���߾��� �� ����Ű�� ����
        cin >> record[i].first >> record[i].second;
    }

    //���� & ���
    cout << makeWheel(n, record);
    return 0;
}