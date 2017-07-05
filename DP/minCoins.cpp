#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int>coins;
  int n, sum, val;
  cout<<"Enter the number of coins: ";
  cin>>n;
  cout<<"\nEnter the coins values: ";
  for(int i = 0; i < n; i++){
    cin>>val;
    coins.push_back(val);
  }
  cout<<"\nEnter the required sum: ";
  cin>>sum;
  vector<int>min_coins(sum+1, INT_MAX);
  min_coins[0] = 0;
  for (size_t i = 1; i <= sum; i++) {
    for(int j = 0; j < coins.size(); j++){
      if((coins[j] <= i) && (min_coins[i-coins[j]]+1 < min_coins[i])){
        min_coins[i] = min_coins[i-coins[j]]+1;
      }
    }
  }
  cout<<"\nThe minimum number of coins to get sum "<<sum<<" :"<<min_coins[sum];
  return 0;
}
