#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef bitset<8> inst;

inst op;
inst val;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  op  = inst(string("11100000"));
  val = inst(string("00011111"));
  inst sta(string("00000000"));
  inst lda(string("00100000"));
  inst beq(string("01000000"));
  inst nop(string("01100000"));
  inst dec(string("10000000"));
  inst inc(string("10100000"));
  inst jmp(string("11000000"));
  inst hlt(string("11100000"));

  string line;
  int pc = 0, acc = 0;
  while (cin >> line) {
    vector<inst> program;
    program.emplace_back(line);
    for (int i = 1; i < 32; ++i) {
      cin >> line;
      program.emplace_back(line);
    }

    while (pc < program.size()) {
      inst cur = program[pc];
      pc++;
      if (pc == 32) pc = 0;
      inst cur_op  =  cur & op;
      inst cur_val =  cur & val;
      if (cur_op == sta) {
        int pos = cur_val.to_ulong();
        program[pos] = inst(acc);
      }

      if (cur_op == lda) {
        int pos = cur_val.to_ulong();
        acc = program[pos].to_ulong();
      }

      if (cur_op == beq) {
        int pos = cur_val.to_ulong();
        if (acc == 0) {
          pc = pos;
        }
      }

      if (cur_op == nop) {

      }

      if (cur_op == dec) {
        acc--;
        if (acc == -1)
          acc = 255;
      }

      if (cur_op == inc) {
        acc++;
        if (acc == 256)
          acc = 0;
      }

      if (cur_op == jmp) {
        int pos = cur_val.to_ulong();
        pc = pos;
      }

      if (cur_op == hlt) {
        for (int i = 7; i >= 0; --i)
          if ((acc >> i) & 1)
            cout << 1;
          else
            cout << 0;
        cout << endl;
        pc = 0;
        acc  = 0;
        break;
      }
    }
  }
  return 0;
}
