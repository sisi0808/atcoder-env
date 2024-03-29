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
const int inf = 1 << 31;
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

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
どう見てもDP!
*/

int main(void) {
    fio();
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<mint>> a(h, vector<mint>(w));

    vector<vector<mint>> add_h(h, vector<mint>(w));
    vector<vector<mint>> add_w(h, vector<mint>(w));
    vector<vector<mint>> add_cross(h, vector<mint>(w));
    add_h[0][0] = 1;
    add_w[0][0] = 1;
    add_cross[0][0] = 1;

    rep(i, h) {
        rep(j, w) {
            if(i == 0 && j == 0) continue;
            if(s[i][j] == '#') continue;

            if(i != 0) add_h[i][j] += a[i - 1][j] + add_h[i - 1][j];
            if(j != 0) add_w[i][j] += a[i][j - 1] + add_w[i][j - 1];
            if(i != 0 && j != 0) add_cross[i][j] += a[i - 1][j - 1] + add_cross[i - 1][j - 1];

            a[i][j] = add_h[i][j] + add_w[i][j] + add_cross[i][j];
        }
    }

    // rep(i, h) {
    //     rep(j, w) {
    //         cout << a[i][j].val() << ' ';
    //     }
    //     cout << endl;
    // }
    cout << a[h - 1][w - 1].val() << endl;
}
