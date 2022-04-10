#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//Si에 시작해서 Ti에 끝나는 N개의 수업
//최소의 강의실을 사용해서 모든 수업을 가능하게 해야 함

vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n;
	cin >> n;

	int s, t; //Si, Ti
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		//s를 first, t를 second에 넣어서 int형 vector인 arr 맨 끝에 삽입
		arr.push_back(make_pair(s, t));
	}

	//끝나는 시간이 빠른 것이 위로 가도록
	sort(arr.begin(), arr.end());

	pq.push(arr[0].second);

	for (int i = 1; i < n; i++) {
		//현재 진행 중인 강의 중 가장 먼저 끝나는 강의의 끝나는 시간보다
		//다른 강의가 늦게 시작하거나 같게 시작하면
		if (pq.top() <= arr[i].first)
			pq.pop();

		pq.push(arr[i].second);
	}

	//강의실의 개수 출력
	cout << pq.size();
}