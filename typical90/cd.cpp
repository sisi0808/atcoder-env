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

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using vs = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1000000000000000;
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

/* a+1からbまでの等差数列の和 */
mint tousa_sum(ll a, ll b) {
    mint aa = mint(a);
    mint bb = mint(b);
    mint small_a = (aa * (aa + 1) / 2);
    mint big_b = (bb * (bb + 1) / 2);

    return big_b - small_a;
}

int main(void) {
    fio();
    ll l, r;
    cin >> l >> r;
    mint ans = 0;
    int l_d = to_string(l).size();
    int r_d = to_string(r).size();
    /* 桁が(l_r, r_d)の時の文字の個数を計算 */
    repp(i, r_d, l_d + 1) {
        ans += i * tousa_sum(pow_mod(10LL, i - 1, modl) - 1, pow_mod(10LL, i, modl) - 1);
    }
    /* 桁が同じ場合 */
    if(l_d == r_d) {
        ans += l_d * tousa_sum(l - 1, r);
    }
    /* 違う場合は[l, l_r+1), [l_r r]を計算 */
    else {
        ans += l_d * tousa_sum(l - 1, pow_mod(10LL, l_d, modl) - 1);
        // cout << ans.val() << endl;
        ans += r_d * tousa_sum(pow_mod(10LL, r_d - 1, modl) - 1, r);
    }

    pri(ans.val());
}
