#include <iostream>
#include <vector>

using namespace std;
const int MAX = 19;

vector<vector<int>> board(MAX, vector<int>(MAX, 0));

int count_right(int row, int col, int flag) {
	int cnt = 0;
	for (int i = col; i < MAX; i++) {
		cout << "col";
		if (board[row][i] != flag) {
			break;
		}
		cnt++;
	}

	if (cnt == 5) {
		if (col - 1 < 0) {
			return flag;
		}
		if (board[row][col - 1] != flag) {
			return flag;
		}
	}

	cnt = 0;
	for (int i = row; i < MAX; i++) {
		cout << "row";
		if (board[i][col] != flag) {
			break;
		}
		cnt++;
	}

	if (cnt == 5) {
		if (row - 1 < 0) {
			return flag;
		}
		if (board[row - 1][col] != flag) {
			return flag;
		}
	}

	cnt = 0;
	for (int i = 0; i < MAX; i++) {
		cout << "down";
		if (row + i >= MAX || col + i >= MAX) {
			break;
		}
		if (board[row + i][col + i] != flag) {
			break;
		}
		cnt++;
	}

	if (cnt == 5) {
		
		if (row == 0) {
			return flag;
		}
		if (col == 0) {
			return flag;
		}
		/*if (col - 1 < 0 && row - 1 < 0) {
			return flag;
		}*/
		if (board[row - 1][col - 1] != flag) {
			return flag;
		}
	}

	cnt = 0;
	for (int i = 0; i < MAX; i++) {
		cout << "up";
		if (row - i < 0 || col + i >= MAX) {
			break;
		}
		if (board[row - i][col + i] != flag) {
			break;
		}
		cnt++;
	}

	if (cnt == 5) {
		if (row == MAX - 1) {
			return flag;
		}
		if (col == 0) {
			return flag;
		}
		if (board[row + 1][col - 1] != flag) {
			return flag;
		}
	}

	return 0;
}

void game() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (board[i][j] == 0) {
				continue;
			}
			int k = count_right(i, j, board[i][j]);
			if (k == 1 || k == 2) {
				cout << board[i][j] << '\n';
				cout << i + 1  << ' ' << j + 1;
				return;
			}
		}
	}
	cout << "0";
}

int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> board[i][j];
		}
	}

	game();

	return 0;
}