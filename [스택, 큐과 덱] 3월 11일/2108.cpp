#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;

	double num;
	double sum = 0;
	int freq[10001] = { 0 };
	vector<int> v;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
		sum += v[i];

		freq[v[i] + 4000]++; //�󵵼�
	}

	int modeMax = *max_element(freq, freq + 10000); //�ִ� �� ��
	int mode; //�ֺ�
	int cnt = 0;
	for (int i = 0; i < 8001; i++) {
		if (cnt == 2)  //�ֺ� �� �ι�°�� ���� ��
			break;
		if (freq[i] == modeMax) {
			mode = i;
			cnt++;
		}
	}
	mode -= 4000;

	sort(v.begin(), v.end());	
	
	cout << (int)(round(sum / v.size())) << '\n';
	cout << v[v.size() / 2] << '\n';
	cout << mode << '\n';
	cout << v[N - 1] - v[0];
}