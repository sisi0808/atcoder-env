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
* h or wが3で割れるのなら、答えは0
* 最大公約数などの問題になりそう？

* あり得るパターン
    全部を縦 or 横一列
    一つが縦、他が横
    一つが横、他が縦

* 一つ場所が確定したら、他の二つも決まる？
*/

ll h, w;
int main(void) {
    fio();
    cin >> h >> w;

    ll ans = INF;

    /* 縦3の場合 */
    chmin(ans, min(1ll, h % 3) * w);
    /* 横3の場合 */
    chmin(ans, min(1ll, w % 3) * h);

    repp(i, h, 1) {
        /* 縦1, 横2の場合 */
        ll s1 = i * w;
        ll s2 = (h - i) * (ll)((w + 1) / 2);
        ll s3 = (h - i) * (ll)(w / 2);
        chmin(ans, max({abs(s1 - s2), abs(s2 - s3), abs(s3 - s1)}));
    }
    repp(i, w, 1) {
        /* 縦2, 横1の場合 */
        ll s1 = i * h;
        ll s2 = (w - i) * (ll)((h + 1) / 2);
        ll s3 = (w - i) * (ll)(h / 2);
        chmin(ans, max({abs(s1 - s2), abs(s2 - s3), abs(s3 - s1)}));
    }
    cout << ans << endl;
}