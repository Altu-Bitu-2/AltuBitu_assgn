#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll>& arr, ll fixed, int left, int right) {
    pair<ll, ll> ans;
    ans = make_pair(INF, INF); //ans값 초기화

    while (left < right) { //left의 값이 right의 값보다 작으면
        ll mix = fixed + arr[left] + arr[right]; //고정된 값과 arr의 left, right값을 더한 값을 mix에 저장
        if (mix == 0) { //mix 특성의 값이 0이면
            return make_pair(arr[left], arr[right]); //반복문 중단하고 output return
        }
        if (abs(mix) < min_diff) { //mix의 절댓값이 min_diff의 값보다 작으면
            min_diff = abs(mix); //min_diff의 값을 mix의 절댓값으로 갱신
            ans = make_pair(arr[left], arr[right]); //ans값에 arr의 left값과 right값으로 pair 생성
        }
        if (mix > 0) { //mix의 값이 0보다 크면
            right--; //right값 감소
        }
        else { //mix의 값이 0보다 작으면
            left++; //left값 증가
        }
    }
    return ans;
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n; //전체 용액의 수

    //입력
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //용액의 특성값을 나타내는 n개의 정수 입력
    }

    //연산
    sort(arr.begin(), arr.end()); //용액들의 특성값 arr을 정렬
    tuple<ll, ll, ll> ans;
    for (int i = 0; i < n - 2; i++) {
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second); //tuple 생성
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}