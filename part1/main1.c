#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    double x, y = 0.0;

    printf("Enter n (>10): ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%lf", &x);

    for (int k = 1; k <= n; ++k) {
        y += (n - k + 1) * cos(k * x);
    }

    printf("y = %lf\n", y);
    return 0;
}