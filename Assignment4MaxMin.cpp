#include<iostream>
using namespace std;

void MaxMin(int arr[],int low,int high, int &maxval,int &minval){
    if(low == high){
        minval = arr[low];
        maxval = arr[high];
        return;
    }
    
    if(high == low+1){
        if(arr[low]<arr[high]){
            minval = arr[low];
            maxval = arr[high];
        }else{
            minval = arr[high];
            maxval = arr[low];
        }
        return;
    }

    int mid = low + (high-low)/2;

    int rightmin,rightmax,leftmin,leftmax;

    MaxMin(arr,low,mid,leftmax,leftmin);
    MaxMin(arr,mid+1,high,rightmax,rightmin);

    if(leftmax < rightmax){
        maxval = rightmax;
    }else{
        maxval = leftmax;
    }

    if(leftmin > rightmin){
        minval = rightmin;
    }else{
        minval = leftmin;
    }

}

int main(){
    int n;
    cout<<"Enter the lenth of array :";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements in the array"<<endl;

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int low = 0;
    int high = n-1;
    int maxVal,minVal;

    MaxMin(arr,low, high,maxVal,minVal);

    cout<<"Max value is"<<maxVal<<endl;
    cout<<"Min Value is"<<minVal<<endl;
}