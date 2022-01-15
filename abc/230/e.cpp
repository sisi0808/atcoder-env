#include <bits/stdc++.h>
#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(ll i = 0; i < ll(n); ++i)
#define rrep(i, n) for(ll i = n; i > 0; --i)
#define repp(i, n, m) for(ll i = m; i < ll(n); ++i)
#define fore(i_in, a) for(auto &i_in : a)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
const ll SIZE = 100005;
const ll inf = INT_MAX;
const ll modi = 1000000007;
const long long INF = LLONG_MAX;
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

vector<ll> dx = {1, 0, -1, 0};
vector<ll> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

graph G;

int main(void){
    fio();
    ll N,k; cin >> N;
    ll ans = 0;
    rep(i,N){
        if(i*i <= N) k = i;
        else break;
    }
    // (n/i)<√nの場合
    repp(i,k+1,1) ans += (N/i - N/(i+1)) * i;
    // i<√nの場合
    repp(i,N/(k+1)+1,1) ans += (N / i);
    cout << ans << endl;
}
