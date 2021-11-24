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

int n;
vi a, b;

bool check(int x)
{
    int selected = 0;
    fo(i, 0, n)
    {
        if ((b[i] >= selected) && (a[i] >= (x - selected - 1)))
        {
            selected++;
        }
    }
    if (selected >= x)
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
        cin >> n;
        a.clear();
        b.clear();
        a.resize(n);
        b.resize(n);
        fo(i, 0, n)
        {
            cin >> a[i] >> b[i];
        }
        int lo = 1, hi = n;
        int mid;
        int ans;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (check(mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        cout << ans << endl;
    }

    return 0;
}