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
//using mint = modint998244353;
using mint = modint1000000007;
int n,m;

vector<vector<int>> g;
vector<mint> ans;

vector<int> temp;

void bfs(int st){
    int dis;
    temp[st] = 1;
    // 次に探索する経路、距離
    queue<int> pp;
    pp.push(st);

    while(!pp.empty()){
        st = pp.front(); pp.pop();
        for(auto c: g[st]){
            /* 最短経路更新の場合 */
            if(temp[st]+1 < temp[c]){
                temp[c] = temp[st] + 1;
                ans[c] = ans[st];
                pp.push(c);
            }
            /* 最短経路の場合 */
            else if(temp[st]+1 == temp[c]){
                ans[c] += ans[st];
            }
        }
    }
}

int main(void){
    fio();
    cin >> n >> m;
    g.resize(n);
    ans.resize(n);
    temp.resize(n, INT_MAX);

    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ans[0] = 1;
    bfs(0);

    if(ans[n-1] != INT_MAX) cout << ans[n-1].val() << endl;
    else cout << 0 << endl;

}
