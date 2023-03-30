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

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

const int MAXN = 17;
int n;
vector<vector<int>> d;
vector<vector<int>> dp;
// int d[MAXN][MAXN];
// int dp[1 << MAXN][MAXN];

int rec(int S, int v) {
    if(dp[S][v] >= 0) return dp[S][v];
    if(S == (1 << n) - 1 && v == 0) return dp[S][v] = 0;
    int tmp = 90000000;
    rep(u, n) if(!(S >> u & 1)) tmp = min(tmp, rec(S | 1 << u, u) + d[v][u]);
    return dp[S][v] = tmp;
}

int main(void) {
    fio();
    cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    d.resize(n, vector<int>(n));
    dp.resize((1 << n), vector<int>(n, -1));

    /* 有効辺の初期化 */
    rep(i, n) {
        rep(j, n) {
            d[i][j] = abs(x[j] - x[i]) + abs(y[j] - y[i]) + max(0, z[j] - z[i]);
        }
    }
    // fill((int *)dp, (int *)(dp + (1 << MAXN)), -1);
    cout << rec(0, 0) << endl;
    return 0;
}