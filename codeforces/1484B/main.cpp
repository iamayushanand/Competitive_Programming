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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		bool eq=1;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i>1 && a[i]-a[i-1]!=a[1]-a[0])eq=0;	
		}
		if(eq){
			cout<<0<<'\n';
			continue;
		}
		long long pos=-1;
		long long neg=1;
		bool imposs=0;
		for(int i=0;i<n-1;i++){
			if(a[i+1]-a[i]>0){
				if(pos>0 && pos!=a[i+1]-a[i]){
					imposs=1;
					break;
				}else{
					pos=a[i+1]-a[i];
				}
			}
			if(a[i+1]-a[i]<0){
				if(neg<0 && neg!=a[i+1]-a[i]){
					imposs=1;
					break;
				}else{
					neg=a[i+1]-a[i];
				}
			}
			if(a[i+1]==a[i]){
				imposs=1;
			}
			
		}
		for(int i=0;i<n;i++){
			if(a[i]>=pos-neg){
				imposs=1;
			}
		}
		if(imposs){
			cout<<-1<<'\n';
		}else{
			cout<<pos-neg<<' '<<pos<<'\n';
		}
	}
	return 0;
}
