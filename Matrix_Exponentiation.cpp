#include <iostream>

using namespace std;
#define big long long
const long long mod=1000000007;
big A[2][2]={{1,1},{1,0}};

inline void multiply_one(big A[2][2],big B[]){
    big p = (A[0][0]*B[0]+A[0][1]*B[1])%mod;
    if(p<0)
        p+=mod;
    big q = (A[1][0]*B[0]+A[1][1]*B[1])%mod;
    if(q<0)
        q+=mod;
    B[0]=p;
    B[1]=q;
}
void find_pow(big n);
void multiply(big A[][2],big B[][2]);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
//	big mat[2][2]={{1,1},{1,0}};
/*	for(int i=0;i<2;i++){
	        for(int j=0;j<2;j++)
	            cout<<mat[i][j]<<" ";
	            cout<<endl;
	    }*/
	 big start[2]={1,0};   
	   
	int t; cin>>t;
	while(t-->0){
	    big low,high;
	    cin>>low>>high; big sum=0,sum1=0;
	     A[0][0]=A[0][1]=A[1][0]=1; A[1][1]=0;
	       start[0]=1;start[1]=0;
	      
	       find_pow(low);
	       multiply_one(A,start);
	       sum=(start[0]-1)%mod;
	       if(sum<0)
	        sum+=mod;
	       A[0][0]=A[0][1]=A[1][0]=1; A[1][1]=0;
	       start[0]=1;start[1]=0;
	       
	       find_pow(high+1);
	       multiply_one(A,start);
	       sum1=(start[0]-1)%mod;
	       if(sum1<0)
	        sum1+=mod;
	       
	       big result=(sum1-sum)%mod;
	       if(result<0)
	        result+=mod;
	        
	        cout<<result<<endl;
	        
	    }
	    
	    return 0;
	}
//	return 0;


void find_pow(big n){
    
       // A={(1,0),(0,1)};
    if(n<=1)
        return;
        
    if(n%2==0){
        find_pow(n/2);
        multiply(A,A);
    }
    else{
        big B[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                B[i][j]=A[i][j];
        }
        find_pow(n-1);
        multiply(A,B);
    }
}
void multiply(big A[][2],big B[][2]){
    big C[2][2];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j]=0;
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
                if(C[i][j]<0)
                    C[i][j]+=mod;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            A[i][j]=C[i][j];
    }
}
