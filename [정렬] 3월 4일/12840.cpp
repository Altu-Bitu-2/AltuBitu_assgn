#include <iostream>

using namespace std;

void printTime(int t) {

	int h = t / 3600;
	t = t % 3600;
	int m = t / 60;
	int s = t % 60;
	cout << h << " " << m << " " << s << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int h, m, s, cur, q, num, c;

	cin >> h >> m >> s >> q;
	cur = h * 3600 + m * 60 + s;

	while (q--) {
		cin >> num;
		switch (num) {
		case 1:
			cin >> c;
			cur = (cur + c) % 86400;
			break;
		case 2:
			cin >> c;
			cur = (cur - c) % 86400;
			break;
		case 3:
			if (cur < 0)
				cur += 86400;
			printTime(cur);
			break;
		}
	}
}