// Assignment 7- Minimum Spanning tree
// AIM : Implementation of Minimum Spanning tree using Kruskals Algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int v1, v2, wt;
};

const int MAX = 100; 
vector<Edge> edges;

int findSet(int v, vector<int>& parent) {
    if (parent[v] != v) {
        parent[v] = findSet(parent[v], parent);  
    }
    return parent[v];
}

void unionSets(int v1, int v2, vector<int>& parent, vector<int>& rank) {
    int root1 = findSet(v1, parent);
    int root2 = findSet(v2, parent);
    if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

bool compareEdge(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

 

void Kruskal(int V) {
    vector<int> parent(V), rank(V, 0);
    int mincost = 0;

    for (int i = 0; i < V; i++) parent[i] = i;
 
    sort(edges.begin(), edges.end(), compareEdge);

    cout << "Edges in the Minimum Spanning Tree and their paths:" << endl;
    int edgeCount = 0;
    for (size_t i = 0; i < edges.size(); i++) {
        const Edge& edge = edges[i];
        int set1 = findSet(edge.v1, parent);
        int set2 = findSet(edge.v2, parent);

        if (set1 != set2) {   
            cout << edge.v1 << " - " << edge.v2 << " : " << edge.wt << endl;

            mincost += edge.wt;
            unionSets(set1, set2, parent, rank);
            edgeCount++;
            if (edgeCount == V - 1) break;  
        }
    }
    cout << "Minimum cost of the spanning tree: " << mincost << endl;
}

int main() {
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (vertex1 vertex2 weight):" << endl;
    for (int i = 0; i < E; i++) {
        Edge edge;
        cin >> edge.v1 >> edge.v2 >> edge.wt;
        edges.push_back(edge);
    }

    Kruskal(V);
    return 0;
}


/* OUTPUT:

Enter the number of vertices: 4
Enter the number of edges: 5
Enter the edges (vertex1 vertex2 weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Edges in the Minimum Spanning Tree and their paths:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
Minimum cost of the spanning tree: 19
  */
