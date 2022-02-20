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
    string s; cin >> s;
    char v[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

    if (s[s.size() - 1] == 'y' || s[s.size() - 1] == 'Y') {
        cout << s << " is ruled by nobody." << endl;
        return;
    }

    for (auto i : v) {
        if (s[s.size() - 1] == i) {
            cout << s << " is ruled by Alice." << endl;
            return;
        }
    }

    cout << s << " is ruled by Bob." << endl;
}

int main() {
    fastio();
    int t; cin >> t;
    int i = 1;
    while (t--) {       
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
}
