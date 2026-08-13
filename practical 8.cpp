#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // DFS
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V, E;

    cout << "===== GRAPH TRAVERSAL USING DAA =====\n";

    cout << "\nEnter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "\nEnter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Check valid vertices
        if (u >= 0 && u < V && v >= 0 && v < V) {
            g.addEdge(u, v);
        } else {
            cout << "Invalid edge! Enter vertices between 0 and "
                 << V - 1 << ".\n";
            i--;
        }
    }

    int start;

    cout << "\nEnter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= V) {
        cout << "Invalid starting vertex!\n";
        return 0;
    }

    // ---------------- DFS ----------------

    auto startDFS = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    g.DFS(start);

    auto endDFS = high_resolution_clock::now();

    auto dfsTime =
        duration_cast<nanoseconds>(endDFS - startDFS);

    // ---------------- BFS ----------------

    auto startBFS = high_resolution_clock::now();

    cout << "\n\nBFS Traversal: ";
    g.BFS(start);

    auto endBFS = high_resolution_clock::now();

    auto bfsTime =
        duration_cast<nanoseconds>(endBFS - startBFS);

    // ---------------- RESULTS ----------------

    cout << "\n\n========== DAA ANALYSIS ==========\n";

    cout << "\nNumber of Vertices (V): " << V;
    cout << "\nNumber of Edges (E): " << E;

    cout << "\n\nDFS Execution Time: "
         << dfsTime.count() << " ns";

    cout << "\nBFS Execution Time: "
         << bfsTime.count() << " ns";

    // Time Complexity
    cout << "\n\n----- Time Complexity -----";

    cout << "\nDFS: O(V + E)";
    cout << "\nBFS: O(V + E)";

    // Space Complexity
    cout << "\n\n----- Space Complexity -----";

    cout << "\nDFS: O(V)";
    cout << "\nBFS: O(V)";

    // Cases
    cout << "\n\n----- Case Analysis -----";

    cout << "\nDFS Best Case:    O(V + E)";
    cout << "\nDFS Average Case: O(V + E)";
    cout << "\nDFS Worst Case:   O(V + E)";

    cout << "\n\nBFS Best Case:    O(V + E)";
    cout << "\nBFS Average Case: O(V + E)";
    cout << "\nBFS Worst Case:   O(V + E)";

    cout << "\n\n==================================\n";

    return 0;
}