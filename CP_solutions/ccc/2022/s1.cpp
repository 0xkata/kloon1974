#include <bits/stdc++.h>
using namespace std;
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
    int n; cin >> n; 
    int cnt = 0;

    for (int i = n / 4; i >= 0; i -= 2) {
        if ((n - i * 4) % 5 == 0) cnt++;
    }

    cout << cnt << endl;
}

int main() {
    fastio();
    solve();
}
