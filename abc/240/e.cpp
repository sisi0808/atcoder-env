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

//graph G;
using mint = modint998244353;

/*
最大値は葉の数
yt
*/
vector<int>  G[501010];
int L[501010], R[501010];
int leaf[500000];
int id = 0;

// 葉に番号を割り振る
// (v, p) = (見ているnode, 親のnode)
void dfs(int v, int p){
    /* 葉の場合 */
    if(v != 0 && G[v].size() == 1){
        leaf[v] = ++id;
        return;
    }
    for(auto u: G[v]) if(u != p) dfs(u, v);
}

// nodeに組み合わせを割り当てる
// (v, p) = (見ているnode, 親のnode)
void dfs2(int v, int p){
    /* 葉の場合 */
    if(leaf[v]){
        L[v] = R[v] = leaf[v];
        return;
    }
    //L[v] = 1e9; R[v] = 0;
    for(auto u: G[v]){
        if(u == p) continue;
        else{
            dfs2(u, v);
            L[v] = min(L[v], L[u]);
            R[v] = max(R[v], R[u]);
        }
    }
}


int main(void){
    fio();
    int n; cin >> n;
    rep(i,n-1){
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i,n){
        L[i] = inf;
        R[i] = 0;
    }

    dfs(0, -1);
    dfs2(0, -1);

    //rep(i,n) cout << leaf[i] << endl;

    /* 回答 */;
    rep(i,n){
        cout << L[i] << " " << R[i] << endl;
    }
}
