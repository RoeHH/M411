#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double Quadrat = 81.0;
    //Das problem lag darin das man keinen double direkt einem Pointer zuweisen kann
    //Korrektur:
    double* pQuadrat = &Quadrat;
    //
    printf("Quadrat = %lf\n", *pQuadrat);
    printf("Zahl    = %lf\n", sqrt(*pQuadrat));
    system("pause");
    return 0;
}