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
using ivec = vector<int>;
using lvec = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1000000000000000000;
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

/*
頂点数が1の木を無くせれば良い
脇の数の合計<=自身の数ならば、脇の二本をつなぐ
*/

int main(void) {
    fio();
    int n;
    cin >> n;
    lvec a(n);
    rep(i, n) cin >> a[i];
    vector<bool> v(n, false);
    // dp[N個目の条件を][行うか]
    vector<vector<ll>> dp1(n + 1, vector<ll>(2, INF));
    vector<vector<ll>> dp2(n + 1, vector<ll>(2, INF));

    /* 行動１を行わない場合 */
    dp1[0][0] = 0;
    dp1[0][1] = INF;

    repp(i, n, 1) {
        /* 行動i+1を行わない場合 */
        dp1[i][0] = dp1[i - 1][1];
        /* 行動i+1を行う場合 */
        dp1[i][1] = min(dp1[i - 1][0], dp1[i - 1][1]) + a[i];
    }

    /* 行動１を行う場合 */
    dp2[0][0] = INF;
    dp2[0][1] = a[0];

    repp(i, n, 1) {
        /* 行動i+1を行わない場合 */
        dp2[i][0] = dp2[i - 1][1];
        /* 行動i+1を行う場合 */
        dp2[i][1] = min(dp2[i - 1][0], dp2[i - 1][1]) + a[i];
    }

    cout << min({dp1[n - 1][1], dp2[n - 1][0], dp2[n - 1][1]}) << endl;
}
