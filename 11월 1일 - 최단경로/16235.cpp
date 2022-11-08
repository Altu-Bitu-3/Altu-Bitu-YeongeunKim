#include <iostream>  //입출력 헤더
#include <deque>  //덱 헤더
#include <vector>  //벡터 헤더

using namespace std;  //std 라이브러리
typedef vector<vector<int>> matrix;  //2차원 배열 선언 짧게

int countTrees(int n, vector<deque<int>>& trees) {  //나무의 개수 세는 함수
	int answer = 0;  //0부터 시작
	for (int i = 0; i < n; i++)  //0부터 n - 1까지
	{ 
		for (int j = 0; j < n; j++)  //0부터 n - 1까지
		{
			answer += trees[i * 10 + j].size();  //i행 j열의 덱에 들어있는 나무 개수 더하기
		}
	}
	return answer;  //개수 값을 리턴
}

void reproduceTree(int n, int x, int y, vector<deque<int>>& trees)  //나무 번식
{
	for (int i = x - 1; i <= x + 1; i++)  //i - 1행부터 i + 2행까지
	{
		for (int j = y - 1; j <= y + 1; j++)  //j - 1열부터 j + 1열까지
		{
			if ((i == x) && (j == y)) {  //i, j인 경우
				continue;  //같은 자리에는 번식하지 않음
			}
			if (i >= 0 && j >= 0 && i < n && j < n)  //i, j 아닐 경우에
			{
				trees[i * 10 + j].push_front(1);  //나이가 1인 나무 추가
			}
		}
	}
}
void solution(int n, vector<deque<int>>& trees, matrix& food, matrix& a, vector<pair<int, int>>& breeding_tree)  //전체 계절을 반복하는 함수
{
	for (int i = 0; i < n; i++)  //0행부터 n - 1행까지
	{
		for (int j = 0; j < n; j++)  //0열부터 n - 1열까지
		{
			int leftover = 0;  //여름에 양분이 되는 값
			deque<int> dq;  //덱 선언
			for (auto age : trees[i * 10 + j])  //i행 j열에 있는 나무에 접근
			{
				if (food[i][j] < age) { //양분을 먹을 수 없다
					leftover += age / 2;  //나무가 죽게 됨. leftover에 죽은 나무 나이 / 2만큼 추가
					continue;  //죽으면 여기까지만 실행
				}
				food[i][j] -= age;  //먹을 수 있다면 해당 땅의 양분에서 age만큼 빼줌
				dq.push_back(age + 1); //나이를 1 증가시킨다
				if ((age + 1) % 5 == 0)// 번식 가능하다
				{
					breeding_tree.push_back({ i, j });  //번식 벡터에 해당 열과 행 저장
				}
			}
			trees[i * 10 + j] = dq;  //i행 j열 트리를 현재 변화한 덱으로 업데이트
			food[i][j] += (a[i][j] + leftover);  //겨울에 양분 추가
		}
	}
}
/**16235 나무 재테크
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * A : 로봇(S2D2)가 겨울에 주는 양분의 양
 * food : 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */
int main()
{
	int n, m, k;  //입력을 위한 변수
	cin >> n >> m >> k;  //입력
	matrix a(n, vector<int>(n, 0));  //매년 추가되는 양분 배열
	matrix food(n, vector<int>(n, 5));  //기본 땅 양분 배열
	vector<deque<int>> trees(n * 10 + n);  //i행 j열에 들어가는 트리 덱

	for (int i = 0; i < n; i++)  //0행부터 n - 1행까지
	{
		for (int j = 0; j < n; j++)  //0열부터 n - 1열까지
		{
			cin >> a[i][j];  //a에 들어갈 양분 입력
		}
	}
	for (int i = 0, x, y, z; i < m; i++)  //m개의 나무 입력 받기
	{
		cin >> x >> y >> z;  //행, 열, 나이 입력
		x--; y--;  //트리 배열은 0행 0열부터 시작하기 때문에 1씩 감소
		trees[x * 10 + y].push_front(z);  //해당 위치에 나무 삽입
	}
	while (k--) {  //k해동안 반복
		vector<pair<int, int>> breeding_tree;  //번식하는 나무를 위한 배열
		solution(n, trees, food, a, breeding_tree);  //1년동안의 과정 반복
		for (auto[i, j] : breeding_tree)  //번식하는 나무가 있는 행, 열에 대해
		{
			reproduceTree(n, i, j, trees);  //번식하는 함수 시행
		}
	}
	cout << countTrees(n, trees);  //최종 결과 출력
	return 0;
}