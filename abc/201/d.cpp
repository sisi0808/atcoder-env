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
// using mint = modint1000000007;

/*
* ゲーム終了は右下
* ゴールから始めると計算可能？

* ゴール及び端から始める野が良さそう
*/

int main(void) {
    fio();
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    /* そのマスに入った時の、残りの行動による(自分の得点 - 相手の特典)の最大値 */
    vector<vector<ll>> c(h, vector<ll>(w, -6000000));
    c[h - 1][w - 1] = 0;

    /* 最大を最小化 */

    rrep(i, h - 1) {
        rrep(j, w - 1) {
            if(i == h - 1 && j == w - 1) continue;
            if(i + 1 < h) {
                ll b = 1;
                if(a[i + 1][j] == '-') b = -1;
                chmax(c[i][j], -c[i + 1][j] + b);
            }
            if(j + 1 < w) {
                ll b = 1;
                if(a[i][j + 1] == '-') b = -1;
                chmax(c[i][j], -c[i][j + 1] + b);
            }
        }
    }
    // rep(i, h) {
    //     rep(j, w) {
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if(c[0][0] > 0) cout << "Takahashi" << endl;
    else if(c[0][0] < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
}
