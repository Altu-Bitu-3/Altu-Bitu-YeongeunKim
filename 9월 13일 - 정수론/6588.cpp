#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1000001;

int findPrime(int n, vector<bool> &is_prime) {
	for (int i = 3; i < n; i++) {
		if (is_prime[i] == true && is_prime[n - i] == true) {
			cout << n << " = " << i << " + " << n - i << '\n';
			return 0;
		}
	}
	cout << "Goldbach's conjecture is wrong.";
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	vector<int> arr;
	cin >> n;
	while (n) {
		arr.push_back(n);
		cin >> n;
	}

	int m = *max_element(arr.begin(), arr.end());

	vector<bool> is_prime(m + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= m + 1; i++) {
		if (!is_prime[i]) {
			continue;
		}
		if (i*i > m) {
			break;
		}
		for (int j = i * i; j <= m; j += i) {
			if (!is_prime[j]) {
				continue;
			}
			is_prime[j] = false;
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		findPrime(arr[i], is_prime);
	}

	return 0;
}