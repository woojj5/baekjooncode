#include <iostream>
#include <queue>
using namespace std;
int n,k,w;
int arr[101][101], t[101];
char c[101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int d, ans;
int x = 1, y = 1,z;
queue  <pair <int, int> > q;
void solve(){
	q.push({1,1});
	arr[x][y] = 2;
	while(1){
		x+=dx[d];
		y+=dy[d];
		ans++;
		// 벽과 자기자신 만나는 경우 생각 
		if( x< 1 || y < 1 || x > n || y > n || arr[x][y] == 2) {
			cout << ans;
			return;
		}
		else if(arr[x][y] == 0) {
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			arr[nx][ny] = 0;
		}
		arr[x][y] = 2;
		q.push({x,y});
		if(ans == t[z]) {
			if(c[z] == 'L') d = (d + 3)%4;
			else d = (d + 1 )%4;
			z++;
		}
	}
}

int main(int argc, char** argv) {
	cin >> n >> k;
	//사과 위치 
	for(int i = 0; i< k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	cin >> w;
	for(int i = 0; i< w; i++) cin >> t[i] >> c[i];
	solve();
	
	
	return 0;
}
