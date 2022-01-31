#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
using namespace atcoder;

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
using P = vector<ll, ll>;
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

graph G;
using mint = modint998244353;

int main(void){
    fio();
    int n,m; cin >> n >> m;

    vector<string> hand(2*n);
    /* 勝数したか*/
    vector<int> a(2*n, 0);
    vector<int> order(2*n);
    iota(ALL(order), 0);

    rep(i,2*n){
        string s; cin >> hand[i];
    }

    rep(i,m){
        for(int j=0; j<2*n-1; j+=2){
            char hand1 = hand[order[j]][i];
            char hand2 = hand[order[j+1]][i];

            if(hand1 == hand2) continue;
            if(hand1 == 'G'){
                if(hand2 == 'C') a[order[j]] += 1;
                if(hand2 == 'P') a[order[j+1]] += 1;
            }
            if(hand1 == 'C'){
                if(hand2 == 'P') a[order[j]] += 1;
                if(hand2 == 'G') a[order[j+1]] += 1;
            }
            if(hand1 == 'P'){
                if(hand2 == 'G') a[order[j]] += 1;
                if(hand2 == 'C') a[order[j+1]] += 1;
            }
        }
        /*
        得点が大きいほど強い
        得点が同じなら、インデックス番号が小さい方が強い
        */
        sort(ALL(order), [&](int ii, int jj) {
            if(a[ii] != a[jj]) return a[ii] > a[jj];
            else return ii < jj;
        });
    }

    for(auto r : order){
        cout << r+1 << endl;
    }

}
