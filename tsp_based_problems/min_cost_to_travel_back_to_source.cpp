#include <bits/stdc++.h>
using namespace std;

class TSPSolver {
    int n;
    vector<vector<int>> cost;

public:
    TSPSolver(int cities, vector<vector<int>> matrix) {
        n = cities;
        cost = matrix;
    }

    int bfs_tsp() {
        queue<pair<int, pair<int, int>>> q; // {cost, {city, mask}}
        q.push({0, {0, 1}}); // Start from city 0 with only city 0 visited

        map<pair<int, int>, int> visited; // {city, mask} → cost
        visited[{0, 1}] = 0;

        int min_cost = INT_MAX;

        while (!q.empty()) {
            auto [curr_cost, state] = q.front();
            int city = state.first, mask = state.second;
            q.pop();

            if (mask == (1 << n) - 1) { // All cities visited
                min_cost = min(min_cost, curr_cost + cost[city][0]); // Return to start
                continue;
            }

            for (int next = 0; next < n; next++) {
                if (!(mask & (1 << next))) { // If city 'next' is not visited
                    int new_mask = mask | (1 << next);
                    int new_cost = curr_cost + cost[city][next];

                    if (visited.find({next, new_mask}) == visited.end() || visited[{next, new_mask}] > new_cost) {
                        visited[{next, new_mask}] = new_cost;
                        q.push({new_cost, {next, new_mask}});
                    }
                }
            }
        }

        return min_cost;
    }
};

int main() {
    vector<vector<int>> costMatrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    TSPSolver tsp(4, costMatrix);
    cout << "Minimum Cost for TSP: " << tsp.bfs_tsp() << endl;
    return 0;
}
