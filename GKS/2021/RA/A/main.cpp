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
	int N,K;
	cin>>N>>K;
	string s;
	cin>>s;
	int init=0;
	for(int i=0;i<N/2;i++){
		if(s[i]!=s[N-i-1]){
			init++;
		}
	}

	return abs(K-init);
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
