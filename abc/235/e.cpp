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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = vector<ll, ll>;
const int SIZE = 100005;
const int inf = 1000000000;
const int modi = 1000000007;
const long long INF = 10000000000;
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

Graph g;
using mint = modint998244353;
// using mint = modint1000000007;
/*
* クラスカル法を使えば、O(ElogE)で最小全域木を使うことは可能
* また、クラスカル法のなかで一番重い処理はソートなので、それを事前にできれば良い

*/

struct edge {
    int u, v;
    ll cost;
    ll idx;
};

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

edge es[1000000];
int n, m, q;

vector<bool> ans;

// 最小全域木のコストを求める
void kruskal() {
    sort(es, es + m + q, comp);
    dsu d(n);
    rep(i, m + q) {
        edge e = es[i];
        if(!d.same(e.u, e.v)) {
            if(e.idx != -1) ans[e.idx] = true;
            else d.merge(e.u, e.v);
        }
    }
}

int main(void) {
    fio();
    cin >> n >> m >> q;
    ans.resize(q, false);
    rep(i, m) {
        cin >> es[i].u >> es[i].v >> es[i].cost;
        es[i].u--;
        es[i].v--;
        es[i].idx = -1;
    }
    rep(i, q) {
        cin >> es[i + m].u >> es[i + m].v >> es[i + m].cost;
        es[i + m].u--;
        es[i + m].v--;
        es[i + m].idx = i;
    }
    kruskal();
    rep(i, q) yn(ans[i]);
}
