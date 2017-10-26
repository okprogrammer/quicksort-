#include <iostream>

using namespace std;

void swap(int* a, int* b)/* swap function to swapping two numbers*/
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int A[], int start, int end) /* This function takes the element and set a pivot element smaller value in array
set left to this and greater value from this set right to it*/
{
    int pivot=A[end];
    int partitionIndex=start;
    for(int i=start;i<end;i++)
    {
        if(A[i]<=pivot)
        {
            swap(&A[i],&A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&A[partitionIndex],&A[end]);
    return partitionIndex;
}

void QuickSort(int A[],int start,int end)
{
    if(start<end)
    {
        int partitionIndex=Partition(A,start,end);
        QuickSort(A,start,partitionIndex-1);
        QuickSort(A,partitionIndex+1,end);
    }
}

int main()
{
    int A[20],n;
    cout<<"how many do you want to enter in the array"<<endl;
    cin>>n;
    cout<<"Enter array element"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    QuickSort(A,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<endl;
    }
    return 0;
}
