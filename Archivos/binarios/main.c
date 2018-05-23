#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int edad;
    char nombre[50];
} Persona;
int main()
{
    /// /// BINARIO /// ///
    FILE* punteroArchivo;
    Persona* miPersona  = malloc(sizeof(Persona)*2);

    if(miPersona != NULL)
    {
        miPersona->edad =  32;
        strcpy(miPersona->nombre,"Persona2");

        (miPersona+1)->edad = 41;
        strcpy((miPersona+1)->nombre,"persona3");

        // printf("%s %d", miPersona->nombre,miPersona->edad);

        punteroArchivo = fopen("pepe.txt","ab");
        if(punteroArchivo != NULL)
        {
            printf("\nSe pudo abrir el archivo binario.");
            getchar();
            system("cls");
            if(fwrite(miPersona,sizeof(Persona),2,punteroArchivo) == 2)
            {
                printf("\nSe pudo escribir el archivo binario.");
            }
            else
                printf("\nNo se pudo escribir el archivo.");

            if(!fclose(punteroArchivo))
                    printf("\n\nArchivo cerrado...\n\n");
                else
                     printf("\n\nNo se cerro el archivo...\n\n");
        }
        else
            printf("\nNo se pudo obtener memoria para la miPersona");
    }

    getchar();

    /// /// ///  Leer Binario /// /// ///

    punteroArchivo =  fopen("pepe.txt","rb");
    Persona* miOtraPersona = malloc(sizeof(Persona)*2);
    if(punteroArchivo != NULL)
    {
        while(!feof(punteroArchivo))
        {
            if(fread(miOtraPersona,sizeof(Persona),2,punteroArchivo)==2)
            {
                printf("\n\nPersona leida: %s, %d",
                            miOtraPersona->nombre,miOtraPersona->edad );
                printf("\n - Persona leida: %s, %d",
                            (miOtraPersona+1)->nombre,(miOtraPersona+1)->edad );
            }

        }
        fclose(punteroArchivo);
    }
    return 0;
}
