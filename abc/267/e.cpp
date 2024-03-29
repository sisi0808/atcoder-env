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
上限と下限は比較的簡単に求めることが可能
上限:接する辺のコストが最大の頂点を削除した時
下限：

削除コストが最も軽い頂点の内、最もコストが重い辺を削除
1: 1 + 2 + 4
2: 3
3: 3
4: 3

こういうのは、逆順に構築していくのが楽なはず
削除コストが最も重い頂点の内、最もコストが軽い辺を追加

*/

int main(void) {
    fio();
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> b(n); // 頂点の削除コスト
    Graph g(n);      // 頂点の繋がり(グラフ)
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        b[u] += a[v];
        b[v] += a[u];
        g[u].pb(v);
        g[v].pb(u);
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, n) pq.push({b[i], i});
    vector<bool> erased(n);

    ll ans = 0;
    while(!pq.empty()) {
        auto [cost, i] = pq.top();
        pq.pop();
        if(erased[i]) continue;
        erased[i] = true;
        ans = max(ans, cost);
        for(auto v : g[i]) {
            if(erased[v]) continue;
            b[v] -= a[i];
            pq.push({b[v], v});
        }
    }
    cout << ans << endl;
}
