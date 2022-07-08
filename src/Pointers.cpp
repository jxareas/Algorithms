#include <cstdio>
#include <cstdlib>

int main()
{
    int u = 3;
    int v;
    int *pu;
    int *pv;

    pu = &u;
    v = *pu;
    pv = &v;

    printf("\n u = %d, &u = %X, pu = %X, *pu = %d", u, &u, pu, *pu);
    printf("\n\n v = %d, &v = %X, pv = %X, *pv = %d", v, &v, pv, *pv);

    printf("\n\n\n\n");
    system("PAUSE");
    return 0;
}
