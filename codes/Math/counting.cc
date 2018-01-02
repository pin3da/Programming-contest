const int MN = 1e5 + 100;
long long fact[MN];

void fill_fact() {
  fact[0] = 1;
  for (int i = 1; i < MN; i++) {
    fact[i] = mult(fact[i - 1], i);
  }
}

long long perm_rep(vector<int> &frec) {
  int total = 0;
  long long den = 1;
  for (int i = 0; i < (int)frec.size(); i++) {
    den = mult(den, mod_inv(fact[frec[i]]));
    total += frec[i];
  }
  return mult(fact[total], den);
}
