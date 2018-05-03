#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

using namespace std;

class AllOne {

  unordered_map<string, int> values;
  list<unordered_set<string>> sets_by_value;
  unordered_map<int, list<unordered_set<string>>::iterator> value_to_it;

  void remove_key(string key, int value) {
    auto it = value_to_it[value];
    it->erase(key);
    if (it->size() == 0) {
      sets_by_value.erase(it);
      value_to_it.erase(value);
    }
  }

  void add_key(string key, int value, list<unordered_set<string>>::iterator pos) {
    if (value_to_it.count(value)) {
      auto it = value_to_it[value];
      it->insert(key);
    } else {
      unordered_set<string> current_set;
      current_set.insert(key);
      auto current_it = sets_by_value.insert(pos, current_set);
      value_to_it[value] = current_it;
    }
  }

  public:
  AllOne() {}

  void inc(string key) {
    if (values.count(key)) {
      int current = values[key];
      auto pos = value_to_it[current];
      pos++;
      add_key(key, current + 1, pos);
      remove_key(key, current);
    } else {
      add_key(key, 1, sets_by_value.begin());
    }
    values[key]++;
  }

  void dec(string key) {
    if (values.count(key) == 0) {
      return;
    }

    int current = values[key];
    auto pos = value_to_it[current];
    if (pos != sets_by_value.begin() && value_to_it.count(current - 1)) pos--;

    if (current > 1) {
      add_key(key, current - 1, pos);
    }

    remove_key(key, current);

    values[key]--;
    if (values[key] == 0)
      values.erase(key);
  }

  string getMaxKey() {
    if (values.size() == 0)
      return "";
    return *sets_by_value.back().begin();
  }

  string getMinKey() {
    if (values.size() == 0)
      return "";
    return *sets_by_value.front().begin();
  }
};

