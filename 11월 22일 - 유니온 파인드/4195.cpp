#include <iostream>
#include <vector>
#include <map>
#include <string>

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, f;
	cin >> t;
	while (t--) {
		cin >> f;
		parent.assign(2 * f, -1);
		map<string, int> name;
		name.clear();
		int idx = 0;
		while(f--) {
			string s1, s2;
			int x, y;
			cin >> s1 >> s2;
			if (name.find(s1) == name.end()) {
				name[s1] = idx++;
			}
			x = name[s1];
			if (name.find(s2) == name.end()) {
				name[s2] = idx++;
			}
			y = name[s2];
			//맵으로 각 이름의 값을 받아온 후 집합을 합쳐줌
			unionInput(x, y);
			//합친 집합의 부모값에 접근해 총 친구수를 출력
			cout << -parent[findParent(x)] << '\n';
		}
	}

	return 0;
}