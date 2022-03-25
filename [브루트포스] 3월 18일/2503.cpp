#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef pair<int, int> ci; //��Ʈ����ũ�� ���� ������ ���� pair

struct baseball {
    string num;       // ���� �ٸ� �� �ڸ� ��
    int strike, ball; // ��Ʈ����ũ ����, �� ����
};

ci cntStrikeBall(string& s1, string& s2) { //s1�� s2�� ���� ��Ʈ����ũ�� �� ����
    int strike_cnt = 0; //s1�� s2������ strike ����
    int ball_cnt = 0;   //s1�� s2������ ball ����

    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i]) { //��ġ+�� ��Ȯ�� ��ġ -> ��Ʈ����ũ
            strike_cnt++; //��Ʈ����ũ ���� ī��Ʈ
        }
        else if (s1.find(s2[i]) != s1.npos) { //��ġ �ٸ��� ���� ���� -> ��
            ball_cnt++; //�� ���� ī��Ʈ
        }
    }

    return ci(strike_cnt, ball_cnt);
}

int game(int n, vector<baseball>& question) {
    int ans = 0; //���� ����

    for (int i = 123; i <= 987; i++) { //������ �ּ� ����: 123, ������ �ִ� ����: 987
        bool check = true; //
        string s1 = to_string(i);  //�������� Ȯ���� ��

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') { //0�� �ϳ��� �ִٸ�
            continue;
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) { //���� ���� �� �ϳ��� �ִٸ�
            continue;
        }

        for (int j = 0; j < n; j++) {
            string s2 = question[j].num; //�������� ���� ��
            ci cnt = cntStrikeBall(s1, s2); //s1�� s2������ ��Ʈ����ũ�� �� ����
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //�ϳ��� �ٸ���
                check = false; 
                break;
            }
        }

        if (check) { //check�� true�̸�
            ans++;
        }
    }

    return ans;
}

/**
 * [���� �߱�]
 * ���� �ٸ� �� �ڸ� ������ ��ġ + �� ������ ��Ʈ����ũ, ��ġ�� �ٸ��� ���� �����ϸ� ��
 * n���� �������� ���� ��Ʈ����ũ�� �� ������ �־��� ��, �̸� ��� �����ϴ� ���� �ٸ� �� �ڸ� ���� ���� ����
 *
 * [Ǯ��]
 * ���� �ٸ� �� �ڸ����� 123 ~ 987�� �����ϴ�. �̴� �� 865����
 * ���� n�� ������ �ִ� 100
 * ���� 123���� �ϳ��� ������Ű�� ������ �Ǵ��� �˻��ص� 865 * 100 * 3(�ڸ���)���� ���� ����� ����!
 */

int main() {
    int n;

    //�Է�
    cin >> n; //�����̳� �������� �� �� �����ߴ���
    
    vector<baseball> question(n); //baseball struct ���� vector ����
    for (int i = 0; i < n; i++) {
        cin >> question[i].num >> question[i].strike >> question[i].ball; //������ ���ڸ� ��, ��Ʈ����ũ ����, �� ����
    }

    //���� + ���
    cout << game(n, question);

    return 0;
}