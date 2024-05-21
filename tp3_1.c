#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define C 12
#define F 5

void cargarValores(int matriz[F][C]);
void promedioGanancias(int matriz[F][C]);
void informe(int matriz[F][C]);


int main()
{
    srand(time(NULL));

    int matriz[F][C];
    cargarValores(matriz);
    promedioGanancias(matriz);
    informe(matriz);
    
    return 0;
}

void cargarValores(int matriz[F][C])
{
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            matriz[i][j] = rand() % (50000 - 10000 + 1) + 10000; 
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
}

void promedioGanancias (int matriz[F][C])
{
    int gananciasT = 0;
    int promedioG;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < 1; j++)
        {
             gananciasT = gananciasT + matriz[i][j];
        }
    }
    promedioG = gananciasT/5;
    
    printf("La cantidad de ganancias por año es: %d", gananciasT);
    printf("\nLa cantidad de ganancia promedio por año es: %d", promedioG);
}

void informe(int matriz[F][C])
{
    int mayor = 0;
    int menor = 0;
    int anio, mes, anio2, mes2;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matriz[i][j] > mayor)
            {
                mayor = matriz[i][j];
                anio = i;
                mes = j;
            }
            if (menor == 0 || matriz[i][j] < menor)
            {
                menor = matriz[i][j];
                anio2 = i;
                mes2 =j;
            }
            
            
        }
    }
    
    printf("\nEl mayor valor es %d en el anio %d del mes %d", mayor, anio, mes);
    printf("\nEl menor valor es %d en el anio %d del mes %d", menor, anio2, mes2);
    
}
