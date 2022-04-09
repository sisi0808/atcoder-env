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
    ll cost;
    ll rev;
    edge(int to, ll cost, ll rev) : to(to), cost(cost), rev(rev) {}
};

int n, m, x, y;
vector<edge> G[101010]; // 辺のコスト
ll d[101010];           // 始点からの最短距離

void dijkstra(int s) {
    fill(d, d + n, INF);
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
            ll nc = e.cost;
            ll nr = e.rev;
            ll t_cost = (d[v] + nr - 1) / nr * nr + nc;
            if(d[nv] > t_cost) {
                d[nv] = t_cost;
                que.push(P(d[nv], nv));
            }
        }
    }
}

int main(void) {
    fio();
    cin >> n >> m >> x >> y;
    x--;
    y--;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        ll t, k;
        cin >> t >> k;
        a--;
        b--;
        G[a].push_back(edge(b, t, k));
        G[b].push_back(edge(a, t, k));
    }
    dijkstra(x);

    cout << (d[y] == INF ? -1 : d[y]) << endl;
}
