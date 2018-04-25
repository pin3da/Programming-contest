class LRUCache {
  int capacity, cur_time;
  map<int, int> values;
  set<pair<int, int>> ttl;
  map<int, int> cur_ttl;

  void update_ttl(int key) {
    cur_time++;
    int old_time = cur_ttl[key];
    cur_ttl[key] = cur_time;
    ttl.erase({old_time, key});
    ttl.insert({cur_time, key});
  }

  public:
  LRUCache(int cap) {
    capacity = cap;
    cur_time = 0;
  }

  int get(int key) {
    if (values.count(key) == 0) {
      return -1;
    }
    update_ttl(key);
    return values[key];
  }

  void put(int key, int value) {
    if (values.count(key)) {
      update_ttl(key);
      values[key] = value;
      return;
    }

    while (values.size() >= capacity) {
      auto it = ttl.begin();
      values.erase(it->second);
      cur_ttl.erase(it->second);
      ttl.erase(it);
    }

    cur_time++;
    values[key] = value;
    cur_ttl[key] = cur_time;
    ttl.insert({cur_time, key});
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
