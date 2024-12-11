// Assignment 7- Minimum Spanning tree
// AIM : Implementation of Minimum Spanning tree using Prims Algorithm

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 100;  
 
void Prims(int weight[MAX][MAX], int V) {
    vector<int> KNOWN(V, 0), PREV(V, -1), cost(V, INT_MAX);
    int mincost = 0;

    int current = 0;  
    cost[current] = 0;

    for (int Total_v = 0; Total_v < V - 1; ++Total_v) {
        KNOWN[current] = 1;
         
        for (int i = 0; i < V; i++) {
            if (weight[current][i] && !KNOWN[i] && weight[current][i] < cost[i]) {
                cost[i] = weight[current][i];
                PREV[i] = current;
            }
        }
 
        int minEdgeCost = INT_MAX;
        for (int i = 0; i < V; i++) {
            if (!KNOWN[i] && cost[i] < minEdgeCost) {
                minEdgeCost = cost[i];
                current = i;
            }
        }
    }
  
    cout << "\nEdges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; i++) {
        cout << PREV[i] << " - " << i << " : " << cost[i] << "   "<<endl; 
        mincost += cost[i];
    }
     
    cout << "\nMinimum cost of the spanning tree: " << mincost << endl;
}

int main() {
    int V;  
    int weight[MAX][MAX];

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the adjacency matrix (0 for no edge, large number for no direct connection):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> weight[i][j];
            if (weight[i][j] == 0 && i != j) {
                weight[i][j] = INT_MAX;   
            }
        }
    }

    Prims(weight, V);
    return 0;
}

/* OUTPUT :

Enter the number of vertices: 4
Enter the adjacency matrix (0 for no edge, large number for no direct connection):
0 10 0 30
10 0 50 0
0 50 0 20
30 0 20 0

Edges in the Minimum Spanning Tree:
0 - 1 : 10   
0 - 3 : 30   
3 - 2 : 20   

Minimum cost of the spanning tree: 60
  */
