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
* 手順に順番は関係ない
* おそらく全探索

* (mn, mx) = (0, 999*3)

* 合成で得られるすべての組み合わせを列挙

8C1 + 8C2 + (8C2)C2

dp[a][b][c] = (長さa,長さb, 長さc, MP)

思いついた手順
1. N個数からa,b,cに該当する三種を取得
2. それぞれを合致させるのに最適な値を求める
*/

int main(void) {
    fio();
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<ll> l(n);
    rep(i, n) cin >> l[i];

    vector<int> o(n);
    iota(ALL(o), 0); // a == {0,1,2,3,4}

    ll ans = INF;
    do {
        ll a_cnt = 0;
        repp(i, n + 1, 3) {
            // ll a_mp = min(abs(l[0] - a), abs(l[0] + a_cnt - a));
            ll a_mp = abs(l[o[0]] + a_cnt - a) + (i - 3) * 10;
            ll b_cnt = 0;
            repp(j, n + 1, i) {
                // ll b_mp = min(abs(l[1] - b), abs(l[1] + b_cnt - b));
                ll b_mp = abs(l[o[1]] + b_cnt - b) + (j - i) * 10;
                ll c_cnt = 0;
                repp(k, n + 1, j) {
                    // ll c_mp = min(abs(l[2] - c), abs(l[2] + c_cnt - c));
                    ll c_mp = abs(l[o[2]] + c_cnt - c) + (k - j) * 10;
                    chmin(ans, a_mp + b_mp + c_mp);
                    if(k != n) c_cnt += l[o[k]];
                }
                if(j != n) b_cnt += l[o[j]];
            }
            if(i != n) a_cnt += l[o[i]];
        }
    } while(next_permutation(ALL(o)));
    cout << ans << endl;
}
