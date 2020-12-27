void print(std::ostream& out) { out << std::endl; }

template <typename T, typename T2>
void printOne(std::ostream& out, const std::pair<T, T2>& a) {
  out << "{" << a.first << ", " << a.second << "}";
}

template <typename T>
void printOne(std::ostream& out, const T& a) {
  out << a;
}

template <typename T>
void printOne(std::ostream& out, const std::vector<T>& a) {
  out << "{";
  for (int i = 0; i < a.size(); i++) {
    if (i) out << ", ";
    printOne(out, a[i]);
  }
  out << "}";
}

template <typename T>
void printOne(std::ostream& out, const std::deque<T>& a) {
  out << "{";
  for (int i = 0; i < a.size(); i++) {
    if (i) out << ", ";
    printOne(out, a[i]);
  }
  out << "}";
}


template <typename T, typename  V>
void printOne(std::ostream& out, const std::map<T, V>& a) {
  out << "{";
  for (auto [key, val] : a) {
    out << "["; printOne(out, key); out << " = "; printOne(out, val); out << "],";
  }
  out << "}";
}


template <typename T, typename... Tail>
void print(std::ostream& out, const T& first, const Tail... tail) {
  printOne(out, first);
  if (sizeof...(tail) != 0) {
    out << ", ";
  }
  print(out, tail...);
}

#ifdef LOCAL_CP
#define debug(...) \
    std::cerr << "[DEBUG] [" << #__VA_ARGS__ << "] = ", print(std::cerr, __VA_ARGS__)
#else
#define debug(...) 0
#endif
