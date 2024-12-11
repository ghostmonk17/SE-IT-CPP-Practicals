/* Assignment 8 – Shortest Path
AIM: Implementation of Dijikstra’s Algorithm 

Represent a given graph using adjacency matrix /adjacency list and find the shortest path using 
Dijkstra's algorithm (single source all destination). */

#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

int findMinDistance(int dist[], bool S[], int n) {
    int minDist = INT_MAX, minIndex;

    for (int v = 0; v < n; v++) {
        if (!S[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int prev[], int vertex) {
    if (prev[vertex] == -1) {
        cout << vertex;
        return;
    }
    printPath(prev, prev[vertex]);
    cout << " -> " << vertex;
}

void Dijkstra(int cost[MAX][MAX], int dist[], int prev[], int n, int source) {
    bool S[MAX] = {false};

    for (int i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        prev[i] = (dist[i] != INT_MAX && i != source) ? source : -1;
        S[i] = false;
    }

    dist[source] = 0;
    S[source] = true;

    for (int count = 1; count < n; count++) {
        int u = findMinDistance(dist, S, n);
        S[u] = true;

        for (int w = 0; w < n; w++) {
            if (!S[w] && cost[u][w] != INT_MAX && dist[u] != INT_MAX && dist[u] + cost[u][w] < dist[w]) {
                dist[w] = dist[u] + cost[u][w];
                prev[w] = u;
            }
        }
    }
}

void display(int dist[], int prev[], int n, int source) {
    cout << "Vertex\tDistance from Source (" << source << ")\tPath\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t\t" << dist[i] << "\t\t\t";
        if (dist[i] == INT_MAX) {
            cout << "No path";
        } else {
            printPath(prev, i);
        }
        cout << endl;
    }
}

int main() {
    int n, source;
    int cost[MAX][MAX], dist[MAX], prev[MAX];

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the cost adjacency matrix (enter 9999 for no direct edge): "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 9999) {
                cost[i][j] = INT_MAX;
            }
        }
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    Dijkstra(cost, dist, prev, n, source);

    display(dist, prev, n, source);

    return 0;
}

/* OUTPUT:

Enter the number of vertices: 4
Enter the cost adjacency matrix (enter 9999 for no direct edge):
0 3 9999 7
3 0 1 9999
9999 1 0 2
7 9999 2 0
Enter the source vertex: 0
Vertex  Distance from Source (0)        Path
0               0                       0
1               3                       0 -> 1
2               4                       0 -> 1 -> 2
3               6                       0 -> 1 -> 2 -> 3
*/
