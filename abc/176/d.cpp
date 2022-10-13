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
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
 * 多分,BFSで行ける
 * 探索の際は、徒歩とワープを別の配列に入れる
 */

ll h, w;
ll sty, stx, edy, edx;
vector<string> s;
vector<vector<int>> g;

bool judge_masu(int y, int x) {
    if(y < 0 || x < 0) return false;
    if(y >= h || x >= w) return false;
    if(s[y][x] == '#') return false;
    return true;
}

/* st = 始点 */
int load_map() {
    g[sty][stx] = 0;
    queue<P> pp;
    pp.push({sty, stx});

    while(!pp.empty()) {
        sty = pp.front().first;
        stx = pp.front().second;
        pp.pop();

        /* 徒歩移動出来るか */
        rep(i, 4) {
            int y = sty + dy[i];
            int x = stx + dx[i];
            cout << sty << " " << stx << endl;
            cout << y << " " << x << endl;
            cout << endl;
            if(judge_masu(y, x)) {
                if(g[sty][stx] < g[y][x] && g[y][x] == -1) {
                    g[y][x] = g[sty][stx];
                    pp.push({y, x});
                }
            }
        }

        // for(auto c : g[st]) {
        //     if(dist[c] == -1) {
        //         dist[c] = dist[st] + 1;
        //         pp.push(c);
        //     }
        // }
    }
    return g[edy][edx];
}

int main(void) {
    fio();
    cin >> h >> w;
    cin >> sty >> stx >> edy >> edx;
    s.resize(h);
    g.resize(h, vector<int>(w, -1)); // 最短ワープ回数
    rep(i, h) cin >> s[i];

    cout << load_map() << endl;

    rep(i, h) {
        rep(j, w) {
            cout << g[i][j];
        }
        cout << endl;
    }
}
