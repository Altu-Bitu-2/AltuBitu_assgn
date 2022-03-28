#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int beforeW, beforeI, T; // 다이어트 전 체중, 일일 에너지 섭취량, 기초 대사량 변화 역치
	cin >> beforeW >> beforeI >> T;
	int D, dietI, dietA;
	cin >> D >> dietI >> dietA; // 다이어트 기간, 일일 에너지 섭취량, 일일 활동 대사량
	
	double afterW = 0; // 다이어트 후 체중
	int beforeI2 = beforeI;
	int afterW2 = afterW;
	
	// 일일 기초 대사량의 변화를 고려하지 않았을 때
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
	// 일일 기초 대사량의 변화를 고려할 때
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