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
			if (st.empty() || st.top() != '(') { //stack이 비어있거나 top이 '(' 아닌 경우
				res = 0;
				break;
			}
			else if (input[i - 1] == '(') { //이전 문자열이 '('인 경우
				res += temp;
				temp /= 2;
				st.pop();
			}
			else { //이전 문자열이 '(' 아닌 경우
				temp /= 2;
				st.pop();
			}
		}
		
		else if (input[i] == '[') {
			temp *= 3;
			st.push(input[i]);
		}

		else if (input[i] == ']') {
			if (st.empty() || st.top() != '[') { //stack이 비어있거나 top이 '[' 아닌 경우
				res = 0;
				break;
			}
			else if (input[i - 1] == '[') { //이전 문자열이 '['인 경우
				res += temp;
				temp /= 3;
				st.pop();
			}
			else { //이전 문자열이 '[' 아닌 경우
				temp /= 3;
				st.pop();
			}
		}
	}
	if (!st.empty())
		res = 0;
	cout << res;
}