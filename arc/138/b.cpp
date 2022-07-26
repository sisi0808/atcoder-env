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
先頭に0があるのなら、その数は操作Aの巻き戻しが可能
末尾に0があるのなら、その数は操作Aの巻き戻しが可能


先頭に0が続く限り、操作は可能
* 操作中、末尾に⓪が出てきたら即座に取り除いてよい
    * 後の操作に影響を及ば差ないため
    *
* 先頭から順に処理することが可能（な気がする）
    * 何回Flipしたかを記録しておけば

答えはy/nで回数等は記録する必要はない
*/

int main(void) {
    fio();
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    bool temp[200004];
    rep(i, 200004) temp[i] = false;

    int flip = 0;
    int l = 0;
    int r = n - 1;
    while(l <= r) {
        while(l <= r) {
            if(a[r] == flip % 2) {
                temp[r] = true;
                r--;
            } else break;
        }
        if(a[l] == flip % 2) {
            temp[l] = true;
            flip++;
        }
        l++;
    }

    bool ans = true;
    rep(i, n) ans &= temp[i];
    yn(ans);
}
