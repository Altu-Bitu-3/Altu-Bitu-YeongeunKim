#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> v;  //들어오는 입력 저장할 벡터

//후위 순회 출력할 함수
//어떤 한 노드와 해당 노드에 속한 서브트리의 마지막 인덱스를 받아옴
void postorder(int node, int tr) {
	if (node >= tr) return;  //범위 벗어나면 리턴
	int i;
	for (i = node + 1; i < tr; i++) {
		//노드 + 1 -> 왼쪽 자식 노드부터 검사하며 
		//오른쪽 자식 노드가 시작되는 지점을 찾음(노드보다 v[i]의 값이 커지는 순간)
		if (v[i] > v[node]) break;
	}

	//후위 순회기 때문에 왼쪽 자식노드 호출 후 오른쪽 자식노드 호출
	postorder(node + 1, i);
	postorder(i, tr);
	//마지막으로 현재 노드 출력
	cout << v[node] << '\n';
}

int main() {
	int k;
	
	while (cin >> k) {
		v.push_back(k);
	}

	//첫 입력으로 루트 노드와 트리의 크기
	postorder(0, v.size());

	return 0;
}