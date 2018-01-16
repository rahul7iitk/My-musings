#include <iostream>
using namespace std;
    /**
     * Returns index in T for ceiling of s
     */
     int ceilIndex(int input[], int T[], int end, int s){
        int start = 0;
        int middle;
        int len = end;
        while(start <= end){
            middle = (start + end)/2;
            if(middle < len && input[T[middle]] < s && s <= input[T[middle+1]]){
                return middle+1;
            }else if(input[T[middle]] < s){
                start = middle+1;
            }else{
                end = middle-1;
            }
        }
        return -1;
    }
    
int longestIncreasingSubSequence(int input[],int n){
    int T[n] ;
    int R[n];
        for(int i=0; i < n ; i++) {
            R[i] = -1;
        }
        T[0] = 0;
        int len = 0;
        for(int i=1; i < n; i++){
            if(input[T[0]] > input[i]){ //if input[i] is less than 0th value of T then replace it there.
                T[0] = i;
            }else if(input[T[len]] < input[i]){ //if input[i] is greater than last value of T then append it in T
                len++;
                T[len] = i;
                R[T[len]] = T[len-1];
            }else{ //do a binary search to find ceiling of input[i] and put it there.
                int index = ceilIndex(input, T, len,input[i]);
                T[index] = i;
                R[T[index]] = T[index-1];
            }
        }
        
        //this prints increasing subsequence in reverse order.
        //System.out.print("Longest increasing subsequence ");
        int index = T[len];
        while(index != -1) {
            cout<<input[index]<<" ";
            index = R[index];
        }
        
    cout<<"\n";
    return len+1;
    }
    
    int main(){
        //int input[] = {2,5,3,1,2,10,6,7,8};
        int input[] = {3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10};
        
        cout<<"Maximum length " << longestIncreasingSubSequence(input,11)<<"\n";
    }

