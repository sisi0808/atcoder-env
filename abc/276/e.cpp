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
最短経路ならぬ最長経路
*/

ll h, w;
vector<ll> dist; // 各頂点が探索済みか
vector<vector<ll>> g;
/* st = 始点 */
void load_map(int st, int col) {
    dist.resize(h * w, -1);
    dist[st] = 0;
    queue<int> pp;
    pp.push(st);

    while(!pp.empty()) {
        st = pp.front();
        pp.pop();
        for(auto c : g[st]) {
            if(dist[c] == -1) {
                dist[c] = col;
                pp.push(c);
            } else if(dist[c] != col && dist[c] != 0ll) {
                yes();
                exit(0);
            }
        }
    }
}

int main() {
    fio();
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    g.resize(h * w);

    int sty, stx; //始点
    rep(i, h) {
        rep(j, w) {
            if(c[i][j] == '#') continue;
            if(c[i][j] == 'S') {
                sty = i;
                stx = j;
            }
            rep(k, 4) {
                int y = i + dy[k];
                int x = j + dx[k];
                if(y >= h || y < 0) continue;
                if(x >= w || x < 0) continue;
                if(c[y][x] == '#') continue;
                g[i * w + j].pb(y * w + x);
                g[y * w + x].pb(i * w + j);
            }
        }
    }
    dist.resize(h * w, -1);
    dist[sty * w + stx] = 0;
    rep(k, 4) {
        int y = sty + dy[k];
        int x = stx + dx[k];
        if(y >= h || y < 0) continue;
        if(x >= w || x < 0) continue;
        if(c[y][x] == '#') continue;
        load_map(y * w + x, k + 1);
    }
    no();
}