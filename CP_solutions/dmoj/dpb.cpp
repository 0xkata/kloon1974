#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//---typedef--------------------------------------------------------------------
typedef long long ll;
typedef long long unsigned llu;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
//---alias----------------------------------------------------------------------
#define endl "\n"
#define inf 0x3f3f3f3f
#define pb(a) push_back(a)
//---macros------------------------------------------ --------------------------
template <typename T> T gcd(T a, T b) { return a == 0 ? b : gcd((b % a), a); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
//------------------------------------------------------------------------------

void solve() {
    int n, k; cin >> n >> k;
    int arr[n], dp[n];
    fill (dp, dp + n, inf);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    dp[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= i + k; ++j) {
            if (j < n) {
                dp[j] = min(dp[j], dp[i] + abs(arr[j] - arr[i]));
            }
        }
    }
    
    cout << dp[n - 1] << endl;
}

int main() {
    fastio();
    solve();
}
