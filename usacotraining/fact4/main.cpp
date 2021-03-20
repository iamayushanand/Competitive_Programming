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
TASK: fact4
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("fact4.out");
    	ifstream fin ("fact4.in");
	int N;
	fin>>N;
	int two=0;
	int five=0;
	int ans=1;
	for(int i=1;i<=N;i++){
		int cur=i;
		while(cur%2==0 || cur%5==0){
			if(cur%2==0){
				two++;
				cur/=2;
			}
			if(cur%5==0){
				five++;
				cur/=5;
			}
		}
		cur%=10;
		ans*=cur;
		ans%=10;
	}
	while(two>five){
		two--;
		ans*=2;
		ans%=10;
	}
	fout<<ans<<'\n';
	//cin.tie(0);	
	return 0;
}
