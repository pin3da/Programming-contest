class Solution {
  bool isOperator(const string &s) {
    if (s == "+" || s == "*" || s == "-" || s == "/")
      return true;
    return false;
  }

  int compute(int a, int b, string op) {
    if (op == "+") return a + b;
    if (op == "*") return a * b;
    if (op == "-") return a - b;
    if (op == "/") return a / b;
    assert(false);
    return 0;
  }

  public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto token : tokens) {
      if (isOperator(token)) {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        int ans = compute(first, second, token);
        st.push(ans);
      } else {
        int number = stoi(token);
        st.push(number);
      }
    }
    int result = st.top();
    return result;
  }
};
