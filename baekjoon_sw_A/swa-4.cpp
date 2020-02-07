#include <iostream>
#include <queue>
using namespace std;
int n;
int arr[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue <int> q;
int res;
void move2(int c){
	
	if(c == 0){
		for(int i = 0; i< n; i++) {
			for(int j = 0; j< n; j++){
				if(arr[i][j]) q.push(arr[i][j]);
				arr[i][j] = 0;	
			}
				int idx = 0;
				while(!q.empty()){
					int data = q.front();
					q.pop();
					if(arr[i][idx] == 0) arr[i][idx] = data;
				else if(arr[i][idx] == data){
					arr[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					arr[i][idx] = data;
				}
			}
		}
	}
	
	else if(c == 1){
		for(int i = 0; i< n; i++) {
			for(int j = n-1; j>=0 ; j--){
				if(arr[i][j]) q.push(arr[i][j]);
				arr[i][j] = 0;	
			}
				int idx = n-1;
				while(!q.empty()){
					int data = q.front();
					q.pop();
					if(arr[i][idx] == 0) arr[i][idx] = data;
				else if(arr[i][idx] == data){
					arr[i][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					arr[i][idx] = data;
				}
			}
		}
	}
	
	else if(c == 2){
		for(int i = 0; i< n; i++) {
			for(int j = 0; j< n; j++){
				if(arr[j][i]) q.push(arr[j][i]);
				arr[j][i] = 0;	
			}
				int idx = 0;
				while(!q.empty()){
					int data = q.front();
					q.pop();
					if(arr[idx][i] == 0) arr[idx][i] = data;
				else if(arr[idx][i] == data){
					arr[idx][i] *= 2;
					idx++;
				}
				else {
					idx++;
					arr[idx][i] = data;
				}
			}
		}
	}
	
	else if(c == 3){
		for(int i = 0; i< n; i++) {
			for(int j = n-1; j>=0 ; j--){
				if(arr[j][i]) q.push(arr[j][i]);
				arr[j][i] = 0;	
			}
				int idx = n-1;
				while(!q.empty()){
					int data = q.front();
					q.pop();
					if(arr[idx][i] == 0) arr[idx][i] = data;
				else if(arr[idx][i] == data){
					arr[idx][i] *= 2;
					idx--;
				}
				else {
					idx--;
					arr[idx][i] = data;
				}
			}
		}
	}
}


void move(int cnt){
	if(cnt == 5 ){
		int sum = 0;
		for(int i = 0; i< n; i++) for(int j = 0; j< n; j++) sum = max(sum, arr[i][j]);
		res = max(res, sum);
		return;
	}
	int car[20][20];
	for(int i = 0; i<n; i++)for(int j = 0; j<n; j++) car[i][j] = arr[i][j];
	for(int i = 0; i< 4; i++){
		move2(i);
		move(cnt+1);
		for(int i = 0; i<n; i++) for(int j = 0; j< n; j++) car[i][j] = arr[i][j];
	}
}

int main(int argc, char** argv) {
	cin >> n;
	for(int i = 0; i< n; i++) for(int j = 0; j< n; j++) cin >> arr[i][j];
	for(int i = 0; i< 4; i++) move(0);
	cout << res;
	
	return 0;
}
