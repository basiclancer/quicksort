#include <stdio.h>
#include <time.h>
int a[50], n;
partition(int m, int p)
{
    int i, t, v;
    v = a[m];
    i = m;
    while (i < p)
    {
        do
            i++;
        while (a[i] < v);
        do
            p--;
        while (a[p] > v);
        if (i < p)
        {
            t = a[i];
            a[i] = a[p];
            a[p] = t;
        }
        else
            break;
    }
    a[m] = a[p];
    a[p] = v;
    return p;
}
quick_sort(int p, int q)
{
    int j;
    if (p < q)
    {
        j = q + 1;
        j = partition(p, j);
        quick_sort(p, j - 1);
        quick_sort(j + 1, q);
    }
}
int main()
{
    int i;
    clock_t f, s;
    printf("\n\t\t\t QUICK SORT \n");
    printf("\n Enter the length of the array:");
    scanf("%d", &n);
    printf("\n Enter elements of the array \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    s = clock();
    quick_sort(1, n);
    f = clock();
    printf("\n Sorted elements are \n");
    for (i = 1; i <= n; i++)
        printf("%d\t", a[i]);
    printf("Time taken to execute quick sort is % f", (f - s));
    return 0;
}
