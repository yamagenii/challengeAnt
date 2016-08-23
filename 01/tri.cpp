#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//オーダーO(n^3) nは100なので、1000000回程度

int n;
vector<int> a;

void mainmain(){
    cin >> n;
    for (int i = 0;i < n; i++){
        int m;
        cin >> m;
        a.push_back(m);
    }
    static int ans = 0;
    for (int i = 0; i < n-2; i++){
        for(int j = i+1;j < n-1 ; j++){
            for(int k= j+1; k < n ;k++){
                if (2*max(max(a[i],a[j]),a[k])<a[i]+a[j]+a[k]){//三角形の条件
                    ans = max(ans,a[i]+a[j]+a[k]);
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}
