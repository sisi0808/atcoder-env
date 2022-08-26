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

/*
 ACになったら、それ以降編集出来ない

*/

int main(void) {
    fio();
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> v;

    int st = 0;
    int aa = 0;
    int cc = 0;
    rep(i, n) {
        if(s[i] == 'A') {
            if(st == 0) aa++;
            else if(st == 1) {
                aa = 1;
                st = 0;
            } else {
                v.pb(min(aa, cc));
                st = 0;
                aa = 1;
                cc = 0;
            }
        } else if(s[i] == 'R') {
            if(st == 0) {
                st = 1;
            } else if(st == 1) {
                st = 0;
                aa = 0;
            } else {
                v.pb(min(aa, cc));
                st = 0;
                aa = 0;
                cc = 0;
            }

        } else {
            if(st == 0) aa = 0;
            else if(st == 1) {
                st = 2;
                cc = 1;
            } else cc++;
        }
    }
    if(min(aa, cc) > 0) v.pb(min(aa, cc));

    // map<int, int> mp;
    // for(int vi : v) mp[vi]++;

    // int ans = 0;
    // while(!mp.empty()) {
    //     ans++;
    //     int mn = mp.begin()->first;
    //     int mx = mp.rbegin()->first;
    //     if(ans % 2 == 0) {
    //         mp[mn]--;
    //         if(mp[mn] == 0) mp.erase(mn);
    //     } else {
    //         mp[mx]--;
    //         if(mp[mx] == 0) mp.erase(mx);
    //         if(mx > 1) mp[mx - 1]++;
    //     }
    // }
    ll ans = min(accumulate(ALL(v), 0), (int)v.size() * 2);
    cout << ans << endl;
}
