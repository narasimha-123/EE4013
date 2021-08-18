#include <stdio.h>

struct OurNode
{
    char x, y, z;
};

int main()
{
    struct OurNode p = {'0', '1', 'a' + 2};
    struct OurNode *q = &p;
    printf("%c,%c \n", *((char *)q + 1), *((char *)q + 2));
}
