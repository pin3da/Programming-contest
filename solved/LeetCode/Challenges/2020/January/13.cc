class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(), people.end());
      deque<int> q;
      for (auto it : people) q.push_back(it);
      
      int boats = 0;
      
      while (q.size() > 1) {
        boats++;
        int last = q.back();
        q.pop_back();
        if (last + q.front() <= limit) {
          q.pop_front();
        }
      }
      
      return boats + q.size();
    }
};
