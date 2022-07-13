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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*

その集合の中の数は互いに素？
互いが互いの約数ではない状態
選ぶなら大きい数から

* 素因数分解
* 約数列挙
* エラトステネスの篩
*

*/

int main(void) {
    fio();
    int n;
    cin >> n;
    vector<ll> a(n);         // 入力
    vector<ll> b(1000003);   // その数字が何回出てきたか（重複確認用）
    vector<bool> c(1000003); // その数字の倍数を記録（エラトステネス）
    rep(i, n) cin >> a[i];
    rep(i, n) b[a[i]]++;

    rep(i, 1000003) {
        if(b[i] == 0) continue;
        if(b[i] > 1) c[i] = true;
        for(int j = i * 2; j < 1000003; j += i) {
            c[j] = true;
        }
    }

    ll ans = 0;
    rep(i, n) if(c[a[i]] == false) ans++;
    cout << ans << endl;
}
