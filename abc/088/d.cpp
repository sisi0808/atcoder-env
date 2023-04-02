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
白いマス目の数 - 最短経路の数
*/
ll h, w;
vector<string> s;

bool judge(int y, int x) {
    if(y < 0 || x < 0) return false;
    if(y >= h || x >= w) return false;
    if(s[y][x] == '#') return false;
    return true;
}

int main(void) {
    fio();
    cin >> h >> w;
    s.resize(h);
    rep(i, h) cin >> s[i];

    ll ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '.') ans++;
        }
    }

    /* st = 始点 */
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 0;
    queue<P> pp;
    pp.push({0, 0});

    while(!pp.empty()) {
        int y, x;
        tie(y, x) = pp.front();
        pp.pop();
        rep(i, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(!judge(yy, xx)) continue;
            if(dist[yy][xx] == -1) {
                dist[yy][xx] = dist[y][x] + 1;
                pp.push({yy, xx});
            }
        }
    }
    if(dist[h - 1][w - 1] == -1) cout << -1 << endl;
    else cout << ans - 1 - dist[h - 1][w - 1] << endl;
}
