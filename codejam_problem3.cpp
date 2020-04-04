#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
  int t,n;
  cin>>t;
  int ans;
  int a,b;
  int t1=1;
  while(t1<=t){
    cin>>n;
    vector<pair<pair<int,int>,int> >array;
    for(int i=1;i<=n;i++){
      cin>>a>>b;
      array.push_back(make_pair(make_pair(a,b),i-1));
    }
    string result(n,'.');
    int jj=0,cc=0;
    sort(array.begin(),array.end());
    for(int i=0;i<n;i++){
      int st=array[i].first.first;
      int end=array[i].first.second;
      int idx=array[i].second;
      if(st>=cc){
        cc=end;
        result[idx]='C';
      }
      else if(st>=jj){
        jj=end;
        result[idx]='J';
      }
      else {
        result="IMPOSSIBLE";
        break;
      }
    }
    cout<<"Case #"<<t1<<": "<<result<<endl;
    t1++;
  }
  return 0;
}
