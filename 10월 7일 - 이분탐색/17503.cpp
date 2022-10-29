#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<long long, long long> p;

bool cmp(const p& a, const p& b) {
	return a.second > b.second;
}

//레벨이 beer[mid].first일 때 최대 선호도 값을 구하는 함수
long long int calPre(int mid, int n, vector<p> beer) {
	long long int level = beer[mid].first;
	long long int sum = 0, cnt = 0;
	
	//선호도 순으로 정렬(실제 beer 벡터는 바뀌지 않음)
	sort(beer.begin(), beer.end(), cmp);
	for (int i = 0; i < beer.size(); i++) {
		if (beer[i].first > level) {
			//현재 level에서 못 먹는 술이면 패스
			continue;
		}
		sum += beer[i].second;
		if (++cnt == n) {
			//상위 n개만 합산 후 리턴
			return sum;
		}
	}

	//n개를 채우지 못할 경우 -1 리턴(항상 m보다 작은 값)
	return -1;
}

int binarySearch(int left, int right, int n, int m, vector<p> &beer) {
	while (left <= right) {
		int mid = (left + right) / 2;
		long long int pre = calPre(mid, n, beer);

		if (pre < m) {
			//레벨이 mid일 때 선호도가 m보다 작다면 레벨을 올려줌
			left = mid + 1;
		}

		else {
			//그렇지 않다면 레벨이 낮아도 되므로
			//레벨 값을 낮춰줌
			right = mid - 1;
		}
	}

	return beer[left].first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	
	cin >> n >> m >> k;
	vector<p> beer(k);

	for (int i = 0; i < k; i++) {
		cin >> beer[i].second;
		cin >> beer[i].first;
	}
	sort(beer.begin(), beer.end(), cmp);
	long long int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += beer[i].second;
	}

	if (sum < m) {
		//레벨이 최대여도 만족 안 되는 경우 먼저 계산
		cout << "-1";
		return 0;
	}

	sort(beer.begin(), beer.end());

	cout << binarySearch(0, k - 1, n, m, beer);

	return 0;
}