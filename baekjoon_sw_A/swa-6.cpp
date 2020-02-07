#include <iostream>
using namespace std;
long long n, x, y;
long long arr[1000000];
int main(int argc, char** argv) {
	cin >> n;
	for(int i = 0; i< n; i++) cin >> arr[i];
	cin >> x >> y;
	long long sum[n];
	long long ans = 0;
	for(int i = 0; i< n; i++) sum[i] = 1;
	for(int i = 0; i< n; i++) {
		if(arr[i] - x <0) continue;
		if( (arr[i]-x) % y ) sum[i]++;
		sum[i] += (arr[i] - x)/y;	
	}
	for(int i = 0; i< n; i++) ans += sum[i];
	cout << ans;
	return 0;
}
