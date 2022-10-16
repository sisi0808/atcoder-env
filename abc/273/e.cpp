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
* 多分queue
* ネックは、ノートからコピーしてきた配列を削除した時の数も覚えておかなければならないという点

恐らく答えの先読みが楽
クエリ毎に、それがどのクエリで追加された数かを出力していけば良い

今のidx2とノートに記したidx2は違うのかもしれない
*/
struct linked_list {
    struct node {
        int val;
        node *next;
        node(int val, node *next) : val(val), next(next) {}
    };
    node *head;

    linked_list() : head(nullptr) {}

    void push(int val) { head = new node(val, head); }

    void pop() {
        if(head) {
            head = head->next;
        }
    }

    int get() {
        if(head) {
            return head->val;
        } else {
            return -1;
        }
    }
};

int main(void) {
    fio();
    int Q;
    cin >> Q;
    map<int, linked_list> mp; // ノート

    linked_list a;
    rep(i, Q) {
        string q;
        cin >> q;
        if(q == "ADD") {
            ll x;
            cin >> x;
            a.push(x);
        }
        if(q == "DELETE") {
            a.pop();
        }
        if(q == "SAVE") {
            ll x;
            cin >> x;
            mp[x] = a;
        }
        if(q == "LOAD") {
            ll x;
            cin >> x;
            a = mp[x];
        }
        cout << a.get() << " ";
    }
    cout << endl;
}
