#include <stdio.h>

void swap(int* a, int* b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void asc(int *arr, int n, int tigger)
{
    for (int i=1; i<=n-1; i++)
    {
        for (int j=i+1; j<=n-1-i; j++)
        {
            if (arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void desc(int *arr, int n, int tigger)
{
    for (int i=1; i<=n-1; i++)
    {
        for (int j=i+1; j<=n-1-i; j++)
        {
            if (arr[j]<arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

int main()
{
    int n;
    printf("enter no. of elements: ");
    scanf("%d", &n);


    printf("enter elements: ");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int choice;
    printf("1. Sort in Ascending Order\n2. Sort in Descending order\n3. Exit");
    printf("enter choice: ");
    scanf("&d", &choice);
    switch(choice)
    {
    case 1:
        asc(arr, n);
        for (int i=0; i<n; i++)
            printf("%d ", arr[i]);
        break;
    case 2:
        desc(arr, n);
        for (int i=0; i<n; i++)
            printf("%d ", arr[i]);
        break;
    case 3:
        printf("Exiting...");
    default:
        printf("Please enter a valid choice");
    }
    return 0;
}
