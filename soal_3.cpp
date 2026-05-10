#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if (source == destination) return true;

    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (neighbor == destination) return true;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    // Test case 1: ada jalur
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1},{1,2},{2,0}};
    int src1 = 0, dst1 = 2;
    cout << "Test 1 - n=3, edges={{0,1},{1,2},{2,0}}, src=0, dst=2" << endl;
    cout << "Hasil  : " << (validPath(n1, edges1, src1, dst1) ? "true (ada jalur)" : "false (tidak ada jalur)") << endl;
    cout << endl;

    // Test case 2: tidak ada jalur
    int n2 = 6;
    vector<vector<int>> edges2 = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int src2 = 0, dst2 = 5;
    cout << "Test 2 - n=6, edges={{0,1},{0,2},{3,5},{5,4},{4,3}}, src=0, dst=5" << endl;
    cout << "Hasil  : " << (validPath(n2, edges2, src2, dst2) ? "true (ada jalur)" : "false (tidak ada jalur)") << endl;

    return 0;
}