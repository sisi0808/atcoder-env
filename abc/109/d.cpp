#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include <atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n, m) for(int i = n; i >= m; --i)
#define repp(i, n, m) for(int i = m; i < int(n); ++i)
#define fore(i_in, a) for(auto &i_in : a)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define chmin(a, b) a = min((ll)a, (ll)b)
#define chmax(a, b) a = max((ll)a, (ll)b)

#define pb push_back
#define pf push_front

#define fi first
#define se second

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using ivec = vector<int>;
using lvec = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1 << 30;
const int _inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1LL << 62;
const long long _INF = 1000000000000000000LL;
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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
* 最大化すると、奇数マスの数は0 or 1(コイン和の偶奇に従う)

* 操作方法
1. 奇数枚同士の座標でペアを作成
2. その間を移動


各マスは最大でも1回しか操作出来ない
*/

int main(void) {
    fio();
    ll h, w;
    cin >> h >> w;
    Graph g(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> g[i][j];

    // int f = true;
    // int idx = 0;
    pair<ll, ll> xy;

    bool e = false; // 伝送中か

    ll n = 0;
    graph ans(h * w, vector<int>(4));
    rep(i, h) {
        rep(j, w) {
            int ii, jj;
            ii = i;
            if(i % 2 == 0ll) jj = j;
            else jj = w - j - 1;

            if(e) { // 伝送中の場合
                ans[n][0] = xy.first;
                ans[n][1] = xy.second;
                ans[n][2] = ii;
                ans[n][3] = jj;
                n++;
                xy = {ii, jj};
                if(g[ii][jj] % 2 == 1ll) { // 伝送が終わる場合
                    e = false;
                }

            } else {                       // 伝送していない場合
                if(g[ii][jj] % 2 == 1ll) { // 新しく伝送する場合
                    e = true;
                    xy = {ii, jj};
                }
            }
        }
    }
    cout << n << endl;
    rep(i, n) {
        rep(j, 3) {
            cout << ans[i][j] + 1 << " ";
        }
        cout << ans[i][3] + 1 << endl;
        // cout << endl;
    }
}
