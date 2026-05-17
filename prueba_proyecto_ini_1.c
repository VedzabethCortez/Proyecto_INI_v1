/*     REGLAS PARA EL PROYECTO: Ecos de Traición y Horror en C
IDEA: Juego con 12 personajes y 4 grupos (3 por grupo)  5 VS5 .
                   REGLAS A SEGUIR:
1. Comentarios: Usar para aclarar el propósito de variables y funciones.
2. Nomenclatura: Usar PascalCase para variables ( NombreDeVariable).
   (Primera letra de cada palabra en mayúscula, sin espacios ni guiones).
3. Llaves {}: Abrirlas en una línea nueva para separar mejor los bloques.
4. Indentación: Respetar el sangrado reglamentario para mantener el orden.
5. Idioma: El profesor mencionó que la creación de variables debía ser en inglés... aunque mas adelante las traducire*/
/* Librerias usadas*/
#include <stdio.h>   // necesaria para imprimir y obtener datos del usuario
#include <stdbool.h> // para poder usar valores verdaderos o falsos
#include <stdlib.h>  // funciones como rand y srand para numeros "aleatorios"
#include <time.h>    // necesaria para que la funcion srand tome el reloj interno del computador como "semilla"
#include <math.h> // Necesaria para operaciones matematicas un poco mas avanzadas


// ===================ESTRUCTURAS GLOBLALES=============
//<<<<<grupos de cartas  hechos por PAola>>
typedef struct 
{
	int CharacterID;// Identificacion del personaje
    char Group[30];// Grupo al que pertenece el Personaje
    char Type[30]; // Tipo de personaje (Guerrero, Distancia, Tanque)
    char Name[30]; // Nombre del Personaje
    float Hp; // Vida Máxima del Personaje
    float Def; // Defensa del Personaje
    float Atk; // Ataque del Personaje
    int Energy; // Energía del Personaje 
} Character;
// ==================VARIABLES GLOBALEs====================

Character Roster[12]; // Todos los Personajes que son parte del Juego.
int Lenguaje=0; // 0 es español y 1 ingles
bool JuegoEncendido =true;//por ahora solo la que conrtola el apagado del juego



//===============ARREGLOS GLOBALES===============



/* ==============INDICE DE PROTOTIPOS(FUNCIONES) ===========
se iran mencionando aca para que el programa sepa que en
algun momento conseguira una funcion con ese nombre*/
char ShowPrincipalMenu();
void Principaloop();
void MenuJump();
void CreateRoster();//crea a los personajes (Paola)
void ShowRoster();//muestra a los personajes en catalogo
/*añadir 2 funciones int para SeleccionDePersonaje
 y recordar hacer una funcion aleatrorio entera  para el dado*/
void SelectLanguage();// español opcion 1, ingles opcion 2

//===========INT MAIN donde inicializamos algunas funciones ========
int main()
{   
	CreateRoster();
	SelectLanguage();
	Principaloop();
	return 0;
}
/*===================================================================================
==============================================By: Paola&Jimmelis================
======================FUNCIONES MENU================================================*/
void MenuJump()
{
	printf("\n>>>>>>>>>>>>>>>>>>>>O<<<<<<<<<<<<<<<<<<<<\n");
	printf("=========================================\n");
	printf("\n");
	printf("=========================================\n");
	printf("\n>>>>>>>>>>>>>>>>>>>>O<<<<<<<<<<<<<<<<<<<<\n");
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
//funcion encargada del menu principal//
char ShowPrincipalMenu()
{
	char SeleccionUsuario;
	printf ("\n ====Ecos de Traicion y Horror en C===\n\n \nPOR FAVOR SELECCIONE UNA OPCION\n");
	printf ("\n 1-- Ver lista de personajes \n \n 2-- Formar Equipos \n");
	printf ("\n 3-- Ejecutar Batalla \n \n 4-- Mostar Resultados\n");
	printf ("\n 5-- SALIR DEL JUEGO!\n \n SU SELECCION   ");
	scanf(" %c", &SeleccionUsuario);
	MenuJump();
	return SeleccionUsuario;
}
/* es el bucle principal donde se inicia el juego*/
void Principaloop()
{
    char OpcionDeInicio;

    while (JuegoEncendido == true)
    {
        OpcionDeInicio = ShowPrincipalMenu();
        switch (OpcionDeInicio) 
        {
            case '1':
            	printf("\n   LISTA DE PERSONAJES\n");
            	ShowRoster();
            	// llamamos al catalogo
            break;
            
            case '2':
                printf("\n CREACION DE EQUIPOS\n");
                // aca mostrar y hacer el ciuclo de seleccion de los personajes y al final cartas de ambiente 
            break;
                
            case '3':
                printf("\nINICIAR ENFRENTAMIENTO\n");
            break;
                
            case '4':
                printf("\nREGISTRO  DE  VENCEDORES  EN  IRONHEVEN\n");
            break;
                
            case '5':
                printf("\n*** =SALIENDO DEL JUEGO GRACIAS POR JUGAR! ***\n");
                JuegoEncendido = false;
            break;
                
            default:
                printf("\n==Opcion no valida! Intente de nuevo Por favor===\n");
            break;
            
        }	MenuJump();
    }	
    
}
/*===================================================================================
=====================================================================================
======================SECCION DE PERSONAJES y  CAALOGO===============================*/
void CreateRoster()
 {
    /* Aquí se crean los Personajes junto a sus estadísticas; aquí puedes editar tanto sus 
    Estadísticas cómo su nombre, y cualquier otro Valor único de cada personaje. */
    
    // { ID,"Grupo","Tipo","Nombre", Vida, Defensa, Ataque, Energía}
    Character creating[12] = 
	{
        // Nobles de Ironhaven
        { 1,"Nobles de Ironheven","Guerrero","Alaric", 150, 150, 150, 150}, 
        { 2,"Nobles de Ironheven","Distancia","Elara", 100, 50, 200, 250}, 
        { 3,"Nobles de Ironheven","Tanque","Gareth, el Leal", 250, 200, 100, 50}, 
        // Los Cristalizados
        {4,"Los Cristalizados","Tanque","Espectro de Obsidiana", 250, 200, 100, 50}, 
        {5,"Los Cristalizados","Guerrero" ,"Jaspe, el Baron Rojo", 150, 150, 150, 150}, 
        {6,"Los Cristalizados","Distancia","Selene, Demonio de Plata", 100, 50, 200, 250}, 
        // Cazadores Hostiles
        {7,"Cazadores Hostiles","Tanque","Gehrman, el Verdugo", 250, 200, 100, 50}, 
        {8,"Cazadores Hostiles","Distancia" ,"Kira, Asesino de Monstruos", 100, 50, 200, 250}, 
        {9,"Cazadores Hostiles","Guerrero","Orion, Cazador Celestial", 150, 150, 150, 150}, 
        // La Bruma Escarlata
        {10,"La Bruma Escarlata","Guerrero","El Arcano", 300, 50, 0, 250}, 
        {11,"La Bruma Escarlata","Tanque","Rey Cedric", 250, 200, 100, 50}, 
        {12,"La Bruma Escarlata","Distancia","Principe Arthur", 150, 150, 150, 150}
    };
    for (int i = 0; i < 12; i++) 
        Roster[i] = creating[i];
}

void ShowRoster() 
{
    printf("****       CATALOGO DE PERSONAJES DE IRONHAVEN        ****\n");
    for (int i = 0; i < 12; i++) 
    {
	printf("\n ====================================================================");
        printf("\nID:    %d   |Grupo: %s\n", Roster[i].CharacterID,Roster[i].Group );
        printf(" Nombre: %s   |Tipo: %s\n",Roster[i].Name , Roster[i].Type);
        printf("       ESTADISTICAS\n HP: %.2f  |DEF: %.2f \n ATK: %.2f | PODER: %d\n",Roster[i].Hp, Roster[i].Def, Roster[i].Atk, Roster[i].Energy);       
    }

}