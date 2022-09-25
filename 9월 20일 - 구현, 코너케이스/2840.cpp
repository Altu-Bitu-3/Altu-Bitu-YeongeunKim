#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool rot(vector<char>& arr, int index, char c) {
	if (arr[index] == c) {
		//�ε��� �ڸ��� �Է°��� ���� ���� ������ �н�
		return true;
	}
	if (arr[index] == '?') {
		//�ε��� �ڸ��� ?�� �����鼭
		//�̹� �������� ���� ���ĺ��� �� �迭 ������Ʈ
		if (find(arr.begin(), arr.end(), c) != arr.end()) {
			return false;
		}
		arr[index] = c;
		return true;
	}

	//�ش����� ���� ��� ������ ���� �� �����Ƿ� false�� ����
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

		index = (i + index) % n;  //ȸ�� ���� ���� �ε��� ����
		if (!rot(arr, index, c)) {
			cout << '!';
			return 0;
		}  //���� ���� ���� ��� ! ���
	}


	//������ �ε������� ������ �������� ���
	for (int i = index; i >= 0; i--) {
		cout << arr[i];
	}

	for (int i = n - 1; i > index; i--) {
		cout << arr[i];
	}
	

	return 0;
}