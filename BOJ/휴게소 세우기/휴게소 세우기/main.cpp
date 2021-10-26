#include <iostream>
#include <algorithm>
using namespace std;
int n,m,l;
int tb[110];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m>>l;
	for (int i=1;i<=n;++i) {
		cin>>tb[i];
	}
	tb[n+1]=l;
	sort(tb, tb+n+1);
	int left=1,right=l-1;
	while (left<=right) {
		int cnt = 0;
		int mid = (left+right)/2;
		for (int i=1;i<=n+1;++i) {
			if (tb[i]-tb[i-1]> mid) {
				cnt+=(tb[i]-tb[i-1]-1)/mid;
			}
		}
		if (cnt>m) left=mid+1;
		else right=mid-1;
	}
	cout<<left<< endl;
}
