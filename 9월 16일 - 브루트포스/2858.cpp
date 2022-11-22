#include <iostream>

using namespace std;

int main() {
	int r, b;
	cin >> r >> b;

	for (int i = 3; ; i++) {
		for (int j = i; j >= 3; j--) {
			int l, w;
			w = (i - 2) * (j - 2);
			l = i * j - w;
			if (l == r && w == b) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}