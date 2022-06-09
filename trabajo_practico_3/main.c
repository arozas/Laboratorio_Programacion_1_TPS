#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"

#define RETRIES 3
#define MENU_OPTIONS 10

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/

int main()
{
	int option = 0;
	LinkedList* listaPasajeros = ll_newLinkedList();
	int flagLoadFile = 0;
	do{
		option=menu_menu("TRABAJO PRACTICO 3",
				"\n\n1.  Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
				"\n2.  Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
				"\n3.  Alta de pasajero"
				"\n4.  Modificar datos de pasajero"
				"\n5.  Baja de pasajero"
				"\n6.  Listar pasajeros"
				"\n7.  Ordenar pasajeros"
				"\n8.  Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
				"\n9.  Guardar los datos de los pasajeros en el archivo data.csv (modo binario)."
				"\n10. Salir", "ERROR, INTENTE OPCION <1-10>", RETRIES, MENU_OPTIONS);
		switch(option)
		{
		case 1:
			if(flagLoadFile==0)
			{
				controller_loadFromText("data.csv",listaPasajeros);
				flagLoadFile=1;
			}
			else
			{
				printf("\nYa fue importado un archivo csv con la nómina de empleados");
			}
			break;
		case 2:
			if(flagLoadFile == 0)
			{
				if(controller_loadFromBinary("dataB.bin",listaPasajeros) == 0)
				{
					flagLoadFile = 1;
				}
			}
			else
			{
				printf("\nYa fue importado un archivo csv con la nómina de empleados");
			}
			break;
		case 3:
			controller_addPassenger(listaPasajeros);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			controller_ListPassenger(listaPasajeros);
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}
	}while(option != 10);
	return 0;
}

