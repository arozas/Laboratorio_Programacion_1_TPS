/*
 * utntp1.h
 *
 *  Created on: 13 abr. 2022
 *  Author: Alejandro Alberto Martín Rozas
 *  Biblioteca de funciones especificas del TP 1 de Laboratorio.
 *  Versión 1.0 del 14 de abril de 2022.
 */

#ifndef UTNTP1_H_
#define UTNTP1_H_
#include "Operations.h"

int utntp1_calculateResults(float kilometros, float precioEmpresa, int descuentoDebito, int aumentoCredito, float valorBTC, float* precioConDebito, float* precioCredito, float* precioBTC, float* precioXkm);
int utntp1_printResult(float kilometros, float precioEmpresa,float precioEmpresaDos, char nombreEmpresaUno[], char nombreEmpresaDos[], float precioDebito,float precioDebitoDos, float precioCredito,float precioCreditoDos, float precioBTC, float precioBTCDos, float precioKm, float precioKmDos, float diferenciaPrecio);
int utntp1_calculateDiference(float precioUno, float precioDos, float* diferenciaPrecio);
int utntp1_forceCharge(float kilometrosForzados, float precioUnoForzado, float precioDosForzado, int descuento, int interes, float btc);

#endif /* UTNTP1_H_ */
