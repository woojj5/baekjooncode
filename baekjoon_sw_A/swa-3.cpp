#include <iostream>
using namespace std;
int n,m,x,y,k;
int arr[6];
int arr2[20][20];
void move(int a){
	int temp[6];
	for(int i = 0; i< 6; i++) temp[i] = arr[i];
	if(a == 1) {
		arr[0] = temp[3];
		arr[1] = temp[1];
		arr[2] = temp[0];
		arr[3] = temp[5];
		arr[4] = temp[4];
		arr[5] = temp[2];
		y = y + 1;
	}
	if(a == 2) {
		arr[0] = temp[2];
		arr[1] = temp[1];
		arr[2] = temp[5];
		arr[3] = temp[0];
		arr[4] = temp[4];
		arr[5] = temp[3];
		y = y - 1;
	}
	if(a == 3) {
		arr[0] = temp[4];
		arr[1] = temp[0];
		arr[2] = temp[2];
		arr[3] = temp[3];
		arr[4] = temp[5];
		arr[5] = temp[1];
		x = x - 1;
	}
	if(a == 4) {
		arr[0] = temp[1];
		arr[1] = temp[5];
		arr[2] = temp[2];
		arr[3] = temp[3];
		arr[4] = temp[0];
		arr[5] = temp[4];
		x = x + 1;
	}
	
	if(arr2[x][y] == 0 ) arr2[x][y] = arr[5];
	else {
		arr[5] = arr2[x][y];
		arr2[x][y] = 0;	
	}
}

int main(int argc, char** argv) {
	cin >> n >> m >> x >> y >> k;
	for(int i = 0; i< n; i++) for(int j = 0; j< m; j++) cin >> arr2[i][j];
	arr[5] = arr2[x][y];
	
	int a;
	int b;
	for(int i = 0; i < k; i++) {
		int mv;
		cin >> mv;
		a = x; 
		b = y;
		if(mv == 1) b+=1;
		if(mv == 2) b-=1;
		if(mv == 3) a-=1;
		if(mv == 4) a+=1;
		if(a < 0 || a > n-1 || b < 0 || b > m-1) {
			a = x;
			b = y;
			continue;
		}
		else {
			move(mv);
			cout << arr[0] <<"\n";
		}
		
	}
	
	return 0;
}
