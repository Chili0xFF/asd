#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
using namespace std;

void heapSort(int arr[], int leng);
bool isSortedAsc(int arr[], int leng);
void heapify(int arr[], int n, int i);

int main()
{
    int n=100000;
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
    cout<<"Czas sortowania losowych heapsortem:";
    heapSort(losowe,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania posortowanych heapsortem:";
    heapSort(sortowane,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania posortowanych odwrotnie heapsortem:";
    heapSort(odwrotnie,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    return 0;
}

void heapify(int arr[], int n, int i)
{
    //if(isSortedAsc(arr,high)==true)return;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

bool isSortedAsc(int arr[],int leng){
    for(int i=0;i<leng;i++){
        if(arr[i]>arr[i+1])return false;
    }
    return true;
}

