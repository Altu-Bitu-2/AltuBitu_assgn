#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int beforeW, beforeI, T; // ���̾�Ʈ �� ü��, ���� ������ ���뷮, ���� ��緮 ��ȭ ��ġ
	cin >> beforeW >> beforeI >> T;
	int D, dietI, dietA;
	cin >> D >> dietI >> dietA; // ���̾�Ʈ �Ⱓ, ���� ������ ���뷮, ���� Ȱ�� ��緮
	
	double afterW = 0; // ���̾�Ʈ �� ü��
	int beforeI2 = beforeI;
	int afterW2 = afterW;
	
	// ���� ���� ��緮�� ��ȭ�� ������� �ʾ��� ��
	double tmp = 0;
	for (int i = 0; i < D; i++) {
		tmp += (dietI - (beforeI + dietA));
	}
	afterW = beforeW + tmp;
	
	if (afterW <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		cout << afterW << " " << beforeI << '\n';
	}

	tmp = 0;
	// ���� ���� ��緮�� ��ȭ�� ����� ��
	for (int i = 0; i < D; i++) {
		tmp += (dietI - (beforeI2 + dietA));
		if (abs(dietI - (beforeI2 + dietA)) > T) {
			beforeI2 += floor((dietI - (beforeI2 + dietA)) / 2.0);
		}
	}
	afterW2 = beforeW + tmp;

	string st;
	
	if (afterW2 <= 0 || beforeI2 <= 0) {
		cout << "Danger Diet";
	}
	else {
		if (beforeI - beforeI2 > 0) {
			st = "YOYO";
		}
		else {
			st = "NO";
		}
		cout << afterW2 << " " << beforeI2 << " " << st;
	}
}