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

/*
入力Xが最小の要素だったら
* ソートされたら最小の要素

二つ持てば良い？
    通常Queueとpriority queue

末尾はソートされていない
先頭はソートされている

1の後、ソートが入るか判定？

*/

int main(void){
    fio();
    int q; cin >> q;
    queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    rep(i,q){
        int query; cin >> query;

        // Add x to the tale of A
        if(query == 1){
            ll x; cin >> x;
            q1.push(x);
        }
        // Print the first element of A.
        // Then Delete it.
        else if(query == 2){
            if(!q2.empty()){
                cout << q2.top() << endl;
                q2.pop();
            }
            else{
                cout << q1.front() << endl;
                q1.pop();
            }
        }

        // sort A in ascending order.
        else{
            while(!q1.empty()){
                q2.push(q1.front()); q1.pop();
            }
        }
    }
}
