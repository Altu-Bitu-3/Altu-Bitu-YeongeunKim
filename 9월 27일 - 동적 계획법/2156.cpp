#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dynamic(vector<int> &arr, int n) {
	vector<int> dp(n + 1, 0);
	if (n == 1) {
		//하나면 바로 값 리턴
		return arr[1];
	}

	//dp초기값 설정
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		//최대 3개의 경우의 수
		//1. 첫 번째, 두 번째, 현재 포도주 선택
		//2. 첫 번째, 세 번째, 현재 포도주 선택
		//3. 현재 포도주 선택 x
		dp[i] = max({ dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1] });
	}

	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cout << dynamic(arr, n);

	return 0;
}