#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i > 0; --i)
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
const int inf = INT_MAX;
const int modi = 1000000007;
const long long INF = LLONG_MAX;
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
vector<ll> cou;
vector<vector<pair<ll, ll>>> G;

/*
 最短経路は必ず一つ
 各頂点毎に通る合計数を記録
 kが-+で処理は変わらない
まず絶対値で試す

*/

/* 現在頂点, 親頂点, 目標頂点 */
int dfs(int v, int p, int t){
    if(v == t) return 1;
    for(auto [g, i]: G[v]){
        if(p != g){
            if(dfs(g, v, t)){
                cou[i]++;
                return 1;
            }
        }
    }
    return 0;
}

int main(void){
    fio();
    int n,m,k; cin >> n >> m >> k;
    G.resize(n);
    cou.resize(n,0);

    vector<int> a(m);
    rep(i,m){ cin >> a[i]; a[i]--;}

    rep(i,n-1){
        int u,v; cin >> u >> v;
        u--;  v--;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    repp(i,m,1) dfs(a[i-1], -1, a[i]);

    ll S = 0;
    rep(i,n-1) S += cou[i];
    if((S+k) % 2 || S+k < 0){
        cout << 0;
        return 0;
    }

    vector<mint> dp(100010, 0);
    dp[0] = 1;


    rep(i,n-1){
        for(int x = 100000; x >= cou[i]; x--){
            dp[x] +=  dp[x-cou[i]];
        }
    }

    cout << dp[(k+S)/2].val() << endl;
}
