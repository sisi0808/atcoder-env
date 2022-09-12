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
最大でも2種類(0 or 1)
つまり、1か2のどちらになるかを答える問題

全てのmodを同じにできる共通の数が一つあるかないか


昇順で並べた時の、それぞれの数の差が一定の数の倍数になればよい
*/

// 1以外の因数を集める(元の数xも含む)
vector<ll> pfact(ll x) {
    vector<ll> res;
    for(ll i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            x /= i;
            res.push_back(i);
        }
    }
    if(x != 1) res.push_back(x);
    return res;
}

int main(void) {
    fio();
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a));
    ll min_d = 1000000000000;
    rep(i, n - 1) {
        if(a[i] == a[i + 1]) continue;
        chmin(min_d, a[i + 1] - a[i]);
    }
    vector<ll> v = pfact(min_d);
    rep(i, n - 1) {
        ll b = a[i + 1] - a[i];
        bool ans = false;
        for(auto vv : v) {
            if(b % vv == 0) ans = true;
        }
        if(!ans) {
            cout << 2 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}
