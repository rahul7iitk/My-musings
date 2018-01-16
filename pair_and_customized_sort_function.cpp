#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pair_def;//typedef to enhance readability, purely optional

bool compare(const pair_def &i, const pair_def &j)//this is the function that you will use to compare two pairs, the syntax is pre defined as you can see, you
//you can try to change i.second to i.first , or change the relation symbol as you want, to modify your sort function.
{
    return i.second < j.second;
}

int main() {

vector<pair_def> v;// a vector of pairs, it stores vectors sequentially

for(int i=1;i<=8;i++)
v.push_back(make_pair(i,i*i));//make_pair is a function that returns a pair of two arguments provided to it.

sort(v.begin(),v.end(),compare);//sort function has another parameter: compare , our user defined function that will decide how the sorting takes place.

int i=0;

while(i<v.size()){

cout<<v.at(i).first<<" "<<v.at(i).second<<endl;//first and second are the two data fields of a pair.
i++;
}

return 0;
}