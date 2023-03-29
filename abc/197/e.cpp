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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = vector<ll, ll>;
const int SIZE = 100005;
const int inf = 1000000000;
const int modi = 1000000007;
const long long INF = 10000000000;
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

/*
 * 最後の操作を「座標0に数字N+1が書かれていると設定」
 * 一つの数字が複数地点ある時、その左端と右端だけ管理していれば良い
 */

int main(void) {
    fio();
    int n;
    cin >> n;
    vector<ll> x(n), c(n);
    rep(i, n) cin >> x[i] >> c[i];

    // 色iが存在する座標の左端と右端
    // 一つもない場合は
    vector<vector<ll>> g(n + 1, vector<ll>(2));
    rep(i, n + 1) g[i][0] = INF;
    rep(i, n + 1) g[i][1] = -INF;
    g[0][0] = 0;
    g[0][1] = 0;
    rep(i, n) {
        chmin(g[c[i]][0], x[i]);
        chmax(g[c[i]][1], x[i]);
    }

    // 道筋の選択による、最小値
    // dp[i][j] := 0~i色のボールをすべて取り切った後、i色のj(左端 or 右端)にいる時の最短移動距離
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 100000000000000000ll));
    dp[0][0] = 0;
    dp[0][1] = 0;
    rep(i, n) {
        // そこに整数がない場合
        if(g[i + 1][0] == INF) {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            g[i + 1][0] = g[i][0];
            g[i + 1][1] = g[i][1];
            continue;
        }
        ll m = abs(g[i + 1][0] - g[i + 1][1]);
        rep(j, 2) {
            rep(k, 2) {
                chmin(dp[i + 1][(k + 1) % 2], dp[i][j] + abs(g[i][j] - g[i + 1][k]) + m);
            }
        }
    }

    // 最終的な移動距離 + 0への距離
    ll ans = min(dp[n][1] + abs(g[n][1]), dp[n][0] + abs(g[n][0]));
    cout << ans << endl;
}
