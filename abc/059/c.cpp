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
const long long _INF = 1000000000000000LL;
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
* A_iとA_(i+1)の符号は異なる
* abs(sa_i) < abs(sa_(i+1))

* 狭義単調増加の亜種？
* 末尾から決めたほうが良さそう
    * 末尾は必ず最小の選択ができる
    * 毎回最大で良さげ

* 先頭が-のときと＋の時の二通りシミュレート
*/

int main(void) {
    fio();
    int n;
    cin >> n;
    vector<ll> a(n), c(n);
    rep(i, n) cin >> a[i];

    ll ans = INF;
    ll _ans = 0;
    ll sum_a = max(0ll, a[0]);
    rep(i, n) {
        if(sum_a >= 0) {
            ll b = -(sum_a + 1);
            if(i == 0 && sum_a == 0ll) b = -1;
            if(a[i] > b) _ans += abs(a[i] - b);
            c[i] = min(a[i], b);
        } else {
            ll b = -(sum_a - 1);
            if(a[i] < b) _ans += abs(a[i] - b);
            c[i] = max(a[i], b);
        }
        if(i == 0 && a[0] == c[0]) sum_a = c[0];
        else sum_a += c[i];
    }
    chmin(ans, _ans);

    _ans = 0;
    sum_a = min(-1ll, a[0]);
    rep(i, n) {
        if(sum_a >= 0) {
            ll b = -(sum_a + 1);
            if(a[i] > b) _ans += abs(a[i] - b);
            c[i] = min(a[i], b);
        } else {
            ll b = -(sum_a - 1);
            if(i == 0 && sum_a == -1ll) b = 0;
            if(a[i] < b) _ans += abs(a[i] - b);
            c[i] = max(a[i], b);
        }
        if(i == 0 && a[0] == c[0]) sum_a = c[0];
        else sum_a += c[i];
    }

    chmin(ans, _ans);
    cout << ans << endl;
}
