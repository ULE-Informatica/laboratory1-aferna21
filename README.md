# dps-lab-1
Laboratory 1, Adrián Fernández Álvarez.


Primero compilo con gcc -Wall. Los warnings son los siguientes: 

************************************************************************************
exampleStrings.c: In function ‘gets_example_func’:
exampleStrings.c:32:16: warning: ‘return’ with a value, in function returning void
         return 1;
                ^
exampleStrings.c:28:6: note: declared here
 void gets_example_func(void) {
      ^~~~~~~~~~~~~~~~~
exampleStrings.c: In function ‘get_y_or_n’:
exampleStrings.c:51:2: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
  gets(response);
  ^~~~
  fgets
exampleStrings.c: In function ‘main’:
exampleStrings.c:73:10: warning: unused variable ‘analitic3’ [-Wunused-variable]
     char analitic3[100]="аналитик";
          ^~~~~~~~~
exampleStrings.c:69:9: warning: unused variable ‘size_array2’ [-Wunused-variable]
     int size_array2 = 100;
         ^~~~~~~~~~~
exampleStrings.c:68:9: warning: unused variable ‘size_array1’ [-Wunused-variable]
     int size_array1 = strlen("аналитик");
         ^~~~~~~~~~~
/tmp/ccO4HnZZ.o: En la función `get_y_or_n':
exampleStrings.c:(.text+0xd8): aviso: the `gets' function is dangerous and should not be used.
*************************************************************************************

Se han corregido los warnings de compilación de la siguiente manera: 

-Para el primero, se ha impreso en un fichero el error y se ha salido del método con
la función exit(-1). La escritura del caracter '\0' en el buffer se ejecutará si no ha saltado el error. 

-Para el segundo se ha sustituido la función gets, la cual recomienda el parámetro de compilación
-Wall no utilizar, por un scanf de un único caracter, no reservando más memoria de la necesaria.
Posteriormente, se trabajará con él. Además, la variable response era un array de tamaño 8, cuando solamente se requería
una variable para almacenar una letra.

-Las variables que no son utilizadas han sido comentadas.



Otros cambios en el código en cuanto a malas prácticas o errores:

-Se ha cambiado el tipo int que guardan tamaños de cadenas por el size_t

-Se comprueba que se introducen los argumentos necesarios para la ejecución del programa y su tamaño.

-Los strings que se pasan como argumento serán truncados en el caso de sobrepasar la memoria reservada en el array para ellos. 

-Si no se asigna memoria para el puntero "ptr_char" salta violación de core. Posteriormente la memoria ha de ser liberada. 

-Se ha cambiado la función fgets del main por un scanf debido a que si se sobrepasaba la longitud de la variable response, en la cual
escribe la función, los caracteres que sobran se guardan en stdin igualmente y la siguiente función que requiere entrada coge lo que ha sobrado de esa llamada.
Para garantizar que no se sobrepasa el tamaño del string, se trunca con el caracter '\0' en su última posición.

-Las dos últimas funciones strncpy del main están mal en cuanto al argumento del tamaño de la copia. En el primer caso, dicho valor es 16, siendo array3[15] la
última posición posible a rellenar. Por lo tanto, se soluciona restándole 1 al valor sizeof(array3). La siguiente llamada a la función tiene como error que se toma
de argumento para el tamaño el sizeof del array fuente y no del array destino, mala práctica de programación. La solución es igual que en el caso anterior.

-Ha sido modificado el comportamiento con el que se trata el puntero ptr_char. Primero, se crea para que apunte a un segmento de memoria liberada de char 24 con la función malloc. Después,
se copia a esa memoria liberada con la función strcpy (si se hace ptr_char = "lo que sea", pierde la referencia a la memoria liberada y el free dará error). Una vez realizados esos cambios
acceder a una posición de ese puntero y modificar el char que contiene funciona sin problema. Al final, será liberada la memoria. 



Una vez arreglados los errores de compilación y fallos de programación, se prueba a compilar con otros estándares: 

<pre><font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ gcc exampleStrings.c 
<font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ 
</pre>
