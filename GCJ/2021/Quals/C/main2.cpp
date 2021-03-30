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
int L[101];
int cost(int N){
	int ans=0;
	int M[101];
	for(int i=0;i<N;i++){
		M[i]=L[i];
	}
	for(int i=0;i<N-1;i++){
		int j=i;
		for(j=i;j<N;j++){
			if(M[j]==i+1){
				break;
			}
		}
		reverse(M+i,M+j+1);
		ans+=j-i+1;
	}
	
	return ans;
}
void solve(){
	int N,C;
	cin>>N>>C;
	if(C<N-1 || C>((N*(N+1)/2)-1)){
		cout<<"IMPOSSIBLE";
		return;
	}
	for(int i=0;i<N;i++){
		L[i]=i+1;
	}
	C-=N-1;
	int curr=0;
	int en=N;
	int turn=0;
	while(C>0 && curr<N){
		if(en-1-curr<=C){
			C-=en-1-curr;
			reverse(L+curr,L+en);
			en--;
		}else{
			reverse(L+curr,L+C+1+curr);
			C=0;
		}
		cout<<cost(N)<<'\n';
		curr++;
		turn++;
	}
	cout<<"cost:"<<cost(N)<<'\n';
	for(int i=0;i<N;i++){
		cout<<L[i]<<' ';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cout<<"Case #"<<i<<": ";
		solve();
		cout<<'\n';
	}
	return 0;
}
