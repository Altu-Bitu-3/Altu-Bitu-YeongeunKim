#include <iostream>
#include <vector>

using namespace std;
vector<int> parent;

int findParent(int x) {
	if (parent[x] < 0) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	if (xp == yp) {
		return;
	}
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int countStory(vector<vector<int>>& party, int base) {
	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < party.size(); i++) {
		flag = true;
		for (int j = 0; j < party[i].size(); j++) {
			//각 파티를 다시 체크하면서 파티에 진실을 아는 집합의 사람이 한 명이라도 있으면
			//cnt를 더하지 않음
			if (parent[base] == party[i][j]) {
				flag = false;
				break;
			}
			if (findParent(party[i][j]) == findParent(base) || parent[party[i][j]] == base) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			continue;
		}
		cnt++;
	}
	return cnt;
}

int main() {
	int n, m, k, h;
	cin >> n >> m >> k;
	parent.assign(n + 1, -1);

	if (k == 0) {
		cout << m;
		return 0;
	}

	int base;
	cin >> base;
	k--;
	//진실을 아는 사람은 한 집합에
	while (k--) {
		cin >> h;
		unionInput(base, h);
	}

	vector<vector<int>> party(m);

	//각 파티마다 같은 집합으로 묶어줌
	for(int i = 0; i < m; i++) {
		int pp, x, y;
		cin >> pp;
		pp--;
		cin >> x;
		party[i].push_back(x);
		while (pp--) {
			cin >> y;
			party[i].push_back(y);
			unionInput(x, y);
		}
	}

	cout << countStory(party, base);

	return 0;
}