#include <iostream>
using namespace std;

int minKey(int key[], bool mp[], int V) {
    int min = 99999; 
    int min_index;

    for (int v = 0; v < V; v++) {
        if (!mp[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int **graph, int V) {
    int parent[V]; 
    int key[V];   
    bool mp[V];  
	int total_weight = 0; 

    for (int i = 0; i < V; i++) {
        key[i] = 99999;
        mp[i] = false;
        parent[i] = -1; 
    }

    key[0] = 0; 
 
    for (int count = 0; count < V - 1; count++) {
        
        int u = minKey(key, mp, V);

        mp[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mp[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << " \n";
		 total_weight += graph[i][parent[i]];
    }
      cout << "Total weight of MST: " << total_weight << endl;

}

int main() {
  int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

   
    int** graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
    }

 
    cout << "Enter the  matrix of the graph (enter 0 for no connection):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }


    primMST(graph, V);
    return 0;
}
