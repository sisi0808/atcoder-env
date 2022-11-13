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
* 同じ道を二度通る事はない

* unionfindを使えば、通れるかは判定可能
* 回数は

* 特殊な最短経路探索


頂点0から行ける頂点で合って、
*/

int n, m, k;
vector<int> dist; // 各頂点が探索済みか
vector<vector<int>> g;

void load_map(int st) {
    dist.resize(2 * n, inf);
    deque<int> pp;
    pp.push_back(st);
    dist[st] = 0;

    while(!pp.empty()) {
        st = pp.front();
        pp.pop_front();
        for(auto c : g[st]) {
            if(dist[c] == inf) {
                if(abs(c - st) == n) {
                    dist[c] = dist[st];
                    pp.push_front(c);
                } else {
                    dist[c] = dist[st] + 1;
                    pp.push_back(c);
                }
            }
        }
    }
}

int main(void) {
    fio();
    cin >> n >> m >> k;

    /* g[0] == 反転 、g[1] = 通常 */
    g.resize(n * 2);

    rep(i, m) {
        ll u, v, a;
        cin >> u >> v >> a;
        u--;
        v--;
        g[a * n + u].pb(a * n + v);
        g[a * n + v].pb(a * n + u);
    }

    rep(i, k) {
        int s;
        cin >> s;
        s--;
        /* 別のグラフへの移動 */
        g[s].push_back(n + s);
        g[n + s].push_back(s);
    }

    load_map(n); // 頂点とどちらのグラフにいるか
    // cout << dist[n - 1] << endl;
    // cout << dist[n * 2 - 1] << endl;

    if(dist[n - 1] == dist[2 * n - 1] && dist[n - 1] == inf) cout << -1 << endl;
    else cout << min(dist[n - 1], dist[2 * n - 1]) << endl;
}
