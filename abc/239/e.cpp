#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
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
const int inf = 100000000;
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

using mint = modint998244353;

/*
k <= 20
そのため、各2分木のk番目までの数を記録しておけば良い
DFSで、木の末尾から配列を求めていく
*/

bool temp[300000];
vector<ll> x;
vector<vector<ll>> g;
vector<vector<ll>> mst;

void dfs(int now){
    if(now == 0)  mst[now].push_back(x[now]);
    temp[now] = true;

    for(int gg: g[now]){
        if(!temp[gg]){
            mst[gg].push_back(x[gg]);

            dfs(gg);

            // Vectorの結合
            mst[now].insert(mst[now].end(), ALL(mst[gg]));

            // ソートを行い、要素が20以上だったらそれは保持しない
            sort(RALL(mst[now]));
            mst[now] = {mst[now].begin(), mst[now].begin() + min(20, int(mst[now].end() - mst[now].begin()))};
        }
    }

    if(now == 0) return;
}

int main(void){
    fio();
    int n,q; cin >> n >> q;
    g.resize(n);
    mst.resize(n);
    x.resize(n);
    rep(i,n) cin >> x[i];
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);

    rep(i,q){
        ll v,k; cin >> v >> k;
        cout << mst[v-1][k-1] << endl;
    }
}
