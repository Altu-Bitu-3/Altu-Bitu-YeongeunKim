#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

map<char, int> row;
map<char, int> column;
ci king;
ci rock;

void move(string cmd) {
	map<string, ci> dir;
	dir["R"] = { 0, 1 };
	dir["L"] = { 0, -1 };
	dir["B"] = { 1, 0 };
	dir["T"] = { -1, 0 };
	dir["RT"] = { -1, 1 };
	dir["LT"] = { -1, -1 };
	dir["RB"] = { 1, 1 };
	dir["LB"] = { 1, -1 }; //각 명령에 대한 방향 정보

	ci m = dir[cmd];
	if (king.first + m.first < 0 || king.first + m.first > 7 || king.second + m.second < 0 || king.second + m.second > 7) {
		//킹의 자리가 체스판을 벗어나면 무시
		return;
	}
	
	//킹의 위치 갱신
	king.first += m.first;
	king.second += m.second;

	if (king.first == rock.first && king.second == rock.second) {
		//돌의 자리가 체스판을 벗어나면 킹의 자리를 원래 위치로 돌리고 무시
		if (rock.first + m.first < 0 || rock.first + m.first > 7 || rock.second + m.second < 0 || rock.second + m.second > 7) {
			king.first -= m.first;
			king.second -= m.second;
			return;
		}
		//아니라면 돌도 이동
		rock.first += m.first;
		rock.second += m.second;
	}

	return;
}

int main() {
	string k, r;
	int n;
	cin >> k >> r >> n;

	//각 위치에 대한 정보
	row['8'] = 0, row['7'] = 1, row['6'] = 2, row['5'] = 3, row['4'] = 4, row['3'] = 5, row['2'] = 6, row['1'] = 7;
	column['A'] = 0, column['B'] = 1, column['C'] = 2, column['D'] = 3, column['E'] = 4, column['F'] = 5, column['G'] = 6, column['H'] = 7;

	king = { row[k[1]], column[k[0]] };
	rock = { row[r[1]], column[r[0]] };

	while (n--) {
		//각 명령에 대해 이동
		string cmd;
		cin >> cmd;
		move(cmd);
	}

	string king_loca = "", rock_loca = "";
	
	//맵을 돌며 킹과 돌의 위치 저장
	for_each(column.begin(), column .end(), [&](pair<char, int> itr) {
		if (itr.second == king.second) {
			king_loca += itr.first;
		}
		if (itr.second == rock.second) {
			rock_loca += itr.first;
		}
	});

	for_each(row.begin(), row.end(), [&](pair<char, int> itr) {
		if (itr.second == king.first) {
			king_loca += itr.first;
		}
		if (itr.second == rock.first) {
			rock_loca += itr.first;
		}
	});

	cout << king_loca << '\n' << rock_loca;

	return 0;
}