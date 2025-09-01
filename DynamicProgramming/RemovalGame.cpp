// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// long f(vector<int>&GamePoint, int s, int e, int mask){
//     if(s>e)return 0;

//     long  takenFirst=0;
//     if(mask){
//         takenFirst=GamePoint[s];
//     }
//     takenFirst+=f(GamePoint,s+1,e,mask^1);


//     long takenLast=0;
//     if(mask){
//         takenLast=GamePoint[e];
//     }
//     takenLast+=f(GamePoint,s,e-1,mask^1);
    
//     return max(takenFirst,takenLast);

// }

// int main(){

//     int n;cin>>n;
//     vector<int>GamePoint(n);
//     for(int i=0;i<n;i++){
//         cin>>GamePoint[i];
//     }

//     cout<< f(GamePoint,0,n-1,1);
// }


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void print(vector<int>&arr){
    for(auto & a:arr)cout<<a<<" ";
}

int partition(vector<int>&arr, int low ,int high){

    int pivot=arr[high];

    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quick_sort(vector<int>&arr,int low ,int high){

    if(low>high){
        return;
    }

    int p=partition(arr,low,high);
    quick_sort(arr,low,p-1);
    quick_sort(arr,p+1,high);

    

}

int main(){

    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    quick_sort(arr,0,n-1);

    print(arr);
}