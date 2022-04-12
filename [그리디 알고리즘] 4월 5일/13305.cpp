#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll greedyOil(vector<pair<ll, ll>>& city, int n) { //�������� ������ ���÷� ���� �ּ� ����� return�ϴ� �Լ�
    ll cur_cost = city[0].second, tot_cost = 0;

    for (int i = 0; i < n; i++) { 
        if (city[i].second < cur_cost) { //�� ������ �⸧���� �� �����ϸ�
            cur_cost = city[i].second; //��ü
        }
        tot_cost += (cur_cost * city[i].first); //�̵� ���
    }
    return tot_cost; //�̵� �ּ� ���
}

/**
 * [������]
 *
 * �ִ��� ������ �� ������ ���� �⸧�� �־�� �Ѵ�.
 * ���� ù��° ���ú��� ������� ���� �� ������ �����ϰ�, 
 * �̵��� �ʿ��Ѹ�ŭ�� �⸧�� ä���.
 * �̷��� �ϸ� ���ݱ��� ���� �� ���� �� ���� �� ������ �ִ��� ���� �� �� �ִ�.
 *
 * !����! ���� ������ ������ �ִ� 10^9�̰�, ���ʹ� ������ �ִ� 10^9�̹Ƿ�
 *       ������ ������ �ִ��� 10^18���� int ���� �Ѿ! -> long long ��� ��
 */

int main() {
    int n; //������ ����

    //�Է�
    cin >> n;
    vector<pair<ll, ll>> city(n, { 0, 0 });
    for (int i = 0; i < n - 1; i++) {
        cin >> city[i].first; //������ �� ���ø� �����ϴ� ������ ���� (N -1)��
    }
    for (int i = 0; i < n; i++) {
        cin >> city[i].second; //�������� ���ʹ� ���� N��
    }

    //���� & ���
    cout << greedyOil(city, n);
    return 0;
}