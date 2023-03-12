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

// int n, m;          // 頂点と辺の数
// vector<bool> seen; // 既に見た頂点か
// graph g;

// ll x = 0;
// ll y = 0;
// bool fl;
// void dfs(int v, int u) {
//     seen[v] = true; // v を訪問済にする

//     // v から行ける各頂点 next_v について
//     for(auto next_v : g[v]) {
//         if(next_v == u) continue; // next_v が探索済だったらスルー
//         else if(seen[next_v]) fl = true;
//         else dfs(next_v, v); // 再帰的に探索
//     }
// }

// int main() {
//     fio();
//     cin >> n >> m;
//     n *= 2;
//     g.resize(n);
//     seen.resize(n);
//     int f, t;
//     rep(i, m) {
//         ll a, c;
//         char b, d;
//         cin >> a >> b >> c >> d;
//         a--;
//         c--;
//         int cnt_a, cnt_c;
//         if(b == 'R') cnt_a = 1;
//         else cnt_a = 0;
//         if(d == 'R') cnt_c = 1;
//         else cnt_c = 0;

//         g[2 * c + cnt_c].push_back(2 * a + cnt_a);
//         g[2 * a + cnt_a].push_back(2 * c + cnt_c);
//     }
//     rep(i, n / 2) {
//         g[2 * i].pb(2 * i + 1);
//         g[2 * i + 1].pb(2 * i);
//     }

//     rep(i, n / 2) {
//         fl = false;
//         if(!seen[2 * i]) {
//             dfs(2 * i, -1);
//             if(fl == true) x++;
//             else y++;
//         }
//     }
//     cout << x << " " << y << endl;
// }

int main() {
    fio();
    ll n, m;
    cin >> n >> m;
    dsu uf(n);

    graph g(n);
    rep(i, m) {
        ll a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        g[a].pb(c);
        g[c].pb(a);
        uf.merge(a, c);
    }

    ll x, y;
    x = y = 0;
    /* 各連結成分を探索 */
    for(auto dd : uf.groups()) {
        bool f = true;
        /* 連結成分の各頂点を探索 */
        for(auto ddd : dd) {
            if(g[ddd].size() != 2) f = false;
        }
        if(f) x++;
        else y++;
    }
    cout << x << " " << y << endl;
}