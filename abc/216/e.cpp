#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
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

/* a+1からbまでの等差数列の輪 */
ll tousa_sum(ll a, ll b){
    ll small_a = (a * (a+1) / 2);
    ll big_b = (b * (b+1) / 2);

    return big_b - small_a;
}

/* 貪欲法で解ける */

int main(void){
    fio();
    ll n,k; cin >> n >> k;
    vector<ll> a(n+1);
    rep(i,n) cin >> a[i];
    a[n] = 0;
    sort(RALL(a));

    ll ans = 0;
    rep(i,n){
        ll diff = a[i] - a[i+1];

        ll cnt = diff * (i+1);
        if(cnt <= k){
            k -= cnt;
            ans += tousa_sum(a[i+1], a[i]) * (i+1);
        }
        else{
            ll d = k / (i+1);
            ll m = k % (i+1);
            ans += tousa_sum(a[i]-d, a[i]) * (i+1);
            ans += (a[i]-d) * m;

            break;
        }
    }

    cout << ans << endl;
}
