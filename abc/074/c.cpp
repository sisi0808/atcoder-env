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
 * DPぽい
 * 水が必ず多めになるように考える事により、溶け残りをなくす
 */

ll a, b, c, d, e, f;
// 砂糖、水
bool judge(int i, int j) {
    // 水が超えたら
    if(j > 30 || i > 30) return false;
    // 質量が超えたら
    if(j * 100 + i > f) return false;
    // 濃度が超えたら
    if(i > j * e) return false;
    return true;
}

int main(void) {
    fio();
    cin >> a >> b >> c >> d >> e >> f;

    vector<vector<bool>> dp(31, vector<bool>(31, false));
    dp[0][0] = true;

    ll ans_a = 1; // 水
    ll ans_b = 0; // 砂糖水
    // 砂糖
    rep(i, 31) {
        // 水(100刻み)
        rep(j, 31) {
            if(!dp[i][j]) continue;
            // 操作
            if(judge(i, j + a)) {
                // dp[i][j + a] != dp[i][j];
                dp[i][j + a] != true;
            }
            if(judge(i, j + b)) {
                // dp[i][j + b] != dp[i][j];
                dp[i][j + b] != true;
            }
            if(judge(i + c, j)) {
                // dp[i + c][j] != dp[i][j];
                dp[i + c][j] != true;
            }
            if(judge(i + d, j)) {
                // dp[i + d][j] != dp[i][j];
                dp[i + d][j] != true;
            }

            // 濃度の比較
            if((100 * ans_b) * 100 * (j + i) < (100 * i) * 100 * (ans_a + ans_b)) {
                ans_a = j;
                ans_b = i;
            }
        }
    }
    rep(i, 31) {
        rep(j, 31) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans_a + ans_b << " " << ans_b << endl;
}
