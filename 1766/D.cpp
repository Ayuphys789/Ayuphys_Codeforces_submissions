
// 1766_D Lucky Chains
// #187920192

/*
diff:1600
解法:
D=Y-XとするときX+K,Y+KがLuckyである必要十分条件はgcd(D,X+K)=1
Dの各素因数p_iについて,p_i|Xならc_i=0,X%p_i=tならc_i=p_i-tとして,
ANS=min{c_i}
前計算O((Max)loglog(Max)) (Eratosthenesの篩を用いる)
素因数の個数が高々logD,それぞれO(1)なので,
O((Max)loglog(Max)+TlogD)
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
int T;
vector<int> B;
 
vector<int> Eratosthenes(int n)
{
    vector<int> isPrime(n + 1, -1);
    isPrime[0] = 0;
    isPrime[1] = 1;
    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p] != -1)
            continue;
        for (long long q = p; q <= n; q += p)
        {
            isPrime[q] = p;
        }
    }
    return isPrime;
}
 
void solve()
{
    int X, Y;
    cin >> X >> Y;
    int D = Y - X;
    if (D == 1)
    {
        cout << -1 << endl;
        return;
    }
    int ANS = 100000000;
    while (D > 1)
    {
        int P = B[D];
        while (D % P == 0)
        {
            D /= P;
        }
        int K = X % P;
        if (K)
            K = P - K;
        ANS = min(ANS, K);
    }
    cout << ANS << endl;
    return;
}
 
int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    cin >> T;
    B = Eratosthenes(10000000);
    while (T--)
    {
        solve();
    }
    return 0;
}
