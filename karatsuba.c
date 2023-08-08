#include <stdio.h>
#include <stdlib.h>

long long int karatsuba(long long int x, long long int y) {
    long long int n = 0;
    long long int a, b, c, d;
    long long int ac, bd, ad_bc;

    if (x < 10 && y < 10) {
        return x * y;
    }

    n = (long long int) (log10(x) + 1);
    a = x / (long long int)pow(10, n/2);
    b = x % (long long int)pow(10, n/2);
    c = y / (long long int)pow(10, n/2);
    d = y % (long long int)pow(10, n/2);

    ac = karatsuba(a, c);
    bd = karatsuba(b, d);
    ad_bc = karatsuba(a+b, c+d) - ac - bd;

    return (long long int)(ac * pow(10, n) + ad_bc * pow(10, n/2) + bd);
}

int main() {
    long long int x, y;
    printf("Enter two integers to multiply: ");
    scanf("%lld %lld", &x, &y);
    printf("Product of %lld and %lld using Karatsuba algorithm: %lld\n", x, y, karatsuba(x, y));
    return 0;
}
