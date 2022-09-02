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
* スタート地点寄りも低い所が条件
* そこに行くまでに、出来るだけ上昇を無くす
* スタートをst, ゴールをedと置いた時、以下の式を最大化する
* h[st] - h[ed] - (2*上昇合計数)
つまり,上った高さの合計を最大化

* その頂点に負の頂点のみを伝って行けるのなら、その頂点は絶対に正しい
* その頂点を戻る事は絶対にない

* 恐らくすべての辺を探索(オーダーM)で解ける！
*/

struct edge {
    int to;
    ll cost;
    edge(int to, ll cost) : to(to), cost(cost) {}
};

int V; // 頂点数
int E; // 辺数
vector<vector<edge>> G;
vector<ll> d; // 始点からの最短距離
ll n, m;
vector<ll> h;

/* 上った高さの合計をダイクストラで解く */
void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> que;
    ll ans = 0;
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;

        if(d[v] < p.first) continue;
        for(auto e : G[v]) {
            int nv = e.to;
            ll nc = e.cost;
            if(d[nv] > d[v] + nc) {
                d[nv] = d[v] + nc;
                que.push(P(d[nv], nv));
            }
        }
    }
}

int main(void) {
    fio();
    cin >> n >> m;
    V = n;
    E = 2 * m;

    h.resize(V);
    G.resize(V);
    d.resize(V, INF);

    rep(i, n) cin >> h[i];

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(edge(b, max(h[b] - h[a], 0LL)));
        G[b].pb(edge(a, max(h[a] - h[b], 0LL)));
    }
    dijkstra(0);
    ll ans = 0;
    rep(i, n) chmax(ans, h[0] - h[i] - d[i]);
    cout << ans << endl;
}