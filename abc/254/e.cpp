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
const int inf = 1 << 31;
const int _inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1LL << 62;
const long long _INF = 1000000000000000000;
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

graph g;
int n, m;
vector<vector<ll>> aa;
vector<vector<bool>> dist;

void load_map(int st, int k) {
    queue<P> pp;
    pp.push({st, 0});
    aa[st][0] = st + 1;

    while(!pp.empty()) {
        int kk, t;
        tie(t, kk) = pp.front();
        pp.pop();
        for(auto c : g[t]) {
            if(!dist[st][c] && kk < k) {
                dist[st][c] = true;
                pp.push({c, kk + 1});
                aa[st][kk + 1] += c + 1;
            }
        }
    }
}

int main(void) {
    fio();
    cin >> n >> m;
    g.resize(n);
    aa.resize(n, vector<ll>(4));
    dist.resize(n, vector<bool>(n));

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    rep(i, n) {
        load_map(i, 3);
        aa[i][2] -= i + 1;
    }

    int q;
    cin >> q;
    rep(i, q) {
        int x, k;
        cin >> x >> k;
        ll ans = 0;
        rep(j, k + 1) {
            ans += aa[x - 1][j];
        }
        pri(ans);
    }
}
