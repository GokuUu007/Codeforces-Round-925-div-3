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


int ceil (int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);

    for (auto &s  : a) {
        cin >> s;  
    }   

    map<pair<int, int>, int> p;

    for (auto &s : a) {
        p[make_pair(s % x, s % y)] += 1;
    }

    ll ans = 0;
    for (auto &s : a) {

        auto l = make_pair(s % x, s % y);
        auto r = make_pair((x-(s % x)) % x, s % y);

        if (l == r) ans += p[r]-1;
        else ans += p[r];
      
    }

    cout << ans / 2 << endl;
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
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
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
