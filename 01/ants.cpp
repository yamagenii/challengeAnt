#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int l;
vector<int> a;

int ansMin();
int ansMax();

void mainmain(){
    cin >> l;
    cin >> n;
    for (int i = 0;i < n; i++){
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << ansMin() << endl;
    cout << ansMax() << endl;
}

int ansMin(){
    double h = ((double)l)/2;
    int minAnt = 0;
    double minAntL = 1000000;
    for (int i = 0; i< n ;i++){
        //cout << "aa" <<endl;
        if (minAntL > pow((h-(double)a[i]),2)){
            minAntL = pow((h-(double)a[i]),2);
            minAnt = a[i];
        }
    }
    return min(minAnt,l - minAnt);
}

int ansMax(){
    sort(a.begin(),a.end());
    return max(l-a[0],a[n-1]);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}
