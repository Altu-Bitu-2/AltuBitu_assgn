#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll finalChildren(ll t, vector<int>& rides) { //�־��� t���� ���̱ⱸ�� ź ���̵� �� ���ϴ� �Լ�
    ll child = 0; //child ���� �ʱ�ȭ
    for (int i = 1; i < rides.size(); i++) { //���̱ⱸ�� ���� ����ŭ �ݺ�
        child += (t / rides[i] + 1); //�ش� �ð����� ���̱ⱸ�� ź ���̵� ���� ī��Ʈ
    }
    return child; //���̵� �� ����
}

ll lowerSearch(ll left, ll right, ll target, vector<int>& rides) {
    while (left <= right) { //left�� ���� right�� ������ �۰ų� ������
        ll mid = (left + right) / 2; //left�� right�� �߰����� mid ����
        ll child = finalChildren(mid, rides); //finalChildren�� �Լ� ���ϰ� child�� ����

        if (child >= target) { //���� ������ ���̺��� �� �ڿ� �ִ� ���̶��
            right = mid - 1; //right���� mid -1
        }
        else { //���� ������ ���̺��� �ڿ� �ִ� ���̰� �ƴ϶��
            left = mid + 1; //left���� mid+1
        }
    }
    return left; //left�� ����
}

int findRides(int n, int m, vector<int>& rides) {
    ll t = lowerSearch(0, (ll)rides[1] * n, n, rides); //t�� �ִ� ���̵� �� * �ִ� ���̱ⱸ �ð��� ���� lowerSearch �Լ��� ���ϰ�
    ll child = finalChildren(t, rides); //finalChildren�Լ��� ���� ���� child�� ����
    for (int i = m; i >= 1; i--) {
        if (t % rides[i] == 0) { //���̰� Ž
            if (child-- == n) { //���̱ⱸ�� ź ���̵� ���� n�̸�
                return i; //���̱ⱸ ��ȣ�� ����
            }
        }
    }
}

/**
 * [���� ����]
 *
 * n��° ���̰� ���̱ⱸ�� Ÿ�� �ð��� ���� ��, �ش� �ð��� ���̱ⱸ�� Ÿ�� ���̵��� ��� �˻��ϸ� n��° ���̰� Ÿ�� ���̱ⱸ�� ��ȣ�� ���Ѵ�!
 *
 * 1. n��° ���̰� ���̱ⱸ�� Ÿ�� �ð��� �������� parametric search ���� ����
 *    - �̶�, �� �ð� �� ���̱ⱸ Ÿ�� ������ ������ ��ȣ ���ϴ� ������ ������ ����
 *      f(t) = (��� i(���� �ⱸ)�� ���ؼ�) t/num[i] + n(�ð� 0�϶� ���̱ⱸ Ÿ�� ���� ��)
 *
 *    - left: ���̱ⱸ Ÿ�� �ð��� �ּ� = 0
 *    - right: ���̱ⱸ Ÿ�� �ð��� �ִ� = 1�� ���̱ⱸ ���� �ð� x n (Ÿ��Ʈ�ϰ� ������ �ּ� ���� �ð� x n ������ ���ǻ� �̷��� ����)
 *
 *    - n��° ���̰� ���̱ⱸ�� Ÿ�� ù �ð��� ���ؾ� �ϹǷ� lower bound
 *
 * 2. n��° ���̰� ���̱ⱸ�� Ÿ�� �ð��� ���ߴٸ�, �� �ð��� ���������� ���̱ⱸ�� Ÿ�� ���̺��� �����ؼ�
 *    ���̱ⱸ�� m���� Ž���ϸ鼭 n��° ���̰� �� �� ���̱ⱸ Ÿ���� ���ϸ� ��!
 */

int main() {
    int n, m; //���̵� ��, ���̱ⱸ�� ���� ��

    //�Է�
    cin >> n >> m;
    vector<int> rides(m + 1, 0); //�� ���̱ⱸ�� ���� �ð��� �����ϴ� vector
    for (int i = 1; i <= m; i++) {
        cin >> rides[i]; //�� ���̱ⱸ�� ���� �ð��� ��Ÿ���� m���� ��
    }

    if (n <= m) { //������ ���� ���̱ⱸ ������ ���ٸ�
        cout << n; //���̵� �� ���
        return 0;
    }

    //���� & ���
    cout << findRides(n, m, rides); //������ ���̰� Ÿ�� �Ǵ� ���̱ⱸ�� ��ȣ ���
    return 0;
}