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
2進数に変換してから、再変換
2^(N+1) - 2^N = 2^N
*/

string convert_2(ll x) {
    // 答え(2進数への変換)
    string res;
    while(x) {
        res = to_string(x % 2) + res;
        x /= 2;
    }
    return res;
}

string convert_n(string t) {
    // 答え(2進数への変換)
    // bitset<40> s(t);
    string res = "";
    int cnt = 0;
    reverse(ALL(t));
    rep(i, t.size()) {
        char c = t[i];
        // 普通に加算
        if(i % 2 == 0) {
            if(cnt > 0) {
                if(c == '0') {
                    cnt--;
                    c = '1';
                } else c = '0';
            }
        } else { // 減算の場合
            if(c == '0' && cnt != 0) c = '1';
            else if(c == '1') {
                if(cnt > 0) c = '0';
                else cnt++;
            }
        }
        res += c;
    }

    if(cnt) {
        if(t.size() % 2 == 0) res += '1';
        else res += "11";
    }
    reverse(ALL(res));

    return res;
}

string convert_m(string t) {
    // 答え(2進数への変換)
    // bitset<40> s(t);
    string res = "";
    int cnt = 0;
    reverse(ALL(t));
    rep(i, t.size()) {
        char c = t[i];
        // 普通に加算
        if(i % 2 == 1) {
            if(cnt > 0) {
                if(c == '0') {
                    cnt--;
                    c = '1';
                } else c = '0';
            }
        } else { // 減算の場合
            if(c == '0' && cnt != 0) c = '1';
            else if(c == '1') {
                if(cnt > 0) c = '0';
                else cnt++;
            }
        }
        res += c;
    }
    if(cnt) {
        if(t.size() % 2 == 1) res += '1';
        else res += "11";
    }
    reverse(ALL(res));

    return res;
}

int main(void) {
    fio();
    ll n;
    cin >> n;
    // -2進数への変換
    string t = "";
    if(n > 0) t = convert_n(convert_2(abs(n)));
    else if(n < 0) t = convert_m(convert_2(abs(n)));
    else t = '0';
    cout << t << endl;
}