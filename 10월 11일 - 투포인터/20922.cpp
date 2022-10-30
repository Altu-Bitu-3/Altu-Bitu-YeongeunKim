#include <iostream>
#include <vector>

using namespace std;

vector<int> cntList(100001, 0);
vector<int> num;

int calLen(int k) {
	int left = 0, right = 0, max_cnt = 0;
	while (left <= right && right < num.size()) {
		if (++cntList[num[right]] > k) {
			if (right - left > max_cnt) {
				//현재까지의 길이가 max값보다 크면 값을 갱신
				max_cnt = right - left;
			}
			while (cntList[num[right]] > k) {
				//해당되는 숫자의 개수가 k보다 작거나 같아질 때까지
				//left값과 그에 해당하는 숫자 개수 감소
				cntList[num[left++]]--;
			}
		}
		right++;
	}
	if (right - left > max_cnt) {
		//리스트 마지막까지 탐색 끝났을 경우
		max_cnt = right - left;
	}

	return max_cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}

	cout << calLen(k);

	return 0;
}