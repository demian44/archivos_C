#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    FILE*  pArchivo; /// 1 Se declara un puntero a la estructura FILE
    char texto[50];

    pArchivo = fopen("./pepe.txt","w"); ///Intentar abrir el archivo

    if(pArchivo != NULL) /// Verificar que no sa null
    {
        printf("Se abrio el archivo correctamente");
        getchar();
        strcpy(texto, "Texto escrito exitosamente con fwrite"); /// Cargo la variable


        int cLeidos = fwrite(texto,sizeof(char),strlen(texto),pArchivo);

        if(strlen(texto) == cLeidos) /// SI la cantiad de caracteres escritos es la correcta
        {
            printf("Texto escrito exitosamente con fwrite");
        }
        else
        {
            printf("\n\nNo se pudo guardar todo el texto");
        }

        if(!fclose(pArchivo))
            printf("\n\nArchivo cerrado");
        else
            printf("Archivo no pudo cerrarse correctamente");


    }
    else
    {
        printf("No se pudo abrir el archivo");
    }
    getchar();
    /// /// ///

    pArchivo = fopen("./pepe.txt","a");
    if(pArchivo != NULL)
    {
        printf("Se abrio el archivo correctamente");
        getchar();

        /// Escribo los datos con fprintf
        int cLeidos = fprintf(pArchivo,"\n%s %.1f","flotante:",45.5);

        sprintf(texto,"\n%s %.1f","flotante:",45.5);

        if(cLeidos == strlen(texto))
        {
            printf("\n\nSe escribio todo el texto con fprintf");
        }
        else
        {
            printf("\n\nNo se pudo guardar todo el texto");
        }

        if(!fclose(pArchivo))
            printf("\n\nArchivo cerrado");
        else
            printf("Archivo no pudo cerrarse correctamente");
    }
    else
    {
        printf("No se pudo abrir el archivo");
    }

    getchar();
    //system("cls");

    char buffer[1024];
    pArchivo = fopen("pepe.txt","r");
    //
    if(pArchivo != NULL)
    {
        printf("Se abrio para leer");
       /* printf("\n");
        int datosLeidos = fread(buffer,sizeof(char),10,pArchivo);
        if(datosLeidos == 10)
        {
            printf("\nTramo leido: %s\n",buffer);
        }
        else
        {
            printf("No se pudo leer el archivo.");
        }
        getchar();

        printf("\n");*/

        while(!feof(pArchivo))
        {
            ///fgets lee hasta encontrar un salto linea o el final del archivo
            fgets(buffer,1023,pArchivo);
            printf("\nTramo leido: %s\n",buffer);

            getchar();
        }

        fclose(pArchivo);

    }


    return 0;
}
