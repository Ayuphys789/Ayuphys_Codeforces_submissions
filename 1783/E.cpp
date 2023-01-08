
// 1783_E Game of the Year
// submission #188510000

/*
diff:-
解法:
各iについて条件を満たさないKを除く
A[i]>B[i]のときだけ見る
k<=(A[i]-B[i])はダメ ...(A[i]-B[i])の最大値をmとする
kがC(C=B[i],B[i]+1,B[i]+2,...A[i]-1)の約数のときダメ
前半:各iについてCを全て記録 RUQを用いる O(NlogN) 
後半:t(m+1<=i<=N)についてtの倍数にCに含まれるものが存在するか判定 O(NlogN)
ミス:
Eratosthenesでは約数列挙はできない,素因数列挙ができる
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <array>
#include <random>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REP(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define rFOR(i, a, b) for (ll i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll INF = 1000000000000000000;
const ll NIL = -1;
// const ll MOD = 998244353;
// const ll MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

template <typename T>
struct Binary_Indexed_Tree // 1-indexed, [left,right]
{
    ll n;
    vector<T> bit[2];
    Binary_Indexed_Tree(ll n_) { init(n_); }
    void init(ll n_)
    {
        n = n_ + 2;
        for (int p = 0; p < 2; p++)
            bit[p].assign(n, 0);
    }
 
    void add_sub(int p, ll i, T x)
    {
        for (ll id = i; id < n; id += (id & -id))
        {
            bit[p][id] += x;
        }
    }
 
    void add(ll left, ll right, T x)
    {
        add_sub(0, left, -x * (left - 1));
        add_sub(0, right + 1, x * right);
        add_sub(1, left, x);
        add_sub(1, right + 1, -x);
    }
 
    T sum_sub(int p, ll i)
    {
        T s(0);
        for (ll id = i; id > 0; id -= (id & -id))
        {
            s += bit[p][id];
        }
        return s;
    }
 
    T sum(ll i) // [1, i]
    {
        return sum_sub(0, i) + sum_sub(1, i) * i;
    }
 
    T query_sum(ll i, ll j) // [i, j]
    {
        return sum(j) - sum(i - 1);
    }
};
void Ayuphys_solve()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    Binary_Indexed_Tree<ll> BIT(N);
    ll minim = 0;
    rep(i, N)
    {
        if (A[i] <= B[i])
            continue;
        ll C = A[i] - B[i];
        BIT.add(B[i], A[i] - 1, 1);
        minim = max(minim, C);
    }
    vector<bool> Q(N + 1, 0), Z(N + 1, 1);
    FOR(i, minim + 1, N)
    {
        if (BIT.sum(i) > BIT.sum(i - 1))
            Q[i] = 1;
    }
    FOR(i, minim + 1, N)
    {
        for (ll val = i; val <= N; val += i)
        {
            if (Q[val])
            {
                Z[i] = 0;
                break;
            }
        }
    }
    ll cnt = 0;
    vector<ll> ANS;
    FOR(i, minim + 1, N)
    {
        if (Z[i])
        {
            cnt++;
            ANS.push_back(i);
        }
    }
    cout << cnt << endl;
    rep(i, cnt) cout << ANS[i] << " ";
    cout << endl;
    return;
}
 
int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        Ayuphys_solve();
    }
    return 0;
}
