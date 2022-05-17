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

int n;
Graph g;

bool temp[100008]; /* 既に行った場所ならTrue*/
vector<int> root;  /* 頂点の遷移を管理 */

/* オイラーツアーを使う */
void dfs(int now) {
    temp[now] = true;

    for(int to : g[now]) {
        if(!temp[to]) {
            root.push_back(to);
            dfs(to);
            root.push_back(now);
        }
    }

    if(now == 0) return;
}

int main(void) {
    fio();
    cin >> n;
    g.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // rep(i, n) sort(ALL(g));

    /* オイラーツアー開始 */
    root.push_back(0);
    dfs(0);

    /* オイラーツアーの表を作成 */
    vector<int> v_in(n, -1);
    vector<int> v_out(n, -1);
    rep(i, root.size()) {
        // cout << i << ":" << root[i] << endl;
        if(v_in[root[i]] == -1) v_in[root[i]] = i;
        else v_out[root[i]] = i;
    }
    ll ans = 0;
    rep(i, n) {
        int a = v_out[i] - v_in[i];
        ans += (ll)a * (n - a);
        // cout << a << ":" << n - a << endl;
    }
    pri(ans);
}
