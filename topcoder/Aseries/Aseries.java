import java.util.*;
import java.io.*;
import java.math.*;
public class Aseries{
	public int longest(int values[]){
		Arrays.sort(values);
		int ans=-1;
		for(int i=0;i<values.length;i++){
			for(int j=i+1;j<values.length;j++){
				int diff=values[j]-values[i];
				int prev=values[j];
				int cnt = 2;
				for(int k=j+1;k<values.length;k++){
					if(values[k]-prev==diff){
						cnt++;
						prev=values[k];
					}
					
				}
				ans=Math.max(ans,cnt);
			}	
			
		}
		return ans;
	}


}
