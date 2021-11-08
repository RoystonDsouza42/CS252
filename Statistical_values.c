//Royston Calder Dsouza
//191EE143
//CS252 - Operating systems
//Q4.22

//Libraries required
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//Global variables
int n;
int *arr;

// average , minimum and maimum variables stored globally.
float average;
int minimum;
int maximum;

//Thread1 for calculating average
void *avg()
{
    int i;
    float sum = 0;

    for (i =0; i< n; i++)
    {
        sum = sum + arr[i];
    }
    average = sum/n;
}

//Thread2 for calculating minimum value
void *min()
{
    int i;
    minimum = arr[0];

    for (i =0; i< n;i++)
    {
        if (minimum > arr[i])
            minimum = arr[i];
    }
}

//Thread3 for calculating maximum value
void *max()
{
    int i;
    maximum = arr[0];

    for (i=0; i< n; i++)
    {
        if (maximum < arr[i])
            maximum = arr[i];
    }
}

//main function
void main(int argc, char *argv[])
{
    int i;
    //The data elements passed on the command line.
    n = argc-1;

    //creating a dynamic array to store n elements.
    arr = (int *) malloc(sizeof(int)*n);

    //Converting the command line argument from string into integer.
    for (i=1; i < argc; i++)
    {   
        arr[i-1] = atoi(argv[i]);
    }   

    printf("\nThe number of elements passed on the command line are: %d\n",n);
    printf("\nThe entered elements are: \n");
    for (i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
 
    printf("\n\n");

    // Declaring three worker threads t1,t2,t3.
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    //creating threads
    pthread_create(&t1,NULL,&avg,NULL);
    pthread_join(t1,NULL);

    pthread_create(&t2,NULL,&min,NULL);
    pthread_join(t2,NULL);

    pthread_create(&t3,NULL,&max,NULL);
    pthread_join(t3,NULL);

    //main of the parent thread
    /*The parent thread will output the result once the workers
    have exited*/

    printf("The average value is %f\n",average);
    printf("The minimum value is %d\n",minimum);
    printf("The maximum value is %d\n",maximum);  
    printf("\n\n");
}
