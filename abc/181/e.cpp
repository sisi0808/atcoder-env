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
const int inf = 1 << 31;
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

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
全ての児童が違いの身長差が最も大きい人と組めば、それが上解

*/

int n, m;
lvec h, w;

int main(void) {
    fio();
    cin >> n >> m;
    h.resize(n);
    w.resize(m);
    rep(i, n) cin >> h[i];
    rep(i, m) cin >> w[i];
    sort(ALL(h));
    vector<int> sum1((n + 1) / 2), sum2((n + 1) / 2); // 次のやつとの加算 && 前のやつとの加算
    for(int i = 0; i + 1 < n; i += 2) sum1[i / 2 + 1] = sum1[i / 2] + h[i + 1] - h[i];
    for(int i = n - 2; i > 0; i -= 2) sum2[i / 2] = sum2[i / 2 + 1] + h[i + 1] - h[i];

    // rep(i, n / 2 + 1) {
    //     cout << sum1[i] << ':' << sum2[i] << endl;
    // }
    ll ans = INF;
    rep(i, m) {
        int x = lower_bound(ALL(h), w[i]) - h.begin();
        if(x % 2 == 1) x--;
        chmin(ans, sum1[x / 2] + sum2[x / 2] + abs(h[x] - w[i]));
        // pri(ans);
    }
    pri(ans);
}
