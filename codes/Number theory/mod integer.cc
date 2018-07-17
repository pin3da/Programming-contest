template<class T, T mod>
struct mint_t {
  T val;
  mint_t() : val(0) {}
  mint_t(T v) : val(v % mod) {}

  mint_t operator + (const mint_t& o) const {
    return (val + o.val) % mod;
  }
  mint_t operator - (const mint_t& o) const {
    return (val - o.val) % mod;
  }
  mint_t operator * (const mint_t& o) const {
    return (val * o.val) % mod;
  }
};

typedef mint_t<long long, 998244353> mint;
