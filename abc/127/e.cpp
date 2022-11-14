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
* 恐らくxy独立に計算が可能
* まずは一次元年て考えてみる


ある点xに絞って考えると、
    それが計算に関与する回数
*/

mint nCr(ll n, ll r) {
    mint num = 1;
    for(int i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int main(void) {
    fio();
    ll h, w, k;
    cin >> h >> w >> k;

    mint ans = 0;
    // repp(i, w, 1) ans += i * (w - 1) * (h * h);
    // repp(i, h, 1) ans += i * (h - 1) * (w * w);
    // repp(i, w, 1) ans += (mint)i * (w - 1) * (h * h);
    // repp(i, h, 1) ans += (mint)i * (h - 1) * (w * w);
    // repp(i, w, 1) ans += (w - i) * (h * h);
    // repp(i, h, 1) ans += (h - i) * (w * w);
    repp(i, w, 1) ans += (mint)i * (mint)(w - i) * (mint)(h * h);
    repp(i, h, 1) ans += (mint)i * (mint)(h - i) * (mint)(w * w);

    // rep(i,h){
    //     rep(j,m){

    //     }
    // }
    ans *= nCr(h * w - 2, k - 2);
    cout << ans.val() << endl;
}
