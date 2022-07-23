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
思いついた回答
* 10^18以下の周期性の数の最大値はm<=10^9まで、なのでその範囲で全探索
* 桁数からMが何桁なのかを想定してシミュレート
    *  例）nが 6桁の場合、想定するmは1,2,3桁
    *  例）nが18桁の場合、想定するmは1,2,3,6,9桁
*/

int main(void) {
    fio();
    int t;
    cin >> t;
    vector<string> nn(t);
    rep(i, t) cin >> nn[i];
    set<string> st;
    rep(i, 10) st.insert('1' + string(i, '0'));

    for(string n : nn) {
        ll max_ans = 0;
        for(int i = 9; i > 0; i--) {
            string ans = "";
            if(n.size() % i == 0 && n.size() != i) {
                bool isOk = true;
                rep(j, n.size() / i - 1) {
                    if(stoll(n.substr(0, i)) > stoll(n.substr(i * (j + 1), i))) {
                        isOk = false;
                        break;
                    }
                    if(stoll(n.substr(0, i)) < stoll(n.substr(i * (j + 1), i))) {
                        isOk = true;
                        break;
                    }
                }
                // 左辺が小さいとき
                if(isOk) {
                    rep(j, n.size() / i) {
                        ans += n.substr(0, i);
                    }
                    chmax(max_ans, stoll(ans));
                }
                // 左辺が大きいとき
                else if(st.count(n.substr(0, i)) == 0) {
                    rep(j, n.size() / i) {
                        ans += to_string(stoll(n.substr(0, i)) - 1);
                    }
                    chmax(max_ans, stoll(ans));
                }
            }
        }
        chmax(max_ans, stoll(string(n.size() - 1, '9')));
        cout << max_ans << endl;
    }
}