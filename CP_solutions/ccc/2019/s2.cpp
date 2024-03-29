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
#define google() int t; cin >> t; int i = 1; while (t--) { cout << "Case #" << i << ":"; solve(); i++; }
//------------------------------------------------------------------------------

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        bool flag = 1;
        for (int i = 1; i < n && flag; ++i) {
            if (isPrime(n + i) && isPrime(n - i)) {
                cout << n - i << " " << n + i << endl;
                flag = 0;
            }
        }
    }
}

int main() {
    fastio();
    solve();
}
