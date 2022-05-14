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
int n;

struct state {
    int d, c;
    ll s;
};

/* 締め切り、必要日数、報酬*/
vector<state> a;

ll solve() {
    Graph dp(5005, vector<ll>(5005, 0));

    /* 締め切りの早い順にソート*/
    sort(ALL(a), [&](state i, state j) {
        return i.d < j.d;
    });
    rep(i, n) {
        rep(j, 5001) {
            // 仕事 i+1をやらない場合
            chmax(dp[i + 1][j], dp[i][j]);
            // 仕事 i+1をやる場合
            if(j + a[i].c <= a[i].d) {
                chmax(dp[i + 1][j + a[i].c], dp[i][j] + a[i].s);
            }
        }
    }

    ll ans = 0;
    rep(i, 5001) {
        chmax(ans, dp[n][i]);
    }
    return ans;
}

int main(void) {
    fio();
    cin >> n;

    rep(i, n) {
        int d, c;
        ll s;
        cin >> d >> c >> s;
        a.push_back({d, c, s});
    }

    ll ans = solve();
    pri(ans);
}
