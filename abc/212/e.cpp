#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include <atcoder/all>
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
* 閉路は必須
* 同じ所を通っても良い

* 頂点jで終わる、長さkの道

* あり得るすべての組み合わせから、除外する頂点を使う経路を引けば良い?


* 道a,bが使えない時の答え
* = すべての道が使える時 - (道aを使う時 + 道bを使う時) + 道abを使う時
*/

int main(void) {
    fio();
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<mint>> dp(2, vector<mint>(n));
    dp[0][0] = 1;

    graph g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 経路の長さ
    rep(i, k) {
        mint sum_a = 0; // 今の頂点から各頂点へ行く時の場合の数
        rep(j, n) sum_a += dp[0][j];
        // 自己ループの分を引く
        rep(j, n) dp[1][j] = sum_a - dp[0][j];

        // ここまでの操作で、dp[1]にはすべての道がつながっている場合の通り数が格納
        // ここから、断絶された経路分を引く
        rep(j, n) {
            for(auto h : g[j]) {
                dp[1][h] -= dp[0][j];
            }
        }

        rep(j, n) dp[0][j] = dp[1][j];
    }
    cout << dp[0][0].val() << endl;
}
