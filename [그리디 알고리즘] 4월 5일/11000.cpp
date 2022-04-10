#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//Si�� �����ؼ� Ti�� ������ N���� ����
//�ּ��� ���ǽ��� ����ؼ� ��� ������ �����ϰ� �ؾ� ��

vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n;
	cin >> n;

	int s, t; //Si, Ti
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		//s�� first, t�� second�� �־ int�� vector�� arr �� ���� ����
		arr.push_back(make_pair(s, t));
	}

	//������ �ð��� ���� ���� ���� ������
	sort(arr.begin(), arr.end());

	pq.push(arr[0].second);

	for (int i = 1; i < n; i++) {
		//���� ���� ���� ���� �� ���� ���� ������ ������ ������ �ð�����
		//�ٸ� ���ǰ� �ʰ� �����ϰų� ���� �����ϸ�
		if (pq.top() <= arr[i].first)
			pq.pop();

		pq.push(arr[i].second);
	}

	//���ǽ��� ���� ���
	cout << pq.size();
}