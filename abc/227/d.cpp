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

/*
プロジェクトに配属される最大人数ΣAi
プロジェクトは最大でΣAi / K
sum_h = ΣAi
sum_p = ΣAi / K

作れない時:
* 残りの部署数がK個以下
プロジェクト数
(sum_h - Σremain(k)) / k


小さい方から見ていき、その時点までの合計数と全体数を比較
合計数が全体数の半部を上回ったらbreak;
*/

int main(void){
    fio();
    int n,k; cin >> n >> k;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];

    ll ok = 0;
    ll ng = 1e18 / k;

    while(ng-ok > 1){
        ll x = (ok+ng)/2; ll sum_h = 0;
        rep(i,n){ sum_h += min(A[i], x); }
        if(sum_h >= x*k) ok = x;
        else ng = x;

    }
    cout << ok << endl;

}
