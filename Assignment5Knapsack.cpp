#include<iostream>
using namespace std;

void Ratio(int n ,int profit[],int weight[],double ratio[]){
    for(int i=0;i<n;i++){
        ratio[i] = (double)profit[i]/weight[i]; 
    }
}

void Sorting(int n ,int profit[],int weight[],double ratio[]){
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(ratio[j] < ratio[j+1]){

                double tempRatio = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = tempRatio;

                int tempProfit = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = tempProfit;

                int tempWeight = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = tempWeight;
            }
        }
    }
}

int Knapsack(int n,int profit[],int weight[],double ratio[],int cap){
    int maxProfit = 0;
    int currentWeight = 0;

    for(int i=0;i<n;i++){
        if(currentWeight + weight[i] <=cap){
            currentWeight += weight[i];
            maxProfit += profit[i];
        }else{
            int remainingCap = cap - currentWeight;
            maxProfit += ratio[i]*remainingCap;
            break;
        }
    }

    return maxProfit;
}

int main(){
    int n;
    cout<<"Enter the No of Objects";
    cin>>n;

    int profit[n];
    int weight[n];
    double ratio[n];

    for(int i=0;i<n;i++){
        cout<<"Profit of Object "<<i+1<<":";
        cin>>profit[i];
    }

    for(int i=0;i<n;i++){
        cout<<"Weight of Object "<<i+1<<":";
        cin>>weight[i];
    }

    int capacity;
    cout<<"Enter the Capacity of Sack :";
    cin>>capacity;

    Ratio(n,profit,weight,ratio);

    Sorting(n,profit,weight,ratio);

    cout<<"Profit\tWeight\tRatio\n";
    for(int i=0;i<n;i++){
        cout<<profit[i]<<"\t"<<weight[i]<<"\t"<<ratio[i]<<endl;
    }

    double MaxProfit = Knapsack(n,profit,weight,ratio,capacity);
    cout<<"The Maximum Profit is "<<MaxProfit;
}