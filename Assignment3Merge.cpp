#include<iostream>
using namespace std;

class Sort{
public:
    void Display(int arr[],int n){
        for(int i=0;i<n;i++){
            cout<<arr[i];
            cout<<'\t';
        }
    }

    void Merge(int arr[],int low,int mid,int high){
        int n1,n2;
        n1 = mid-low+1;
        n2 = high-mid;
        int L[n1],R[n2];

        for(int i = 0;i<n1;i++){
            L[i] = arr[low + i]; 
        }
        for(int j = 0;j<n2;j++){
            R[j] = arr[mid + 1 + j];
        }

        int i=0;
        int j=0;
        int k=low;

        while(i<n1 && j<n2){
            if(L[i] <=  R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void MergeSort(int arr[],int low,int high){
        if(low < high){
            int mid = low + (high-low)/2;

            MergeSort(arr,low,mid);
            MergeSort(arr,mid+1,high);

            Merge(arr,low,mid,high);
        }
    }
};


int main(){
    int n;
    cout<<"Enter the Number of elements in the array :";
    cin>>n;

    int arr[n];
    cout<<"Enter the Elements in the array"<<endl;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Sort sorter;

    sorter.Display(arr,n);
    cout<<endl;

    int low = 0;
    int high = n-1;

    sorter.MergeSort(arr,low,high);

    sorter.Display(arr,n);
}