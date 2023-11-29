#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(vector<vector<int>>& graph, int start) {
    int nodes = graph.size();
    vector<int> distance(nodes, INF);
    vector<bool> visited(nodes, false);

    distance[start] = 0;

    for (int i = 0; i < nodes - 1; ++i) {
        int minDist = INF, minIndex = -1;
        for (int j = 0; j < nodes; ++j) {
            if (!visited[j] && distance[j] < minDist) {
                minDist = distance[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) {
            break;
        }

        visited[minIndex] = true;

        for (int j = 0; j < nodes; ++j) {
            if (!visited[j] && graph[minIndex][j] != INF &&
                distance[minIndex] != INF &&
                distance[minIndex] + graph[minIndex][j] < distance[j]) {
                distance[j] = distance[minIndex] + graph[minIndex][j];
            }
        }
    }

    cout << "Shortest distances from node " << start << " to other nodes:\n";
    for (int i = 0; i < nodes; ++i) {
        cout << "Node " << i << ": " << distance[i] << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 4, 2, INF, INF},
        {INF, 0, 5, 10, INF},
        {INF, INF, 0, INF, 3},
        {INF, INF, INF, 0, 4},
        {INF, INF, INF, INF, 0}
    };

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    dijkstra(graph, startNode);

    return 0;
}
