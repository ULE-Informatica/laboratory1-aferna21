/* Adrian Fernandez Alvarez*/

/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two.
 * At the end the source code  should compile without warnings to the variant selected (you can remove/change instructions).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";                              /* Cumple con la regla STR36-C STR11-C */ 
char array2[7] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };   //Es un string porque se ha anyadido el caracter nulo
 
enum { BUFFER_MAX_SIZE = 1024 };
 
const char* s1 = R"foo(
Hello
World
)foo";
const char* s2 = "\nHello\nWorld\n";

/* Manejar el error y no retornar 1 puesto que es una funcion void  */
void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
//        return 1;
          fprintf(stderr, "Error in function gets_example_func\n");
          exit(-1);
  }
  buf[strlen(buf) - 1] = '\0';  
  
  
}

const char *get_dirname(const char *pathname) {
  char *slash = malloc(sizeof(strrchr(pathname, '/')));
  //slash = strrchr(pathname, '/'); // se debe reservar memoria para el puntero.

  if (slash) {
    *slash = '\0'; /* Undefined behavior */ //STR30-C
  }
  free(slash);
  return pathname;
}
 

void get_y_or_n(void) {  
  //char response[8];  //tambien reserva mas memoria de la que se necesita.
  char response = '\0'; 

  printf("Continue? [y] n: ");  
  //gets(response); eliminado por deprecated. Regla MSC34-C
  scanf(" %c", &response);
  if (response != 'y') 
    exit(0);  

  return;
}

 
int main(int argc, char *argv[])
{
    //Aseguramos que se introduzcan los argumentos de ejecucion necesarios
    if(argc != 3){
      fprintf(stderr, "Error in function gets_example_func\n");
      return -1;
    }


    char key[24];         
    char response[8];
    char array3[16];
    char array4[16];
    char array5[]  = "01234567890123456";
    //char *ptr_char  = "new string literal"; //incumple la MEM32-C
    char *ptr_char = malloc(sizeof(char) * 24);
    strcpy(&ptr_char[0], "new string literal");
    printf("%ld\n", sizeof(&ptr_char[0]));
    //size_t size_array1 = strlen("аналитик"); //cambiado int por size_t
    //size_t size_array2 = 100; //cambiado int por size_t

    
   // char analitic1[size_array1]="аналитик"; //STR11-C
   // char analitic2[size_array2]="аналитик"; //STR11-C
   // char analitic3[100]="аналитик"; //STR11-C

    puts(get_dirname(__FILE__));
    
    if (strlen(argv[1])>10) argv[1][10] = '\0'; //se trunca si supera el tamano de (key-3)/2
    if (strlen(argv[1])>10) argv[1][10] = '\0'; //se trunca si supera el tamano de (key-3)/2

    strcpy(key, argv[1]); //strcopy
    printf("%s\n", key);  
    strcat(key, " = ");
    printf("%s\n", key);  
    strcat(key, argv[2]);
    printf("%s\n", key);

    //fgets(auxresponse,sizeof(response),stdin);
    scanf("%s", &response[0]); //se ha cambiado por el fgets
    response[7] = '\0';

    printf("%s\n", response);
    get_y_or_n(); 

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);        
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    /*
    strncpy(array3, array5, sizeof(array3));  //el sizeof devolvera 16, el tamano del array, pero array3[16] no existe.
    strncpy(array4, array3, strlen(array3)); //no se puede asumir que el array fuente y el array destino tienen la misma longitud.
    */
    strncpy(array3, array5, sizeof(array3)-1);  
    strncpy(array4, array3, sizeof(array4)-1);

    array5 [0] = 'M';
    ptr_char [0] = 'N'; //STR30-C
    
    array3[sizeof(array3)-1]='\0';
    free(ptr_char);
    
    return 0;
}
