class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
      int best = 0;
      int current_height = 0;
      int n = heights.size();
      deque<pair<int, int>> last_position;
      for (int i = 0; i < heights.size(); i++) {
        if (heights[i] > current_height) {
          last_position.emplace_back(heights[i], i);
        } else {
          int further = i;
          while (last_position.size() && last_position.back().first > heights[i]) {
            int last_h = last_position.back().first;
            int last_p = last_position.back().second;
            further = min(further, last_p);
            last_position.pop_back();
            best = max(best, (i - last_p) * last_h);
          }
          last_position.emplace_back(heights[i], further);
        }
        current_height = heights[i];
      }

      while (last_position.size()) {
        int last_h = last_position.back().first;
        int last_p = last_position.back().second;
        last_position.pop_back();
        best = max(best, (n - last_p) * last_h);
      }

      return best;
    }
};
