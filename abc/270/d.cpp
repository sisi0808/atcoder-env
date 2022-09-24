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
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
Bの回数はAと同じかプラス一回
*/

int main(void) {
    fio();
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    rep(i, k) cin >> a[i];

    /* 残りがN個の時、何個取るのが良いか */
    /* 残りがp個数の時、何個取ることが出来るか */
    /* 次の相手が取れる個数を最小化する */
    vector<ll> dp(n + 1);

    /* 残り個数がp個なら、後x個取ることが出来る */

    repp(i, n + 1, 1) {
        ll mn = 5000000;
        rep(j, k) {
            if(i < a[j]) break;
            // chmin(dp[i], i - dp[i - a[j]]);
            if(dp[i - a[j]] <= mn) {
                chmin(mn, dp[i - a[j]]);
                dp[i] = i - dp[i - a[j]];
            }
        }
    }
    // rep(i, n + 1) cout << dp[i] << endl;
    cout << dp[n] << endl;
}
