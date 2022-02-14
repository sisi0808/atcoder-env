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

/*
つまり任意の4つの点の集合で、X,yが２種類ずつしか存在しないもの

対角となる点を選び、それに対応する２点があるか調べる
*/

int main(void){
    fio();
    int n; cin >> n;

    vector<pair<ll, ll>> xy(n);
    rep(i,n) cin >> xy[i].first >> xy[i].second;

    sort(ALL(xy));

    ll ans = 0;
    rep(i,n){
        rep(j,n){
            // この判定文により、同じ長方形が２回加算される事を防ぐ(２点の位置関係は必ず左下と右上)
            if(!(xy[i].first < xy[j].first && xy[i].second < xy[j].second)) continue;
            if(binary_search(ALL(xy), make_pair(xy[i].first, xy[j].second)) && (binary_search(ALL(xy), make_pair(xy[j].first, xy[i].second)))){
                ans ++;
            }
        }
    }

    cout << ans << endl;
}
