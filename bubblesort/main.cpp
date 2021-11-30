#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

bool isSortedAsc(int arr[], int leng);
void bubblesort(int arr[], int leng);

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
    }*/

        cout<<"Czas podany jest w milisekundach"<<endl;


    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

    bubblesort(losowe,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania losowych bąbelkowym:";
    cout<<msecs_time_end-msecs_time_start<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    bubblesort(sortowane,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania posortowanych bąbelkowym:";
    cout<<msecs_time_end-msecs_time_start<<endl;

    gettimeofday(&time_now, nullptr);
    msecs_time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

    bubblesort(odwrotnie,n);
    gettimeofday(&time_now, nullptr);
    msecs_time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    cout<<"Czas sortowania posortowanych odwrotnie bąbelkowym:";
    cout<<msecs_time_end-msecs_time_start<<endl;
    return 0;
}

void bubblesort(int arr[], int leng)
{
    int iteration=0;
    while(!isSortedAsc(arr,leng))
    {
        iteration++;
        for(int i=0; i<leng; i++)
        {
            if(arr[i+1]<arr[i])
            {
                swap(arr[i+1],arr[i]);
            }
        }
    }
    //cout<<iteration<<endl;
}

bool isSortedAsc(int arr[],int leng)
{
    for(int i=0; i<leng-1; i++)
    {
        if(arr[i]>arr[i+1])return false;
    }
    return true;
}

//99451 iteracji
//99592 iteracji oko³o 31 sekund
//Wiêcej prób nie zostanie podjêtych ze wzglêdu na bardzo wysokie zu¿ycie mojego procesora przez d³ugi czas. Szkoda sprzêtu
