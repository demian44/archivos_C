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

    punteroArchivo =  fopen("pepe.txt","rb");
    Persona* miPersona = malloc(sizeof(Persona));
    printf("Imprimimos todas las personas:");
      getchar();
    if(punteroArchivo != NULL)
    {
        while(!feof(punteroArchivo))
        {
            if(fread(miPersona,sizeof(Persona),1,punteroArchivo)==1)
            {
                printf("\n\nPersona leida: %s, Edad: %d",
                       miPersona->nombre,miPersona->edad );
            }
            getchar();

        }
        getchar();
        system("cls");
        printf("Utilizando fseek vamos al comienzo y nos desplazamos dos espacios hacia delante");

         getchar();
        system("cls");
        fseek(punteroArchivo,sizeof(Persona)*2,SEEK_SET);
        printf(" fseek(punteroArchivo,sizeof(Persona)*2,SEEK_SET); \n\n");
        printf("  Persona0 Persona1  Persona2 Persona3|>     (Punto de partida)\n");
        printf("|>Persona0 Persona1  Persona2 Persona3     (Cursor al inicio del archivo)\n");
        printf("  Persona0 Persona1|>Persona2 Persona3   (Avanza 2 lugares)\n\n");


        if(fread(miPersona,sizeof(Persona),1,punteroArchivo)==1)
        {
             printf("fread(miPersona,sizeof(Persona),1,punteroArchivo)\n\n");
            printf("Persona leida: %s , Edad: %d\n\n",
                   miPersona->nombre,miPersona->edad );
        }


        getchar();
        system("cls");
        printf("Utilizando fseek vamos 1 posicion hacia atras");

        getchar();
        system("cls");
        fseek(punteroArchivo,-1 * sizeof(Persona),SEEK_CUR);
        printf(" fseek(punteroArchivo,-1 * sizeof(Persona),SEEK_CUR); \n\n");
        printf(" Persona0 Persona1 Persona2|>Persona3   (Partimos donde quedo el cursor)\n");
        printf(" Persona0 Persona1|>Persona2 Persona3    (Retrocedemos un espacio)\n\n");


        if(fread(miPersona,sizeof(Persona),1,punteroArchivo)==1)
        {
            printf("fread(miPersona,sizeof(Persona),1,punteroArchivo)\n\n");
            printf("Persona leida: %s , Edad: %d\n\n",
                   miPersona->nombre,miPersona->edad );
        }


        getchar();
        system("cls");
        printf("Utilizando fseek nos posicionamos al final del archivo y retrocedemos 3 espacios");

        getchar();
        system("cls");
        fseek(punteroArchivo,-3 * sizeof(Persona),SEEK_END);
        printf(" fseek(punteroArchivo,-3 * sizeof(Persona),SEEK_END); \n\n");
        printf(" Persona0  Persona1 Persona2|>Persona3      (Cursor al final del archivo)\n");
        printf(" Persona0  Persona1 Persona2  Persona3|>     (Cursor al final del archivo)\n");
        printf(" Persona0|>Persona1 Persona2 Persona3       (Retrocede 3 espacios)\n\n");


        if(fread(miPersona,sizeof(Persona),1,punteroArchivo)==1)
        {
            printf("fread(miPersona,sizeof(Persona),1,punteroArchivo)\n\n");
            printf("Persona leida: %s , Edad: %d\n\n",
                   miPersona->nombre,miPersona->edad );
        }


        fclose(punteroArchivo);

    }
    return 0;
}
