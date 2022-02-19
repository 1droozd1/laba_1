#include <stdio.h>
#include <stdlib.h>

int sign(int a)
{
    if (a > 0) {
        return 1;
    } else if (a == 0) {
        return 0;
    }
    return -1;
}

int mod1(int x, int y)
{
    return (y + x % y) % y;
}

int max(int x, int y)
{
    if (x > y) {
        return x;
    }
    return y;
}

int min(int x, int y)
{
    if (x < y) {
        return x;
    }
    return y;
}

int is_in_ellips(long long i, long long j) #определение принадлежности точки к эллипсу
{
    i -= 20;
    if ((i * i) / 100.0 + (j * j) / 25.0 <= 1) {
        return 1;
    }
    return 0;
}

int main(void)
{
    int i, j, l, k, i1, j1, l1;
    scanf("%d%d%d", &i, &j, &l)
    for (k = 0; k < 50 && !is_in_ellips(i, j); k++) #основные функции перемещения в цикле
    {
        i1 = i * mod1((max(j, l)), 20) + j * mod1((min(i, l)), 30) + k;
        j1 = mod1((abs(i - j + l - k) * sign(k - 10)), 20);
        l1 = mod1((abs(i - j) * l - abs(j - l) * i + abs(i - l) * j), 20) - k;
        i = i1;
        j = j1;
        l = l1;
    }
    if (is_in_ellips(i, j)) {
        printf("Yes\n");
        printf("%d %d %d %d\n", i, j, l, k);
    } else {
        printf("No\n");
        printf("%d %d %d %d\n", i, j, l, k);
    }
    return 0;
}