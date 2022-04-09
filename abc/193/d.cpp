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
 * その数のカードは合計でK枚ある
 * そのため、引いたカードの数分だけ確率から減らす
 * まずは、K君の数をXと仮定して、T君がX以上になる確率を求める
 */

int main(void) {
    fio();
    int k;
    string s, t;
    cin >> k >> s >> t;
    /* カードが残り何枚残っているか*/
    vector<ll> b(10, 0); /* S君の合計カウント */
    vector<ll> c(10, 0); /* T君の合計カウント */
    rep(i, 4) {
        b[s[i] - '0']++;
        c[t[i] - '0']++;
    }

    ll ans = 0;
    /* S君がiのカードを引く確率 */
    repp(i, 10, 1) {
        /* T君がiのカードを引く確率 */
        repp(j, 10, 1) {

            /* S君の得点を計算 */
            ll s_score = 0;
            repp(ii, 10, 1) {
                s_score += ii * pow(10, b[ii] + (i == ii));
            }

            /* T君の得点を計算 */
            ll t_score = 0;
            repp(jj, 10, 1) {
                t_score += jj * pow(10, c[jj] + (j == jj));
            }

            /* S君が勝つなら */
            if(s_score > t_score) {
                ans += (k - b[i] - c[i]) * (k - b[j] - c[j] - (i == j ? 1 : 0));
            }
        }
    }

    cout << fixed << setprecision(12);
    cout << (double)ans / (9 * k - 8) / (9 * k - 9) << endl;
}
