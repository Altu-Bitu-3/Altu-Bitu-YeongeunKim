#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int count(int k, vector<pair<int, int>> recruit) {

	sort(recruit.begin(), recruit.end());

	int sum = 1;
	int tmp = recruit[0].second;

	for (int i = 1; i < k; i++) {
		if (recruit[i].second < tmp) {
			sum += 1;
			tmp = recruit[i].second;
		}
	}

	return sum;
}

int main() {

	int n;
	cin >> n;


	while (n--) {
		int k;
		cin >> k;
		vector<pair<int, int>> recruit(k);
		for (int i = 0; i < k; i++) {
			cin >> recruit[i].first >> recruit[i].second;
		}
		cout << count(k, recruit) << "\n";
	}

	return 0;
}