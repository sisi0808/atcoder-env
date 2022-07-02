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

<= N の出費で最大のX利益

* 最大で操作回数は(n / min([C1-9]]))
    * 最大回数にするのが吉
    *
順番が大切な問題でもある

10(10(10(i_1)+i_2)+i_3)+i_4

10^(i-1)*(i_1) + 10^(i-2)*(i_2) + 10^(i-3)*(i_3) + 10^(i-4)*(i_4)

1. 最大回数が何回かを求める
2. 同じ回数の中で、出来るだけ大きい数を選択出来るようにする

大きい数はなるべく早めに選択した方が良い



*/

int main(void) {
    fio();
    int n;
    cin >> n;
    ivec c(10);
    rep(i, 9) cin >> c[i + 1];
    int min_c = 10000000;
    rep(i, 9) chmin(min_c, c[i + 1]);

    // 操作の回数
    // 上の桁の方から貪欲に決めていけばよい
    string ans = "";
    // cout << n << ":" << min_c << endl;
    int max_cnt = (n / min_c);
    rep(i, max_cnt) {
        for(int j = 9; j > 0; j--) {
            int rest_len = max_cnt - i - 1;
            int rest_n = n - c[j];
            if(0 <= rest_n && rest_len <= rest_n / min_c) {
                ans += char('0' + j);
                n -= c[j];
                // cout << ans << ":" << j << endl;
                break;
            }
        }
    }
    cout << ans << endl;
}
