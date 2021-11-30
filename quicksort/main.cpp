#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
using namespace std;

void quicksort(int arr[], int low, int high);
bool isSortedAsc(int arr[], int leng);
int main()
{
    int n=10000;
    int losowe[n];
    int sortowane[n];
    int odwrotnie[n];

    struct timeval time_now{};
    time_t msecs_time_start;
    time_t msecs_time_end;

    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        losowe[i]=(rand()%1500);
    }
    for(int i=0; i<n; i++)
    {
        sortowane[i]=i;
    }
    for(int i=n-1, j=0; j<n; i--,j++)
    {
        odwrotnie[j]=i;
    }

    /*for(int i=0;i<n;i++){
        cout<<losowe[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<sortowane[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<odwrotnie[i]<<endl;
    }
    */

    cout<<"Czas podany jest w milisekundach"<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania losowych quicksortem:";
    quicksort(losowe,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania posortowanych quicksortem:";
    quicksort(sortowane,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania posortowanych odwrotnie quicksortem:";
    quicksort(odwrotnie,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    return 0;
}

void quicksort(int arr[], int low, int high)
{
    //if(isSortedAsc(arr,high)==true)return;
    if(low<high)
    {
        int i=low-1,j=low;
        int p=arr[high];

        for(; j<high; j++)
        {
            if(arr[j]<p)
            {
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        int middle = i+1;
        quicksort(arr,low,middle-1);
        quicksort(arr,middle+1,high);
    }
}

bool isSortedAsc(int arr[],int leng)
{
    for(int i=0; i<leng; i++)
    {
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;
}
