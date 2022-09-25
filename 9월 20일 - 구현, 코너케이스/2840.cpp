#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool rot(vector<char>& arr, int index, char c) {
	if (arr[index] == c) {
		//인덱스 자리에 입력값과 같은 값이 있으면 패스
		return true;
	}
	if (arr[index] == '?') {
		//인덱스 자리에 ?가 있으면서
		//이미 등장하지 않은 알파벳일 때 배열 업데이트
		if (find(arr.begin(), arr.end(), c) != arr.end()) {
			return false;
		}
		arr[index] = c;
		return true;
	}

	//해당하지 않을 경우 바퀴를 만들 수 없으므로 false를 리턴
	return false;
}

int main() {
	int n, k;
	cin >> n >> k;
	
	int index = 0;
	vector<char> arr(n, '?');
	while (k--) {
		int i;
		char c;
		cin >> i >> c;

		index = (i + index) % n;  //회전 수에 따라 인덱스 갱신
		if (!rot(arr, index, c)) {
			cout << '!';
			return 0;
		}  //조건 만족 못할 경우 ! 출력
	}


	//마지막 인덱스부터 시작해 역순으로 출력
	for (int i = index; i >= 0; i--) {
		cout << arr[i];
	}

	for (int i = n - 1; i > index; i--) {
		cout << arr[i];
	}
	

	return 0;
}