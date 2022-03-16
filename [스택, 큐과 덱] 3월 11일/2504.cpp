#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	stack<char> st;

	cin >> input;
	int res = 0;
	int temp = 1;

	for (int i = 0; i < input.length(); i++) {
		
		if (input[i] == '(') {
			temp *= 2;
			st.push(input[i]);
		}

		else if (input[i] == ')') {
			if (st.empty() || st.top() != '(') { //stack�� ����ְų� top�� '(' �ƴ� ���
				res = 0;
				break;
			}
			else if (input[i - 1] == '(') { //���� ���ڿ��� '('�� ���
				res += temp;
				temp /= 2;
				st.pop();
			}
			else { //���� ���ڿ��� '(' �ƴ� ���
				temp /= 2;
				st.pop();
			}
		}
		
		else if (input[i] == '[') {
			temp *= 3;
			st.push(input[i]);
		}

		else if (input[i] == ']') {
			if (st.empty() || st.top() != '[') { //stack�� ����ְų� top�� '[' �ƴ� ���
				res = 0;
				break;
			}
			else if (input[i - 1] == '[') { //���� ���ڿ��� '['�� ���
				res += temp;
				temp /= 3;
				st.pop();
			}
			else { //���� ���ڿ��� '[' �ƴ� ���
				temp /= 3;
				st.pop();
			}
		}
	}
	if (!st.empty())
		res = 0;
	cout << res;
}