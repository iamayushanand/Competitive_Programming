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
int ans=0;
int curans=0;
int recurse(int ind,int N,int K,int P,int prefix[51][31]){
	if(ind>=N && P>0){
		curans=0;
		return 0;
	}
	if(P==0){
		ans=MAX(ans,curans);
		cout<<curans<<'\n';
		return 0;
	}
	
	for(int i=0;i<=MIN(P-1,K-1);i++){
		curans+=prefix[ind][i];
		recurse(ind+1,N,K,P-i+1,prefix);
	}
	return 0;
}

int solve(){
	int N,K,P;
	cin>>N>>K>>P;
	int prefix[51][31];
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			int cur;
			cin>>cur;
			if(j==0){
				prefix[i][j]=cur;
				continue;
			}
			prefix[i][j]=cur+prefix[i][j-1];
		}
	}
	recurse(0,N,K,P,prefix);
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		solve();
		cout<<"Case #"<<i<<": "<<ans<<'\n';
		ans=0;
	}
	return 0;
}
