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
TASK: friday
LANG: C++                 
*/
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("friday.out");
    	ifstream fin ("friday.in");
	int N;
	fin>>N;
	int year=1900;
	bool isleap=0;
	int daycount=0;
	int week[7]={0};
	for(int i=0;i<N;i++){
		if(year % 400==0){isleap=1;}
		if((year % 100!=0) && (year % 4==0)){isleap=1;}
		for(int j=0;j<12;j++){
			daycount+=12;
			week[daycount % 7]++;
			int monlen;
			if(j==3 || j==5 || j==8 || j==10){
				monlen=30;
			}else if(j==1 && isleap){
				monlen=29;
			}else if(j==1 && !isleap){
				monlen=28;
			}else{
				monlen=31;
			}
			daycount+=monlen-12;
		}
		year++;
		isleap=0;
	}
	
	fout<<week[5]<<' '<<week[6]<<' '<<week[0]<<' '<<week[1]<<' '<<week[2]<<' '<<week[3]<<' '<<week[4]<<'\n';
	//cin.tie(0);	
	return 0;
}
