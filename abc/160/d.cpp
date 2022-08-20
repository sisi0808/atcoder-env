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
恐らくだが、追加した辺の左側・中側・右側で分離可能
*/

int n, x, y;
graph g;
vector<int> dist; // 各頂点が探索済みか
vector<int> ans;

/* st = 始点 */
void load_map(int st) {
    int sst = st;
    rep(i, n) dist[i] = -1;
    dist[st] = 0;
    queue<int> pp;
    pp.push(st);

    while(!pp.empty()) {
        st = pp.front();
        pp.pop();
        for(auto c : g[st]) {
            if(dist[c] == -1) {
                dist[c] = dist[st] + 1;
                if(c > sst) ans[dist[c]]++;
                // else cout << c << ":" << st << endl;
                pp.push(c);
            }
        }
    }
}

int main(void) {
    fio();
    cin >> n >> x >> y;
    g.resize(n);
    ans.resize(n);
    rep(i, n - 1) {
        g[i].pb(i + 1);
        g[i + 1].pb(i);
    }
    g[x - 1].pb(y - 1);
    g[y - 1].pb(x - 1);

    // rep(i, n) {
    //     for(auto q : g[i]) {
    //         cout << q << " ";
    //     }
    //     cout << endl;
    // }

    // ll l = x;
    // ll m = y - x + 1;
    // ll r = n - x + 1;

    dist.resize(n);
    rep(i, n - 1) {
        load_map(i);
        // cout << ans[3] << endl;
    }
    rep(i, n - 1) cout << ans[i + 1] << endl;
}
