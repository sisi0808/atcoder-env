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

graph G;
using mint = modint998244353;
/*
パターンは以下の2つか、それをRotateした計１２通りのみ

(x,y) * (a,b,c) * 以下のパターン
 --------------
|              |
 --------------
 --------------
|              |
 --------------
 --------------
|              |
 --------------
       OR
 --------------
|              |
 --------------
 ------ -------
|      ||      |
|      ||      |
|      ||      |
|      ||      |
 ------ -------
*/

bool f2(ll x, ll y, ll a, ll b){
    ll w = ceil(a,y) + ceil(b,y);
    return w <= x;
}

bool f(ll x, ll y, ll a, ll b, ll c){
    ll w = ceil(a,y);
    if(w >= x) return false;
    x -= w;
    return f2(x,y,b,c) || f2(y,x,b,c);
}

int main(void){
    fio();
    ll x,y,a,b,c; cin >> x >> y >> a >> b >> c;

    /* fiは(x,y)の条件*/
    rep(fi,2) {
        /* riは(x,y)の条件*/
        rep(ri,3){
            if(f(x,y,a,b,c)){
                yes();
                return 0;
            }
            swap(a,b); swap(b,c);
        }
        swap(x,y);
    }
    no();
}
