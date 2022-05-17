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

// opでは求める値に応じて関数を設定
ll op(ll a, ll b) {
    return max(a, b);
}

// eでは条件に応じた初期値を設定
// 区間最大値を求める際は-1
// 区間最大値を求める際はINFを指定
ll e() {
    return (ll)(-1);
}

int main(void) {
    fio();
    ll w, n;
    cin >> w >> n;
    vs l(n), r(n), v(n);

    rep(i, n) cin >> l[i] >> r[i] >> v[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, -1));
    dp[0][0] = 0;

    // 初期化1(長さn, 初期値e()のsegtreeを作成)
    segtree<ll, op, e> seg(w + 1);
    seg.set(0, 0);

    rep(i, n) {
        rep(j, w + 1) {
            dp[i + 1][j] = dp[i][j];
            ll m_n = seg.prod(max(0LL, j - r[i]), max(0LL, j - l[i] + 1));
            if(m_n != -1) dp[i + 1][j] = max(dp[i + 1][j], m_n + v[i]);
        }
        rep(j, w + 1) {
            seg.set(j, dp[i + 1][j]);
        }
    }
    cout << dp[n][w] << endl;
}
