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

graph G;
vector<ll> dist;
using mint = modint998244353;

int n,m;
vector<ll> h;

void load_map(int st){
    dist.resize(n,-1*INF);
    dist[st]=0;
    queue<ll> pp;
    pp.push(st);

    while(!pp.empty()){
        st = pp.front(); pp.pop();
        for(auto c: G[st]){
            /* 幸福が＋になるとき */
            if(h[st] > h[c]){
                if(dist[c] < dist[st] + (h[st]-h[c])){
                    dist[c] = dist[st] + (h[st]-h[c]);
                    pp.push(c);
                }
            }
            /* 幸福が－になるとき */
            else if(h[st] <= h[c]){
                if(dist[c] < dist[st] + 2*(h[st]-h[c])){
                    dist[c] = dist[st] + 2*(h[st]-h[c]);
                    pp.push(c);
                }
            }
        }
    }
}

int main(void){
    fio();
    cin >> n >> m;
    h.resize(n);
    G.resize(n);
    rep(i,n) cin >> h[i];
    rep(i,m) {
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    load_map(0);

    ll ans = 0;
    rep(i,n){
        if(ans < dist[i]) ans = dist[i];
    }

    cout << ans << endl;
}
