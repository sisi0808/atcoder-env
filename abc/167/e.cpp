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

#define pb push_back
#define pf push_front

#define fi first
#define se second

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using ivec = vector<int>;
using lvec = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1 << 31;
const int _inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1LL << 62;
const long long _INF = 1000000000000000000LL;
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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

using mint = modint998244353;
// using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
 * iブロックまで見た時の同じ色の組の数を管理
 * ではなく、あり得る数の管理？
 * 一番右の色も管理?
 * 色を区別しない以上、それもいらないか
 */

// 組み合わせの数nCrを計算
mint fact[200005];

void init() {
    fact[0] = 1;
    rep(i, 200004) fact[i + 1] = fact[i] * (i + 1);
}

mint nCr(int n, int r) {
    if(n == 0) return r == 0;
    r = min(r, n - r);
    if(r < 0) return 0;
    auto nr = make_pair(n, r);
    mint nu = fact[n];
    mint de = fact[r] * fact[n - r];
    return nu / de;
}

int main(void) {
    fio();
    ll n, m, k;
    cin >> n >> m >> k;

    init();
    mint ans = 0;
    rep(i, k + 1) {
        ans += nCr(n - 1, i) * m * pow_mod(m - 1, n - 1 - i, 998244353);
    }

    cout << ans.val() << endl;
}
