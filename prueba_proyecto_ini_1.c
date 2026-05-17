/*     REGLAS PARA EL PROYECTO: Ecos de Traición y Horror en C
IDEA: Juego con 12 personajes y 4 grupos (3 por grupo)  5 VS5 .
                   REGLAS A SEGUIR:
1. Comentarios: Usar para aclarar el propósito de variables y funciones.
2. Nomenclatura: Usar PascalCase para variables ( NombreDeVariable).
   (Primera letra de cada palabra en mayúscula, sin espacios ni guiones).
3. Llaves {}: Abrirlas en una línea nueva para separar mejor los bloques.
4. Indentación: Respetar el sangrado reglamentario para mantener el orden.
5. Idioma: El profesor mencionó que la creación de variables debía ser en inglés... aunque mas adelante las traducire*/
// Librerias usadas
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
void PrincipalLoop();
void MenuJump();
void CreateRoster();//crea a los personajes (Paola)
void ShowRoster();//muestra a los personajes en catalogo
/*añadir 2 funciones int para SeleccionDePersonaje
 y recordar hacer una funcion aleatrorio entera  para el dado*/
void SelectLanguage();// español opcion 1, ingles opcion 2
//===========INT MAIN donde inicializamos algunas funciones ========
int main()
{   
	SelectLanguage();
	CreateRoster();
	PrincipalLoop();
	return 0;
}
/*===================================================================================
==============================================By: Paola&Jimmelis================
======================FUNCIONES MENU================================================*/
void MenuJump()
{
	printf("\n>>>>>>>>>>>>>>>>>>>>O<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>>>>O<<<<<<<<<<<<<<<<<<<<\n");
}
/* aca se elije el idioma del juego*/
void SelectLanguage()
{
	char Option;
	printf("Selecciona un Idioma // Select a language \n");
	printf("=========================================\n");
	printf("1- ESPANIOL       //      1-SPANISH   \n");
	printf("2- INGLES         //      2-ENGLISH   \n");
	printf("Su Seleccion      // Your selection: -> ");
	scanf(" %c", &Option); 
	if(Option == '2') 
	{
		Lenguaje = 1; 
		printf("=========================================\n");
		printf("Starting the game in **ENGLISH**\n");
	}
	else if(Option == '1')
	{
		Lenguaje = 0; 
		printf("=========================================\n");
		printf("Inicializando el juego en **ESPANIOL**\n");
	}
	else 
	{
		// Si escriben otra cosa, forzamos español
		Lenguaje = 0; 
		printf("=========================================\n");
		printf("Opcion invalida. Inicializando por defecto en **ESPANIOL**\n");
	}
	
	MenuJump();
}
/*funcion encargada del menu principa, use char ya que un numero es igual un caracter y asi nos
 salvamos de un bucle infinito si sin querer escribian una letra u otro simbolo salvamos de u
 n bucle infinito si sin querer escribian una letra u otro simbolo*/
 	
char ShowPrincipalMenu()
{
	char SeleccionUsuario;
	if (Lenguaje == 0) // Si es 0, mostramos todo en ESPANIOL
	{
		printf ("\n ==== Ecos de Traicion y Horror en C ====\n\n");
		printf (" POR FAVOR SELECCIONE UNA OPCION\n");
		printf ("\n 1-- Ver lista de personajes \n");
		printf ("\n 2-- Formar Equipos \n");
		printf ("\n 3-- Iniciar Batalla \n");
		printf ("\n 4-- Mostrar Resultados \n");
		printf ("\n 5-- SALIR DEL JUEGO!\n");
		printf ("\n SU SELECCION   ");
	}
	else // Si es 1 (o cualquier otra cosa), mostramos todo en INGLES
	{
		printf ("\n ==== Echoes of Treason and Horror in C ====\n\n");
		printf (" PLEASE SELECT AN OPTION\n");
		printf ("\n 1-- View character list \n");
		printf ("\n 2-- Form Teams \n");
		printf ("\n 3-- Start Battle \n");
		printf ("\n 4-- Show Results \n");
		printf ("\n 5-- EXIT GAME!\n");
		printf ("\n YOUR SELECTION   ");
	}
	scanf(" %c", &SeleccionUsuario);
	MenuJump();
	return SeleccionUsuario;
}
// es el bucle principal donde se inicia el juego
void PrincipalLoop()
{
	char OpcionDeInicio;
	while (JuegoEncendido == true)
	{
		OpcionDeInicio = ShowPrincipalMenu();
		switch (OpcionDeInicio) 
		{	
			case '1':
				if (Lenguaje == 0) 
				{ 
					printf("\n   LISTA DE PERSONAJES\n"); 
				}
				else 
				{ 
					printf("\n   CHARACTER LIST\n"); 
				}
				ShowRoster(); // Llamamos al catalogo
			break;
			case '2':
				if (Lenguaje == 0)
				{
				  printf("\n CREACION DE EQUIPOS\n"); 
				}
				else
				{
				  printf("\n TEAM CREATION\n");
				}
			break;
			case '3':
				if (Lenguaje == 0)
				{
				  printf("\n INICIAR BATALLA\n"); 
				}
				else
				{
				  printf("\n START BATTLE \n");
				}
			break;
			case '4':
				if (Lenguaje == 0)
				{
				  printf("\nREGISTRO DE VENCEDORES EN IRONHAVEN\n"); 
				}
				else
				{
				  printf("\nRECORD OF VICTORS IN IRONHAVEN\n");
				}	
			break;
			case '5':
				if (Lenguaje == 0)
				{
				  printf("\n*** =SALIENDO DEL JUEGO GRACIAS POR JUGAR! ***\n"); 
				}
				else
				{
				  printf("\n*** EXITING GAME THANKS FOR PLAYING! ***\n");
				}
				JuegoEncendido = false;				
			break;
			default:
				if (Lenguaje == 0)
				{
				  printf("\n==Opcion no valida! Intente de nuevo Por favor===\n"); 
				}
				else
				{
				  printf("\n==Invalid option! Please try again===\n");
				}			
			break;
		}	
		MenuJump();
	}	
}
/*===================================================================================
=====================================================================================
=============CREACION,SECCION DE PERSONAJES y CATALOGO===============================*/
void CreateRoster() // paola
{
    // Si el lenguaje es ESPANIOL (0)
    if (Lenguaje == 0) 
    {
        Character creatingES[12] = 
        {
            // Nobles de Ironhaven
            { 1,"Nobles de Ironhaven","Guerrero","Alaric", 150, 150, 150, 150}, 
            { 2,"Nobles de Ironhaven","Distancia","Elara", 100, 50, 200, 250}, 
            { 3,"Nobles de Ironhaven","Tanque","Gareth, el Leal", 250, 200, 100, 50}, 
            // Los Cristalizados
            { 4,"Los Cristalizados","Tanque","Espectro de Obsidiana", 250, 200, 100, 50}, 
            { 5,"Los Cristalizados","Guerrero" ,"Jaspe, el Baron Rojo", 150, 150, 150, 150}, 
            { 6,"Los Cristalizados","Distancia","Selene, Demonio de Plata", 100, 50, 200, 250}, 
            // Cazadores Hostiles
            { 7,"Cazadores Hostiles","Tanque","Gehrman, el Verdugo", 250, 200, 100, 50}, 
            { 8,"Cazadores Hostiles","Distancia" ,"Kira, Asesino de Monstruos", 100, 50, 200, 250}, 
            { 9,"Cazadores Hostiles","Guerrero","Orion, Cazador Celestial", 150, 150, 150, 150}, 
            // La Bruma Escarlata
            {10,"La Bruma Escarlata","Guerrero","El Arcano", 300, 50, 0, 250}, 
            {11,"La Bruma Escarlata","Tanque","Rey Cedric", 250, 200, 100, 50}, 
            {12,"La Bruma Escarlata","Distancia","Principe Arthur", 150, 150, 150, 150}
        };
        for (int i = 0; i < 12; i++) Roster[i] = creatingES[i];
    }
    // Si el lenguaje es INGLES
    else 
    {
        Character creatingEN[12] = 
        {
            // Ironhaven Nobles
            { 1,"Ironhaven Nobles","Warrior","Alaric", 150, 150, 150, 150}, 
            { 2,"Ironhaven Nobles","Ranged","Elara", 100, 50, 200, 250}, 
            { 3,"Ironhaven Nobles","Tank","Gareth, the Loyal", 250, 200, 100, 50}, 
            // The Crystallized
            { 4,"The Crystallized","Tank","Obsidian Wraith", 250, 200, 100, 50}, 
            { 5,"The Crystallized","Warrior" ,"Jasper, the Red Baron", 150, 150, 150, 150}, 
            { 6,"The Crystallized","Ranged","Selene, Silver Demon", 100, 50, 200, 250}, 
            // Hostile Hunters
            { 7,"Hostile Hunters","Tank","Gehrman, the Executioner", 250, 200, 100, 50}, 
            { 8,"Hostile Hunters","Ranged" ,"Kira, Monster Hunter", 100, 50, 200, 250}, 
            { 9,"Hostile Hunters","Warrior","Orion, Celestial Hunter", 150, 150, 150, 150}, 
            // The Scarlet Mist
            {10,"The Scarlet Mist","Warrior","The Arcane", 300, 50, 0, 250}, 
            {11,"The Scarlet Mist","Tank","King Cedric", 250, 200, 100, 50}, 
            {12,"The Scarlet Mist","Ranged","Prince Arthur", 150, 150, 150, 150}
        };
        for (int i = 0; i < 12; i++) Roster[i] = creatingEN[i];
    }
}

void ShowRoster() //CATALOGO DE PERSONAJES
{
	if (Lenguaje == 0) 
	{
	 	printf("****       CATALOGO DE PERSONAJES DE IRONHAVEN        ****\n");
    	for (int i = 0; i < 12; i++) 
    	{
			printf("\n ====================================================================");
        	printf("\nID:    %d   |Grupo: %s\n", Roster[i].CharacterID,Roster[i].Group );
        	printf(" Nombre: %s   |Tipo: %s\n",Roster[i].Name , Roster[i].Type);
        	printf("       ESTADISTICAS\n HP: %.2f  |DEF: %.2f \n ATK: %.2f | ENERGIA: %d\n",Roster[i].Hp, Roster[i].Def, Roster[i].Atk, Roster[i].Energy);       
    	}
	}
	else 
	{
		printf("****       IRONHAVEN CHARACTER CATALOG       ****\n");
    	for (int i = 0; i < 12; i++) 
    	{
			printf("\n ====================================================================");
        	printf("\nID:    %d   |Group:: %s\n", Roster[i].CharacterID,Roster[i].Group );
        	printf(" Name: %s   |Type: %s\n",Roster[i].Name , Roster[i].Type);
        	printf("       STATISTICS\n HP: %.2f  |DEF: %.2f \n ATK: %.2f | ENERGY: %d\n",Roster[i].Hp, Roster[i].Def, Roster[i].Atk, Roster[i].Energy);       
    	}
	}
    	
}


