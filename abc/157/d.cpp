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
* ブロック関係はノイズ？
* aとbが友達関係にないのを補償するのみ

DSUを使うのなら以下
* その頂点がつながっている友人の数 - 直接繋がっている友人の数 - 直接繋がっているブロックの数 + 同じグループに属さないブロック

友人としては繋がっていないけど、ブロックとしては繋がっている
*/

int main(void) {
    fio();
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    vector<ll> c(k), d(k);
    rep(i, k) cin >> c[i] >> d[i];

    dsu ds(n);

    graph ga(n), gb(n), gc(n);
    rep(i, m) {
        ga[a[i] - 1].pb(b[i] - 1);
        ga[b[i] - 1].pb(a[i] - 1);
        ds.merge(a[i] - 1, b[i] - 1);
    }
    rep(i, k) {
        gb[c[i] - 1].pb(c[i] - 1);
        gb[d[i] - 1].pb(d[i] - 1);

        if(!ds.same(c[i] - 1, d[i] - 1)) {
            gc[c[i] - 1].pb(d[i] - 1);
            gc[d[i] - 1].pb(c[i] - 1);
        }
    }

    rep(i, n) {
        // cout << ds.size(i) << " " << ga[i].size() << " " << gb[i].size() << " " << gc[i].size() << endl;
        ll ans = ds.size(i) - ga[i].size() - gb[i].size() + gc[i].size() - 1;
        cout << ans << " ";
    }
    cout << endl;
}
