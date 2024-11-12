#include <iostream>
#include <climits>
using namespace std;

int n; 
int** dist; 
int** dp; 
int** path; 
bool* visitedCities; 

int tsp(int pos) {
    bool allVisited = true;
    for (int i = 0; i < n; i++) {
        if (!visitedCities[i]) {
            allVisited = false;
            break;
        }
    }

    if (allVisited) {
        return dist[pos][0]; 
    }
    
    if (dp[pos][0] != -1) {
        return dp[pos][0];
    }

    int minCost = INT_MAX;

    for (int city = 0; city < n; city++) {
        if (!visitedCities[city]) {
            visitedCities[city] = true; 
            int newCost = dist[pos][city] + tsp(city);
            visitedCities[city] = false;

            if (newCost < minCost) {
                minCost = newCost;
                path[pos][0] = city; 
            }
        }
    }

    return dp[pos][0] = minCost; 
}

void printPath() {
    int pos = 0; 
    cout << "Path: " << (pos + 1) << " -> ";

    for (int i = 1; i < n; ++i) {
        pos = path[pos][0]; 
        cout << (pos + 1) << " -> ";
    }

    cout << "1" << endl;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    dist = new int*[n];
    dp = new int*[n];
    path = new int*[n];
    visitedCities = new bool[n];

    for (int i = 0; i < n; i++) {
        dist[i] = new int[n];
        dp[i] = new int[1]; 
        path[i] = new int[1];
        visitedCities[i] = false; 
    }

    cout << "Enter the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        dp[i][0] = -1; 
        path[i][0] = -1; 
    }

    visitedCities[0] = true; 
    int minCost = tsp(0); 

    cout << "Minimum cost: " << minCost << endl; 
    printPath();

    return 0;
}

