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

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using vs = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1000000000000000;
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

struct edge {
    int to;
    int cost;
    edge(int to, int cost) : to(to), cost(cost) {}
};

int V;                  // 頂点数
int E;                  // 辺数
vector<edge> G[101010]; // 辺のコスト
ll d[101010];           // 始点からの最短距離

void dijkstra(int s) {
    fill(d, d + V, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(auto e : G[v]) {
            int nv = e.to;
            int nc = e.cost;
            if(d[nv] > d[v] + nc) {
                d[nv] = d[v] + nc;
                que.push(P(d[nv], nv));
            }
        }
    }
}

/*
 1. 全点最短系で、街１から街Kまでの時間をすべて求める
 2. 全点最短系で、街Nから街Kまでの時間をすべて求める
 */

int main(void) {
    fio();
    cin >> V >> E;
    rep(i, E) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(edge(b, c));
        G[b].push_back(edge(a, c));
    }
    vector<ll> ans(V);
    dijkstra(0);
    rep(i, V) ans[i] = d[i];
    dijkstra(V - 1);
    rep(i, V) {
        cout << ans[i] + d[i] << endl;
    }
}
