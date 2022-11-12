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

ll ans = 0;
int n;
graph g;
set<ll> st;
vector<ll> c;
map<ll, ll> mp;

// 深さ優先探索
vector<bool> seen; // 既に見た頂点か
void dfs(int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for(auto next_v : g[v]) {
        if(seen[next_v]) continue; // next_v が探索済だったらスルー
        chmax(ans, c[next_v]);
        dfs(next_v); // 再帰的に探索
    }
}

int main(void) {
    fio();
    cin >> n;
    g.resize(2 * n);
    seen.resize(2 * n);
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) {
        st.insert(a[i]);
        st.insert(b[i]);
    }

    for(auto cc : st) {
        c.pb(cc);
        mp[cc] = c.size() - 1;
    }
    if(c[0] != 1LL) {
        cout << 1 << endl;
        return 0;
    }

    rep(i, n) {
        // cout << a[i] << " " << b[i] << endl;
        g[mp[a[i]]].pb(mp[b[i]]);
        g[mp[b[i]]].pb(mp[a[i]]);
    }

    dfs(0);

    cout << ans << endl;
}
