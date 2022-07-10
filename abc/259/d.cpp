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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
その円からいける円をグラフで管理
*/

// 深さ優先探索
vector<bool> seen; // 既に見た頂点か
bool ans = false;
Graph g;

int n;
ll sx, sy, tx, ty;
lvec x, y, r;

// 座標上の点Pが指定したidxの円の円周上に位置しているか
bool getCircleOn(int px, int py, int i) {
    ll xx = (x[i] - px) * (x[i] - px);
    ll yy = (y[i] - py) * (y[i] - py);
    ll rr = r[i] * r[i];
    if(xx + yy == rr) return true;
    return false;
}

void dfs(int v) {
    seen[v] = true; // v を訪問済にする
    if(getCircleOn(tx, ty, v)) ans = true;

    // v から行ける各頂点 next_v について
    for(auto next_v : g[v]) {
        if(seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(next_v);               // 再帰的に探索
    }
}

int main(void) {
    fio();
    cin >> n;
    cin >> sx >> sy >> tx >> ty;
    g.resize(n);
    seen.resize(n, false);
    x.resize(n);
    y.resize(n);
    r.resize(n);

    rep(i, n) {
        cin >> x[i] >> y[i] >> r[i];
    }

    rep(i, n) {
        repp(j, n, i + 1) {
            ll xx = (x[i] - x[j]) * (x[i] - x[j]);
            ll yy = (y[i] - y[j]) * (y[i] - y[j]);
            ll r1 = (r[i] + r[j]) * (r[i] + r[j]);
            ll r2 = (r[i] - r[j]) * (r[i] - r[j]);

            // 円同士の接点があるとき
            if(xx + yy > r1) continue; // 半径の合計よりも２つの円の中心間距離が離れている場合
            if(xx + yy < r2) continue; // 半径の合計よりも２つの円の中心間距離が近い場合
            g[i].pb(j);
            g[j].pb(i);
        }
    }
    int st = -1;
    rep(i, n) {
        if(getCircleOn(sx, sy, i)) st = i;
    }

    if(st == -1) {
        no();
        return 0;
    }

    dfs(st);
    yn(ans);
}
