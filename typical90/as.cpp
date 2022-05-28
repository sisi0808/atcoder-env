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

int main(void) {
    fio();
    int n, k;
    cin >> n >> k;
    vs x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    /* 任意の２頂点間のユークリッド距離の２乗 */
    vector<vector<ll>> dis(n, vector<ll>(n, 0));

    rep(i, n) {
        rep(j, n) {
            ll dis_x = (x[i] - x[j]) * (x[i] - x[j]);
            ll dis_y = (y[i] - y[j]) * (y[i] - y[j]);
            dis[i][j] = dis_x + dis_y;
        }
    }

    /* その頂点グループの中のコスト最大値 */
    vector<ll> cost((1 << n), 0);
    repp(i, (1 << n), 1) {
        rep(j, n) {
            if(i & (1 << j)) {
                repp(jj, n, j + 1) {
                    if(i & (1 << jj)) {
                        chmax(cost[i], dis[jj][j]);
                    }
                }
            }
        }
    }

    vector<vector<ll>> dp(k + 1, vector<ll>(1 << n, (1LL << 62)));
    dp[0][0] = 0;
    rep(i, k) {
        repp(j, (1 << n), 1) {
            for(int jj = j; jj != 0; jj = (jj - 1) & j) {
                chmin(dp[i + 1][j], max(dp[i][j - jj], cost[jj]));
            }
        }
    }

    cout << dp[k][(1 << n) - 1] << endl;
}
