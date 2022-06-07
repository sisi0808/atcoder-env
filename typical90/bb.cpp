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

/*
 * Tと直接の共著がある場合、高橋数は１
 * 共著した人間との高橋数はn+1
 *
 *
 * グラフの可能性が高い気がする
 *  距離が１の場合、高橋数は１
 *
 *
 * その時点で最も高橋数が高いものから線を伸ばす？
 */

int n, m;
vector<vector<int>> g, o;
vector<int> dist, dad;

void load_map(int st) {
    dist.resize(n, -1);
    dad.resize(m, -1);
    dist[st] = 0;
    queue<int> pp;
    pp.push(st);

    while(!pp.empty()) {
        st = pp.front();
        pp.pop();
        /* c == 共著者グループ番号 */
        for(auto c : g[st]) {
            if(dad[c] != -1) continue;
            dad[c] = 1;
            /* d == 著者番号 */
            for(auto d : o[c]) {
                if(dist[d] == -1) {
                    dist[d] = dist[st] + 1;
                    pp.push(d);
                }
            }
        }
    }
}
/*
 * どの共著に関わったか
 * その共著の著者
 */

int main(void) {
    fio();
    cin >> n >> m;
    g.resize(n);
    o.resize(m);

    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int v;
            cin >> v;
            v--;
            g[v].push_back(i);
            o[i].push_back(v);
        }
    }
    load_map(0);

    rep(i, n) {
        pri(dist[i]);
    }
}
