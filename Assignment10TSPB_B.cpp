#include <iostream>
#include <limits.h>

using namespace std;

void branchAndBound(int** cost, int N, int pos, int* visited, int currentPath[], int& currentCost, int& ans, int path[], int count) {
    if (count == N - 1) {
        currentCost += cost[pos][0];
        if (currentCost < ans) {
            ans = currentCost;
            for (int i = 0; i < N; i++) {
                path[i] = currentPath[i];
            }
            path[N] = 0;
        }
        currentCost -= cost[pos][0];
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0 && cost[pos][i] != 0) {
            visited[i] = 1;
            currentPath[count + 1] = i;
            currentCost += cost[pos][i];
            count++;

            branchAndBound(cost, N, i, visited, currentPath, currentCost, ans, path, count);

            count--;
            visited[i] = 0;
            currentCost -= cost[pos][i];
        }
    }
}

void tsp(int** cost, int N) {
    int* visited = new int[N];
    int ans = INT_MAX;
    int* path = new int[N + 1];
    int* currentPath = new int[N + 1];
    int currentCost = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    
    visited[0] = 1;
    currentPath[0] = 0;

    branchAndBound(cost, N, 0, visited, currentPath, currentCost, ans, path, count);

    cout << "Minimum cost: " << ans << endl;
    cout << "Path: ";
    for (int i = 0; i <= N; i++) {
        cout << path[i] + 1 << " ";
    }
    cout << endl;
}


int main() {
    int N;
    cout << "Enter the number of cities: ";
    cin >> N;

    int** cost = new int*[N];
    for (int i = 0; i < N; i++) {
        cost[i] = new int[N];
    }

    cout << "Enter the cost matrix\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    tsp(cost, N);

    return 0;
}

