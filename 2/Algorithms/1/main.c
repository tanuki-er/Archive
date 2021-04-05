#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input, *output;
    long long int a, b, c;

    input = fopen("aplusbb.in", "r");
    output = fopen("aplusbb.out", "w");

    fscanf(input, "%lld %lld", &a, &b);

    c = a + b * b;

    fprintf(output, "%lld", c);

    fclose(input);
    fclose(output);

    return 0;
}
