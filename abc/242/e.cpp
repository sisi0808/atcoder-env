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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = vector<ll, ll>;
const int SIZE = 100005;
const int inf = 100000000;
const int modi = 1000000007;
const long long INF = 10000000000;
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

graph G;
using mint = modint998244353;
// using mint = modint1000000007

/*
* 回分である以上、0~|s|/2までが確定すれば後半も自動的に求まる

* 考え方としては桁DPが最も近い

満たすべき条件

* 前半がS以下か
* 後半がS以下か
* 回分か

* 前半で<Sであることが確定した場合、後半は何でも良い
* ==である場合、後半に気を使う
*/

int main(void) {
    fio();
    int t;
    cin >> t;
    vector<vector<mint>> dp;

    vector<mint> cnt(2000000);
    cnt[0] = 1;
    rep(i, 2000000) cnt[i + 1] = cnt[i] * 26;

    rep(i, t) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        mint ans = 0;
        /* 左から何桁目までを見ているか */
        rep(i, (int)((n + 1) / 2)) {
            /* 必ず小さくなる数*/
            rep(j, s[i] - 'A') {
                ans += cnt[(int)((n + 1) / 2) - i - 1];
            }
        }

        // Sの前半 + 前半の反転がSより小さかったら、+1
        string sr = s.substr((ll)((n + 1) / 2));
        string sl = s.substr(0, (ll)(n / 2));
        reverse(ALL(sl));
        if(sl <= sr) ans++;
        cout << ans.val() << endl;
    }
}
