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
    int a; cin >> a;
    string arr[a * 2];
    for (int i = 0; i < a * 2; ++i) {
        cin >> arr[i];
    }
    
    int b; cin >> b;
    string brr[b * 2];
    for (int i = 0; i < b * 2; ++i) {
        cin >> brr[i];
    }

    int c; cin >> c;
    vector<string> crr(c * 3);
    for (int i = 0; i < c * 3; ++i) {
        cin >> crr[i];
    }

    int cnt = 0;
    for (int i = 0; i < a * 2 - 1; i += 2) {
        if (((find(crr.begin(), crr.end(), arr[i]) - crr.begin()) / 3) != ((find(crr.begin(), crr.end(), arr[i + 1]) - crr.begin()) / 3)) cnt++;
    }

    for (int i = 0; i < b * 2 - 1; i += 2) {
        if (((find(crr.begin(), crr.end(), brr[i]) - crr.begin()) / 3) != ((find(crr.begin(), crr.end(), brr[i + 1]) - crr.begin()) / 3)) cnt++;
    }

    cout << cnt << endl;
}

int main() {
    fastio();
    solve();
}
