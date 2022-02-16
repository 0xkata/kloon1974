#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//---typedef--------------------------------------------------------------------
typedef long long ll;
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
    int m, n, k;
    cin >> m >> n >> k;
    int arr[m][n];
    bool r[m];
    bool c[n];
    memset(arr, 0, sizeof(arr));
    memset(r, false, sizeof(r));
    memset(c, false, sizeof(c));

    while (k--) {
        char a; int b;
        cin >> a >> b;
        if (a == 'R') {
            r[b - 1] ^= 1;
        }
        else {
            c[b - 1] ^= 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (r[i]) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] ^= 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (c[i]) {
            for (int j = 0; j < m; ++j) {
                arr[j][i] ^= 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j]) cnt++;
        }
    }

    cout << cnt << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    auto start = steady_clock::now();
    fastio();
    solve();
    auto end = steady_clock::now();
#ifndef TIMER
    double elapsed_time = double (duration_cast <nanoseconds> (end-start).count());
    cerr << "Time elapsed(s): " << elapsed_time / 1e9;
#endif
}
