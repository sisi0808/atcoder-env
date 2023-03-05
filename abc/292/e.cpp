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
* 辺を追加する順番は関係ない(最終形は同じ)
* 最初のグラフと最終的なグラフを作成して、辺数を比較？
* 完全な状態の法則とは
  * 最短距離が2の辺が存在しない
  * もっと言えば、最短距離が2以上の辺は存在しない
  * 入次数は2以上
  *
  *
  *
* そもそも辺の長さは2までしか探索しなくてよいのか

* 頂点aから頂点bへの最短距離が2の時、辺を追加
*/

ll n, m;
graph g;
ll ans = 0;

// 深さ優先探索
vector<bool> seen; // 既に見た頂点か
void dfs(int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for(auto next_v : g[v]) {
        if(seen[next_v]) continue; // next_v が探索済だったらスルー
        ans++;
        dfs(next_v); // 再帰的に探索
    }
}

int main(void) {
    fio();
    cin >> n >> m;

    g.resize(n);
    seen.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
    }
    rep(i, n) {
        rep(i, n) seen[i] = false;
        dfs(i);
    }

    cout << ans - m << endl;
}
