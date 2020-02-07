#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int x, y;
struct point{
	int x1,y1,x2,y2;
};
point p;
int cnt, ans;
int visit[10][10][10][10];
int dx[4] = {0,0, 1, -1};
int dy[4] = {1,-1,0,0};
string a[10];
queue <point> q;
void dfs(){
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int bx = q.front().x2;
			int by = q.front().y2;
			int rx = q.front().x1;
			int ry = q.front().y1;
			q.pop();
			if(a[bx][by] != 'O' && a[rx][ry] == 'O'){
				ans = cnt;
				return;				
			}
			for(int i = 0; i<4; i++){
				int rxx = rx;
				int ryy = ry;
				int bxx = bx;
				int byy = by;
				
				while(1){
					int nrx = rxx + dx[i];
					int nry = ryy + dy[i];
					if(a[nrx][nry] == '#' || a[rxx][ryy] == 'O') break;
					rxx = nrx;
					ryy = nry;
				}
				while(1){
					int nbx = bxx + dx[i];
					int nby = byy + dy[i];
					if(a[nbx][nby] == '#' || a[bxx][byy] == 'O') break;
					bxx = nbx;
					byy = nby;
				}
				if(bxx == rxx && byy == ryy){
					if(a[bxx][byy]  == 'O')continue;
					if(abs(rx - rxx) + abs(ry - ryy) >  abs(bx - bxx) + abs(by - byy)){
						rxx -= dx[i];
						ryy -= dy[i];
					}
					else {
						bxx -= dx[i];
						byy -= dy[i];
					}
				}
				if(visit[rxx][ryy][bxx][byy]) continue;
				visit[rxx][ryy][bxx][byy] = 1;
				q.push({rxx,ryy,bxx,byy});
			}
		}
		if(cnt == 10) {
			ans = -1;
			return; 
		}
		cnt++;
	}
	ans = -1;
	return;
}
int main(int argc, char** argv) {
	cin >> x >> y;
	for(int i = 0; i< x; i++) cin >> a[i];
	
	for(int i = 0; i< x; i++){
		for(int j = 0; j< y; j++){
			if(a[i][j] == 'B') {p.x2 = i; p.y2 = j; a[i][j] = '.';}
			if(a[i][j] == 'R') {p.x1 = i; p.y1 = j; a[i][j] = '.';}
		}
	}
	visit[p.x1][p.y1][p.x2][p.y2] = 1;
	q.push({p.x1, p.y1, p.x2, p.y2});
	dfs();
	cout << ans;
	
	
	return 0;
}
