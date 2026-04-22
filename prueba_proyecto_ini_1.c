/*     REGLAS PARA EL PROYECTO: Ecos de Traición y Horror en C
IDEA: Juego con 12 personajes y 4 grupos (3 por equipo)  6 VS6.
                   REGLAS A SEGUIR:
1. Comentarios: Usar para aclarar el propósito de variables y funciones.
2. Nomenclatura: Usar PascalCase para variables ( NombreDeVariable). 
   (Primera letra de cada palabra en mayúscula, sin espacios ni guiones).
3. Llaves {}: Abrirlas en una línea nueva para separar mejor los bloques.
4. Indentación: Respetar el sangrado reglamentario para mantener el orden.
5. Idioma: El profesor mencionó que la creación de variables debía ser en inglés... aunque mas adelante las traducire*/
/* Librerias usadas*/
#include <stdio.h>   /* necesaria para imprimir y obtener datos del usuario*/
#include <stdbool.h> /* para poder usar valores verdaderos o falsos*/
#include <stdlib.h>  /* funciones como rand y srand para numeros "aleatorios"*/
#include <time.h>    /* necesaria para que la funcion srand tome el reloj interno del computador como "semilla"*/
/* INDICE DE PROTOTIPOS(FUNCIONES) se iran mencionando aca para que el programa sepa que en 
algun momento conseguira una funcion con ese nombre*/
int MostarMenuPrincipal();
//añadir 2 funciones int para FormaDeSeleccionDePersonajes y ResumenDeSeleccion, para realizar el otro menu//
//recordar hacer una funcion aleatrorio entera que sera llamada en FormaDeSeleccionDePersonajes//
void ConfigurarPartida();
void IniciarCuentaRegresiva();
/* VARIABLES GLOBALES*/
//por ahora solo la que conrtola el apagado del juego/
	bool JuegoEncendido =true;
/*CORAZON DEL PROYECTO creo*/
int main()
{
	/*variables locales*/
	int OpcionDeInicio;
/*inicio del bucle principal del juego.la condicion de "JuegoEncendido= false"es la condicion de salida del juego"*/
	while (JuegoEncendido == true)
	{
		OpcionDeInicio= MostarMenuPrincipal();
		//Aca llamamos a la funcion para mostrar menu principal//
		if (OpcionDeInicio==1)
		{
			ConfigurarPartida();
			//aca llamamos a la funcion para configurar la partida//
		}
		else if (OpcionDeInicio==2)
		{
			printf("\n ***==informacion y reglas== del juego***");
			printf("\n ***espacio en construccion, se aniade al final***");
		}
		else if(OpcionDeInicio==3)//para ver los personajes//
		{
			//lista de personajes hecha pormariangela//
			printf("\n**** Ver lisa de personajes****");
			printf("\n============================================\n");
    		printf("1. LOS NOBLES DE IRONHAVEN\n");
    		printf("   - Alaric\n");
    		printf("   - Elara\n");
    		printf("   - aniadir otro personaje\n");
    		printf("\n============================================\n");
   			printf("2. LOS CRISTALIZADOS\n");
    		printf("   - Espectro de Obsidiana\n");
    		printf("   - Jaspe, el baron rojo\n");
    		printf("   - Selene, demonio de plata\n\n");
    		printf("\n============================================\n");
  			printf("3. CAZADORES HOSTILES\n");
    		printf("   - Gehrman, el Verdugo\n");
    		printf("   - Kira, asesino de monstruos\n");
    		printf("   - Orion, cazador celestial \n\n");
    		printf("\n============================================\n");
    		printf("4. LA BRUMA ESCARLATA\n");
    		printf("   - El Arcano\n");
    		printf("   - Rey Cedric\n");
    		printf("   - Principe Arthur\n");
    		printf("\n============================================\n");
    		printf(" LAS ESTADISTICAS PROXIMAMENTE SERAN AGREGADAS");
		}
		else if(OpcionDeInicio==4)//validar la salida //
		{
			printf("\n******* =SALIENDO DEL JUEGO GRACIAS POR JUGAR!****");
			JuegoEncendido =false;
		}
		else //en caso que ninguna se cumpla se muetra el mensaje de error//
		{
			printf ("\n>>>>>>>>>>>>>>>>>=================================================\n");
			printf ("\n==Opcion no valida! Intente de nuevo Por favor===\n ");
			printf ("\n=================================================<<<<<<<<<<<<<<<<<<<\n");
		}
	}
return 0;
}
//funcion encargada del menu principal//
int MostarMenuPrincipal()
{
	int SeleccionUsuario;
	printf ("\n ======================================\n");
	printf ("\n ====Ecos de Traicion y Horror en C====\n");
	printf ("\n ======================================\n");
	printf ("\nPORFAVOR SELECCIONE UNA OPCION\n");
	printf ("\n 1-- JUGAR\n");
	printf ("\n 2-- INFORMACION DEL JUEGO\n");
	printf ("\n 3-- VER LISTA DE PERSONAJES\n");
	printf ("\n 4-- SALIR DEL JUEGO\n");
	printf ("\n SU SELECCION:     ");
	scanf("%d", &SeleccionUsuario);
return SeleccionUsuario;	
}
//en esta funcion pedimos el modo de juego//
void ConfigurarPartida()
{
	//variables locales de la funcion//
	bool MenuDeModos=true;
	int SeleccionModoJuego;
	do
	{	
		printf ("\n ===================================== \n");
		printf ("\n ======  MODO    de    JUEGO========== \n");
		printf ("\n ===================================== \n");
		printf ("\n Seleccione el MODO de JUEGO \n");
		printf ("\n1--P vs P (Persona versus Persona)  \n");
		printf ("\n2--P vs M (Persona versus Maquina)  \n");
		printf ("\n3--M vs M **SOLO ESPECTADOR** (Maquina versus Maquina)  \n");
		printf ("\n4--Para ir al MENU anterior  \n");
		printf ("\n5--Para salir del juego \n");
		printf ("\n**SU SELECCION: ");
		scanf ("%d", &SeleccionModoJuego); 
		if (SeleccionModoJuego==1)
		{
			//en esta seleccion va a ir la funcion de forma de eleccion de personajes//
			printf ("\n===========================================================================================\n");
			printf(">>>>Ha seleccionado el modo -P vs P-");
			printf ("\n===========================================================================================\n");
		}
		else if (SeleccionModoJuego==2)
		{
			//en esta seleccion va a ir la funcion de forma de eleccion de personajes//
			printf ("\n===========================================================================================\n");			
			printf(">>>>Ha seleccionado el modo -P vs M-");
			printf ("\n===========================================================================================\n");
		}
		else if (SeleccionModoJuego==3)
		{
			//al seleccionar esto ira al resumen de eleccion de personajes//
			printf ("\n===========================================================================================\n");			
			printf (">>>>Ha seleccionado el modo ESPECTADOR -M vs M-");
			printf ("\n===========================================================================================\n");
		}
		else if (SeleccionModoJuego==4)
		{
			//ir al menu anterior//
			printf ("\n===========================================================================================\n");			
			printf (">>>Regresando al MENU anterior ");
			printf ("\n===========================================================================================\n");	
			MenuDeModos=false;
		}
		else if (SeleccionModoJuego==5)
		{
		//condicion de salidadel while del int main//
			printf("\n******* =SALIENDO DEL JUEGO GRACIAS POR JUGAR!****");
		//menudemodos=false, ahi le digo que al seleccionar 5 sale de ese ciclo y la ora condicion me cierra el ciclo while principal//
			MenuDeModos=false;
			JuegoEncendido =false;
			printf ("\n===========================================================================================\n");
		}
		else //en caso que ninguna se cumpla se muetra el mensaje de error//
		{
			printf ("\n====>>>>>>>>>>>>>>>>>=============================================\n");
			printf ("\n==Opcion no valida! Intente de nuevo Por favor===\n ");
			printf ("\n=================================================<<<<<<<<<<<<<<<<<<\n");
		}	
	}while(MenuDeModos==true);
}
