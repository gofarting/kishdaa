#include <iostream>

using namespace std;

void start(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findparent(int parent[], int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findparent(parent, parent[node]);
}

void unionset(int u, int v, int parent[], int rank[]) {
    u = findparent(parent, u);
    v = findparent(parent, v);
    
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int partition(int src[], int dest[], int weight[], int low, int high) {
    int pivot = weight[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (weight[j] < pivot) {
            i++;
            swap(src[i], src[j]);
            swap(dest[i], dest[j]);
            swap(weight[i], weight[j]); 
        }
    }
    swap(src[i + 1], src[high]);
    swap(dest[i + 1], dest[high]);
    swap(weight[i + 1], weight[high]);
    return i + 1;
}


void quickSort(int src[], int dest[], int weight[], int low, int high) {
    if (low < high) {
        int pi = partition(src, dest, weight, low, high);  
        quickSort(src, dest, weight, low, pi - 1);
        quickSort(src, dest, weight, pi + 1, high);
    }
}

void kruskal(int n, int src[], int dest[], int weight[], int e) {
    int parent[n], rank[n];
    start(parent, rank, n);

    quickSort(src, dest, weight, 0, e - 1);

    int result[n][3];  
    int resultIndex = 0;

    for (int i = 0; i < e; i++) {
        int u = src[i];
        int v = dest[i];

    
        if (findparent(parent, u) != findparent(parent, v)) {
            unionset(u, v, parent, rank);
            result[resultIndex][0] = u; 
            result[resultIndex][1] = v;  
            result[resultIndex][2] = weight[i];  
            resultIndex++;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    int minimumCost = 0;
    for (int i = 0; i < resultIndex; i++) {
        cout << result[i][0] << " - " << result[i][1] << " == " << result[i][2] << endl;
        minimumCost += result[i][2];
    }
    cout << "Minimum Cost: " << minimumCost << endl;
}

int main() {
    int n;  
    cout << "Enter the number of vertices: ";
    cin >> n;

    int adj[n][n];

    cout << "Enter the  matrix (use 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int src[n * n], dest[n * n], weight[n * n];
    int e = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  
            if (adj[i][j] != 0) {
                src[e] = i;
                dest[e] = j;
                weight[e] = adj[i][j];
                e++;
            }
        }
    }

    kruskal(n, src, dest, weight, e);

    return 0;
}











