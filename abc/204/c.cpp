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
//using mint = modint1000000007;

int n,m;
int temp[3000][3000];


void dfs(int st){
    queue<int> q;
    q.push(st);

    while(!q.empty()){
        int qq = q.front(); q.pop();
        for(auto load : g[qq]){
            if(!temp[st][load]){
                q.push(load);
                temp[st][load] = 1;
            }
        }
    }
}

int main(void){
    fio();
    cin >> n >> m;
    g.resize(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    rep(i,n+1) rep(j,n+1) temp[i][j] = 0;
    rep(i,n+1) temp[i][i] = 1;

    rep(i,n) dfs(i);

    ll ans = 0;
    rep(i,n){
        rep(j,n){
            ans += temp[i][j];
        }
    }

    cout << ans << endl;
}
