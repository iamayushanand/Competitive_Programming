#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define MOD 1000000007
int check(int b,int a){
	int ans=0;
	for(int i=2;i<=a;i++){
		if(b>=2*i){
			ans++;
		}
	}
	for(int i=2;i<=b;i++){
		if(a>=2*i){
			ans++;
		}
	}
	return ans;
}
int solve(){
	int R,C;
	cin>>R>>C;
	int u[R][C];
	int d[R][C];
	int l[R][C];
	int r[R][C];
	int orig[R][C];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>orig[i][j];
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(orig[i][j]==0){
				r[i][j]=0;
				continue;
			}
			int cur=0;
			while(j+cur<C && orig[i][j+cur]==1 )cur++;
			r[i][j]=cur;
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(orig[i][j]==0){
				l[i][j]=0;
				continue;
			}
			int cur=0;
			while(j-cur>=0 && orig[i][j-cur]==1 )cur++;
			l[i][j]=cur;
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(orig[i][j]==0){
				u[i][j]=0;
				continue;
			}
			int cur=0;
			while(i-cur>=0 && orig[i-cur][j]==1 )cur++;
			u[i][j]=cur;
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(orig[i][j]==0){
				d[i][j]=0;
				continue;
			}
			int cur=0;
			while(i+cur<R && orig[i+cur][j]==1 )cur++;
			d[i][j]=cur;
		}
	}
	int ans=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(orig[i][j]==1 && r[i][j]>=2 && u[i][j]>=2 )ans+=check(MAX(r[i][j],u[i][j]),MIN(r[i][j],u[i][j]));
			if(orig[i][j]==1 && r[i][j]>=2 && d[i][j]>=2 )ans+=check(MAX(r[i][j],d[i][j]),MIN(r[i][j],d[i][j]));
			if(orig[i][j]==1 && l[i][j]>=2 && u[i][j]>=2 )ans+=check(MAX(l[i][j],u[i][j]),MIN(l[i][j],u[i][j]));
			if(orig[i][j]==1 && l[i][j]>=2 && d[i][j]>=2 )ans+=check(MAX(l[i][j],d[i][j]),MIN(l[i][j],d[i][j]));
//			cout<<ans<<" "<<i<<" "<<j<<'\n';
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cout<<"Case #"<<i<<": "<<solve()<<'\n';
	}
	return 0;
}
