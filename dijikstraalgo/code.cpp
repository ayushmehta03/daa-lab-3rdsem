#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> dijkstraAlgo(vector<pair<int, int>> adj[], vector<int>& dis, int src, int n) {

    // mark the soruce as 0
    dis[src] = 0;


    // declaring the priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // pushing the src value
    pq.push({0, src});

    while (!pq.empty()) {

        // grab the top element
        auto it = pq.top();
        // pop out from queue
        pq.pop();

        // take the distance and the nnode
        int distance = it.first;
        int node = it.second;

        // iterating through the adjacnet node 
        for (auto it : adj[node]) {
            // tkae the node and weight
            int adjNode = it.first;
            int weight = it.second;
            // if the current distance is less than the stored one
            if (distance + weight < dis[adjNode]) {
                dis[adjNode] = distance + weight;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    // return the distance 
    return dis;
}

int main() {
    // declaring the edges start end and weight
    vector<vector<int>> edges = {
        {0, 2, 4},
        {0, 1, 3},
        {1, 3, 2},
        {2, 3, 1},
        {3, 4, 3},
        {3, 5, 6},
        {4, 5, 5}
    };

    int n = 6; // total nodes

    // adjacency list creation
    vector<pair<int, int>> adj[n];
    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]}); 
    }

    // distance vector for storing min distance
    vector<int> dis(n, 1e9);
    // calling the function for getting the min distnace from the source 

    vector<int> ans = dijkstraAlgo(adj, dis, 0, n);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "0 -> " << i << " = " << ans[i] << endl;
    }

    return 0;
}
