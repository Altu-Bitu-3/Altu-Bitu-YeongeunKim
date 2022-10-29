#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> mode(8001, 0);
	double sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		mode[arr[i] + 4000]++;
	}
	sort(arr.begin(), arr.end());
	
	int best = 0;
	for (int i = 0; i < mode.size(); i++) {
		if (mode[i] > best) {
			best = mode[i];
		}
	}

	int cnt = 0;
	int mod;
	for (int i = 0; i < mode.size(); i++) {
		if (mode[i] == best) {
			cnt++;
			mod = i - 4000;
		}
		if (cnt == 2) {
			mod = i - 4000;
			break;
		}
	}


	int avg = round(sum / n);
	int mid = arr[n / 2];
	int k = arr[n - 1] - arr[0];
	
	cout << avg << '\n';
	cout << mid << '\n';
	cout << mod << '\n';
	cout << k;

	return 0;
}