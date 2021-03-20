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
#include <fstream>

using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define MOD 1000000007

/*
ID: iamayus1
TASK: sort3
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("sort3.out");
    	ifstream fin ("sort3.in");
	int N;
	int ans=0;
	fin>>N;
	int lst[N];
	int cnt[3]={0,0,0};
	int sorted[3][3];//sorted[x][y] x's in y's position
	for(int i=0;i<N;i++){
		fin>>lst[i];
		cnt[lst[i]-1]++;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			sorted[i][j]=0;
		}
	}
	int st=0;
	for(int j=0;j<3;j++){
		int end=st+cnt[j];
		for(;st<end;st++){
			sorted[lst[st]-1][j]++;
		}
		
	}
	for(int i=0;i<3;i++){
		for(int j=i+1;j<3;j++){
			int tmp=MIN(sorted[i][j],sorted[j][i]);
			sorted[i][j]-=tmp;
			sorted[j][i]-=tmp;
			ans+=tmp;
		}
	}
	int tmp=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==j)continue;
			tmp+=sorted[i][j];
		}
	}
	ans+=2*(tmp/3);
	fout<<ans<<'\n';
	//cin.tie(0);	
	return 0;
}
