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

struct edge {
    int to;
    ll cost;
    edge(int to, ll cost) : to(to), cost(cost) {}
};

int V; // 頂点数
int E; // 辺数
// vector<edge> G[101010]; // 辺のコスト
vector<edge> G[2001];                 // 辺のコスト
Graph d(2001, vector<ll>(2001, inf)); // 始点からの最短距離

void dijkstra(int s) {
    // fill(d, d + V, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    d[s][s] = 0;
    que.push(P(0, s));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[s][v] < p.first) continue;
        for(auto e : G[v]) {
            int nv = e.to;
            ll nc = e.cost;
            if(d[s][nv] > d[s][v] + nc) {
                d[s][nv] = d[s][v] + nc;
                que.push(P(d[s][nv], nv));
            }
        }
    }
}
/*
* 頂点iから頂点iまでの最短距離を求める

* 帰れるとは(サイクルができていること)
*/

int main(void) {
    fio();
    cin >> V >> E;

    vector<ll> ans(V, inf);
    rep(i, E) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if(a == b) {
            if(ans[a] == inf) ans[a] = c;
            else chmin(ans[a], c);
        } else G[a].push_back(edge(b, c));
    }

    rep(i, V) dijkstra(i);
    rep(i, V) {
        rep(j, V) {
            if(i == j) continue;
            chmin(ans[i], d[i][j] + d[j][i]);
        }
        if(ans[i] >= inf) cout << -1 << endl;
        else cout << ans[i] << endl;
    }
}
