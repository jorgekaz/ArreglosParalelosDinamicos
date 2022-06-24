#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#define cantidad 20

int cargarPersonas(int legajosCarga[], char nombresCarga[][30], int aniosCarga[]); //1
int buscarLegajo(int legajosCarga[], int val);//2
void buscarNombreLegajo(int legajosCarga[],char nombresCarga[][30], int aniosCarga[], int val);//3
void ordenarSeleccion(int legajosCarga[],char nombresCarga[][30],int aniosCarga[],int val); //4
void mostrarPersonas(int legajosCarga[],char nombresCarga[][30], int aniosCarga[], int val); //5
void mostrarArreglo(int arreglo[],int validos);
int totalPares(int arreglo[],int validos);
void crearArregloPar(int arregloPares[],int arreglo[], int validos);
int* redimensionar(int* dinamico,int* dim);
void cargarDinamico(int* dinamico,int dim);
void mostrarDinamico(int* dinamico, int dim);
int menu();
void funcionMenu();


int main(){
    funcionMenu();
}

/// 1
int cargarPersonas(int legajosCarga[], char nombresCarga[][30], int aniosCarga[]){
    int i=0;
    char option;
    do{
        printf(" CARGAR LEGAJO: ");
        fflush(stdin);
        scanf ("%d", &legajosCarga[i]);
        printf(" CARGAR NOMBRE: ");
        fflush(stdin);
        scanf ("%s", &nombresCarga[i]);
        printf(" CARGAR AÑOS: ");
        fflush(stdin);
        scanf ("%d", &aniosCarga[i]);
        i++;

        printf("\n DESEA CARGAR UN NUEVO ELEMENTO Y/N: ");
        fflush(stdin);
        scanf("%c", &option);
    }
    while(option=='Y'||option=='y' && i<cantidad);
    return i;
}

/// 2
int buscarLegajo(int legajosCarga[], int val){
    int i;
    int legajoBuscado=0;
    int pos=0;
    int flag=0;
    printf(" BUSCAR LEGAJO: ");
    fflush(stdin);
    scanf("%d", &legajoBuscado);
    for(int i=0; i<val&&flag==0; i++){
        if(legajosCarga[i]==legajoBuscado){
            pos=i;
            flag=1;
            printf("\n EL LEGAJO PERTENECE A LA POSICION %i \n",i);
        }
    }
    if(flag==0){
        printf("\n EL LEGAJO BUSCADO NO EXISTE\n");
        pos=-1;
    }
    return pos;
}

///3
void buscarNombreLegajo(int legajosCarga[],char nombresCarga[][30], int aniosCarga[], int val){
    int posicion=-1;
    posicion=buscarLegajo(legajosCarga,val);
    if(posicion!=-1){
        printf("\n LA PERSONA DEL LEGAJO %i ES: %s\n",legajosCarga[posicion],nombresCarga[posicion]);
    }
}

///4
int buscarMenor(char nombresCarga[][30], int val, int pos){
    int posMenor=pos;
    char menor[30];
    strcpy(menor,nombresCarga[pos]);
    for(int i=pos+1; i<val;i++){
        if(strcmpi(nombresCarga[i],menor)<0){
            posMenor=i;
            strcpy(menor,nombresCarga[i]);
        }
    }
    return posMenor;
}

void ordenarSeleccion(int legajosCarga[],char nombresCarga[][30],int aniosCarga[],int val){
    int i=0;
    int legajoAux;
    char nombreAux[30];
    int aniosAux;
    int posMenor;
    while(i<val-1){
        posMenor=buscarMenor(nombresCarga,val,i);
        strcpy(nombreAux,nombresCarga[posMenor]);
        strcpy(nombresCarga[posMenor],nombresCarga[i]);
        strcpy(nombresCarga[i],nombreAux);

        legajoAux=legajosCarga[posMenor];
        legajosCarga[posMenor]=legajosCarga[i];
        legajosCarga[i]=legajoAux;

        aniosAux=aniosCarga[posMenor];
        aniosCarga[posMenor]=aniosCarga[i];
        aniosCarga[i]=aniosAux;

        i++;
    }
}

///5
void mostrarPersonas(int legajosCarga[],char nombresCarga[][30], int aniosCarga[], int val){
    printf("\n PERSONAS\n");
    printf(" --------------\n");
    for(int i=0; i<val; i++){
        printf(" LEGAJO: %i\n", legajosCarga[i]);
        printf(" NOMBRE: %s\n", strupr(nombresCarga[i]));
        printf(" AÑOS: %i\n", aniosCarga[i]);
        printf(" --------------\n");
    }
}

///6
void mostrarArreglo(int arreglo[],int validos){
    for(int i=0;i<validos;i++)
    {
        printf(" | %d |", arreglo[i]);
    }
    printf("\n\n");
}

int totalPares(int arreglo[],int validos){
    int cantidadPares=0;
    for(int i=0;i<validos;i++)
    {
        if(arreglo[i]%2==0)
        {
            cantidadPares++;
        }
    }
    return cantidadPares;
}

void crearArregloPar(int arregloPares[],int arreglo[], int validos){
    int j=0;
    for(int i=0;i<validos;i++)
    {
        if(arreglo[i]%2==0)
        {
            arregloPares[j]=arreglo[i];
            j++;
        }
    }
}

///7
int* redimensionar(int dinamico[],int* dim){
    printf("\n INGRESE LA NUEVA DIMENSION DEL ARREGLO: ");
    scanf("%d", dim);
    dinamico=(int*)realloc(dinamico,*dim);
    return dinamico;
}

void cargarDinamico(int dinamico[],int dim){
    for(int i=0; i<dim; i++)
    {
        printf("\n CARGAR ELEMENTO: ");
        scanf("%d", &dinamico[i]);
    }
}

void mostrarDinamico(int dinamico[], int dim){
    for(int i=0;i<dim;i++)
    {
        printf(" | %d |", dinamico[i]);
    }
    printf("\n");
}

/// Menu
int menu(){
    int option;
        printf("===========================================\n");
        printf(" TRABAJO PRACTICO N° 5: ARREGLOS PARALELOS\n");
        printf("===========================================\n");
        printf(" 1.CREAR UNA FUNCIÓN QUE LOS CARGUE, HASTA QUE EL USUARIO LO DECIDA.\n\n");
        printf(" 2.CREAR UNA FUNCIÓN QUE BUSQUE DENTRO DEL ARREGLO DE LEGAJOS Y RETORNE LA POSICIÓN DE UN DETERMINADO VALOR.\n\n");
        printf(" 3.HACER UNA FUNCIÓN QUE RECIBA COMO PARÁMETRO TODOS LOS ARREGLOS Y ENCUENTRE EL NOMBRE CORRESPONDIENTE A UN DETERMINADO LEGAJO Y LO IMPRIMA POR PANTALLA. SE DEBE INVOCAR LA FUNCIÓN 2.\n\n");
        printf(" 4.HACER UNA FUNCIÓN QUE RECIBA COMO PARÁMETRO TODOS LOS ARREGLOS Y LOS ORDENE POR NOMBRE. (POR EL MÉTODO DE SELECCIÓN O INSERCIÓN).\n\n");
        printf(" 5.MOSTRAR POR PANTALLA LOS 3 ARREGLOS PERO DE A UN “REGISTRO” O ALUMNO POR VEZ (ES DECIR: MUESTRA EL LEGAJO, NOMBRE Y AÑOS DEL 1ER ALUMNO, LUEGO EL LEGAJO, NOMBRE Y AÑOS DEL 2DO ALUMNO, Y ASÍ SUCESIVAMENTE)..\n\n");
        printf(" 6.SE CUENTA CON UN ARREGLO DE NÚMEROS ENTEROS QUE YA FUE CARGADO, SE PIDE HACER UNA FUNCIÓN QUE COPIE LOS DATOS DE TODOS LOS VALORES DEL ARREGLO ANTERIOR QUE SEAN PARES EN OTRO ARREGLO DEL TAMAÑO JUSTO. USAR MALLOC DENTRO DE LA FUNCIÓN Y RETORNAR EL ARREGLO O USAR DOS PARÁMETROS DE TIPO ARREGLO Y CREAR EL ARREGLO DINÁMICO ANTES DE LA INVOCACIÓN. DESARROLLE LAS FUNCIONES QUE CONSIDERE NECESARIAS, POR EJEMPLO, UNA FUNCIÓN QUE CUENTE LA CANTIDAD DE ELEMENTOS PARES Y OTRA PARA EL TRASPASO DE LOS ELEMENTOS.\n\n");
        printf(" 7.HACER UNA FUNCIÓN QUE RECIBA UN ARREGLO DINÁMICO POR PARÁMETRO, LA CANTIDAD DE ELEMENTOS VÁLIDOS DEL MISMO, Y UN VALOR QUE INDIQUE EL NUEVO TAMAÑO QUE SE LE QUIERE DAR A DICHO ARREGLO. LA FUNCIÓN DEBE REDIMENSIONAR EL ARREGLO (USAR LA FUNCIÓN REALLOC) Y RETORNAR EL PUNTERO A DICHO ESPACIO DE MEMORIA. INVESTIGAR EL USO DE LA FUNCIÓN REALLOC.\n\n");
        printf(" 8.SALIR\n\n");
        printf("\n ELIJA UNA OPCIÓN: ");
        fflush(stdin);
        scanf("%i", &option);
        return option;
}

void funcionMenu(){
    int legajos[cantidad];
    char nombres[cantidad][30];
    int anios[cantidad];
    int validos;
    int arregloCompleto[]={5,10,15,20,25,30};
    int validosD=6;
    int* arregloPar;
    int cantidadD = totalPares(arregloCompleto,validosD);
    setlocale(LC_ALL, "");
    int option=0;
    do{
        option=menu();
        system("cls");
        switch(option){
        case 1:{
            printf(" 1.CREAR UNA FUNCIÓN QUE LOS CARGUE, HASTA QUE EL USUARIO LO DECIDA.\n\n");
            validos=cargarPersonas(legajos,nombres,anios);
            system("pause");
            system("cls");
        }
        break;
        case 2:{
            printf(" 2.CREAR UNA FUNCIÓN QUE BUSQUE DENTRO DEL ARREGLO DE LEGAJOS Y RETORNE LA POSICIÓN DE UN DETERMINADO VALOR.\n\n");
            mostrarPersonas(legajos,nombres,anios,validos);
            system("pause");
            system("cls");
        }
        break;
        case 3:{
            printf(" 3.HACER UNA FUNCIÓN QUE RECIBA COMO PARÁMETRO TODOS LOS ARREGLOS Y ENCUENTRE EL NOMBRE CORRESPONDIENTE A UN DETERMINADO LEGAJO Y LO IMPRIMA POR PANTALLA. SE DEBE INVOCAR LA FUNCIÓN 2.\n\n");
            buscarNombreLegajo(legajos,nombres,anios,validos);
            system("pause");
            system("cls");
        }
        break;
        case 4:{
            printf(" 4.HACER UNA FUNCIÓN QUE RECIBA COMO PARÁMETRO TODOS LOS ARREGLOS Y LOS ORDENE POR NOMBRE. (POR EL MÉTODO DE SELECCIÓN O INSERCIÓN).\n\n");
            ordenarSeleccion(legajos,nombres,anios,validos);
            mostrarPersonas(legajos,nombres,anios,validos);
            system("pause");
            system("cls");
        }
        break;
        system("cls");
        case 5:{
            printf(" 5.MOSTRAR POR PANTALLA LOS 3 ARREGLOS PERO DE A UN “REGISTRO” O ALUMNO POR VEZ (ES DECIR: MUESTRA EL LEGAJO, NOMBRE Y AÑOS DEL 1ER ALUMNO, LUEGO EL LEGAJO, NOMBRE Y AÑOS DEL 2DO ALUMNO, Y ASÍ SUCESIVAMENTE)..\n\n");
            mostrarPersonas(legajos,nombres,anios,validos);
            system("pause");
        }
        break;
        system("cls");
        case 6:{
            printf(" 6.SE CUENTA CON UN ARREGLO DE NÚMEROS ENTEROS QUE YA FUE CARGADO, SE PIDE HACER UNA FUNCIÓN QUE COPIE LOS DATOS DE TODOS LOS VALORES DEL ARREGLO ANTERIOR QUE SEAN PARES EN OTRO ARREGLO DEL TAMAÑO JUSTO. USAR MALLOC DENTRO DE LA FUNCIÓN Y RETORNAR EL ARREGLO O USAR DOS PARÁMETROS DE TIPO ARREGLO Y CREAR EL ARREGLO DINÁMICO ANTES DE LA INVOCACIÓN. DESARROLLE LAS FUNCIONES QUE CONSIDERE NECESARIAS, POR EJEMPLO, UNA FUNCIÓN QUE CUENTE LA CANTIDAD DE ELEMENTOS PARES Y OTRA PARA EL TRASPASO DE LOS ELEMENTOS.\n\n");
            printf(" ARREGLO COMPLETO\n\n");
            mostrarArreglo(arregloCompleto,validosD);
            printf(" ARREGLO PAR\n\n");
            arregloPar = (int*)malloc(cantidadD*sizeof(int));
            crearArregloPar(arregloPar,arregloCompleto,validosD);
            mostrarArreglo(arregloPar,cantidadD);
            system("pause");
        }
        break;
        system("cls");
        case 7:{
            printf(" 7.HACER UNA FUNCIÓN QUE RECIBA UN ARREGLO DINÁMICO POR PARÁMETRO, LA CANTIDAD DE ELEMENTOS VÁLIDOS DEL MISMO, Y UN VALOR QUE INDIQUE EL NUEVO TAMAÑO QUE SE LE QUIERE DAR A DICHO ARREGLO. LA FUNCIÓN DEBE REDIMENSIONAR EL ARREGLO (USAR LA FUNCIÓN REALLOC) Y RETORNAR EL PUNTERO A DICHO ESPACIO DE MEMORIA. INVESTIGAR EL USO DE LA FUNCIÓN REALLOC.\n\n");
            int* arregloDinamico;
            int dimension=0;
            printf(" INGRESE LA DIMENSION DEL ARREGLO: ");
            scanf("%d", &dimension);
            arregloDinamico=(int*)calloc(dimension,sizeof(int));
            cargarDinamico(arregloDinamico,dimension);
            printf("\n ARREGLO BASE\n");
            mostrarDinamico(arregloDinamico,dimension);
            redimensionar(arregloDinamico,&dimension);
            cargarDinamico(arregloDinamico,dimension);
            printf("\n ARREGLO DINAMICO\n");
            mostrarDinamico(arregloDinamico,dimension);
            system("pause");
        }
        break;
        system("cls");
        case 8:{
            printf("  8.SALIR\n");
            system("pause");
            system("cls");
        }
        break;
        default:
            printf("\n OPCION INCORRECTA\n\n");
            system("pause");
            system("cls");
        break;
        }
    }while(option!=8);
    printf("\n FIN DEL PROGRAMA\n\n");
    system("pause");
}

