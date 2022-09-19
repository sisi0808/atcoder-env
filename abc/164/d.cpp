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

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
3 * 673
mod計算のDPて感じ


*/
int main(void) {
    fio();
    string s;
    cin >> s;

    // int mo = 2019;
    // int m = 0;
    // vector<ll> v(2019, 0);
    // v[0] = 1;
    // rep(i, s.size()) {
    //     int a = s[i] - '0';
    //     m = (m * 10 + a) % mo;
    //     v[m]++;
    //     cout << m << endl;
    // }
    // ll ans = 0;
    // rep(i, mo) ans += v[i] * (v[i] - 1) / 2;
    // rep(i, mo) if(v[i] > 0) cout << v[i] << endl;
    // cout << ans << endl;

    int mo = 2019;
    int m = 0;
    int p = 1;
    vector<ll> v(2019, 0);
    v[0] = 1;
    rrep(i, s.size() - 1) {
        m = (m + p * (s[i] - '0')) % mo;
        p = 10 * p % mo;
        v[m]++;
    }
    ll ans = 0;
    rep(i, mo) ans += v[i] * (v[i] - 1) / 2;
    cout << ans << endl;
}
