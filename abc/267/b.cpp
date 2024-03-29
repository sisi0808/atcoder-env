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

int main(void) {
    fio();
    string s;
    cin >> s;

    vector<int> a(10);
    vector<int> b(7);
    rep(i, 10) {
        a[i] = s[i] - '0';
    }
    b[0] = a[6];
    b[1] = a[3];
    b[2] = a[1] + a[7];
    b[3] = a[0] + a[4];
    b[4] = a[2] + a[8];
    b[5] = a[5];
    b[6] = a[9];

    if(a[0] == 1) {
        no();
        return 0;
    }

    rep(i, 5) {
        repp(j, 7, i + 2) {
            if(b[i] != 0 && b[j] != 0) {
                int sum = 0;
                repp(k, j, k + 1) {
                    sum += b[k];
                }
                if(sum == 0) {
                    yes();
                    return 0;
                }
            }
        }
    }
    no();

    // bool ans = false;
    // if(s[0] == '1') {
    //     no();
    //     return 0;
    // }
    // if(s[3] == '0' && s[6] == '1' && (s[1] == '1' || s[7] == '1')) ans = true;
    // if(s[3] == '1' && s[4] == '1' && s[1] == '0' && s[7] == '0') ans = true;
    // if(s[4] == '0' && (s[1] == '1' || s[7] == '1') && (s[2] == '1' || s[8] == '1')) ans = true;
    // if(s[5] == '1' && s[4] == '1' && s[2] == '0' && s[8] == '0') ans = true;
    // if(s[9] == '1' && (s[2] == '1' || s[8] == '1') && s[5] == '0') ans = true;

    // if(s[6] == '1' && s[4] == '1' && s[3] == '0' && s[1] == '0' && s[7] == '0') ans = true;
    // if(s[9] == '1' && s[4] == '1' && s[2] == '0' && s[5] == '0' && s[8] == '0') ans = true;
    // if(s[5] == '1' && (s[1] == '1' || s[7] == '1') && s[2] == '0' && s[4] == '0' && s[8] == '0') ans = true;
    // if(s[3] == '1' && (s[2] == '1' || s[8] == '1') && s[1] == '0' && s[4] == '0' && s[7] == '0') ans = true;

    // if(s[6] == '1' && (s[2] == '1' || s[8] == '1') && s[1] == '0' && s[3] == '0' && s[4] == '0' && s[7] == '0') ans = true;
    // if(s[9] == '1' && (s[1] == '1' || s[7] == '1') && s[2] == '0' && s[5] == '0' && s[4] == '0' && s[8] == '0') ans = true;

    // if(s[5] == '1' && s[6] == '1' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[7] == '0' && s[8] == '0') ans = true;
    // if(s[3] == '1' && s[9] == '1' && s[1] == '0' && s[2] == '0' && s[4] == '0' && s[5] == '0' && s[7] == '0' && s[8] == '0') ans = true;
    // if(s[6] == '1' && s[9] == '1' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[5] == '0' && s[7] == '0' && s[8] == '0') ans = true;

    // yn(ans);
}
