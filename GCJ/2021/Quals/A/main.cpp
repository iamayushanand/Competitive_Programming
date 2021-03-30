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
int solve(){
	int N;
	cin>>N;
	int L[N+1];
	for(int i=0;i<N;i++){
		cin>>L[i];
	}
	int ans=0;
	for(int i=0;i<N-1;i++){
		int j=i;
		for(j=i;j<N;j++){
			if(L[j]==i+1){
				break;
			}
		}
		reverse(L+i,L+j+1);
		ans+=j-i+1;
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
