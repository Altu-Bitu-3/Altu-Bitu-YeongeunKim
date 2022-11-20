#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_time = 2e9;
int max_height = -1;

//높이가 h일 때 걸리는 시간 계산하는 함수
void calTime(vector<int> land, int height, int n, int m, int b) {
	int time = 0;
	//다른 블록에서 남으면 인벤토리에 저장할 수 있기 때문에 값이 큰 블록부터 접근
	sort(land.begin(), land.end(), greater<>());

	for (int j = 0; j < n * m; j++) {
		if (land[j] == height) continue;  //높이가 같으면 패스

		//높이가 더 높으면 시간과 남는 블록의 개수 조정
		if (land[j] > height) {
			time += (land[j] - height) * 2;
			b += land[j] - height;
			continue;
		}
		//만약 부족한만큼 채울 수 없으면 바로 리턴
		if (height - land[j] > b) return;

		//채울 수 있는 경우 시간과 블록 개수 조정
		time += height - land[j];
		b -= height - land[j];
	}

	//같은 시간이라면 가장 높이가 높을 때의 시간을 구해야하므로
	//조건을 작거나 같을 때로 설정
	if (time <= min_time) {
		min_time = time;
		max_height = height;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, b;
	cin >> n >> m >> b;
	vector<int> land(n*m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> land[i * m + j];
		}
	}
	
	sort(land.begin(), land.end());
	
	for (int i = 0; i < 257; i++) {
		calTime(land, i, n, m, b);
	}

	cout << min_time << ' ' << max_height;

	return 0;
}