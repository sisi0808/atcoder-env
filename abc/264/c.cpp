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

int main(void) {
    fio();
    ll h1, w1;
    cin >> h1 >> w1;
    Graph a(h1, vector<ll>(w1));
    rep(i, h1) rep(j, w1) cin >> a[i][j];

    ll h2, w2;
    cin >> h2 >> w2;
    Graph b(h2, vector<ll>(w2));
    rep(i, h2) rep(j, w2) cin >> b[i][j];

    Graph c(h2, vector<ll>(w2));

    rep(i, (1 << h1)) {
        int cnt = 0;
        rep(ii, h1) if(i & (1 << ii)) cnt++;
        if(cnt != h2) continue;
        rep(j, (1 << w1)) {
            cnt = 0;
            rep(jj, w1) if(j & (1 << jj)) cnt++;
            if(cnt != w2) continue;

            rep(ii, h2) rep(jj, w2) c[ii][jj] = 0;

            int c_cnt = 0;
            rep(ii, h1) {
                rep(jj, w1) {
                    if((i & (1 << ii)) && (j & (1 << jj))) {
                        // cout << c_cnt % w2 << ":" << (int)(c_cnt / w2) << endl;
                        c[(int)(c_cnt / w2)][c_cnt % w2] = a[ii][jj];
                        c_cnt++;
                    }
                }
            }

            if(b == c) {
                yes();
                return 0;
            }
        }
    }
    no();
}
