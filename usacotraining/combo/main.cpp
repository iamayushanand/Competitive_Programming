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
TASK: combo
LANG: C++                 
*/
int N;
int mod(int a){
	a%=N;
	if(a<=0){return N+a;}
	return a;
}
int circdiff(int a,int b){
	if(a>b){
		if((a-b)>(N/2)){return N-(a-b);}else{return (a-b);}
	}else{
		if((b-a)>(N/2)){return N-(b-a);}else{return (b-a);}
	}
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("combo.out");
    	ifstream fin ("combo.in");
//	int N;
	fin>>N;
	int john[3];
	int mst[3];
	fin>>john[0]>>john[1]>>john[2];
	fin>>mst[0]>>mst[1]>>mst[2];
	int c1=0;
	for(int i=john[0]-2;i<john[0]+3;i++){
		int x=mod(i);
//		cout<<x<<' '<<mst[0]<<' '<<circdiff(x,mst[0])<<'\n';
		if(circdiff(x,mst[0])<=2){c1++;}
	}
//	fout<<c1<<' ';
	int c2=0;
	for(int i=john[1]-2;i<john[1]+3;i++){
	//	fout<<mod(i,N)<<'\n'; 
		int x=mod(i);
		if(circdiff(x,mst[1])<=2){c2++;}
	}
//	fout<<c2<<' ';
	int c3=0;
	for(int i=john[2]-2;i<john[2]+3;i++){
		int x=mod(i);
		if(circdiff(x,mst[2])<=2){c3++;}
	}
	if(N<5){
		fout<<(N*N*N)<<'\n';
		return 0;
	}
//	fout<<c3<<' ';
	fout<<250-(c1*c2*c3)<<'\n';
	//cin.tie(0);	
	return 0;
}
