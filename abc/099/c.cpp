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
    int n;
    cin >> n;

    set<ll> st;
    st.insert(1);
    ll num = 6;
    while(num <= n) {
        st.insert(num);
        num *= 6;
    }
    num = 9;
    while(num <= n) {
        st.insert(num);
        num *= 9;
    }

    /* 解法1 */
    // vector<vector<ll>> dp(st.size() + 1, vector<ll>(n + 1, n));
    // dp[0][0] = 0;
    // int idx = 0;
    // for(auto t : st) {
    //     rep(j, n + 1) {
    //         chmin(dp[idx + 1][j], dp[idx][j]);
    //         if(j + t > n) continue;
    //         chmin(dp[idx + 1][j + t], dp[idx + 1][j] + 1);
    //     }
    //     idx++;
    // }
    // cout << dp[st.size()][n] << endl;

    /* 解法2 */
    vector<ll> dp(n + 1, n);
    dp[0] = 0;
    for(auto t : st) {
        rep(j, n) {
            if(j + t > n) continue;
            chmin(dp[j + t], dp[j] + 1);
        }
    }

    cout << dp[n] << endl;
}
