#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to find the largest mobile element
int getMobile(int a[], int dir[], int n)
{
    int mobile = 0;
    int mobile_prev = 0;

    for (int i = 0; i < n; i++)
    {
        if (dir[a[i] - 1] == LEFT && i != 0)
        {
            if (a[i] > a[i - 1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

        if (dir[a[i] - 1] == RIGHT && i != n - 1)
        {
            if (a[i] > a[i + 1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    return mobile;
}

// Function to print one permutation
void printPermutation(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

// Johnson-Trotter Algorithm
void johnsonTrotter(int n)
{
    int a[n];
    int dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    // Print first permutation
    printPermutation(a, n);

    // Generate remaining permutations
    for (int count = 1; count < n * n; count++)
    {
        int mobile = getMobile(a, dir, n);

        if (mobile == 0)
            break;

        int pos;

        // Find position of mobile element
        for (int i = 0; i < n; i++)
        {
            if (a[i] == mobile)
            {
                pos = i;
                break;
            }
        }

        // Swap mobile element in its direction
        if (dir[mobile - 1] == LEFT)
        {
            int temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;

            pos = pos - 1;
        }
        else if (dir[mobile - 1] == RIGHT)
        {
            int temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;

            pos = pos + 1;
        }

        // Reverse direction of all elements greater than mobile
        for (int i = 0; i < n; i++)
        {
            if (a[i] > mobile)
                dir[a[i] - 1] = -dir[a[i] - 1];
        }

        // Print permutation
        printPermutation(a, n);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
