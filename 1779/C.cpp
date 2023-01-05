
// 1779_C Least Prefix Sum
// submission #187808078

/*
diff:-
解法:
2つの数列(a_k,a_k-1,..,a_1),(a_k+1,a_k+2,...a_n)について1~i項目の和が常に非負にであることが必要十分
priority_queueを用いて1~i個目のうち小さいものから*-1すれば最小の操作回数が求められる
O(NlogN)
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
#define Graph vector<vector<ll>>
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll INF = 1000000000000000000;
const ll NIL = -1;
const ll MOD = 998244353;
// const ll MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};
 
ll T;
 
ll query(vector<ll> v, ll p)
{
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    ll sum = 0;
    ll res = 0;
    rep(i, v.size())
    {
        Q.push(v[i]);
        sum += v[i];
        if (sum < 0)
        {
            while (sum < 0)
            {
                ll val = Q.top();
                Q.pop();
                sum -= val * 2;
                res++;
            }
        }
    }
    return res;
}
 
int main(void)
{
    cin >> T;
    while (T--)
    {
        ll N, M;
        cin >> N >> M;
        M--;
        ll ANS = 0;
        vector<ll> A(N);
        rep(i, N) cin >> A[i];
        if (M > 0)
        {
            vector<ll> W1;
            rFOR(j, M, 1) W1.push_back(-A[j]);
            ANS += query(W1, M + 1);
        }
        if (M < N - 1)
        {
            vector<ll> W2;
            FOR(j, M + 1, N - 1)
            W2.push_back(A[j]);
            ANS += query(W2, N - M + 1);
        }
        cout << ANS << endl;
    }
    return 0;
}
