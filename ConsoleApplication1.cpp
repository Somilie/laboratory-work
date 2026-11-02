#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(){
    int n, i, j, k;
    double min, max, sum = 0;
    double m[1000];
    int f[1000];
    printf("Input n, min, max: ");
    scanf_s("%d %lf %lf", &n, &min, &max);
    if (n <= 0 || n > 1000 || min >= max){
        printf("Incorrect data");
        return 1;
    }
    srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++){
        m[i] = min + (max - min) *
            ((double)rand() / RAND_MAX);
        m[i] = round(m[i] * 100) / 100;
        f[i] = 0;
        printf("%d: %.2f\n", i + 1, m[i]);
    }
    for (i = 0; i < n; i++){
        double x = fabs(m[i]);
        double d = x - floor(x);
        k = (int)round(d * 100);

        if (k >= 1 && k <= n){
            f[k - 1] = 1;
        }
    }
    for (j = 0; j < n; j++){
        if (f[j] == 1){
            sum = sum - m[j];
            printf("Minus: %.2f\n", m[j]);
        }
        else{
            sum = sum + m[j];
            printf("Plus: %.2f\n", m[j]);
        }
    }
    printf("Sum = %.2f\n", sum);
    return 0;
}
