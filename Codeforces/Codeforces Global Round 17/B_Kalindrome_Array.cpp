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
        vi v(n);
        fo(i, 0, n) cin >> v[i];
        int lo = 0, hi = n - 1;
        int idxLo, idxHi;
        int pLo, pHi;
        while (lo <= hi)
        {
            if (v[lo] == v[hi])
            {
                lo++;
                hi--;
            }
            else
            {
                idxLo = lo;
                idxHi = hi;
                pLo = v[lo];
                pHi = v[hi];
                break;
            }
        }
        if (lo > hi)
        {
            cout << "YES" << endl;
        }
        else
        {
            // trying with pLo
            bool flag1 = true;
            lo = 0, hi = n - 1;
            while (lo <= hi)
            {
                if (v[lo] == v[hi])
                {
                    lo++;
                    hi--;
                }
                else
                {
                    if (v[lo] == pLo)
                        lo++;
                    else if (v[hi] == pLo)
                        hi--;
                    else
                    {
                        flag1 = false; // palindrome nahi ban sakta
                        break;
                    }
                }
            }
            // trying with pHi
            bool flag2 = true;
            lo = 0, hi = n - 1;
            while (lo <= hi)
            {
                if (v[lo] == v[hi])
                {
                    lo++;
                    hi--;
                }
                else
                {
                    if (v[lo] == pHi)
                        lo++;
                    else if (v[hi] == pHi)
                        hi--;
                    else
                    {
                        flag2 = false; // palindrome nahi ban sakta
                        break;
                    }
                }
            }
            if ((flag1 == false) && (flag2 == false))
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }

    return 0;
}