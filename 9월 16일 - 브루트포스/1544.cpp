#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string rotate(queue<char>& q) {
	string s = "";
	for (int i = 0; i < q.size(); i++) {
		s += q.front();
		char tmp = q.front();
		q.push(tmp);
		q.pop();
	}

	return s;
}

bool count(string s, vector<string> &arr) {
	queue<char> q;
	for (int i = 0; i < s.length(); i++) {
		q.push(s[i]);
	}

	int n = q.size();

	bool is_in = false;

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < q.size(); j++) {
			string tmp = rotate(q);

			if (tmp == arr[i]) {
				return true;
			}

			q.push(q.front());
			q.pop();
		}
	}
	return false;
}


int main() {
	int n;
	cin >> n;
	vector<string> arr;

	while (n--) {
		string s;
		cin >> s;

		if (arr.empty()) {
			arr.push_back(s);
			continue;
		}

		if (!count(s, arr)) {
			arr.push_back(s);
		}
	}

	cout << arr.size();

	return 0;
}