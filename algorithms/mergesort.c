#include<iostream>
#include <vector>

using namespace std;

void merge(vector<int>&s, int left, int mid, int right){
    vector<int> tmp1(mid-left+1);
    vector<int> tmp2(right-mid);
    for(int i=0; i<=mid-left; i++) tmp1[i]=s[left+i];
    for(int i=0; i<right-mid; i++) tmp2[i]=s[mid+1+i];
    int i = 0, j = 0, count = 0;
    while(i<=mid-left && j<right-mid){
       if(tmp1[i]<tmp2[j]){
        s[left+count] = tmp1[i++];
       }
       else{
           s[left+count] = tmp2[j++];
       }
       count++;
       if(i > mid - left && j < right-mid){
         while(j< right-mid){
         s[left+count] = tmp2[j++];
         count ++;
         }
       }
       else if (j > right-mid-1){
         while(i <= mid-left){
         s[left+count] = tmp1[i++];
         count ++;
         }
       }
    }

}

void merge_sort(vector<int>&s, int left, int right){
     if(left>=right) return;
     int mid = (left + right)/2;
     merge_sort(s,left,mid);
     merge_sort(s,mid+1,right);
     merge(s,left,mid,right);
}

int main(){
    int n;
    while(true){
      cout<<"Please enter your a number for the lenth:"<<endl;
      cin>>n;
      vector<int> s(n);
      cout<<"Please enter your numbers:"<<endl;
      for (int i=0;i<n;i++)cin>>s[i];
      merge_sort(s, 0, n-1);
      for (int i=0;i<n;i++) cout<<s[i]<<" ";
      cout<<endl;
    }
   return 0;

}
