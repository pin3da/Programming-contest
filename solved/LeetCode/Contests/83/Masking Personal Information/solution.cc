class Solution {

  string maskName(string S) {
    string ans(7, '*');
    ans[0] = tolower(S[0]);
    ans[6] = tolower(S.back());
    return ans;
  }

  string maskEmail(string S) {

    string second = S.substr(S.find("@"));
    string first = S.substr(0, S.size() - second.size());

    for (auto &i : second) {
      i = tolower(i);
    }

    string ans = maskName(first) + second;
    return ans;
  }

  string maskPhone(string S) {
    deque<char> numbers;
    for (auto i : S) {
      if (isdigit(i))
        numbers.push_back(i);
    }

    string ans;

    if (numbers.size() > 10) {
      int extra = numbers.size() - 10;

      ans += "+" + string(extra, '*') + "-";
      while (extra--)
        numbers.pop_front();
    }

    ans += "***-***-";
    while (numbers.size() > 4)
      numbers.pop_front();

    for (auto i : numbers)
      ans += i;
    return ans;
  }
  public:
  string maskPII(string S) {
    if (S.find("@") != string::npos)
      return maskEmail(S);
    return maskPhone(S);
  }
};
