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

bool comp(pii x, pii y)
{
    if (x.ss < y.ss)
        return true;
    else if (x.ss > y.ss)
        return false;
    else
    {
        if (x.ff < y.ff)
            return true;
        else
            return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;
    vector<pii> v(n);
    fo(i, 0, n) cin >> v[i].ff >> v[i].ss;
    sort(all(v), comp);
    int ans = 1;
    int currTime = v[0].ss;
    fo(i, 1, n)
    {
        if (v[i].ff >= currTime)
        {
            ans++;
            currTime = v[i].ss;
        }
    }
    cout << ans << endl;

    return 0;
}