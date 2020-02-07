#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int n;
int arr[1000];
int arr2[1000];
int track;
void solve(int day, int cnt){
	if(day == n){
		if(track < cnt) track = cnt;
			return;	
	}
	if(day > n) return;
	solve(day + arr[day], cnt + arr2[day] );
	solve(day+1, cnt);
}



int main(int argc, char** argv) {
	cin >> n;
	for(int i = 0; i< n; i++){
		int x, y;
		cin >> x >> y;
		arr[i] = x;
		arr2[i] = y;
	}
	solve(0,0);
	cout << track;
	return 0;
}
