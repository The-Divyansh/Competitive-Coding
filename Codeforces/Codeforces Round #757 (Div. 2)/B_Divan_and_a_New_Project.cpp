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
typedef vector<vi> vii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef pair<int, int> pii;

bool comp(pii x, pii y)
{
    if (x.ff > y.ff)
        return true;
    else
        return false;
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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pii> v(n + 1);
        v[0].ff = v[0].ss = 0;
        foe(i, 1, n)
        {
            cin >> v[i].ff;
            v[i].ss = i;
        }
        sort(all(v), comp);
        ll sum = 0;
        vi ans(n + 1);
        ans[0] = 0;
        int currPos = 1;
        foe(i, 0, n)
        {
            if (v[i].ss == 0)
            {
                ans[0] = 0;
                continue;
            }
            ans[v[i].ss] = currPos;
            sum += (1LL) * v[i].ff * 2 * abs(currPos);
            if (currPos > 0)
                currPos *= -1;
            else
            {
                currPos *= -1;
                currPos++;
            }
        }
        cout << sum << endl;
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}