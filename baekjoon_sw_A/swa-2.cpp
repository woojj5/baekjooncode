#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, ans;
int s[20][20];
queue <int> q;

void get(int x, int y){
	if(s[x][y]){
		q.push(s[x][y]);
		s[x][y] = 0;
	}
}

void merge(int i,int j, int di, int dj){
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(!s[i][j]) s[i][j] = x;
		else if(s[i][j] == x){
			s[i][j] = 2 * x;
			i += di;
			j += dj;
		}
		else {
			i+= di;
			j+= dj;
			s[i][j] = x;
		}
	}
}

void move(int k) {
	
	if(k == 0){
		for(int j = 0; j< n; j++){
			for(int i = 0; i<n; i++) get(i,j);
			merge(0,j,1,0);
		}
	}
	
	else if(k == 1){
		for(int j = 0; j< n; j++){
			for(int i = n-1; i>=0; i--) get(i,j);
			merge(n-1,j,-1,0);
		}
	}
	
	else if(k == 2){
		for(int i = 0; i< n; i++){
			for(int j = 0; j<n; j++) get(i,j);
			merge(i,0,0,1);
		}
	}
	
	else{
		for(int i = 0; i< n; i++){
			for(int j = n-1; j>=0; j--) get(i,j);
			merge(i,n-1,0,-1);
		}
	}
}

void solve(int cnt){
	if(cnt == 5){
		for(int i = 0; i<n; i++){
			for(int j = 0; j< n; j++){
				if(ans < s[i][j]) ans = s[i][j];
			}
		}
		return;
	}
	int b[20][20];
	memcpy(b, s, sizeof(s));
	for(int k = 0; k< 4; k++){
		move(k);
		solve(cnt+1);
		memcpy(s, b, sizeof(b));
	}
}

int main(int argc, char** argv) {
	cin >> n;
	for(int i = 0; i< n; i++) for(int j = 0; j< n; j++) cin >> s[i][j];
	solve(0);
	cout << ans;	
	return 0;
}
