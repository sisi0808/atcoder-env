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

int main(void) {
    fio();
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1));
    dp[0][0] = true;

    rep(i, n) {
        rep(j, s) {
            if(j + a[i] <= s) dp[i + 1][j + a[i]] = dp[i + 1][j + a[i]] || dp[i][j];
            if(j + b[i] <= s) dp[i + 1][j + b[i]] = dp[i + 1][j + b[i]] || dp[i][j];
        }
    }

    // rep(i, n + 1) {
    //     rep(j, s + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if(!dp[n][s]) {
        no();
        return 0;
    }
    yes();
    /* 方法が存在する場合 */
    string ans = "";
    for(int i = n - 1; i >= 0; i--) {
        int ss = 0;
        if(s - a[i] >= 0 && dp[i][s - a[i]]) {
            ans += 'H';
            ss = a[i];
        } else if(s - b[i] >= 0 && dp[i][s - b[i]]) {
            ans += 'T';
            ss = b[i];
        }

        s -= ss;
    }

    reverse(ALL(ans));

    cout << ans << endl;
}
