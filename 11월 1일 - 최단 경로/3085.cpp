#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//사탕의 자리를 바꾸고 해당 상태의 최대값을 계산하는 함수
//candy 배열은 항상 원상태를 유지해야하기 때문에 주소값 사용하지 않음
int swapCandy(int n, int i, int j, int sw_i, int sw_j, vector<vector<char>> candy) {
	//스왑이 필요한 두 값 변경
	swap(candy[i][j], candy[sw_i][sw_j]);

	//행의 최대값
	int r_cnt = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] != candy[i][j + 1]) {
				r_cnt = max(r_cnt, cnt);
				cnt = 1;
				continue;
			}
			cnt++;
		}
		r_cnt = max(r_cnt, cnt);
	}

	//열의 최대값
	int c_cnt = 0;
	for (int j = 0; j < n; j++) {
		int cnt = 1;
		for (int i = 0; i < n - 1; i++) {
			if (candy[i][j] != candy[i + 1][j]) {
				c_cnt = max(c_cnt, cnt);
				cnt = 1;
				continue;
			}
			cnt++;
		}
		c_cnt = max(c_cnt, cnt);
	}

	//두 값 중 더 큰 값을 리턴
	return max(c_cnt, r_cnt);
}

int calMax(int n, vector<vector<char>>& candy) {
	int max_candy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//사탕이 연속되지 않으면 값을 바꾼 후 최대값을 계산하는 함수 호출
			if (i + 1 < n && candy[i][j] != candy[i + 1][j]) {
				max_candy = max(max_candy, swapCandy(n, i, j, i + 1, j, candy));
			}
			if (j + 1 < n && candy[i][j] != candy[i][j + 1]) {
				max_candy = max(max_candy, swapCandy(n, i, j, i, j + 1, candy));
			}
		}
	}

	return max_candy;
}

int main() {
	int n;
	cin >> n;
	vector<vector<char>> candy(n, vector<char>(n));

	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			candy[i][j] = c;
		}
	}

	cout << calMax(n, candy);

	return 0;
}