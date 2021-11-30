#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
using namespace std;

void mergeArray(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
bool isSortedAsc(int arr[], int leng);

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
    cout<<"Czas sortowania losowych mergesortem:";
    mergeSort(losowe,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania posortowanych mergesortem:";
    mergeSort(sortowane,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania posortowanych odwrotnie mergesortem:";
    mergeSort(odwrotnie,0,n-1);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<msecs_time_end-msecs_time_start<<endl;

    return 0;
}

void mergeArray(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i=0, j=0, k=p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        mergeArray(arr, l, m, r);
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
