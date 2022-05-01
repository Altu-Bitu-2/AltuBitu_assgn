#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//�ٸ� ��ġ���� �����Ͽ� ���θ� ���� ��������� �� ������
pair<ll, ll> liquid(vector<ll>& arr, ll fixed, int left, int right) {
    pair<ll, ll> ans;
    ans = make_pair(INF, INF); //ans�� �ʱ�ȭ

    while (left < right) { //left�� ���� right�� ������ ������
        ll mix = fixed + arr[left] + arr[right]; //������ ���� arr�� left, right���� ���� ���� mix�� ����
        if (mix == 0) { //mix Ư���� ���� 0�̸�
            return make_pair(arr[left], arr[right]); //�ݺ��� �ߴ��ϰ� output return
        }
        if (abs(mix) < min_diff) { //mix�� ������ min_diff�� ������ ������
            min_diff = abs(mix); //min_diff�� ���� mix�� �������� ����
            ans = make_pair(arr[left], arr[right]); //ans���� arr�� left���� right������ pair ����
        }
        if (mix > 0) { //mix�� ���� 0���� ũ��
            right--; //right�� ����
        }
        else { //mix�� ���� 0���� ������
            left++; //left�� ����
        }
    }
    return ans;
}

/**
 * 2470�� : �� ��� ����
 * 2473�� : �� ��� ����
 *
 * [�� ���]
 *
 * 1. �ϳ��� ����� �ݵ�� ����Ѵٰ� ����
 * 2. ��� �ϳ� ����
 * 3. �ش� ��� ������ ������ ���� �� ������ �˰��� ����
 *
 * pair : 2���� �� ����
 * tuple : 3���� �� ����
 *
 * !����! �� ����� �ִ��� 1e9(=10��)�̱� ������ 3���� ���� �ִ��� 30���̰�, int�� �Ѿ!
 */
int main() {
    int n; //��ü ����� ��

    //�Է�
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //����� Ư������ ��Ÿ���� n���� ���� �Է�
    }

    //����
    sort(arr.begin(), arr.end()); //��׵��� Ư���� arr�� ����
    tuple<ll, ll, ll> ans;
    for (int i = 0; i < n - 2; i++) {
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] ����� ����
        if ((p.first != INF) && (p.second != INF)) { //�ּڰ��� ���ŵ� ���
            ans = make_tuple(arr[i], p.first, p.second); //tuple ����
        }
    }

    //���
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}