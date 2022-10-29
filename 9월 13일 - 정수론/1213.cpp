#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string palindrome(string s, vector<int> &alphabet) {
	for (int i = 0; i < s.size(); i++) {
		int n = s[i];
		alphabet[n - 65]++;
	}

	int cnt = 0;
	string answer = "";

	int mid = -1;

	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i] != 0 && alphabet[i] % 2 == 1) {
			mid = i;
			cnt++;
		}
		if (cnt == 2) {
			return "I'm Sorry Hansoo";
		}
	}

	for (int i = 0; i < alphabet.size(); i++) {
		if (i == mid && alphabet[i] == 1) {
			continue;
		}
		int n = alphabet[i] / 2;
		while (n--) {
			char c = i + 65;
			answer += c;
		}
	}

	string tmp = answer;
	reverse(tmp.begin(), tmp.end());

	if (mid != -1) {
		char c = mid + 65;
		answer += c;
	}
	
	answer += tmp;

	return answer;
}

int main() {
	string s;
	cin >> s;

	vector<int> alphabet(26, 0);
	cout << palindrome(s, alphabet);
	

	return 0;
}