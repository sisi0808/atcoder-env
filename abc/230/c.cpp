#include <bits/stdc++.h>
#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i > 0; --i)
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
const int SIZE = 100005;
const int inf = INT_MAX;
const int modi = 1000000007;
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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

//int N,M;
int H,W;
graph G;

int main(void){
    fio();
    ll N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;
    vector<vector<char>> ans(Q-P+1, vector<char> (S-R+1));

    rep(i,Q-P+1){
        rep(j,S-R+1){
            ans[i][j] = '.';
        }
    }

    ll l1, l2;
    ll r1, r2;

    l1 = max(P-A, R-B);
    l2 = min(Q-A, S-B);

    r1 = max(P-A, B-S);
    r2 = min(Q-A, B-R);

    for (long long i = l1; i <= l2; i++) ans[A + i - P][B + i - R] = '#';
    for (long long i = r1; i <= r2; i++) ans[A + i - P][B - i - R] = '#';

    rep(i,(Q-P+1)){
        rep(j,(S-R+1)){
            cout << ans[i][j];
        }
        cout << endl;
    }

}
