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

/*
* 全体の種類数は簡単に求まる

* 各数が何個ずつあるかをあらかじめ計算しておく

* AijはN以下
    種類数は最大でも300


* やはりimos法の可能性が高い

* 塗りつぶしたマスの中にしかない数字が何種類あるか

* 各数について、その数のminX, maxX, minY, maxXを計算しておいて、それを升目ですべて覆っているかを判定する
*/

int main(void) {
    fio();
    ll h, w, n;
    cin >> h >> w >> n;
    ll hs, ws;
    cin >> hs >> ws;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) a[i][j]--;

    map<ll, ll> mp;
    rep(i, h) rep(j, w) mp[a[i][j]]++;

    vector<vector<vector<ll>>> g(h, vector<vector<ll>>(w, vector<ll>(300)));

    rep(i, h) {
        rep(j, w) {
            g[i][j][a[i][j]]++;
            if(j != 0) {
                rep(k, 300) g[i][j][k] += g[i][j - 1][k];
            }
        }
    }
    rep(j, w) {
        rep(i, h) {
            if(i != 0) {
                rep(k, 300) g[i][j][k] += g[i - 1][j][k];
            }
        }
    }

    for(int i = 0; i <= h - hs; i++) {
        for(int j = 0; j <= w - ws; j++) {
            ll ans = 0;
            vector<ll> aa(300, 0);
            if(i > 0 && j > 0) rep(k, 300) aa[k] += g[i - 1][j - 1][k];
            if(i > 0) rep(k, 300) aa[k] -= g[i - 1][j + ws - 1][k];
            if(j > 0) rep(k, 300) aa[k] -= g[i + hs - 1][j - 1][k];
            rep(k, 300) aa[k] += g[i + hs - 1][j + ws - 1][k];
            rep(k, 300) {
                if(mp[k] != aa[k]) ans++;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}
