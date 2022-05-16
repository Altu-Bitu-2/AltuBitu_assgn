#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 1e9;

int mineLand(int n, int m, int b, int height, vector<vector<int>>& land) {
    int tot_time = 0; //��ü �ð�
    for (int i = 0; i < n; i++) { //n��ŭ �ݺ�
        for (int j = 0; j < m; j++) { //m��ŭ �ݺ�
            //��� ����
            if (land[i][j] > height) { //height���� land�� ũ�Ⱑ ũ��
                b += (land[i][j] - height); //land�� ���̿��� height�� �� ���� �κ��丮�� ����
                tot_time += 2 * (land[i][j] - height); // ��� �����ϹǷ� ��ü �ð��� 2�� �߰�
            }
            //��� �ױ�
            else if (land[i][j] < height) { //height���� land�� ũ�Ⱑ ������
                b -= (height - land[i][j]); //height���� land�� ���� �� ���� �κ��丮���� ����
                tot_time += (height - land[i][j]); //����� �����Ƿ� ��ü �ð��� 1�� �߰�
            }
        }
    }
    if (b < 0) //���������� ���� ������ �Ұ����� ����
        return INF + 1; //INF+1 return
    return tot_time; //��ü �ð� return
}

/**
 * [����ũ����Ʈ]
 *
 * 1. ���� ���� ���� ���̸� h��� �� ��, h-1�� ���̸� ����°� h���� 2*(N*M)�� �ð��� �� �ҿ��
 * 2. ���� ���� ���� ���̸� h��� �� ��, h+1�� ���̸� ����°� h���� (N*M)�� �ð��� �� �ҿ��
 * -> ���� ���� ���̰� �� �� �ִ� �ĺ��� (���� ���� ��) ~ (���� ���� ��)
 * -> ������ ��� ���̿� ���� ���Ʈ���� �����ص� �ð� �ʰ� X
 *
 * !����! ���� ���� ����� ������ ������ �ٸ� ���� ����� �����ؼ� ���� �� ����.
 * �����ϴ� �� 2�ʰ� �ɸ��� ���� �� 1�ʰ� �ɸ�.
 */

int main() {
    int n, m, b, min_height = 256, max_height = 0;

    //�Է�
    cin >> n >> m >> b; // n���� �ٿ� ���� m���� ����, �κ��丮�� �ִ� ����� ��
    vector<vector<int>> land(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) { //n���� �ٿ�
        for (int j = 0; j < m; j++) { //���� m���� ������
            cin >> land[i][j]; //���� ���̰� �־���
            min_height = min(min_height, land[i][j]); //���� ���� �� ����
            max_height = max(max_height, land[i][j]); //���� ���� �� ����
        }
    }

    //����
    int min_time = INF, height = 0;
    for (int i = min_height; i <= max_height; i++) { //�ּ� ���̿��� �ִ� ���̱��� �ݺ�
        int t = mineLand(n, m, b, i, land); //t�� ��ü �ð� ����
        //���� ���� �۾��� ������ ����
        if (t <= min_time) { //����� ��ü �ð��� �ּ� �ð����� �۰ų� ������
            min_time = t; //�ּҽð��� ����� ��ü �ð� ����
            height = i; //height�� i�� ����
        }
    }

    //���
    cout << min_time << ' ' << height; //�۾��� �ɸ��� �ּ� �ð�, �� ��� ���� ����
    return 0;
}