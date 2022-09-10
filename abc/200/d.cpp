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
const int inf = 1000000000;
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

using mint = modint998244353;
// using mint = modint1000000007;

/*
 * 同じ数字が２つ以上存在するのなら、正解は存在する
 * DPですね
 * 多分DPの復元を絡めれば行ける
 */

int main(void) {
    fio();
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n + 1, vector<ll>(201, 0));
    rep(i, n) cin >> a[i];

    // 遷移は以下
    // i番目まで見た時、合計がjになるのは何通り

    dp[0][0] = 1;

    int idx = -1;
    int nn = n;
    rep(i, n) {
        rep(j, 200) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][(a[i] + j) % 200] += dp[i][j];
        }
        rep(j, 200) {
            if(j != 0 && dp[i + 1][j] > 1) idx = j;
            if(dp[i + 1][j] > 2) idx = j;
        }
        if(idx != -1) {
            nn = i + 1;
            break;
        }
    }

    if(idx == -1) {
        no();
        return 0;
    } else yes();

    vector<int> b;
    vector<int> c;
    int idx_b = idx;
    int idx_c = idx;

    rrep(i, nn - 1) {
        // 引いた場合
        if(dp[i + 1][idx_b] != dp[i][idx_b]) {
            if(!dp[i][idx_b] || b.size() != c.size()) {
                b.push_back(i);
                idx_b = (((idx_b - a[i]) % 200) + 200) % 200;
            }
        }
        if(dp[i + 1][idx_c] != dp[i][idx_c]) {
            c.push_back(i);
            idx_c = (((idx_c - a[i]) % 200) + 200) % 200;
        }
    }

    sort(ALL(b));
    sort(ALL(c));
    cout << b.size() << " ";
    for(auto bb : b) cout << bb + 1 << " ";
    cout << endl;
    cout << c.size() << " ";
    for(auto cc : c) cout << cc + 1 << " ";
    cout << endl;
}
