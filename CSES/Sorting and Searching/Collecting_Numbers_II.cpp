// ████████▄   ▄█   ▄█    █▄  ▄██   ▄      ▄████████ ███▄▄▄▄      ▄████████    ▄█    █▄
// ███   ▀███ ███  ███    ███ ███   ██▄   ███    ███ ███▀▀▀██▄   ███    ███   ███    ███
// ███    ███ ███▌ ███    ███ ███▄▄▄███   ███    ███ ███   ███   ███    █▀    ███    ███
// ███    ███ ███▌ ███    ███ ▀▀▀▀▀▀███   ███    ███ ███   ███   ███         ▄███▄▄▄▄███▄▄
// ███    ███ ███▌ ███    ███ ▄██   ███ ▀███████████ ███   ███ ▀███████████ ▀▀███▀▀▀▀███▀
// ███    ███ ███  ███    ███ ███   ███   ███    ███ ███   ███          ███   ███    ███
// ███   ▄███ ███  ███    ███ ███   ███   ███    ███ ███   ███    ▄█    ███   ███    ███
// ████████▀  █▀    ▀██████▀   ▀█████▀    ███    █▀   ▀█   █▀   ▄████████▀    ███    █▀

// #pragma GCC optimize "trapv"

#include <bits/stdc++.h>
using namespace std;

#define ff first
#define endl '\n'
#define ss second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define fo(i, a, b) for (int i = a; i < b; i++)
#define foe(i, a, b) for (int i = a; i <= b; i++)

const int MOD1 = 998244353;
const int MOD = 1000000007;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n, m;
    cin >> n >> m;
    vi v(n + 1, 0);
    vi pos(n + 1, 0);
    foe(i, 1, n)
    {
        int x;
        cin >> x;
        v[i] = x;
        pos[x] = i;
    }

    ll ans = 1;
    foe(i, 2, n)
    {
        if (pos[i - 1] > pos[i])
            ans++;
    }
    while (m--)
    {
        int p1, p2;
        cin >> p1 >> p2;
        set<pii> st;
        int n1, n2;
        n1 = v[p1];
        n2 = v[p2];
        if (n1 != 1)
            st.insert(mp(n1 - 1, n1));
        if (n1 != n)
            st.insert(mp(n1, n1 + 1));
        if (n2 != 1)
            st.insert(mp(n2 - 1, n2));
        if (n2 != n)
            st.insert(mp(n2, n2 + 1));
        for (auto x : st)
        {
            if (pos[x.ff] > pos[x.ss])
                ans--;
        }
        pos[n2] = p1;
        pos[n1] = p2;
        v[p1] = n2;
        v[p2] = n1;
        for (auto x : st)
        {
            if (pos[x.ff] > pos[x.ss])
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}