#include<iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vi, int low, int up){
        int pivot = vi[up];
        int i = low-1;
        for (int j = low; j < up; j++)
        {
                if(vi[j] <= pivot)
                {
                        i++;
                        swap(vi[i], vi[j]);
                }
        }
        swap(vi[i+1], vi[up]);
        return i+1;
}

void quickSort(vector<int> &vi, int low, int up){
        if(low < up)
        {
                int mid = partition(vi, low, up);
                quickSort(vi, low, mid-1);
                quickSort(vi, mid+1, up);
        }
}


int main(){
    int n;
    while(true){
      cout<<"Please enter your a number for the lenth:"<<endl;
      cin>>n;
      vector<int> s(n);
      cout<<"Please enter your numbers:"<<endl;
      for (int i=0;i<n;i++)cin>>s[i];
      quickSort(s, 0, n-1);
      for (int i=0;i<n;i++) cout<<s[i]<<" ";
      cout<<endl;
    }
   return 0;

}
