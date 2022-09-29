#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
const int SIZE = 8;

//https://hwan-shell.tistory.com/130 - set 출력하는 부분 참고

int n, m;
vector<int> arr(SIZE);
set<vector<int>> ans;  //중복값 없애고, 순서대로 저장하기 위한 set
vector<int> tmp;  //set에 넣을 임시 배열
vector<bool> check(SIZE, false);

void backtracking(int cnt, int index) {
	if (cnt == m) { //크기가 m일 때
		//set에 임시 배열 넣어주고 마지막 값 pop
		ans.insert(tmp);
		tmp.pop_back();
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {  //방문하지 않은 요소일 때
			tmp.push_back(arr[i]);  //임시 배열에 i번째 값 넣어줌
			check[i] = true;
			backtracking(cnt + 1, i + 1);
			check[i] = false;  //다시 돌아왔을 때 기준 돌려놓기
		}
	}
	if (!tmp.empty()) tmp.pop_back();
	return;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		arr[i] = k;
	}
	backtracking(0, 0);

	//set 첫 번째 값부터 출력
	for (auto itr = ans.begin(); itr != ans.end(); itr++) {
		for (int i = 0; i < m; i++) {
			cout << (*itr)[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}