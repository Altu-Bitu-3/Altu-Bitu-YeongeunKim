#include <iostream>
#include <vector>
#include <algorithm>

//참고한 사이트 https://bit.ly/3C3fVpb
//max 함수 인자 여러 개 넣는 법 참고

using namespace std;

void dp(vector<vector<int>> &arr, int n, int m) {
	//리스트를 1, 1부터 n, m까지 돌면서
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] += max({ arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1] });
			//올 수 있는 경로의 최댓값과 현재 값을 더해줌
		}
	}

	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	//값 저장하기 위한 배열
	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));

	//0, 0부터가 아닌 1,1부터 저장하면 dp구현이 쉬우므로
	//1, 1부터 값 저장 (1열과 1행의 이전 값인 0번째 열과 행에도 접근 가능)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	dp(arr, n, m);
	cout << arr[n][m];

	return 0;
}