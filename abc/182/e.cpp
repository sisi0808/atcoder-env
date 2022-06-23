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
const long long _INF = 1000000000000000000;
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

/*
光が当たるマスは以下の2種類
* 電球が置かれているマス
* 電球の直線状にあるマス

光が当たらないマスは
* 電球の直線状にないマス
* 電球の直線状にあるが、間にブロックがあるマス


HとWは独立して考えることが可能?d

HWの状態
-1:ブロック
0: 初期
1: 光が当たる場所
*/

int h, w, n, m;
ivec a, b, c, d;
graph gh, gw;

int main(void) {
    fio();
    cin >> h >> w >> n >> m;
    a.resize(n);
    b.resize(n);
    c.resize(m);
    d.resize(m);

    gh.resize(h, vector<int>(w, 0));
    gw.resize(h, vector<int>(w, 0));

    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];
    rep(i, n) {
        a[i]--;
        b[i]--;
    }
    rep(i, m) {
        c[i]--;
        d[i]--;
    }

    map<int, vector<int>> mh;
    map<int, vector<int>> mw;
    rep(i, n) {
        mh[a[i]].pb(b[i]);
        mw[b[i]].pb(a[i]);
    }

    /* まずはブロックを初期配置 */
    rep(i, m) {
        gh[c[i]][d[i]] = -1;
        gw[c[i]][d[i]] = -1;
    }

    /* まずはx(横)方向*/
    rep(i, h) {
        for(auto d : mh[i]) {
            repp(j, w, d) {
                if(gh[i][j] != 0) break;
                gh[i][j] = 1;
            }
            rrep(j, d - 1) {
                if(gh[i][j] != 0) break;
                gh[i][j] = 1;
            }
        }
    }
    /* 次にy(縦)方向*/
    rep(i, w) {
        for(auto d : mw[i]) {
            repp(j, h, d) {
                if(gw[j][i] != 0) break;
                gw[j][i] = 1;
            }
            rrep(j, d - 1) {
                if(gw[j][i] != 0) break;
                gw[j][i] = 1;
            }
        }
    }

    ll ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(gh[i][j] > 0 || gw[i][j] > 0) ans++;
        }
    }
    pri(ans);
}
