#include <stdio.h>
int main()
{
int x = 5;
int y = 10;
int* z = &x;
printf("x: %i y: %i z: %p\n", x, y, z);
printf("&x: %p &y: %p &z: %p\n", &x, &y, &z);
return 0;
}