#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int>& belt) {
    vector<int> sushi(d + 1, 0); //�ʹ� ���� ����

    //�������� ���� �ʹ�
    int section_sushi = 1;
    sushi[c]++; //�ʹ� ���� ���� ����

    //������ �ʱ�ȭ
    for (int i = 0; i < k; i++) {
        if (!sushi[belt[i]]) { //�ʹ� ���� ������ 0�� �ƴϸ�
            section_sushi++; //�������� ���� �ʹ� �� ����
        }
        sushi[belt[i]]++; //�ʹ� ���� ���� ����
    }

    int ans = section_sushi; //ans�� �������� ���� �ʹ� ��
    for (int i = k; i < n + k; i++) { //n+k ������ k������ �����̵� ������
        sushi[belt[i - k]]--; //���� �ʹ� ����
        if (!sushi[belt[i - k]]) { //sushi�� 0�� �ƴϸ�
            section_sushi--; //�������� ���� �ʹ� �� ����
        }
        if (!sushi[belt[i % n]]) { //sushi�� 0�� �ƴϸ�
            section_sushi++; //�������� ���� �ʹ� �� ����
        }
        sushi[belt[i % n]]++; //���� �ʹ� ����
        ans = max(ans, section_sushi); //ans�� �������� ���� �ʹ� �� ū �� ans�� ����
    }
    return ans;
}

/**
 * [ȸ�� �ʹ�]
 *
 * 1. �����ؼ� �Ծ�� �� ���ð� k�� �����Ʊ� ������ �����̵� ������
 * 2. ������ �ƴ϶� �� ������ �迭! ��ⷯ ������ ���� �������� �� �� ��ġ �����ϱ�
 * 3. �������� ���� �ʹ��� ���� ����س���
 * 4. �ʹ��� ������ �ִ� 3000���� ���� ����. �� ������ ���� �ʹ��� ������ �����ֱ�
 */

int main() {
    //ȸ�� �ʹ� ��Ʈ�� ���� ������ ��, �ʹ��� ������, �����ؼ� �Դ� ������ ��, ���� ��ȣ
    int n, d, k, c;

    //�Է�
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0); //vector belt ����
    //ȸ����Ʈ �� �ʹ�
    for (int i = 0; i < n; i++) { //i�� 0���� n���� �ݺ�
        cin >> belt[i]; //vector belt�� �Է�
    }

    //���� & ���
    cout << chooseSushi(n, d, k, c, belt);
    return 0;
}