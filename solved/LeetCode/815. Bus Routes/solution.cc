class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    if (source == target) {
      return 0;
    }

    const int max_stops = 1000000 + 10;
    const int inf_dist = routes.size() + 10;
    initDistances(routes.size(), inf_dist);

    vector<set<int>> bus_by_stop(max_stops);

    for (int bus = 0; bus < routes.size(); bus++) {
      for (int stop : routes[bus]) {
        bus_by_stop[stop].insert(bus);
      }
    }

    for (const auto &buses : bus_by_stop) {
      for (int from : buses) {
        for (int to : buses) {
          if (from != to) {
            dist[from][to] = 1;
            dist[to][from] = 1;
          }
        }
      }
    }

    fillTransitiveDistance();

    int best = inf_dist;
    for (int first : bus_by_stop[source]) {
      for (int last : bus_by_stop[target]) {
        best = min(best, dist[first][last]);
      }
    }

    return (best == inf_dist) ? -1 : best + 1;
  }

private:
  void initDistances(int num_buses, int inf_dist) {
    dist.resize(num_buses);
    for (auto &neigh : dist) {
      neigh.assign(num_buses, inf_dist);
    }
    for (int i = 0; i < num_buses; i++) {
      dist[i][i] = 0;
    }
  }

  void fillTransitiveDistance() {
    for (int k = 0; k < dist.size(); k++) {
      for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist.size(); j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  vector<vector<int>> dist;
};
