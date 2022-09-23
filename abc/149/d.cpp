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
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*

* i回目でAを出した時、i-k回目でBCを出したことと、i+k回目でBCを出すことが保障される
* 勝てるのなら勝つ
* Kの条件によって勝てなくなるのなら、別の手を出す
* ただし、その次がそれで勝てるのなら、それは選ばない


*/

int main(void) {
    fio();
    ll n, k;
    cin >> n >> k;
    vector<ll> v(3);
    rep(i, 3) cin >> v[i];
    string s;
    cin >> s;
    for(auto &c : s) {
        if(c == 'r') c = '2';
        else if(c == 's') c = '0';
        else if(c == 'p') c = '1';
    }

    /* グーチョキパーなら0,1,2で埋める*/
    vector<int> gcp(n + 1, -1);

    rep(i, n) {
        if(gcp[i] == -1) {
            gcp[i] = s[i] - '0';
            for(int j = i + k; j < n; j += k) {
                /* それぞれ勝てる場合 */
                if(gcp[j - k] != s[j] - '0') gcp[j] = s[j] - '0';
                else {
                    if(j + k < n) {
                        if(s[j - k] != s[j + k]) {
                            int aa = (s[j - k] - '0') + (s[j + k] - '0');
                            if(aa == 1) gcp[j] = 2;
                            if(aa == 2) gcp[j] = 1;
                            if(aa == 3) gcp[j] = 0;
                        } else {
                            gcp[j] = (s[j - k] - '0' + 1) % 3;
                        }
                    } else {
                        gcp[j] = (s[j - k] - '0' + 1) % 3;
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i, n) {
        if(gcp[i] == (s[i] - '0')) ans += v[gcp[i]];
        // cout << gcp[i] << ' ';
    }

    cout << ans << endl;
}
