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
TASK: inflate
LANG: C++                 
*/
struct categ{
	int points;
	int time;
};
vector<categ> categs;
int M,N;
int ans[10005];
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("inflate.out");
	ifstream fin ("inflate.in");
	fin>>M>>N;
	for(int i=0;i<N;i++){
		categ cur;
		fin>>cur.points>>cur.time;
		categs.push_back(cur);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<=M;j++){
			if(i==0){
				if(categs[0].time<=j){
					ans[j]=(j/categs[0].time)*categs[0].points;
				}
			}else{
				if(categs[i].time<=j){
				ans[j]=MAX(ans[j-categs[i].time]+categs[i].points,ans[j]);
				}
			}
		}
	}
	fout<<ans[M]<<'\n';
	//cin.tie(0);	
	return 0;
}
