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
int L[20];
bool done=0;
int mx[20];
int mn[20];
int cost(int N){
	int ans=0;
	int M[20];
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
	int max=0;
	int min=INF;
	bool done=0;
	for(int i=0;i<N;i++){
		L[i]=i+1;
	}
	do{
		if(max<cost(N)){
			for(int i=0;i<N;i++){
				mx[i]=L[i];
			}
		}
		if(min>cost(N)){
			for(int i=0;i<N;i++){
				mn[i]=L[i];
			}
		}
		max=MAX(max,cost(N));
		
		min=MIN(min,cost(N));

		cout<<"cost:"<<cost(N)<<'\n';
		for(int i=0;i<N;i++){
			cout<<L[i]<<' ';
		}
		cout<<'\n';
	}while(next_permutation(L,L+N));
//	if(!done){
//		cout<<"IMPOSSIBLE";
//	}
//	cout<<'\n';
//	for(int i=0;i<N;i++){
//		cout<<mx[i]<<' ';
//	}
	cout<<'\n';

	cout<<"N:"<<N<<" max:"<<max<<" min:"<<min;
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
