#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

int main() {
	string s;
	cin >> s;

	int n, m;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			n = stoi(tmp);
			tmp = "";
			continue;
		}
		tmp += s[i];
	}
	m = stoi(tmp);

	int g = gcd(max(n, m), min(n, m));

	cout << n / g << ":" << m / g;

	return 0;
}