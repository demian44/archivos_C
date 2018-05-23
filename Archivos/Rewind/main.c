#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* pArchivo;

    pArchivo = fopen("pepe.txt","r+");
    char valor[51];
    char key[51];

    if(pArchivo != NULL)
    {
        printf("Abrio correctamente...\nTecla para continuar:");
        getchar();

        while(!feof(pArchivo))
        {
            /// fscanf funciona igual que scanf pero lee elementos de un archivo.
            /// Retorna el número de datos de entrada asignados,
            /// que puede ser menor que el ofrecido, incluso cero, en el caso de un error de asignación.
            /// Si un error de entrada ocurre antes de cualquier conversión, la función fscanf retorna el valor de la macro EOF.


            int elementosLeidos = fscanf(pArchivo,"%[^,],%[^\n]",key,valor);
            printf("\nElementos leidos: %d\n", elementosLeidos);
            printf("%s: %s",key,valor);
            getchar();
        }

        system("cls");
        printf("Intentamos leerlo de nuevo...\nPresionar una tecla para ver:");
        getchar();
         system("cls");
        /// Voy a intentar seguir leyendo....
        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^\n]",key,valor);
            printf("%s: %s",key,valor);
        }
        printf("Intentamos leerlo luego de hacer un rewind...\n Presionar una tecla para ver:");
        getchar();
        system("cls");
        rewind(pArchivo);
        /// Voy a intentar seguir leyendo luego de un rewind....
        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^\n]",key,valor);
            printf("%s: %s",key,valor);
        }
    }

    return 0;
}
