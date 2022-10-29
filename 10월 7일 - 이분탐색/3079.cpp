#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간이 mid일 때 심사할 수 있는 최대 사람 수를 계산하는 함수
unsigned long long calPeople(unsigned long long mid, vector<unsigned long long>& entry) {
	unsigned long long sum = 0;
	for (int i = 0; i < entry.size(); i++) {
		sum += mid / entry[i];
	}

	return sum;
}

unsigned long long binarySearch(unsigned long long left, unsigned long long right, int m, vector<unsigned long long>& entry) {
	while (left <= right) {
		unsigned long long mid = (left + right) / 2;
		unsigned long long people = calPeople(mid, entry);

		//mid초동안 m명의 사람을 심사할 수 없다면 mid를 늘려주고,
		//mid초동안 심사할 수 있는 사람이 m보다 크거나 같다면 초를 줄여줌
		if (people >= m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long n, m;
	cin >> n >> m;
	vector<unsigned long long> entry(n);
	for (int i = 0; i < n; i++) {
		cin >> entry[i];
	}
	sort(entry.begin(), entry.end());

	cout << binarySearch(entry[0], entry[0] * m, m, entry);

	return 0;
}