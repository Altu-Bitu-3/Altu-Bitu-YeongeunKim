#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
vector<ci> dir;

int robot(vector<vector<int>>& room, vector<vector<bool>>& clean, int r, int c, int d) {
	ci direction = dir[d];
	
	int cnt = 0;

	while (true) {
		if (!clean[r][c]) {
			//현재 위치가 청소 안 되어있으면 청소하고 카운트 증가
			clean[r][c] = true;
			cnt++;
		}
		
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			//현재 위치에서 네 방향 중 청소 안 된 곳이 있는지 확인
			if (!clean[r + dir[i].first][c + dir[i].second]) {
				flag = true;
				break;
			}
		}

		//청소 안 된 곳이 없는 경우
		if (!flag) {
			//후진할 곳이 없으면 종료
			if (room[r - direction.first][c - direction.second] == 1) return cnt;
			//후진 가능하면 현재 방향 바라보고 후진
			r -= direction.first;
			c -= direction.second;
			continue;
		}

		//청소 안 한 방향 나올 때까지 반시계 방향으로 90도 회전
		do  {
			d = (d + 3) % 4;
			direction = dir[d];
		} while (clean[r + direction.first][c + direction.second]);

		//해당 방향으로 한 칸 이동
		r += direction.first;
		c += direction.second;
	}

	return 0;
}

int main() {
	int n, m, r, c, d;
	cin >> n >> m >> r >> c >> d;
	dir.push_back({ -1, 0 });
	dir.push_back({ 0, 1 });
	dir.push_back({ 1, 0 });
	dir.push_back({ 0, -1 });  //방향 배열
	vector<vector<int>> room(n, vector<int>(m, 1));  //방의 정보
	vector<vector<bool>> clean(n, vector<bool>(m, true));  //각 방이 청소 됐는지. 청소 했거나 벽이면 true

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			cin >> k;
			if (k == 0) clean[i][j] = false;
			room[i][j] = k;
		}
	}

	cout << robot(room, clean, r, c, d);

	return 0;
}