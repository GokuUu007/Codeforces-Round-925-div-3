/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif



// warning - integer overflow : )


bool solve() {
    int n, k;
    cin >> n >> k;

    vector<set<int>> adj(n);
    for (int i = 0; i < k; ++i) {
        vector<int> p(n);
        for (auto &x : p) {
            cin >> x, --x;
        }
        for (int j = 1; j + 1 < n; ++j) {
            adj[p[j]].insert(p[j + 1]);
        }
    }

    vector<int> seen(n), seenOnPath(n);

    function<bool(int)> Dfs = [&] (int u) {
        seen[u] = 1;
        seenOnPath[u] = 1;

        for (auto &x : adj[u]) {
            if (!seen[x]) {
                if (Dfs(x)) {
                    return 1;
                }
            } else if (seenOnPath[x]) {
                return 1;
            }
        }

        seenOnPath[u] = 0;

        return 0;
    };

    int ok = 1;
    for (int i = 0; i < n; ++i) {
        if (!seen[i]) {
            ok &= !Dfs(i);
        }
    }

    return ok;
}   

int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE   
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        // solve();
        cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifndef ONLINE_JUDGE
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
