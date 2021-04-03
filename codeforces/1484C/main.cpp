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
int ciel(int m){
	if(m%2){
		return (m/2)+1;
	}
	return m/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int friends[m+1][2];
		int chosen[m+1];
		int time[n+1];
		int len[m+1];
		for(int i=0;i<n+1;i++){
			time[i]=0;
		}
		for(int i=0;i<m;i++){
			int k;
			cin>>k;
			len[i]=k;
			int ktemp=k;
			k=MIN(k,2);
			for(int j=0;j<k;j++){
				cin>>friends[i][j];
			}
			for(int j=0;j<ktemp-k;j++){
				int dump;
				cin>>dump;
			}
			time[friends[i][0]]++;
			chosen[i]=friends[i][0];
		}
		int stop=0;
		int worse=0;
		for(int i=0;i<n+1;i++){
			if(time[i]>ciel(m)){
				worse=i;
				stop=1;
			}
		}
		if(stop==0){
			cout<<"YES"<<'\n';
			for(int i=0;i<m;i++){
				cout<<chosen[i]<<' ';
			}
			cout<<'\n';
			continue;
		}
		for(int i=0;i<m;i++){
			if(len[i]==1)continue;
			if(friends[i][0]==worse){
				time[worse]--;
				time[friends[i][1]]++;
				chosen[i]=friends[i][1];
				if(time[worse]<=ciel(m)){
					break;
				}
			}
		}
		stop=0;
		for(int i=0;i<n+1;i++){
			if(time[i]>ciel(m)){
				stop=1;
			}
		}
		if(stop==0){
			cout<<"YES"<<'\n';
			for(int i=0;i<m;i++){
				cout<<chosen[i]<<' ';
			}
			cout<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}

	}
	return 0;
}
