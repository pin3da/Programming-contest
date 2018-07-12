class NestedIterator {
  int current;
  vector<int> flat;
  void Flat(vector<NestedInteger>& nestedList, vector<int>& flatten) {
    for (auto it : nestedList) {
      if (!it.isInteger()) Flat(it.getList(), flatten);
      else flatten.push_back(it.getInteger());
    }
  }

  public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    Flat(nestedList, flat);
    current = 0;
  }

  int next() {
    return flat[current++];
  }

  bool hasNext() {
    return current < flat.size();
  }
};
