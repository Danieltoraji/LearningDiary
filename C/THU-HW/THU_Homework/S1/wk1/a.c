#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    int n = 1;
    printf("input x:\n");
    scanf("%f", &x);
    float t = pow(-1, n-1) * 1 / (2 * n + 1) * pow(x, 2 * n + 1);
    float s = 0;
    while (fabs(t) >= 0.000001)
    {
        n = n + 1;
        s = s + t;
        t = pow(-1, n) * 1 / (2 * n + 1) * pow(x, 2 * n + 1);
    }
    printf("s=%f\n", s);
    return 0;
}