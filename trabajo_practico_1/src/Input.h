/*
 * Input.h
 *
 *  Created on: 1 abr. 2022
 *      Author: Alejandro Alberto Martín Rozas
 *      Biblioteca de funciones de entrada.
 *      Versión 0.4 del 14 de abril de 2022
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int input_getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroingresado);
int input_getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado);
int input_getChar(char mensaje[], int reintentos, char minimo, char maximo, char mensajeError[], char *pCaracteringresado);
int input_menuTwoOp(char nombreMenu[], char opcion1[], char opcion2[]);
int input_menuThreeOp(char nombreMenu[], char opcion1[], char opcion2[], char opcion3[]);
int input_menuFourOp(char nombreMenu[], char opcion1[], char opcion2[], char opcion3[], char opcion4[]);
int input_menuFiveOp(char nombreMenu[], char opcion1[], char opcion2[], char opcion3[], char opcion4[], char opcion5[]);
int input_menuSixOp(char nombreMenu[], char opcion1[], char opcion2[], char opcion3[], char opcion4[], char opcion5[], char opcion6[]);
void input_endProgram(void);

#endif /* INPUT_H_ */
