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
s,tのiビット目が同じ時、uのibit目は0
s,tのjビット目が違う時、

sとtで違うbitの数が奇数だったら-1
偶数だったら、違うbitの数をdとした時、先頭からd/2番目までは0、それ以降は1
*/
int main(void) {
    fio();
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    ll d = 0;
    ll ds = 0;
    ll dt = 0;
    rep(i, n) {
        if(s[i] != t[i]) d++;
    }
    if(d % 2) cout << -1 << endl;
    else {
        string u = "";
        ll e = 0;
        rep(i, n) {
            if(s[i] == t[i]) u += '0';
            else {
                if(s[i] == '1') {
                    if(ds < d / 2) {
                        ds++;
                        u += '0';
                    } else u += s[i];
                } else if(t[i] == '1') {
                    if(dt < d / 2) {
                        dt++;
                        u += '0';
                    } else u += t[i];
                }
            }
        }
        cout << u << endl;
    }
}