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
 * どこかの頂点を赤いに、対象になっているはず
 * 頂点1と頂点Nの色は異なるはず
 *
 * 間の頂点の数は必ず偶数
 *
 * 0から距離1のところにa, 距離2のところにa, 距離3のところにb
 * nから距離1のところにb, 距離2のところにb, 距離3のところにa
 */

int main(void) {
    fio();
    int t;
    cin >> t;

    while(t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> c(n);
        rep(i, n) cin >> c[i];
        graph g(n);
        rep(i, m) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        /* st = 始点 */
        int st = 0;
        int ed = n - 1;
        graph dist(n, vector<int>(n, -1));
        dist[st][ed] = 0;
        queue<pair<int, int>> pp;
        pp.push({st, ed});

        while(!pp.empty()) {
            tie(st, ed) = pp.front();
            pp.pop();
            for(auto to_st : g[st]) {
                for(auto to_ed : g[ed]) {
                    if(c[to_st] == c[to_ed]) continue;
                    if(dist[to_st][to_ed] == -1) {
                        dist[to_st][to_ed] = dist[st][ed] + 1;
                        pp.push({to_st, to_ed});
                    }
                }
            }
        }

        cout << dist[n - 1][0] << endl;
    }
}
