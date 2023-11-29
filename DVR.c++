#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max(); // Represents infinity
// Function to perform distance vector routing
void distanceVectorRouting(vector<vector<int>>& graph, int nodes) {
    vector<vector<int>> distance = graph; // Initializing distance vector
    // Applying the distance vector algorithm
    for (int k = 0; k < nodes; ++k) {
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    // Displaying the final distance matrix
    cout << "Distance Vector Table:\n";
    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < nodes; ++j) {
            if (distance[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    vector<vector<int>> graph(nodes, vector<int>(nodes));

    cout << "Enter the adjacency matrix (use INF for unreachable nodes):\n";
    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < nodes; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                graph[i][j] = INF;
            }
        }
    ]
    distanceVectorRouting(graph, nodes);
    return 0;
}
