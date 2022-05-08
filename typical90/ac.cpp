#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include <atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i >= 0; --i)
#define repp(i, n, m) for(int i = m; i < int(n); ++i)
#define fore(i_in, a) for(auto &i_in : a)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define chmin(a, b) a = min((ll)a, (ll)b)
#define chmax(a, b) a = max((ll)a, (ll)b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using vs = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1000000000000000;
const long long modl = 1000000007LL;
const long long modll = 998244353LL;

void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
void yn(bool t) {
    if(t)
        yes();
    else
        no();
}
void Yes() { cout << "YES" << endl; }
void No() { cout << "NO" << endl; }
void YN(bool t) {
    if(t)
        Yes();
    else
        No();
}

void pri(ll a) { cout << a << endl; }
void spri(string a) { cout << a << endl; }
void priV(vector<ll> &vec) {
    for(size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << ":";
    }
    cout << endl;
}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

using mint = modint998244353;
// using mint = modint1000000007;
// cout << fixed << setprecision(12);
class segment_tree {
  private:
    int sz;
    std::vector<int> seg;
    std::vector<int> lazy;
    void push(int k) {
        if(k < sz) {
            lazy[k * 2] = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = 0;
    }
    void update(int a, int b, int x, int k, int l, int r) {
        push(k);
        if(r <= a || b <= l)
            return;
        if(a <= l && r <= b) {
            lazy[k] = x;
            push(k);
            return;
        }
        update(a, b, x, k * 2, l, (l + r) >> 1);
        update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
        seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
    }
    int range_max(int a, int b, int k, int l, int r) {
        push(k);
        if(r <= a || b <= l)
            return 0;
        if(a <= l && r <= b)
            return seg[k];
        int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
        int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
        return max(lc, rc);
    }

  public:
    segment_tree() : sz(0), seg(), lazy(){};
    /* ツリーの初期化 */
    /* Nは要素数 */
    /* segはツリーのサイズ */
    segment_tree(int N) {
        sz = 1;
        while(sz < N) {
            sz *= 2;
        }
        seg = std::vector<int>(sz * 2, 0);
        lazy = std::vector<int>(sz * 2, 0);
    }
    /* 区間の更新  */
    void update(int l, int r, int x) {
        update(l, r, x, 1, 0, sz);
    }
    /* 区間最大値の取得 */
    int range_max(int l, int r) {
        return range_max(l, r, 1, 0, sz);
    }
};

int main(void) {
    fio();
    int w, n;
    cin >> w >> n;

    // セグメントツリーの宣言・初期化
    segment_tree seg(w);
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        // 区間最大値を求める
        int height = seg.range_max(l - 1, r) + 1;
        // 区間最大値を更新
        seg.update(l - 1, r, height);
        cout << height << endl;
    }
}
