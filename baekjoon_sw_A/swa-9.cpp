#include <iostream>
#include <queue>
using namespace std;
int n, m, ans;
int ** arr;
int temp[8][8];
struct pairs{
	int x;
	int y;
};
queue <pairs> q;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void bfs(){
	int copy[8][8];
	for(int i = 0; i< n; i++) for(int j = 0; j< m; j++) copy[i][j] = temp[i][j];
	
	for(int i = 0; i<n; i++) for(int j = 0; j< m; j++) if(copy[i][j] == 2) q.push({i,j});
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
		for(int i = 0; i< 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1) continue;
			if(copy[nx][ny] == 0) {
				copy[nx][ny] = 2;
				q.push({nx, ny} );
			}
		}
	}
	int zero = 0;
	for(int i = 0; i< n; i++) for(int j = 0; j<m; j++) if(copy[i][j] == 0) zero++;
	
	ans = max(ans,zero);
}

void wall(int cnt){
	if(cnt == 3) {
		bfs();
		return;
	}
	for(int i = 0; i<n; i++) for(int j = 0; j< m; j++){
		if(temp[i][j] == 0){
			temp[i][j] = 1;
			wall(cnt+1);
			temp[i][j] = 0;
		}
	}
	
}

int main(int argc, char** argv) {
	cin >> n >> m;
	arr = new int* [n];
	for(int i = 0; i< n; i++) arr[i] = new int[m];
	for(int i = 0; i< n; i++) for(int j = 0; j< m; j++) cin >> arr[i][j];
	for(int i = 0; i<n; i++) for(int j = 0; j<m; j++){
		if(arr[i][j] == 0){
			for(int a = 0; a< n; a++) for(int b = 0; b < m; b++) temp[a][b] =arr[a][b];
			temp[i][j] = 1;
			wall(1);
			temp[i][j] = 0;
		}
	}
	cout << ans;
	
	return 0;
}
