#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int>& tree) {
    ll sum = 0; //변수 sum 초기화
    for (int i = 0; i < tree.size(); i++) { //나무의 수만큼 반복
        if (height >= tree[i]) { //만약 height(mid)가 tree[i]보다 크거나 같으면
            return sum; //sum을 리턴
        }
        sum += (tree[i] - height); //tree[i]에서 height(mid)를 뺀 값을 sum에 더하기
    }
    return sum; //sum값 리턴
}

int upperSearch(int left, int right, int target, vector<int>& tree) {
    while (left <= right) { //left가 right보다 작거나 같으면
        int mid = (left + right) / 2; //left와 right의 중간값 설정
        ll tree_cnt = cntTree(mid, tree); //cntTree 함수의 리턴값 저장

        if (tree_cnt >= target) { //tree_cnt값이 target(주어진 나무의 길이)보다 크거나 같으면
            left = mid + 1; //left에 mid + 1 값을 저장
        }
        else { //tree_cnt값이 targer(주어진 나무의 길이)보다 작으면
            right = mid - 1; //right에 mid -1 값을 저장
        }
    }
    return left - 1; //left - 1값을 리턴
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m; //나무의 수, 나무의 길이

    //입력
    cin >> n >> m; //나무의 수, 나무의 길이
    vector<int> tree(n, 0); //n개의 나무의 높이를 저장하는 vector
    for (int i = 0; i < n; i++) {
        cin >> tree[i]; //나무의 높이
    }

    sort(tree.begin(), tree.end(), greater<>()); //나무의 길이 내림차순 정렬

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree); //절단기에 설정할 수 있는 높이의 최댓값
    return 0;
}