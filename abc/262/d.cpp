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

using mint = modint998244353;
// using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
n個選んだ時に、その合計 % n == 0になる組み合わせの数


*/
int main(void) {
    fio();
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // vector<vector<int>> m(101, vector<int>(101));
    // rep(i, n) {
    //     rep(j, 100) {
    //         m[j + 1][a[i] % (j + 1)]++;
    //     }
    // }

    /* どれかを選ぶ際に、それが何個目で、余りはいくつ */
    // vector<vector<vector<mint>>> dp(n + 1, vector<vectro<mint>>(n + 1, vector<mint>(101)));
    // dp[0][0][0] = 1;

    // /* いくつ選んだかで場合分け */
    // rep(i, n) {
    //     rep(j, n) {
    //         rep(k, 100) {
    //             if(dp[i][j][k] == 0) continue;
    //             /* i個目を選ぶ場合 */
    //             dp[i+1][j+1][() % n]++;
    //             /* i個眼を選ばない場合 */
    //         }
    //     }
    // }
    // mint ans = 0;
    // repp(i, n + 1, 1) ans += dp[][][0];
    cout << ans.val() << endl;
}
