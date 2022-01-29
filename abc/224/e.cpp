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

//graph G;
using mint = modint998244353;

/*
* 二分探索を用いる
* 最大移動回数は[その座標よりも大きい数]の数
* これ以上移動出来ない＝自分より大きい数が縦横にいない
* メモ化が使いやすい

* 自分がいる列で2分探索を行い、自分以上がいるか

目の整数、何番目か
vector<pair<ll,ll>> mp
*/

int main(void){
    fio();
    int h,w,n; cin >> h >> w >> n;

    /* i毎の情報*/
    vector<ll> r(n),c(n),a(n);
    /* (key,value) = (a, [i1...)  */
    map<ll, vector<int>> mp;
    /* 縦、横ごとの最大値*/
    vector<ll> rmax(h+1,0), cmax(w+1,0);
    /* 答え */
    vector<ll> dp(n);

    rep(i,n){
        cin >> r[i] >> c[i] >> a[i];
        mp[a[i]].push_back(i);
    }

    /* key(a)が大きい方から逆順に*/
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        for(auto i : it->second) dp[i] = max(rmax[r[i]], cmax[c[i]]);
        for(auto i : it->second){
            rmax[r[i]] = max(rmax[r[i]], dp[i] + 1);
            cmax[c[i]] = max(cmax[c[i]], dp[i] + 1);
        }
    }

    rep(i,n) cout << dp[i] << endl;

}