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
 
char array1[] = "Foo" "bar";                              /* Cumple con la regla STR36-C STR11-C */ //no se le pasa el ultimo byte porque se ha declarado entero
char array2[7] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };   //Es un array de caracteres, no un string ??
 
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
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	//char response[8];  //tambien reserva mas memoria de la que se necesita.
  char response; //duda????

	printf("Continue? [y] n: ");  
	//gets(response); eliminado por deprecated. Regla MSC34-C
  scanf(" %c", &response);
	if (response == 'n') 
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


    char key[24];         //???? se reserva la memoria si se va a anyadir?? STR07-C
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456"; //STR11-C-EX2, si luego quiero meterle mas que el tring literal debo ponerle limites [loquesea]
    char *ptr_char  = "new string literal"; //incumple la MEM32-C
    printf("%ld\n", sizeof(ptr_char));
    size_t size_array1 = strlen("аналитик"); //cambiado int por size_t
    size_t size_array2 = 100; //cambiado int por size_t

    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";
    char analitic3[100]="аналитик";

    puts(get_dirname(__FILE__));
    
    //if (strlen(argv[1])>24) argv[1][24] = '\0'; //se trunca si supera el tamano de key

    strcpy(key, argv[1]);
    printf("%s\n", key);  
    strcat(key, " = ");
    printf("%s\n", key);  
    strcat(key, argv[2]);
    printf("%s\n", key);


    fgets(response,sizeof(response),stdin);

    printf("%s\n", response);
    get_y_or_n(); //por que si metes mas de 8 caracteres que corresponden al "response" te coge la respuesta?

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);        //puts anyade una nueva linea, que es mas correcto??
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N'; //si no se libera el espacio, salta core
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}
