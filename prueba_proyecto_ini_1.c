/*     REGLAS PARA EL PROYECTO: Ecos de Traición y Horror en C
IDEA: Juego con 12 personajes y 4 grupos (3 por grupo)  6 VS6.
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
#include <math.h> /* Necesaria para operaciones matematicas un poco mas avanzadas */
/* INDICE DE PROTOTIPOS(FUNCIONES) se iran mencionando aca para que el programa sepa que en
algun momento conseguira una funcion con ese nombre*/
int ShowPrincipalMenu();
/*añadir 2 funciones int para FormaDeSeleccionDePersonajes y ResumenDeSeleccion, para realizar el otro menu//
recordar hacer una funcion aleatrorio entera que sera llamada en FormaDeSeleccionDePersonajes*/
void SelectLanguage();// español opcion 1, ingles opcion 2//
void Principaloop();
void MenuJump();
void ConfigurarPartida();
void IniciarCuentaRegresiva();

/* VARIABLES GLOBALES*/
int Lenguaje=0; /* 0 es español y 1 ingles*/
bool JuegoEncendido =true;//por ahora solo la que conrtola el apagado del juego//

// Estructuras Globales//
//<<<<<grupos de cartas >>//


/*INT MAIN EN DONDE LLAMO SOLO A DOS FUNCIONES */
int main()
{	SelectLanguage();
	Principaloop();
	return 0;
}
/*===================================================================================
=====================================================================================
======================FUNCIONES====================================================*/
void MenuJump()
{
	printf("\n>>>>>>>>>>>>>>>>>>>>O<<<<<<<<<<<<<<<<<<<<\n");
	printf("=========================================\n");
	printf("\n");
	printf("=========================================\n");
}
/* aca se elije el idioma del juego*/
void SelectLanguage()
{
	int Option;

	printf("Selecciona un Idioma //select a lenguaje \n");
	printf("=========================================\n");
	printf("1- ESPANIOL       //      1-SPANISH   \n");
	printf("2-   INGLES       //      2-ENGLISH   \n");
	printf("Su Seleccion      // Your selection: -> ");
	scanf("%d", &Option);
	if(Option==2)
	{
		Lenguaje=1;
		printf("=========================================\n");
		printf("Starting the game in **ENGLISH**\n");
	}
	else
	{
		Lenguaje=0;
		printf("=========================================\n");
		printf("inicializando el juego en **ESPANIOL**\n");
	}
	MenuJump();
}
/* es el bucle principal donde se inicia el juego*/
void Principaloop()
{
    int OpcionDeInicio;

    while (JuegoEncendido == true)
    {
        OpcionDeInicio = ShowPrincipalMenu();

        switch (OpcionDeInicio) 
        {
            case 1:
                ConfigurarPartida();
                break;
            case 2:
                printf("\n ***==informacion y reglas== del juego***\n");
                break;
            case 3:
                printf("\n**** Ver lista de personajes****\n");
                break;
            case 4:
                printf("\n*** =SALIENDO DEL JUEGO GRACIAS POR JUGAR! ***\n");
                JuegoEncendido = false;
                break;
            default:
                printf("\n==Opcion no valida! Intente de nuevo Por favor===\n");
                break;
        }
    }
    MenuJump();
}
//funcion encargada del menu principal//
int ShowPrincipalMenu()
{
	int SeleccionUsuario;
	printf ("\n ====Ecos de Traicion y Horror en C====\n");
	printf ("\nPOR FAVOR SELECCIONE UNA OPCION\n");
	printf ("\n 1-- JUGAR\n");
	printf ("\n 2-- INFORMACION DEL JUEGO\n");
	printf ("\n 3-- VER LISTA DE PERSONAJES\n");
	printf ("\n 4-- SALIR DEL JUEGO\n");
	printf ("\n SU SELECCION:     ");
	scanf("%d", &SeleccionUsuario);
	MenuJump();
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
		printf ("\n ======  MODO    de    JUEGO========== \n");
		printf ("\n");
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
			printf("\n                   ***=SALIENDO DEL JUEGO GRACIAS POR JUGAR!**");
			//menudemodos=false, ahi le digo que al seleccionar 5 sale de ese ciclo y la ora condicion me cierra el ciclo while principal//
			MenuDeModos=false;
			JuegoEncendido =false;
			
		}
		else //en caso que ninguna se cumpla se muetra el mensaje de error//
		{
			printf ("\n====>>>>>>>>>>>>>>>>>=============================================\n");
			printf ("\n==Opcion no valida! Intente de nuevo Por favor===\n ");
			printf ("\n=================================================<<<<<<<<<<<<<<<<<<\n");
		}
	} while(MenuDeModos==true);
}
