#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 2e5;

void floydWarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& minNode) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int cost = graph[i][k] + graph[k][j];
				if (cost >= graph[i][j]) {
					//현재 그래프 값보다 작으면 갱신 안 함
					continue;
				}
				//i - (t) - k - j 경로이므로 첫 번째로 방문하게 되는 노드값 갱신
				minNode[i][j] = minNode[i][k];
				//그래프 갱신
				graph[i][j] = cost;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
	vector<vector<int>> minNode(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		//무향 그래프이므로 양쪽 값 전부 갱신
		graph[a][b] = min(graph[a][b], w);
		graph[b][a] = graph[a][b];
		//첫 방문 노드 초기화
		minNode[a][b] = b;
		minNode[b][a] = a;
	}

	floydWarshall(n, graph, minNode);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (minNode[i][j] == 0) cout << '-';
			else cout << minNode[i][j];
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}