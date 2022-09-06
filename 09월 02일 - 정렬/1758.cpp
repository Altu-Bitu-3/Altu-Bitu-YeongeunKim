#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	
	int n;

	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<>());

	long long int sum = 0;

	for (int i = 0; i < n; i++) {
		int tip = arr[i] - i;
		if (tip < 0) {
			break;
		}
		else {
			sum += tip;
		}
	}

	cout << sum;

	return 0;
}