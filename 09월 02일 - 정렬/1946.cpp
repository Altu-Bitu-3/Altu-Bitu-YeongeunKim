#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct recruit {
	int paper, interview;
};

bool cmp(const recruit& a, const recruit& b) {
	return a.paper < b.paper;
}

int count(int k) {

	vector<recruit> arr(k);

	for (int i = 0; i < k; i++) {
		cin >> arr[i].paper >> arr[i].interview;
	}

	sort(arr.begin(), arr.end(), cmp);

	int sum = 1;
	int tmp = arr[0].interview;

	for (int i = 1; i < k; i++) {
		if (arr[i].interview < tmp) {
			sum += 1;
			tmp = arr[i].interview;
		}
	}

	return sum;
}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cout << count(k) << "\n";
	}

	return 0;
}