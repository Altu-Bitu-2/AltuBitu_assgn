#include <iostream>
#include <set>

using namespace std;

int main() {

	string s;
	cin >> s;

	set<string> st;
	string tmp;

	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			tmp += s[j];
			st.insert(tmp);
		}
		tmp = ""; 
	}

	cout << st.size();
}