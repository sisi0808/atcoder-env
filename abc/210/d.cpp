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

Graph g, q;
using mint = modint998244353;
//using mint = modint1000000007

vector<vector<ll>> rot_90(vector<vector<ll>> IMAGE, int x_size, int y_size){

    vector<vector<ll>> rot(x_size, vector<ll> (y_size));
    vector<ll> tmp(y_size);
    int i;
    int j;
    for(j = 0; j < x_size; j++){
        for (i = 0; i < y_size; i++){
            tmp[i] = IMAGE[y_size-i-1][j];
        }
        for(i = 0; i < y_size; i++){
            rot[j][i] = tmp[i];
        }
    }
    return rot;
}

int main(void){
    fio();
    int h,w;
    ll c;
    ll ans = INF;

    cin >> h >> w;
    cin >> c;
    g.resize(h, vector<ll> (w));
    rep(i,h) rep(j,w) cin >> g[i][j];
    q = rot_90(g, w, h);

    //dfs(0, 0);

    rep(i,h) {
        rep(j,w){
            if(i != 0) { ans = min(ans, g[i][j]+g[i-1][j] + c); }
            if(j != 0) { ans = min(ans, g[i][j]+g[i][j-1] + c); }
            if(i != 0) { g[i][j] = min(g[i][j], g[i-1][j] + c); }
            if(j != 0) { g[i][j] = min(g[i][j], g[i][j-1] + c); }
        }
    }
    rep(i,w) {
        rep(j,h){
            if(i != 0) { ans = min(ans, q[i][j]+q[i-1][j] + c); }
            if(j != 0) { ans = min(ans, q[i][j]+q[i][j-1] + c); }
            if(i != 0) { q[i][j] = min(q[i][j], q[i-1][j] + c); }
            if(j != 0) { q[i][j] = min(q[i][j], q[i][j-1] + c); }
        }
    }

    cout << ans << endl;
}
