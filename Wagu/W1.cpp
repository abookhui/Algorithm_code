#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 200000;

vector<int> parent(MAX_N + 1); // 부모 노드 저장
vector<int> depth(MAX_N + 1); // 각 노드의 깊이 저장

// 트리 초기화
void initTree(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        depth[i] = 0;
    }
}

// 루트 노드 찾기
int findRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}

// 노드 합치기
void unionNodes(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a != b) {
        if (depth[a] < depth[b]) swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b]) depth[a]++;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    initTree(n);

    for (int i = 0; i < q; ++i) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 0) {
            // 노드 합치기
            unionNodes(a, b);
        } else {
            // b가 a의 조상인지 확인
            if (findRoot(a) == findRoot(b)) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }

    return 0;
}