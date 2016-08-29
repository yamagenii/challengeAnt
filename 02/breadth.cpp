#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

#define N 10
#define M 10

const int INF = 100000000;//設定などで扱われる



int n = 10,m = 10;
typedef pair<int, int> P;
char maze[N+1][M+1];
int sx,sy;
int gx,gy;

int d[N][M]; //各店までの最短距離を入れるベクトル

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(){
    queue<P> que;
    for(int i = 0;i < n;i++){
        for(int j= 0; j< m;j++){
            d[i][j] = INF;
        }
    }
    d[sx][sy] = 0;
    que.push(P(sx,sy));
    while(!que.empty()){
        P p = que.front();
        que.pop();
        if (gx == p.first && gy == p.second) break;
        for(int i = 0; i < 4;i++){
            if(p.first+dx[i] < 10 && p.first + dx[i] >= 0 && p.second+dy[i] < 10 && p.second + dy[i] >= 0){
                if(maze[p.first+dx[i]][p.second +dy[i]] != '#'  && d[p.first + dx[i]][p.second + dy[i]] == INF){
                    que.push(P(p.first + dx[i],p.second + dy[i]));
                    d[p.first + dx[i]][p.second + dy[i]] = d[p.first][p.second] + 1;
                }
            }
            
        }

    }
    for (int i= 0;i< n;i++){
        for(int j = 0; j< m ;j++){
            cout << d[i][j] << endl;
        }
    }
    return d[gx][gy];
}

void mainmain(){
    for (int i = 0;i < n; i++){
        for (int j= 0;j < m; j++){
            char c;
            cin >> c;
            maze[i][j] = c;
            if(c == 'S'){
                sx = i;
                sy = j;
            }
            if(c == 'G'){
                gx = i;
                gy = j;
            }
        }
    }
    cout << bfs() <<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}
