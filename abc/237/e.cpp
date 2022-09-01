#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include <atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i > 0; --i)
#define repp(i, n, m) for(int i = m; i < int(n); ++i)
#define fore(i_in, a) for(auto &i_in : a)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

#define pb push_back
#define pf push_front

#define fi first
#define se second

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = vector<ll, ll>;
const int SIZE = 100005;
const int inf = 100000000;
const int modi = 1000000007;
const long long INF = 10000000000LL;
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

graph G;
vector<ll> dist;
using mint = modint998244353;

/*
* スタート地点寄りも低い所が条件
* そこに行くまでに、出来るだけ上昇を無くす
* スタートをst, ゴールをedと置いた時、以下の式を最大化する
* h[st] - h[ed] - (2*上昇合計数)

* その頂点に負の頂点のみを伝って行けるのなら、その頂点は絶対に正しい
* その頂点を戻る事は絶対にない

* 恐らくすべての辺を探索(オーダーM)で解ける！
*/

ll n, m;
vector<ll> h;
vector<vector<ll>> g;
vector<ll> seen;

void dfs(int v) {
    // v から行ける各頂点 next_v について
    for(auto next_v : g[v]) {
        ll add = h[v] - h[next_v];
        if(h[next_v] < h[v]) add *= 2;
        if(seen[v] + add < seen[next_v]) continue; // next_v が探索済だったらスルー
        seen[next_v] = seen[v] + add;
        dfs(next_v); // 再帰的に探索
    }
}

int main(void) {
    fio();
    cin >> n >> m;
    h.resize(n);
    g.resize(n);
    seen.resize(n, -1 * INF);
    seen[0] = 0;

    rep(i, n) cin >> h[i];

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0);

    ll ans = 0;
    rep(i, n) chmax(ans, (ll)seen[i]);
    cout << ans << endl;
}
