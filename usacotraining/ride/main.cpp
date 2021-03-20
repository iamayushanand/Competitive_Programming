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
TASK: ride
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("ride.out");
    	ifstream fin ("ride.in");
	string comN,grpN;
	fin>>comN>>grpN;
	int a=1;
	int b=1;
	int s1=comN.size();
	int s2=grpN.size();
	for(int i=0;i<s1;i++){
		a*=comN[i]-'A'+1;
//		cout<<comN[i]<<'\n';
	}
	for(int i=0;i<s2;i++){
		b*=grpN[i]-'A'+1;
	}
//	cout<<a<<' '<<b;
	if((a%47)==(b%47)){
		fout<<"GO"<<'\n';
	}else{
		fout<<"STAY"<<'\n';
	}
	//cin.tie(0);	
	return 0;
}
