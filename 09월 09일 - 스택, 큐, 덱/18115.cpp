#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;
	vector<long long int> arr(n+1);  //기술 저장을 위한 벡터 선언
	deque<long long int> q;  //실제 출력 값을 저장할 덱

	//벡터에 입력되는 기술의 번호 역순으로 저장
	for (int i = n; i >= 1; i--) {
		cin >> k;
		arr[i] = k;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {  //기술 번호가 1이면 제일 앞에 인덱스 값을 삽입
			q.push_front(i);
			continue;
		}
		if (arr[i] == 2) {  //기술 번호가 2면 앞에서 두번째에 인덱스 값 삽입
			long long int tmp = q.front();
			q.pop_front();  //인덱스로 접근 불가하므로 제일 앞에 값을 저장해두었다가 삭제
			q.push_front(i);
			q.push_front(tmp);  //현재 인덱스 값을 넣고 그 앞에 저장했던 값을 삽입
			continue;
		}
		if (arr[i] == 3) {  //기술 번호가 3이면 제일 뒤에 인덱스 값 삽입
			q.push_back(i);
			continue;
		}
	}

	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop_front();
	}

	return 0;
}