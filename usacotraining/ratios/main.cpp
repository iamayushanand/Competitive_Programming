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
TASK: ratios
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("ratios.out");
    	ifstream fin ("ratios.in");
	int goal[3];
	int m1[3];
	int m2[3];
	int m3[3];
	for(int i=0;i<12;i++){
		if(i<=2){
			fin>>goal[i];
			continue;
		}
		if(i<=5){
			fin>>m1[i-3];
			continue;	
		}
		if(i<=8){
			fin>>m2[i-6];
			continue;
		}
		if(i<=11){
			fin>>m3[i-9];
			continue;
		}
	}
	int ansa=-1;
	int ansb=-1;
	int ansc=-1;
	int ansg=-1;
	for(int a=0;a<=100;a++){
		for(int b=0;b<=100;b++){
			for(int c=0;c<=100;c++){
				int x1=a*m1[0]+b*m2[0]+c*m3[0];
				if(goal[0]!=0 && x1%goal[0]!=0)continue;
				
				int x2=a*m1[1]+b*m2[1]+c*m3[1];
				int x3=a*m1[2]+b*m2[2]+c*m3[2];
					
				if(x1!=0 && goal[0]==0)continue;
				if(x2!=0 && goal[1]==0)continue;
				if(x3!=0 && goal[2]==0)continue;
				if(x1==0 && goal[0]!=0)continue;
				if(x2==0 && goal[1]!=0)continue;
				if(x3==0 && goal[2]!=0)continue;
				int quot;
				if(x1!=0)quot=x1/goal[0];
				
				if(x2!=0)quot=x2/goal[1];
				if(x3!=0)quot=x3/goal[2];
				if(a==0 && b==0 && c==0)continue;
				if((x1==0 || x1%goal[0]==0) && (x2==0 || x2%goal[1]==0) && (x3==0 || x3%goal[2]==0) && (x1==0 || quot==x1/goal[0]) && (x2==0 || quot==x2/goal[1]) && (x3==0 || quot==x3/goal[2])){

					if(ansa+ansb+ansc>x1+x2+x3 || ansg==-1){
						ansa=a;
						ansb=b;
						ansc=c;
						ansg=quot;
					}
				}
			}
		}
	}
	if(ansg==-1 ){
		fout<<"NONE"<<'\n';
	}else{
		fout<<ansa<<' '<<ansb<<' '<<ansc<<' '<<ansg<<'\n';
	}
	//cin.tie(0);	
	return 0;
}
