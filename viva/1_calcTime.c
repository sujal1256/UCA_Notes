#include <stdio.h>
#include <time.h>

// int main()
// {
//     clock_t start_time, end_time;
//     double time_taken_by_cpu;

//     start_time = clock(); // get the time of CPU being used till now in terms of clocks

//     for (int i = 0; i < 100000099; i++)
//     {
//     }

//     end_time = clock();

//     printf("%f",((double)(end_time - start_time))/CLOCKS_PER_SEC);
// }

#include <sys/time.h>

int main()
{
    struct timeval before;
    gettimeofday(&before, NULL);

    // conver the seconds and micro second in miliseconds
    long long before_millies = before.tv_sec * 1000LL + before.tv_usec / 1000;  // they calculate time as per the epoch ( 1 January 1970)


    for (int i = 0; i < 99999999; i++)
    {
    }


    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millies = after.tv_sec * 1000LL + after.tv_usec / 1000;

    printf("%ld", after_millies - before_millies);

}
