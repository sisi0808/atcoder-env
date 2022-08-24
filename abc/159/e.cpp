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
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
横に淹れる切れ込みを全探索し、そのあとは貪欲
これで、計算量は2^10 = 10^3 * 10^3

いくら縦線を入れてもk以下にならない場合をはじく方法
*/

int main(void) {
    fio();
    ll h, w, k;
    cin >> h >> w >> k;
    Graph s(h + 1, vector<ll>(w + 1));
    rep(i, h) {
        string t;
        cin >> t;
        rep(j, w) {
            s[i + 1][j + 1] = (t[j] - '0');
        }
    }

    rep(i, h + 1) rep(j, w) s[i][j + 1] += s[i][j];
    rep(j, w + 1) rep(i, h) s[i + 1][j] += s[i][j];

    ll ans = 1000000;
    // rep(i, h + 1) {
    //     rep(j, w + 1) {
    //         cout << s[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    rep(i, (1 << (h - 1))) {
        int wt = 0;
        ll _ans = 0;
        rep(jj, w) {
            int ht = 0;
            rep(ii, h) {
                if(ii == h - 1 || i & (1 << ii)) {
                    if(s[ii + 1][jj + 1] - s[ht][jj + 1] - s[ii + 1][wt] + s[ht][wt] > k) {
                        if(s[ii + 1][jj + 1] - s[ht][jj + 1] - s[ii + 1][jj] + s[ht][jj] > k) _ans = 1000000;
                        wt = jj;
                        _ans++;
                        break;
                    }
                    ht = ii + 1;
                }
            }
        }
        rep(ii, (h - 1)) if(i & (1 << ii)) _ans++;
        chmin(ans, _ans);
    }
    cout << ans << endl;
}
