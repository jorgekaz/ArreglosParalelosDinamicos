# TP-ARREGLOS-PARALELOS-DINAMICOS
Sean los arreglos paralelos, que simbolizan la entidad de software “alumno”:

int legajos[20];
char nombres[20][30];
int anios[20];

1.	Crear una función que los cargue, hasta que el usuario lo decida. 
2.	Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor. 
3.	Hacer una función que reciba como parámetro todos los arreglos y encuentre el nombre correspondiente a un determinado legajo y lo imprima por pantalla. Se debe invocar la función 2.
4.	Hacer una función que reciba como parámetro todos los arreglos y los ordene por nombre. (por el método de selección o inserción).
5.	Mostrar por pantalla los 3 arreglos pero de a un “registro” o alumno por vez (es decir: muestra el legajo, nombre y años del 1er alumno, luego el legajo, nombre y años del 2do alumno, y así sucesivamente).. 

Arreglos dinámicos:
6.	Se cuenta con un arreglo de números enteros que ya fue cargado, se pide hacer una función que copie los datos de todos los valores del arreglo anterior que sean pares en otro arreglo del tamaño justo. Usar malloc dentro de la función y retornar el arreglo o usar dos parámetros de tipo arreglo y crear el arreglo dinámico antes de la invocación. Desarrolle las funciones que considere necesarias, por ejemplo, una función que cuente la cantidad de elementos pares y otra para el traspaso de los elementos.

7.	Hacer una función que reciba un arreglo dinámico por parámetro, la cantidad de elementos válidos del mismo, y un valor que indique el nuevo tamaño que se le quiere dar a dicho arreglo. La función debe redimensionar el arreglo (usar la función realloc) y retornar el puntero a dicho espacio de memoria. Investigar el uso de la función realloc.
