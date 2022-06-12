#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Flight.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int Retorna 0 si la operacion se realizó con exito.
 *				Retorna -1 si los punteros va a Null.
 *				Retorna -2 si scaneo menos caracteres.
 *				Retorna -3 si el nuevo pasajero va a Null.
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int rtn = -1;
	char buffer[6][128];
	Passenger* pPassenger;
	if(pFile != NULL && pArrayListPassenger !=NULL)
	{																//id	name	lastname	price	  flycode   typePasse
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]) < 6)
			{
				rtn = -2;
				break;
			}
			else
			{
				pPassenger = Passenger_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[5],buffer[4]);
				if(pPassenger == NULL)
				{
					rtn = -3;
					break;
				}
				else
				{
					ll_add(pArrayListPassenger,(Passenger*)pPassenger);
					rtn = 0;
				}
			}
		}while(feof(pFile)==0);
	}
	return rtn;
}
/** \brief Parsea los datos los datos de los vuelos desde el archivo dataVuelos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList* Lista de vuelos;
 * \return int 	Retorna 0 si la operacion se realizó con exito.
 *				Retorna -1 si los punteros va a Null.
 *				Retorna -2 si scaneo menos caracteres.
 *				Retorna -3 si el nuevo vuelo va a Null.
 *
 */
int parser_FlightsFromText(FILE* pFile , LinkedList* pArrayListFlights)
{

	int rtn = -1;
	char buffer[2][128];
	Flight* pFlight;
	if(pFile != NULL && pArrayListFlights !=NULL)
	{
		fscanf(pFile,"%[^,],%[^\n]\n",buffer[0],buffer[1]);

		do{
			if(fscanf(pFile,"%[^,],%[^\n]\n",buffer[0],buffer[1]) < 2)
			{
				rtn = -2;
				break;
			}
			else
			{
				pFlight = Flight_newParametros(buffer[0],buffer[1]);
				if(pFlight == NULL)
				{
					rtn = -3;
					break;
				}
				else
				{
					ll_add(pArrayListFlights,(Flight*)pFlight);
					rtn = 0;
				}
			}
		}while(feof(pFile)==0);
	}
	return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo dataB.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	if(pFile != NULL && pArrayListPassenger !=NULL)
	{
		do
		{
			Passenger* newPassenger = Passenger_new();
			if(newPassenger !=NULL)
			{
				if(fread(newPassenger,sizeof(Passenger),1,pFile) != 1)
				{

					free(newPassenger);
					break;
				}
				else
				{
					if(ll_add(pArrayListPassenger,newPassenger) == 0)
					{
						rtn = 0;
					}
				}
			}
		}while(!feof(pFile));
	}
	return rtn;
}
/** \brief Parsea los datos los datos de los vuelos desde el archivo dataVuelosB.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_FlightsFromBinary(FILE* pFile , LinkedList* pArrayListFlights)
{
	int rtn = -1;

	if(pFile != NULL && pArrayListFlights !=NULL)
	{
		do
		{
			Flight* newFlight = Flight_new();
			if(newFlight !=NULL)
			{
				if(fread(newFlight,sizeof(Flight),1,pFile) != 1)
				{

					free(newFlight);
					break;
				}
				else
				{
					if(ll_add(pArrayListFlights,newFlight) == 0)
					{
						rtn = 0;
					}
				}
			}
		}while(!feof(pFile));
	}
	return rtn;
}
