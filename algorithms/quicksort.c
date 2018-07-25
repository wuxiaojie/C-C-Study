#include<iostream>
#include <vector>

using namespace std;

int partion(vector<int>&s, int left, int right){
    int pivot = s[left];
    int i=left,j = right;
    while(i!=j){
       while( i< j && s[j] > pivot) j--;
       s[i] = s[j];
       while(i<j && s[i] < pivot) i++;
       s[j] = s[i];
    }
    s[i] = pivot;
    return i;
}

void quick_sort(vector<int>&s, int left, int right){
     if(left>=right) return;
     int mid = partion(s,left,right);
     quick_sort(s,left,mid-1);
     quick_sort(s,mid+1,right);
}

int main(){
    int n;
    while(true){
      cout<<"Please enter your a number for the lenth:"<<endl;
      cin>>n;
      vector<int> s(n);
      cout<<"Please enter your numbers:"<<endl;
      for (int i=0;i<n;i++)cin>>s[i];
      quick_sort(s, 0, n-1);
      for (int i=0;i<n;i++) cout<<s[i]<<" ";
      cout<<endl;
    }
   return 0;

}
