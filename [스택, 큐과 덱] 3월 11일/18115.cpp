#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//1: ���� ���� ī�忡 �ֱ�
	//2: ������ �ι�° ��ġ�� ī�� �ֱ�
	//3: ���� �ؿ� ī�� �ֱ�

	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	reverse(v.begin(), v.end());

	deque<int> dq;
	for (int i = 0; i < N; i++) {
		switch (v[i]) {
		case 1:
		{
			dq.push_front(i + 1);
			break;
		}
		case 2:
		{
			int top = dq.front();
			dq.pop_front();
			dq.push_front(i + 1);
			dq.push_front(top);
			break;
		}
		case 3:
		{
			dq.push_back(i + 1);
			break;
		}
		}
	}
	while (!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}
}