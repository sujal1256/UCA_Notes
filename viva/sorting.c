#include <stdio.h>
#include <sys/time.h>
#include <assert.h>

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        int j = i - 1;
        while (j >= 0 && ele < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = ele;
    }
}

int test_cases()
{
    int arr[] = {3, 7, 2, 1, 5, 9, 1};
    int expected_arr[] = {1, 1, 2, 3, 5, 7, 9};

    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);
    // selection_sort(arr, n);
    // insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        assert(arr[i] == expected_arr[i]);
    }
}

void print_time()
{
    struct timeval before;
    gettimeofday(&before, NULL);

    // conver the seconds and micro second in miliseconds
    long long before_millies = before.tv_sec * 1000000LL + before.tv_usec; // they calculate time as per the epoch ( 1 January 1970)

    test_cases();

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millies = after.tv_sec * 1000000LL + after.tv_usec;

    printf("%ld mirco seconds", after_millies - before_millies);
}

int main()
{
    print_time();
}