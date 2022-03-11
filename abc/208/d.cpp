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

graph G;
using mint = modint998244353;
//using mint = modint1000000007;

int n, m;
bool temp[300000];
vector<vector<pair<ll, ll>>> yg;
vector<vector<vector<ll>>> ans;

void bfs(int st, int k){
    queue<int> q;
    q.push(st);

    while(!q.empty()){
        int now = q.front(); q.pop();
        for(pair<ll, ll> p : yg[now]){
            ll ed, c;
            tie(ed, c) = p;
            if(ed < k && ans[st][now][k] + c < ans[st][ed][k]){
                ans[st][ed][k] = ans[st][now][k] + c;
                q.push(ed);
            }
        }

    }
}

int main(void){
    fio();
    cin >> n >> m;
    yg.resize(n);
    ans.resize(n, vector<vector<ll>> (n, vector<ll> (n, INF)));
    rep(j,n) rep(i,n) ans[i][i][j] = 0;
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--; b--;
        yg[a].push_back({b, c});
    }

    ll ans = 0;;
    rep(i,n){
        rep(j,n){
            bfs(i,j);
            rep(l, n){
                //cout << i << j << l << endl;
                //if(ans[i][l][j] != INF) ans+= ans[i][l][j];
                if(ans.at(i).at(l).at(j) != INF) ans+= ans.at(i).at(l).at(j);
            }
        }
    }

    cout << ans << endl;
}