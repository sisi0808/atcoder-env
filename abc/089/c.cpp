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

// 組み合わせの数nCrを計算
ll calcNumOfCombination(ll n, ll r) {
    ll num = 1;
    for(ll i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int main(void) {
    fio();
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];

    string key = "MARCH";
    vector<ll> km(5);
    rep(i, n) {
        rep(j, 5) {
            if(a[i][0] == key[j]) km[j]++;
        }
    }
    ll sum_k = accumulate(ALL(km), 0ll);
    ll ans = 0;
    if(sum_k >= 3) ans = calcNumOfCombination(sum_k, 3);
    rep(i, 5) {
        if(km[i] >= 3) ans -= calcNumOfCombination(km[i], 3);
    }
    rep(i, 5) {
        if(km[i] >= 2) ans -= calcNumOfCombination(km[i], 2) * (sum_k - km[i]);
    }
    cout << ans << endl;
}
