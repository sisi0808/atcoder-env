#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include <atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n, m) for(int i = n; i >= m; --i)
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
const int inf = 1 << 30;
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
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
xとy独立に考えることが可能

cにできるということは、-c荷もできる
*/

int main(void) {
    fio();
    int n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    /* 解1 */
    vector<vector<ll>> dp_x(n + 1, vector<ll>(2 * (n * 10) + 1));
    vector<vector<ll>> dp_y(n + 1, vector<ll>(2 * (n * 10) + 1));
    dp_x[1][a[0] + (n * 10)] = 1;
    dp_y[1][(n * 10)] = 1;

    repp(i, n, 1) {
        rep(j, 2 * (n * 10) + 1) {
            if(i % 2 == 0) {
                dp_x[i + 1][j + a[i]] += dp_x[i][j];
                if(j - a[i] >= 0) dp_x[i + 1][j - a[i]] += dp_x[i][j];
                dp_y[i + 1][j] = dp_y[i][j];
            } else {
                dp_y[i + 1][j + a[i]] += dp_y[i][j];
                if(j - a[i] >= 0) dp_y[i + 1][j - a[i]] += dp_y[i][j];
                dp_x[i + 1][j] = dp_x[i][j];
            }
        }
    }

    yn(dp_x[n][x + (n * 10)] && dp_y[n][y + (n * 10)]);

    /* 解2 */
    // vector<vector<ll>> dp_x(n + 1, vector<ll>(n * 10));
    // vector<vector<ll>> dp_y(n + 1, vector<ll>(n * 10));
    // dp_x[0][0] = 1;
    // dp_y[0][0] = 1;

    // /* まずはx */
    // rep(i, n) {
    //     rep(j, n * 10) {
    //         if(i == 0) {
    //             dp_y[i + 1][j] = dp_y[i][j];
    //             dp_x[i + 1][j] = dp_x[i][j];
    //         } else if(i % 2 == 0) {
    //             dp_x[i + 1][j + a[i]] += dp_x[i][j];
    //             dp_x[i + 1][abs(j - a[i])] += dp_x[i][j];
    //             dp_y[i + 1][j] = dp_y[i][j];
    //         } else {
    //             dp_y[i + 1][j + a[i]] += dp_y[i][j];
    //             dp_y[i + 1][abs(j - a[i])] += dp_y[i][j];
    //             dp_x[i + 1][j] = dp_x[i][j];
    //         }
    //     }
    // }
    // cout << endl;
    // yn(dp_x[n][abs(x - a[0])] && dp_y[n][abs(y)]);
}
