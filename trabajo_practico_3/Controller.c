#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "menu.h"
#include "input.h"

static Flight* controller_changeFlight (LinkedList* pArrayListFlights);
static Flight* controller_newFlight(LinkedList* pArrayListFlights);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pFile;
	//strcpy(path,"data.csv");
	pFile = fopen(path,"r");

	if(path != NULL && pArrayListPassenger != NULL)
	{

		if(pFile == NULL )
		{
			printf("\nNO SE PUDO ABRIR EL ARCHIVO");
		}
		else
		{
			if(ll_isEmpty(pArrayListPassenger) == 1)
			{

				if(parser_PassengerFromText(pFile,pArrayListPassenger) == 0)
				{
					printf("\nSE PARSEO EL ARCHIVO CON EXITO");
					rtn = 0;
				}
				else
				{
					printf("\nERROR DE PARSER");
				}
			}
			else
			{
				//TODO Setear nuevos IDS
				printf("\nTENES QUE SETEAR LOS NUEVOS IDS"); // NO LLEGUE A PROGRAMAR ESTA PARTE
			}

		}
	}

	fclose(pFile);
	return rtn;
}
int controller_loadFlightsFromText(char* path , LinkedList* pArrayListFlights)
{
	int rtn = -1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(path != NULL && pArrayListFlights != NULL)
	{

		if(pFile == NULL )
		{
			printf("\nNO SE PUDO ABRIR EL ARCHIVO");
		}
		else
		{
			if(ll_isEmpty(pArrayListFlights) == 1)
			{

				if(parser_FlightsFromText(pFile,pArrayListFlights) == 0)
				{
					printf("\nSE PARSEO EL ARCHIVO CON EXITO");
					rtn = 0;
				}
				else
				{
					printf("\nERROR DE PARSER");
				}
			}
			else
			{
				//TODO Setear nuevos IDS
				printf("\nTENES QUE SETEAR LOS NUEVOS IDS"); // NO LLEGUE A PROGRAMAR ESTA PARTE
			}

		}
	}

	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	FILE* pFile;
	pFile = fopen(path,"rb");
	if(pFile == NULL)
	{
		printf("\nNO SE PUDO ABRIR EL ARCHIVO");
	}
	else
	{
		if(ll_isEmpty(pArrayListPassenger) == 1)
		{
			if(parser_PassengerFromBinary(pFile,pArrayListPassenger) == 0)
			{
				printf("\nSE PARSEO EL ARCHIVO CON EXITO");
				ret = 0;
			}
			else
			{
				printf("\nERROR DE PARSER");
			}
		}
		else
		{
			//TODO Setear nuevos IDS
			printf("\n MENSAJE PARA ALE: TENES QUE SETEAR LOS NUEVOS IDS PARA QUE SEAN CONTINUOS");
		}
	}
	fclose(pFile);
	return ret;
}
/** \brief Carga los datos de los vuelos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFlightsFromBinary(char* path , LinkedList* pArrayListFlights)
{
	int ret = -1;
	FILE* pFile;
	pFile = fopen(path,"rb");
	if(pFile == NULL)
	{
		printf("\nNO SE PUDO ABRIR EL ARCHIVO");
	}
	else
	{
		if(ll_isEmpty(pArrayListFlights) == 1)
		{
			if(parser_FlightsFromBinary(pFile,pArrayListFlights) == 0)
			{
				printf("\nSE PARSEO EL ARCHIVO CON EXITO");
				ret = 0;
			}
			else
			{
				printf("\nERROR DE PARSER");
			}
		}
		else
		{
			//TODO Setear nuevos IDS
			printf("\nMENSAJE PARA ALE: TENES QUE SETEAR LOS NUEVOS IDS PARA QUE SEAN CONTINUOS");
		}
	}
	fclose(pFile);
	return ret;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlights)
{
	{
		int ret = -1;
		int lastID;
		int lastFlightID;
		int menu;
		char bufferFlycode[FLYCODE_LENGTH];
		Passenger* passengerBuffer = NULL;
		Flight* flightBuffer = NULL;
		if(pArrayListPassenger != NULL && pArrayListFlights !=NULL)
		{
			lastID = controller_searchLastId(pArrayListPassenger);
			passengerBuffer = Passenger_new();
			if(passengerBuffer != NULL && lastID != -1)
			{
				if(Passenger_setData(passengerBuffer) == 0)
				{
					do
					{
						if(lastFlightID != -1)
						{
							menu = menu_menu
									("VUELOS",
											"\n1 - CARGAR VUELO NUEVO."
											"\n2 - CARGAR VUELO EXISTENTE.",
											"ERROR, INGRESE UNA OPCIÓN <1-2>:",
											RETRIES,
											2);
						}
						else
						{
							printf("\n LISTA DE VUELOS LLENA");
							menu = 2;
						}
						switch(menu)
						{
						case 1:
							flightBuffer=Flight_new();
							lastFlightID =controller_searchLastId(pArrayListFlights);
							if(flightBuffer != NULL && lastFlightID != -1 )
							{
								if(Flight_setData(flightBuffer)==0
										&&controller_searchFlycode(pArrayListFlights, flightBuffer->codigoVuelo)==NULL)
								{
									lastFlightID++;
									ll_add(pArrayListFlights, flightBuffer);
									printf("\n SE HA CARGADO EL VUELO CON EXITO");
									controller_printFlight(flightBuffer);
									menu=3;
								}
								else
								{
									printf("\nESE VUELO YA EXISTE, SI DESEA CARGAR UN VUELO EXISTENTE.");
									printf("\nELIJA LA OPCIÓN <CARGAR VUELO EXISTENTE>.");
								}
							}
							else
							{
								printf("\n ERROR DE CARGA DE VUELO, VUELVA A CARGARLO");
							}
							break;
						case 2:
							if(ll_isEmpty(pArrayListFlights)!=1)
							{
								controller_ListFlights(pArrayListFlights);
								if(input_getAlphaNumericString("INGRESE EL CÓDIGO DE VUELO:", RETRIES, "ERROR.INTENTE DE NUEVO:", bufferFlycode, FLYCODE_LENGTH)==0)
								{
									flightBuffer = controller_searchFlycode(pArrayListFlights, bufferFlycode);
									menu=3;
								}
								else
								{
									printf("\nNO SE PUDO TOMAR EL FLYCODE INGRESADO, VERIFIQUE QUE ESTAS INGRESANDO UN FLYCODE Y NO OTRO DATO");
								}
							}
							else
							{
								printf("\nNO HAY VUELOS CARGADOS TENDRÁ QUE CARGAR UN VUELO");
								menu=1;
							}
							break;
						}

					} while(menu<3);
					lastID++;
					Passenger_setId(passengerBuffer,lastID);
					Passenger_setCodigoVuelo(passengerBuffer, flightBuffer->codigoVuelo);
					ll_add(pArrayListPassenger,passengerBuffer);
					printf("\nSE HA CARGADO CON EXITO EL NUEVO PAJERO");
					printf(	"\n------------------------------------------------------------------------------------------------------------------|");
					printf("\n%-6s%-15s%-15s%-15s%-20s%-20s%-20s","ID","NOMBRE","APELLIDO","PRECIO","CODIGO DE VUELO","CODIGO DE VUELO","TIPO DE PASAJERO");
					controller_printPassenger(passengerBuffer, pArrayListFlights);
					ret = 0;
				}
			}
		}
		if(ret == -1)
		{
			printf("\n SE CANCELO EL ALTA DE PASAJERO");
			free(passengerBuffer);
			passengerBuffer = NULL;
		}
		return ret;
	}
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlights)
{
	int rtn = -1;
	int bufferId;
	int modMenu;
	int flightMenu[3];
	char bufferName[NAME_LENGTH];
	char bufferLastName[NAME_LENGTH];
	float bufferPrice;
	int bufferTyperPassenger;
	char bufferFlycode[2][FLYCODE_LENGTH];
	Passenger* bufferPassenger = NULL;
	Flight* bufferFlight = NULL;
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger, pArrayListFlights);
		if(input_getIntNoRange("INGRESE EL ID DEL PASAJERO A MODIFICAR:", RETRIES, "ERROR. INTENTE DE NUEVO:", &bufferId) == 0)
		{
			bufferPassenger = controller_searchPassengerId(pArrayListPassenger,bufferId);
			if(bufferPassenger != NULL)
			{
				printf("\nESTE ES EL PASAJERO:\n");
				printf(	"\n------------------------------------------------------------------------------------------------------------------|");
				printf("\n%-6s%-15s%-15s%-15s%-20s%-20s%-20s","ID","NOMBRE","APELLIDO","PRECIO","CODIGO DE VUELO","CODIGO DE VUELO","TIPO DE PASAJERO");
				controller_printPassenger(bufferPassenger, pArrayListFlights);
				if(menu_confirm("¿DESEA MODIFICAR ESTE PASAJERO?", "ERROR INGRESE <S/N>"))
				{
					do{
						modMenu = menu_menu("MODIFICAR EMPLEADO",
								"\n\n1.  MODIFICAR NOMBRE"
								"\n2.  MODIFICAR APELLIDO."
								"\n3.  MODIFICAR PRECIO DE VUELO"
								"\n4.  MODIFICAR TIPO DE PASAJERO"
								"\n5.  MODIFICAR VUELO"
								"\n6.  DEJAR DE MODIFICAR",
								"ERROR, INTENTE OPCION <1-6>",
								RETRIES, 6);
						switch (modMenu)
						{
						case 1:
							if(input_getStringletters("INGRESE EL NUEVO NOMBRE:", RETRIES, "ERROR. INTENTE DE NUEVO:", bufferName, NAME_LENGTH)==0)
							{
								printf("\nEL NOMBRE INGRESADO ES: %s",bufferName);
								if(menu_confirm("¿DESEA HACER LA MODIFICACIÓN?", "ERROR. INGRESE <S/N>"))
								{
									Passenger_setNombre(bufferPassenger, bufferName);
									printf("\nSE HA REALIZADO LA MODIFICACIÓN CON EXITO");
								}
								else
								{
									printf("\nSE HA CANCELADO LA MODIFICACIÓN");
								}

							}
							break;
						case 2:
							if(input_getStringletters("INGRESE EL NUEVO APELLIDO:", RETRIES, "ERROR. INTENTE DE NUEVO:", bufferLastName, NAME_LENGTH)==0)
							{
								printf("\nEL APELLIDO INGRESADO ES: %s",bufferLastName);
								if(menu_confirm("¿DESEA HACER LA MODIFICACIÓN?", "ERROR. INGRESE <S/N>"))
								{
									Passenger_setNombre(bufferPassenger, bufferLastName);
									printf("\nSE HA REALIZADO LA MODIFICACIÓN CON EXITO");
								}
								else
								{
									printf("\nSE HA CANCELADO LA MODIFICACIÓN");
								}

							}
							break;
						case 3:
							if(input_getFloat("INGRESE EL NUEVO PRECIO:", RETRIES, MIN_PRICE, MAX_PRICE, "ERROR, INTENTE DE NUEVO:", &bufferPrice)==0)
							{
								printf("\nEL PRECIO INGRESADO ES: $%.2f",bufferPrice);
								if(menu_confirm("¿DESEA HACER LA MODIFICACIÓN?", "ERROR. INGRESE <S/N>"))
								{
									Passenger_setPrecio(bufferPassenger, bufferPrice);
									printf("\nSE HA REALIZADO LA MODIFICACIÓN CON EXITO");
								}
								else
								{
									printf("\nSE HA CANCELADO LA MODIFICACIÓN");
								}

							}
							break;
						case 4:
							bufferTyperPassenger=menu_menu("ELIJA EL TIPO DE PASAJERO",
									"\n1 - ECONOMY CLASS."
									"\n2 - FIRST CLASS."
									"\n3 - EXECUTIVE CLASS."
									,"ERROR INTENTE DE NUEVO"
									, RETRIES
									, 3);
							if(bufferTyperPassenger!=-1)
							{
								switch (bufferTyperPassenger)
								{
								case ECONOMY_CLASS:
									Passenger_setTipoPasajero(bufferPassenger, "ECONOMY CLASS");
									break;
								case FIRST_CLASS:
									Passenger_setTipoPasajero(bufferPassenger, "FIRST CLASS");
									break;
								case EXECUTIVE_CLASS:
									Passenger_setTipoPasajero(bufferPassenger, "EXECUTIVE CLASS");
									break;
								}
							}
							break;
						case 5:
							Passenger_getCodigoVuelo(bufferPassenger, bufferFlycode[1]);
							do{
								flightMenu[1]=menu_menu("MODIFICAR VUELO",
										"\n1 - MODIFCAR VUELO CARGADO"
										"\n2 - CARGAR UN VUELO NUEVO"
										"\n3 - CAMBIAR A VUELO EXISTENTE"
										"\n4 - VOLVER AL MENU ANTERIOR",
										"ERROR, INGRESE UNA OPCIÓN <1-4>:",
										RETRIES,
										4);
								switch(flightMenu[1])
								{
								case 1:
									bufferFlight = controller_searchFlycode(pArrayListFlights, bufferFlycode[1]);
									if(bufferFlight!=NULL)
									{
										do{
											flightMenu[2]=menu_menu("MODIFICAR VUELO CARGADO",
													"\n1 - MODIFCAR CODIGO DE VUELO"
													"\n2 - MODIFICAR ESTADO"
													"\n3 - VOLVER AL MENU ANTERIOR",
													"ERROR, INGRESE UNA OPCIÓN <1-3>:",
													RETRIES,
													4);
											switch(flightMenu[2])
											{
											case 1:
												if(input_getAlphaNumericString("INGRESE EL NUEVO CODIGO DE VUELO:", RETRIES, "ERROR. INTENTE DE NUEVO:", bufferFlycode[2],FLYCODE_LENGTH)==0)
												{
													printf("\nEL CODIGO DE VUELO INGRESADO ES: %s",bufferFlycode[2]);
													if(menu_confirm("¿DESEA HACER LA MODIFICACIÓN?", "ERROR. INGRESE <S/N>"))
													{
														Flight_setCodigoVuelo(bufferFlight, bufferFlycode[2]);
														Passenger_setCodigoVuelo(bufferPassenger, bufferFlycode[2]);
														controller_changeAllFlycodes(pArrayListPassenger, pArrayListFlights, bufferFlycode[1], bufferFlycode[2]);
														printf("\nSE HA REALIZADO LA MODIFICACIÓN CON EXITO");
													}
													else
													{
														printf("\nSE HA CANCELADO LA MODIFICACIÓN");
													}

												}
												break;
											case 2:
												flightMenu[3]=menu_menu("ELIJA EL ESTADO DE VUELO",
														"\n1 - EN HORARIO."
														"\n2 - RETRASADO."
														"\n3 - ATERRIZADO."
														"\n4 - EN VUELO."
														,"ERROR INTENTE DE NUEVO:"
														, RETRIES
														, 4);
												if(flightMenu[3]!=-1)
												{
													switch (flightMenu[3])
													{
													case SCHEDULED:
														Flight_setEstadoVuelo(bufferFlight, SCHEDULED);
														break;
													case DELAYED:
														Flight_setEstadoVuelo(bufferFlight, DELAYED);
														break;
													case LANDED:
														Flight_setEstadoVuelo(bufferFlight, LANDED);
														break;
													case IN_AIR:
														Flight_setEstadoVuelo(bufferFlight, IN_AIR);
														break;
													}
												}
												break;
											}
										}while(flightMenu[2]<3);
									}
									break;
								case 2:
									bufferFlight = controller_newFlight(pArrayListFlights);
									if(bufferFlight!=NULL
											&&Flight_getCodigoVuelo(bufferFlight, bufferFlycode[2])==0)
									{
										if(menu_confirm("¿DESEA HACER LA MODIFICACIÓN?", "ERROR. INGRESE <S/N>"))
										{
											Passenger_setCodigoVuelo(bufferPassenger, bufferFlycode[2]);
											printf("\nSE HA REALIZADO LA MODIFICACIÓN CON EXITO");
										}
										else
										{
											printf("\nSE HA CANCELADO LA MODIFICACIÓN");
										}
									}
									break;
								case 3:
									bufferFlight = controller_changeFlight(pArrayListFlights);
									if(bufferFlight!=NULL
											&&Flight_getCodigoVuelo(bufferFlight, bufferFlycode[2])==0)
									{
										if(menu_confirm("¿DESEA HACER LA MODIFICACIÓN?", "ERROR. INGRESE <S/N>"))
										{
											Passenger_setCodigoVuelo(bufferPassenger, bufferFlycode[2]);
											printf("\nSE HA REALIZADO LA MODIFICACIÓN CON EXITO");
										}
										else
										{
											printf("\nSE HA CANCELADO LA MODIFICACIÓN");
										}
									}
									break;
								}
							}while(flightMenu[1]<4);
							break;
						}
						rtn = 0;
					}while(modMenu<6);
					printf("\nDATOS DE PASAJEROS ACTUALIZADOS:\n");
					printf(	"\n------------------------------------------------------------------------------------------------------------------|");
					printf("\n%-6s%-15s%-15s%-15s%-20s%-20s%-20s","ID","NOMBRE","APELLIDO","PRECIO","CODIGO DE VUELO","CODIGO DE VUELO","TIPO DE PASAJERO");
					controller_printPassenger(bufferPassenger, pArrayListFlights);
				}
			}
		}

	}
	return rtn;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlights)
{
	int rtn = -1;
	int bufferId;
	int passangerIndex;
	Passenger* pPassenger = NULL;
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger, pArrayListFlights);
		if(input_getIntNoRange("INGRESE EL ID DEL PASAJERO:", RETRIES, "ERROR, INGRESE UN ID VALIDO:", &bufferId) == 0)
		{
			pPassenger = controller_searchPassengerId(pArrayListPassenger,bufferId);
			if(pPassenger != NULL)
			{
				printf("\nESTE ES EL PASAJERO A DAR DE BAJA:\n");
				controller_printPassenger(pPassenger, pArrayListFlights);
				if(menu_confirm("¿DESEA DAR DE BAJA EL PASAJEROS?\n<S/N>:", "ERROR, INGRESE <S/N>:"))
				{
					passangerIndex = ll_indexOf(pArrayListPassenger,pPassenger);
					if(ll_remove(pArrayListPassenger,passangerIndex) == 0)
					{
						printf("\nSE DIÓ DE BAJA EL SIGUIENTE PASAJERO:");
						controller_printPassenger(pPassenger,pArrayListFlights);
						Passenger_delete(pPassenger);
						rtn = 0;
					}
				}
			}
		}
		if(rtn != 0)
		{
			printf("\nSE CANCELÓ LA BAJA DEL PASAJERO");
		}
	}
	return rtn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlights)
{
	int rtn = -1;
	int i;
	int listSize;
	Passenger* pPassenger;
	if(pArrayListPassenger != NULL)
	{
		listSize = ll_len(pArrayListPassenger);
		if(listSize != -1)
		{		printf(
				"\n|::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
				"\n                                                   PASAJEROS"
				"\n|::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
		printf("\n%-6s%-15s%-15s%-15s%-20s%-20s%-20s","ID","NOMBRE","APELLIDO","PRECIO","CODIGO DE VUELO","CODIGO DE VUELO","TIPO DE PASAJERO");
		for (i = 0; i < listSize; i++)
		{
			pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			if(pPassenger != NULL)
			{
				controller_printPassenger(pPassenger, pArrayListFlights);
				rtn = 0;
			}
		}//FIN FOR
		}
	}
	return rtn;
}
int controller_ListFlights(LinkedList* pArrayListFlights)
{
	int rtn = -1;
	int i;
	int listSize;
	Flight* pFlight;
	if(pArrayListFlights != NULL)
	{
		listSize = ll_len(pArrayListFlights);
		if(listSize != -1)
		{
			for (i = 0; i < listSize; i++)
			{
				pFlight = (Flight*)ll_get(pArrayListFlights, i);
				if(pFlight != NULL)
				{
					controller_printFlight(pFlight);
					rtn = 0;
				}
			}//FIN FOR
		}
	}
	return rtn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int orderCriteria[2]={-1,-1};
	int(*pToOrder)(void*,void*);
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger) == 0)
		{
			orderCriteria[0]=menu_menu("CRITERIO DE ORFENAMIENTO",
					"\n1 - ID DE PASAJERO"
					"\n2 - NOMBRE"
					"\n3 - APELLIDO"
					"\n4 - PRECIO DE VUELO"
					"\n5 - TIPO DE PASAJERO"
					"\n6 - CÓDIGO DE VUELO"
					, "ERROR, INGRESE UNA OPCIÓN <1-6>", RETRIES, 6);
			switch (orderCriteria[0])
			{
			case 1:
				pToOrder = Passenger_sortById;
				break;
			case 2:
				pToOrder = Passenger_sortByName;
				break;
			case 3:
				pToOrder = Passenger_sortByLastName;
				break;
			case 4:
				pToOrder = Passenger_sortByPrice;
				break;
			case 5:
				pToOrder = Passenger_sortByPassengerType;
				break;
			case 6:
				pToOrder = Passenger_sortByFlycode;
				break;
			}
			if(orderCriteria[0]!=-1)
			{
				orderCriteria[1]=menu_menu("FORMA DE ORDENAMIENTO",
						"\n1 - ASCENDENTE"
						"\n2 - DESCENDENTE",
						"ERROR, INGRESE UNA OPCIÓN <1-2>", RETRIES, 2);
			}
			else
			{
				orderCriteria[1] = -1;
			}
			if(orderCriteria[1] != -1)
			{
				if(orderCriteria[1] == 1)
				{
					orderCriteria[1] = 0;
				}
				else
				{
					orderCriteria[1] = 1;
				}
				if(ll_sort(pArrayListPassenger,pToOrder,orderCriteria[1]) == 0)
				{
					printf("\nSE ORDENARON LOS PASAJEROS, SEGUN EL CRITERIO ELEGIDO.");
					rtn = 0;
				}
				else
				{
					printf("\nNO SE PUDO HACER EL ORDENAMIENTO");
					rtn = -2;
				}

			}
		}

	}else
	{
		printf("NO HAY PASAJEROS CARGADOS");
	}
	return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	FILE* pFile;
	int sizeList;
	int i;
	int bufferID;
	char bufferName[NAME_LENGTH];
	char bufferLastName[NAME_LENGTH];
	float bufferPrice;
	char bufferFlycode[FLYCODE_LENGTH];
	char bufferTypePassenger[NAME_LENGTH];
	Passenger* pPassenger = NULL;
	if(path != NULL && pArrayListPassenger!= NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile,"ID,NOMBRE,APELLODO,PRECIO,CODIGO DE VUELO,TIPO PASAJERO\n");
			sizeList = ll_len(pArrayListPassenger);
			for (i = 0; i < sizeList; i++)
			{
				pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				if(pPassenger != NULL)
				{
					if(		(Passenger_getId(pPassenger,&bufferID)) != 0 ||
							(Passenger_getNombre(pPassenger,bufferName)) != 0 ||
							(Passenger_getApellido(pPassenger,bufferLastName)) != 0 ||
							(Passenger_getPrecio(pPassenger,&bufferPrice)) != 0 ||
							Passenger_getCodigoVuelo(pPassenger, bufferFlycode)!= 0 || Passenger_getTipoPasajero(pPassenger, bufferTypePassenger))
					{
						pPassenger = NULL;
						free(pPassenger);
						printf("\nERROR, NO SE PUEDEN GUARDAR DATOS EN EL ARCHIVO%s",path);
						break;
					}
					else
					{
						fprintf(pFile,"%d,%s,%s,%f,%s,%s\n",bufferID,bufferName,bufferLastName,bufferPrice,bufferFlycode,bufferTypePassenger);
					}
				}
			}//FIN FOR
		}
		else
		{
			printf("\nNO SE PUEDE ABRIR EL ARICHIVO: %s",path);
		}
	}
	if(pPassenger != NULL)
	{
		ret = 0;
		printf("\nSE GRABO EL ARICHIVO CON EXITO");
	}
	fclose(pFile);
	return ret;
}
/** \brief Guarda los datos de los vuelos en el archivo dataVuelos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveFlightsAsText(char* path , LinkedList* pArrayListFlights)
{
	int ret = -1;
	FILE* pFile;
	int sizeList;
	int i;
	char bufferFlycode[FLYCODE_LENGTH];
	int bufferStatusFlight;
	Flight* pFlight = NULL;
	if(path != NULL && pArrayListFlights!= NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile,"ID,NOMBRE,APELLODO,PRECIO,CODIGO DE VUELO,TIPO PASAJERO\n");
			sizeList = ll_len(pArrayListFlights);
			for (i = 0; i < sizeList; i++)
			{
				pFlight = (Flight*)ll_get(pArrayListFlights, i);
				if(pFlight != NULL)
				{
					if(Flight_getCodigoVuelo(pFlight, bufferFlycode)!= 0
							|| Flight_getEstadoVuelo(pFlight, &bufferStatusFlight))
					{
						pFlight = NULL;
						free(pFlight);
						printf("\nERROR, NO SE PUEDEN GUARDAR DATOS EN EL ARCHIVO%s",path);
						break;
					}
					else
					{
						fprintf(pFile,"%s,%d\n",bufferFlycode,bufferStatusFlight);
					}
				}
			}//FIN FOR
		}
		else
		{
			printf("\nNO SE PUEDE ABRIR EL ARICHIVO: %s",path);
		}
	}
	if(pFlight != NULL)
	{
		ret = 0;
		printf("\nSE GRABO EL ARICHIVO CON EXITO");
	}
	fclose(pFile);
	return ret;
}

/** \brief Guarda los datos de los pasajeros en el archivo dataB.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pFile;
	int sizeList;
	int i;
	Passenger* pPassenger = NULL;
	if(path != NULL && pArrayListPassenger!= NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			sizeList = ll_len(pArrayListPassenger);
			for (i = 0; i < sizeList; i++)
			{
				pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				if(pPassenger != NULL)
				{
					if(fwrite(pPassenger,sizeof(Passenger),1,pFile) != 1)
					{
						pPassenger = NULL;
						free(pPassenger);
						break;
						printf("\nERROR AL GUARDAR EL ARCHIVO");
					}
				}
			}
		}
	}
	if(pPassenger != NULL)
	{
		printf("\nSE GRABO EL ARICHIVO BINARIO CON EXITO");
		rtn = 0;
	}
	fclose(pFile);
	return rtn;
}
/** \brief Guarda los datos de los vuelos en el archivo dataVuelosB.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveFlightAsBinary(char* path , LinkedList* pArrayFlights)
{
	int rtn = -1;
	FILE* pFile;
	int sizeList;
	int i;
	Flight* pFlights = NULL;
	if(path != NULL && pArrayFlights!= NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			sizeList = ll_len(pArrayFlights);
			for (i = 0; i < sizeList; i++)
			{
				pFlights = (Flight*)ll_get(pArrayFlights, i);
				if(pFlights != NULL)
				{
					if(fwrite(pFlights,sizeof(Flight),1,pFile) != 1)
					{
						pFlights = NULL;
						free(pFlights);
						break;
						printf("\nERROR AL GUARDAR EL ARCHIVO");
					}
				}
			}
		}
	}
	if(pArrayFlights != NULL)
	{
		printf("\nSE GRABO EL ARICHIVO BINARIO CON EXITO");
		rtn = 0;
	}
	fclose(pFile);
	return rtn;
}
int controller_searchLastId(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int listSize;
	int i;
	int bufferId;
	int maxId;
	Passenger* pPassenger;
	int flagMaxId = 0;
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger) == 0)
		{
			listSize=ll_len(pArrayListPassenger);
			for (i = 0; i < listSize; i++)
			{
				pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pPassenger,&bufferId);
				if(flagMaxId == 0 || bufferId > maxId)
				{
					maxId = bufferId;
					flagMaxId = 1;
					rtn = maxId;
				}
			}
		}
		else
		{
			printf("\nNO HAY PASAJEROS CARGADADOS EN LA BASE DE DATOS");
			printf("\nPARA EVITAR REPETIR ID, SE SETEARÁ UN ID DESDE EL 2000");
			if(menu_confirm("¿DESEA CONTINUAR?\n<S/N>:", "ERROR, INGRESE <S/N>") == 1)
			{
				rtn = 2000;

			}
			else
			{
				printf("\nCARGA CANCELADA");
			}
		}
	}
	return rtn;
}
void controller_printPassenger(Passenger* this, LinkedList* pArrayFlights)
{
	if(this != NULL && pArrayFlights != NULL )
	{
		int bufferId;
		char bufferName[NAME_LENGTH];
		char bufferSurname[NAME_LENGTH];
		float bufferPrice;
		char bufferFlyCode[FLYCODE_LENGTH];
		int bufferStatusFlight;
		char bufferPassengerType[50];
		Flight* PFlight = NULL;
		Passenger_getId(this,&bufferId);
		Passenger_getNombre(this,bufferName);
		Passenger_getApellido(this,bufferSurname);
		Passenger_getPrecio(this,&bufferPrice);
		Passenger_getCodigoVuelo(this, bufferFlyCode);
		Passenger_getTipoPasajero(this, bufferPassengerType);
		printf(	"\n------------------------------------------------------------------------------------------------------------------|");
		//  ID  NAME LN    PRICE
		printf("\n%-6d%-15s%-15s$%-15.2f%-20s",bufferId,bufferName,bufferSurname,bufferPrice,bufferFlyCode);
		PFlight=controller_searchFlycode(pArrayFlights, bufferFlyCode);
		Flight_getEstadoVuelo(PFlight, &bufferStatusFlight);
		switch(bufferStatusFlight)
		{
		case SCHEDULED:
			printf("%-20s","EN HORARIO");
			break;
		case DELAYED:
			printf("%-20s", "ATRASADO");
			break;
		case LANDED:
			printf("%-20s","ATERRIZADO");
			break;
		case IN_AIR:
			printf("%-20s","EN VUELO");
			break;
		}

		printf("%-20s",bufferPassengerType);
		printf(	"\n------------------------------------------------------------------------------------------------------------------|");
	}
}
void controller_printFlight(Flight* this)
{
	if(this != NULL)
	{
		char bufferCodigoVuelo[NAME_LENGTH];
		int bufferEstadoVuelo;
		Flight_getCodigoVuelo(this,bufferCodigoVuelo);
		Flight_getEstadoVuelo(this,&bufferEstadoVuelo);
		printf("\nCODIGO DE VUELO \t ESTADO DE VUELO");
		printf("\n%s",bufferCodigoVuelo);
		switch(bufferEstadoVuelo)
		{
		case SCHEDULED:
			printf("\t EN HORARIO");
			break;
		case DELAYED:
			printf("\t ATRASADO");
			break;
		case LANDED:
			printf("\t ATERRIZADO");
			break;
		case IN_AIR:
			printf("\t EN VUELO");
			break;
		}
	}

}
Passenger* controller_searchPassengerId(LinkedList* pArrayListPassenger,int idSearch)
{
	Passenger* rtn = NULL;
	int sizeLinkedList;
	int i;
	int bufferID;
	Passenger* pPassenger;
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger) == 0)
		{
			sizeLinkedList=ll_len(pArrayListPassenger);
			for (i = 0; i < sizeLinkedList; i++)
			{
				pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pPassenger,&bufferID);
				if(bufferID == idSearch)
				{
					rtn = pPassenger;
					break;
				}
			}//FIN FOR
			if(rtn != pPassenger)
			{
				printf("\nNO SE ENCONTRÓ EL ID EN LA BASE DE DATOS");
			}
		}
		else
		{
			printf("\nNO HAY PASAJEROS EN LA BASE DE DATOS");
		}
	}

	return rtn;
}
Flight* controller_searchFlycode(LinkedList* pArrayFlights,char* passengerFlycode)
{
	Flight* rtn = NULL;
	int sizeLinkedList;
	int i;
	char bufferFlycode[FLYCODE_LENGTH];
	Flight* bufferFlight;
	if(pArrayFlights != NULL)
	{
		if(ll_isEmpty(pArrayFlights) == 0)
		{
			sizeLinkedList=ll_len(pArrayFlights);
			for (i = 0; i < sizeLinkedList; i++)
			{
				bufferFlight = (Flight*)ll_get(pArrayFlights, i);
				Flight_getCodigoVuelo(bufferFlight,bufferFlycode);
				if(strcmp(bufferFlycode,passengerFlycode)==0)
				{

					rtn = bufferFlight;
					break;
				}
			}//FIN FOR
			if(rtn != bufferFlight)
			{
				printf("\nNO EXISTE ESE VUELO");
			}
		}
		else
		{
			printf("\n NO HAY VUELOS CARGADOS EN LA BASE DE DATOS");
		}
	}

	return rtn;
}
int controller_changeAllFlycodes(LinkedList* pArrayListPassenger, LinkedList* pArrayFlights, char* oldFlyCode, char* newFlyCode)
{
	int rtn = -1;
	int sizeLinkedList;
	int i;
	char bufferFlycode[FLYCODE_LENGTH];
	Passenger* pPassenger;
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger) == 0)
		{
			sizeLinkedList=ll_len(pArrayListPassenger);
			for (i = 0; i < sizeLinkedList; i++)
			{
				pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getCodigoVuelo(pPassenger,bufferFlycode);
				if(strcmp(bufferFlycode,oldFlyCode)==0)
				{
					Passenger_setCodigoVuelo(pPassenger, newFlyCode);
				}
			}//FIN FOR
			if(controller_searchFlycode(pArrayFlights, oldFlyCode)==NULL)
			{
				rtn = 0;
			}
		}
	}
	return rtn;
}
//============================================================================= STATIC =============================================================================
static Flight* controller_newFlight(LinkedList* pArrayListFlights)
{
	Flight* rtn = NULL;
	Flight* pFlight = NULL;
	int lastFlightID;
	pFlight=Flight_new();
	lastFlightID =controller_searchLastId(pArrayListFlights);
	if(pFlight != NULL && lastFlightID != -1 )
	{
		if(Flight_setData(pFlight)==0
				&&controller_searchFlycode(pArrayListFlights, pFlight->codigoVuelo)==NULL)
		{
			lastFlightID++;
			ll_add(pArrayListFlights, pFlight);
			printf("\n SE HA CARGADO EL VUELO CON EXITO");
			controller_printFlight(pFlight);
			rtn = pFlight;
		}
		else
		{
			printf("\nESE VUELO YA EXISTE, SI DESEA CARGAR UN VUELO EXISTENTE.");
			printf("\nELIJA LA OPCIÓN <CARGAR VUELO EXISTENTE>.");
		}
	}
	else
	{
		printf("\n ERROR DE CARGA DE VUELO, VUELVA A CARGARLO");
	}
	return rtn;
}
static Flight* controller_changeFlight (LinkedList* pArrayListFlights)
{
	Flight* rtn = NULL;
	Flight* pFlight = NULL;
	char bufferFlyCode[FLYCODE_LENGTH];
	controller_ListFlights(pArrayListFlights);
	if(input_getAlphaNumericString("INGRESE EL CÓDIGO DE VUELO:", RETRIES, "ERROR.INTENTE DE NUEVO:", bufferFlyCode, FLYCODE_LENGTH)==0)
	{
		pFlight = controller_searchFlycode(pArrayListFlights, bufferFlyCode);
		if(pFlight != NULL)
		{
			rtn = pFlight;
		}
	}
	else
	{
		printf("\nNO SE PUDO TOMAR EL FLYCODE INGRESADO, VERIFIQUE QUE ESTAS INGRESANDO UN FLYCODE Y NO OTRO DATO");
	}
	return rtn;
}
Passenger* controller_searchPassengerDuplicatedIds(LinkedList* pArrayListPassenger,int idSearch)
{
	Passenger* rtn = NULL;
	int sizeLinkedList;
	int i;
	int bufferIDOne;
	int bufferIDTwo;
	Passenger* pPassengerOne;
	Passenger* pPassengerTwo;
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger) == 0)
		{
			sizeLinkedList=ll_len(pArrayListPassenger);
			for (i = 0; i < sizeLinkedList; i++)
			{
				pPassengerOne = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pPassengerOne,&bufferIDOne);
				pPassengerTwo = (Passenger*)ll_get(pArrayListPassenger, i+1);
				Passenger_getId(pPassengerTwo,&bufferIDTwo);
				if(bufferIDOne == idSearch)
				{
					rtn = pPassengerOne;
					break;
				}
			}//FIN FOR
			if(rtn != pPassengerOne)
			{
				printf("\nNO SE ENCONTRÓ EL ID EN LA BASE DE DATOS");
			}
		}
		else
		{
			printf("\nNO HAY PASAJEROS EN LA BASE DE DATOS");
		}
	}

	return rtn;
}
