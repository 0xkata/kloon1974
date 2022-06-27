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
    int arr[n]; for (int i = 0; i < n; ++i) cin >> arr[i];

    int cnt = 0, index = 1;
    for (int i = 0; i < n; ++i) {
        cnt = 0;
        for (int j = 0; j <= i; ++j) {
            if (arr[j] > index) cnt++;
            if (cnt > index) index++;
        }
        cout << index << " ";
    }
    cout << endl;
}

void google() {
    int t; cin >> t;
    int i = 1;
    while (t--) {
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
}

int main() {
    fastio();
    google();
}
