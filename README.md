# dps-lab-1
Laboratory 1, Adrián Fernández Álvarez.

Para la realización de esta práctica voy a realizar los siguientes pasos:
1) Compilar el código con gcc -Wall y arreglar los warnings generados.
2) Ejecutar el código y arreglar los errores de programación. 
3) Enumerar las reglas y recomendaciones que no se cumplen
4) Compilar el código arreglado con diferentes herramientas.
5) Conclusiones de la práctica.

<h1>Primera compilación</h1> 
La primera compilación ha sido realizada a través del comando <b>gcc -Wall exampleStrings.c<\b>
<pre><font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ gcc -Wall exampleStrings.c 
<b>exampleStrings.c:</b> In function ‘<b>gets_example_func</b>’:
<b>exampleStrings.c:32:16:</b> <font color="#CD00CD"><b>warning: </b></font>‘<b>return</b>’ with a value, in function returning void
         return <font color="#CD00CD"><b>1</b></font>;
                <font color="#CD00CD"><b>^</b></font>
<b>exampleStrings.c:28:6:</b> <font color="#00CDCD"><b>note: </b></font>declared here
 void <font color="#00CDCD"><b>gets_example_func</b></font>(void) {
      <font color="#00CDCD"><b>^~~~~~~~~~~~~~~~~</b></font>
<b>exampleStrings.c:</b> In function ‘<b>get_y_or_n</b>’:
<b>exampleStrings.c:51:3:</b> <font color="#CD00CD"><b>warning: </b></font>implicit declaration of function ‘<b>gets</b>’; did you mean ‘<b>fgets</b>’? [<font color="#CD00CD"><b>-Wimplicit-function-declaration</b></font>]
   <font color="#CD00CD"><b>gets</b></font>(response);
   <font color="#CD00CD"><b>^~~~</b></font>
   <font color="#00CD00">fgets</font>
<b>exampleStrings.c:</b> In function ‘<b>main</b>’:
<b>exampleStrings.c:73:10:</b> <font color="#CD00CD"><b>warning: </b></font>unused variable ‘<b>analitic3</b>’ [<font color="#CD00CD"><b>-Wunused-variable</b></font>]
     char <font color="#CD00CD"><b>analitic3</b></font>[100]=&quot;аналитик&quot;;
          <font color="#CD00CD"><b>^~~~~~~~~</b></font>
<b>exampleStrings.c:69:9:</b> <font color="#CD00CD"><b>warning: </b></font>unused variable ‘<b>size_array2</b>’ [<font color="#CD00CD"><b>-Wunused-variable</b></font>]
     int <font color="#CD00CD"><b>size_array2</b></font> = 100;
         <font color="#CD00CD"><b>^~~~~~~~~~~</b></font>
<b>exampleStrings.c:68:9:</b> <font color="#CD00CD"><b>warning: </b></font>unused variable ‘<b>size_array1</b>’ [<font color="#CD00CD"><b>-Wunused-variable</b></font>]
     int <font color="#CD00CD"><b>size_array1</b></font> = strlen(&quot;аналитик&quot;);
         <font color="#CD00CD"><b>^~~~~~~~~~~</b></font>
/tmp/cchNqrCC.o: En la función `get_y_or_n&apos;:
exampleStrings.c:(.text+0xd8): aviso: the `gets&apos; function is dangerous and should not be used.
</pre>

<b>Se han corregido los warnings de compilación de la siguiente manera</b>: 

<p>-Para el primero, se ha impreso en un fichero el error y se ha salido del método con
la función exit(-1). La escritura del caracter '\0' en el buffer se ejecutará si no ha saltado el error. 

-Para el segundo se ha sustituido la función gets, la cual recomienda el parámetro de compilación
-Wall no utilizar, por un scanf de un único caracter, no reservando más memoria de la necesaria.
Posteriormente, se trabajará con él. Además, la variable response era un array de tamaño 8, cuando solamente se requería
una variable para almacenar una letra.

-Las variables que no son utilizadas han sido comentadas.</p>



<h1>Errores de programación corregidos</h1>

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

<h1>Reglas y recomendaciones


<h1>Compilación con otros estándares</h1>

Una vez arreglados los errores de compilación y fallos de programación, se prueba a compilar con otros estándares: 


<b>gcc exampleStrings.c</b>
<pre><font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ gcc exampleStrings.c 
<font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ 
</pre>

<b>g++ exampleStrings.c</b>
<pre><font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ g++ exampleStrings.c 
<b>exampleStrings.c:</b> In function ‘<b>const char* get_dirname(const char*)</b>’:
<b>exampleStrings.c:44:18:</b> <font color="#D41C1C"><b>error: </b></font>invalid conversion from ‘<b>const char*</b>’ to ‘<b>char*</b>’ [<font color="#D41C1C"><b>-fpermissive</b></font>]
   slash = <font color="#D41C1C"><b>strrchr(pathname, &apos;/&apos;)</b></font>;
           <font color="#D41C1C"><b>~~~~~~~^~~~~~~~~~~~~~~</b></font>
<b>exampleStrings.c:</b> In function ‘<b>int main(int, char**)</b>’:
<b>exampleStrings.c:81:28:</b> <font color="#D41C1C"><b>error: </b></font>invalid conversion from ‘<b>void*</b>’ to ‘<b>char*</b>’ [<font color="#D41C1C"><b>-fpermissive</b></font>]
     char *ptr_char = <font color="#D41C1C"><b>malloc(sizeof(char) * 24)</b></font>;
                      <font color="#D41C1C"><b>~~~~~~^~~~~~~~~~~~~~~~~~~</b></font>
<font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ 
</pre>

<b>g++ -Wall exampleStrings.c</b>
<pre><font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ g++ -Wall exampleStrings.c 
<b>exampleStrings.c:</b> In function ‘<b>const char* get_dirname(const char*)</b>’:
<b>exampleStrings.c:44:18:</b> <font color="#D41C1C"><b>error: </b></font>invalid conversion from ‘<b>const char*</b>’ to ‘<b>char*</b>’ [<font color="#D41C1C"><b>-fpermissive</b></font>]
   slash = <font color="#D41C1C"><b>strrchr(pathname, &apos;/&apos;)</b></font>;
           <font color="#D41C1C"><b>~~~~~~~^~~~~~~~~~~~~~~</b></font>
<b>exampleStrings.c:</b> In function ‘<b>int main(int, char**)</b>’:
<b>exampleStrings.c:81:28:</b> <font color="#D41C1C"><b>error: </b></font>invalid conversion from ‘<b>void*</b>’ to ‘<b>char*</b>’ [<font color="#D41C1C"><b>-fpermissive</b></font>]
     char *ptr_char = <font color="#D41C1C"><b>malloc(sizeof(char) * 24)</b></font>;
</pre>

<b>gcc -Wall -std=c11 exampleStrings.c</b>
<pre><font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ gcc -Wall -std=c11 exampleStrings.c 
<b>exampleStrings.c:22:19:</b> <font color="#CD00CD"><b>warning: </b></font>missing terminating &quot; character
 const char* s1 = R<font color="#CD00CD"><b>&quot;</b></font>foo(
                   <font color="#CD00CD"><b>^</b></font>
<b>exampleStrings.c:22:19:</b> <font color="#D41C1C"><b>error: </b></font>missing terminating &quot; character
 const char* s1 = R<font color="#D41C1C"><b>&quot;foo(</b></font>
                   <font color="#D41C1C"><b>^~~~~</b></font>
<b>exampleStrings.c:22:18:</b> <font color="#D41C1C"><b>error: </b></font>‘<b>R</b>’ undeclared here (not in a function)
 const char* s1 = <font color="#D41C1C"><b>R</b></font>&quot;foo(
                  <font color="#D41C1C"><b>^</b></font>
<b>exampleStrings.c:23:1:</b> <font color="#D41C1C"><b>error: </b></font>expected ‘<b>,</b>’ or ‘<b>;</b>’ before ‘<b>Hello</b>’
 <font color="#D41C1C"><b>Hello</b></font>
 <font color="#D41C1C"><b>^~~~~</b></font>
<b>exampleStrings.c:25:5:</b> <font color="#CD00CD"><b>warning: </b></font>missing terminating &quot; character
 )foo<font color="#CD00CD"><b>&quot;</b></font>;
     <font color="#CD00CD"><b>^</b></font>
<b>exampleStrings.c:25:5:</b> <font color="#D41C1C"><b>error: </b></font>missing terminating &quot; character
 )foo<font color="#D41C1C"><b>&quot;;</b></font>
     <font color="#D41C1C"><b>^~</b></font>
<b>exampleStrings.c:</b> In function ‘<b>main</b>’:
<b>exampleStrings.c:118:11:</b> <font color="#D41C1C"><b>error: </b></font>‘<b>s2</b>’ undeclared (first use in this function); did you mean ‘<b>s1</b>’?
     puts (<font color="#D41C1C"><b>s2</b></font>);
           <font color="#D41C1C"><b>^~</b></font>
           <font color="#00CD00">s1</font>
<b>exampleStrings.c:118:11:</b> <font color="#00CDCD"><b>note: </b></font>each undeclared identifier is reported only once for each function it appears in
</pre>



<b>gcc -Wall -std=c99 exampleStrings.c</b>
<pre><b>exampleStrings.c:22:19:</b> <font color="#CD00CD"><b>warning: </b></font>missing terminating &quot; character
 const char* s1 = R<font color="#CD00CD"><b>&quot;</b></font>foo(
                   <font color="#CD00CD"><b>^</b></font>
<b>exampleStrings.c:22:19:</b> <font color="#D41C1C"><b>error: </b></font>missing terminating &quot; character
 const char* s1 = R<font color="#D41C1C"><b>&quot;foo(</b></font>
                   <font color="#D41C1C"><b>^~~~~</b></font>
<b>exampleStrings.c:22:18:</b> <font color="#D41C1C"><b>error: </b></font>‘<b>R</b>’ undeclared here (not in a function)
 const char* s1 = <font color="#D41C1C"><b>R</b></font>&quot;foo(
                  <font color="#D41C1C"><b>^</b></font>
<b>exampleStrings.c:23:1:</b> <font color="#D41C1C"><b>error: </b></font>expected ‘<b>,</b>’ or ‘<b>;</b>’ before ‘<b>Hello</b>’
 <font color="#D41C1C"><b>Hello</b></font>
 <font color="#D41C1C"><b>^~~~~</b></font>
<b>exampleStrings.c:25:5:</b> <font color="#CD00CD"><b>warning: </b></font>missing terminating &quot; character
 )foo<font color="#CD00CD"><b>&quot;</b></font>;
     <font color="#CD00CD"><b>^</b></font>
<b>exampleStrings.c:25:5:</b> <font color="#D41C1C"><b>error: </b></font>missing terminating &quot; character
 )foo<font color="#D41C1C"><b>&quot;;</b></font>
     <font color="#D41C1C"><b>^~</b></font>
<b>exampleStrings.c:</b> In function ‘<b>main</b>’:
<b>exampleStrings.c:118:11:</b> <font color="#D41C1C"><b>error: </b></font>‘<b>s2</b>’ undeclared (first use in this function); did you mean ‘<b>s1</b>’?
     puts (<font color="#D41C1C"><b>s2</b></font>);
           <font color="#D41C1C"><b>^~</b></font>
           <font color="#00CD00">s1</font>
<b>exampleStrings.c:118:11:</b> <font color="#00CDCD"><b>note: </b></font>each undeclared identifier is reported only once for each function it appears in
</pre>

<b>g++ -Wall -std=c11 exampleStrings.c</b>
<pre><font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ g++ -Wall -std=c11 exampleStrings.c 
<b>cc1plus:</b> <font color="#CD00CD"><b>warning: </b></font>command line option ‘<b>-std=c11</b>’ is valid for C/ObjC but not for C++
<b>exampleStrings.c:</b> In function ‘<b>const char* get_dirname(const char*)</b>’:
<b>exampleStrings.c:44:18:</b> <font color="#D41C1C"><b>error: </b></font>invalid conversion from ‘<b>const char*</b>’ to ‘<b>char*</b>’ [<font color="#D41C1C"><b>-fpermissive</b></font>]
   slash = <font color="#D41C1C"><b>strrchr(pathname, &apos;/&apos;)</b></font>;
           <font color="#D41C1C"><b>~~~~~~~^~~~~~~~~~~~~~~</b></font>
<b>exampleStrings.c:</b> In function ‘<b>int main(int, char**)</b>’:
<b>exampleStrings.c:81:28:</b> <font color="#D41C1C"><b>error: </b></font>invalid conversion from ‘<b>void*</b>’ to ‘<b>char*</b>’ [<font color="#D41C1C"><b>-fpermissive</b></font>]
     char *ptr_char = <font color="#D41C1C"><b>malloc(sizeof(char) * 24)</b></font>;
                      <font color="#D41C1C"><b>~~~~~~^~~~~~~~~~~~~~~~~~~</b></font>
</pre>

<b>g++ -Wall -std=c99 exampleStrings.c</b> 

<pre><font color="#00CD00"><b>adri@adri-Lenovo-ideapad-700-15ISK</b></font>:<font color="#0000CD"><b>~/Escritorio/DPS/laboratory1-aferna21</b></font>$ g++ -Wall -std=c99 exampleStrings.c 
<b>cc1plus:</b> <font color="#CD00CD"><b>warning: </b></font>command line option ‘<b>-std=c99</b>’ is valid for C/ObjC but not for C++
<b>exampleStrings.c:</b> In function ‘<b>const char* get_dirname(const char*)</b>’:
<b>exampleStrings.c:44:18:</b> <font color="#D41C1C"><b>error: </b></font>invalid conversion from ‘<b>const char*</b>’ to ‘<b>char*</b>’ [<font color="#D41C1C"><b>-fpermissive</b></font>]
   slash = <font color="#D41C1C"><b>strrchr(pathname, &apos;/&apos;)</b></font>;
           <font color="#D41C1C"><b>~~~~~~~^~~~~~~~~~~~~~~</b></font>
<b>exampleStrings.c:</b> In function ‘<b>int main(int, char**)</b>’:
<b>exampleStrings.c:81:28:</b> <font color="#D41C1C"><b>error: </b></font>invalid conversion from ‘<b>void*</b>’ to ‘<b>char*</b>’ [<font color="#D41C1C"><b>-fpermissive</b></font>]
     char *ptr_char = <font color="#D41C1C"><b>malloc(sizeof(char) * 24)</b></font>;
                      <font color="#D41C1C"><b>~~~~~~^~~~~~~~~~~~~~~~~~~</b></font>
</pre>

<h1>Conclusiones
