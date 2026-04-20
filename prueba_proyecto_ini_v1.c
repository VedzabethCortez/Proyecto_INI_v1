/*     REGLAS PARA EL PROYECTO: Ecos de Traición y Horror en C
IDEA: Juego con 12 personajes y 4 grupos (3 por equipo)  6 VS6.
                   REGLAS DE CODIFICACIÓN A SEGUIR:
1. Comentarios: Usar para aclarar el propósito de variables y funciones.
2. Nomenclatura: Usar PascalCase para variables (Ej: NombreDeVariable). 
   (Primera letra de cada palabra en mayúscula, sin espacios ni guiones).
3. Llaves {}: Abrirlas en una línea nueva para separar mejor los bloques.
4. Indentación: Respetar el sangrado reglamentario para mantener el orden.
5. Idioma: El profesor mencionó que la creación de variables debía ser en inglés.*/
/* Librerias usadas*/
#include <stdio.h>   /* necesaria para imprimir y obtener datos del usuario*/
#include <stdbool.h> /* para poder usar valores verdaderos o falsos*/
#include <stdlib.h>  /* funciones como rand y srand para numeros "aleatorios"*/
#include <time.h>    /* necesaria para que la funcion srand tome el reloj interno del computador como "semilla"*/

/* INDICE DE PROTOTIPOS(FUNCIONES)*/
int MostarMenuPrincipal();
void ConfigurarPartida();
void IniciarCuentaRegresiva();
/* VARIABLES GLOBALES*/

/*CORAZON DEL PROYECTO*/
int main()
{
	/*variables locales*/
	int OpcionDeInicio;
	int JuegoEncendido =true;
/*inicio del bucle principal del juego.la condicion de "JuegoEncendido= false"es la condicion de salida del juego"*/
	while (JuegoEncendido == true)
	{
		OpcionDeInicio= MostarMenuPrincipal();
		
		if (OpcionDeInicio==1)
		{
			ConfigurarPartida();
		}
		else if (OpcionDeInicio==2)
		{
			printf("\n ***Mostar ==informacion y reglas== del juego***");
		}
		else if(OpcionDeInicio==3)
		{
			printf("\n**** Ver lisa de personajes****");
		}
		else if(OpcionDeInicio==4)
		{
			printf("\n******* =SALIENDO DEL JUEGO GRACIAS POR JUGAR!****");
			JuegoEncendido =false;
		}
		else 
		{
			printf ("\n=================================================\n");
			printf("\n===Opcion no valida! intente de nuevo Por favor==\n ");
			printf ("\n=================================================\n");
		}
	}
return 0;
}
int MostarMenuPrincipal()
{
	int SeleccionUsuario;
	printf ("\n ===================================== \n");
	printf ("\n ==========TITULO DEL JUEGO=========== \n");
	printf ("\n ===================================== \n");
	printf ("\nPORFAVOR SELECCIONE UNA OPCION\n");
	printf ("\n 1-- JUGAR\n");
	printf ("\n 2-- INFORMACION DEL JUEGO\n");
	printf ("\n 3-- VER LISTA DE PERSONAJES\n");
	printf ("\n 4-- SALIR DEL JUEGO\n");
	printf ("\n SU SELECCION:     ");
	scanf("%d", &SeleccionUsuario);
return SeleccionUsuario;	
}

void ConfigurarPartida()
{
	printf ("\n MENU de MODO de JUEGO \n");
	printf ("\n aca deberia haber un do  \n");    
}
