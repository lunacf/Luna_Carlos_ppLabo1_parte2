/*
 * informes.h
 *
 *  Created on: 11 oct 2021
 *      Author: 54117
 */

#ifndef INFORMES_H_
#define INFORMES_H_

char menuInformes();
void informarAvionesPorMarca(eAvion aviones[], int tamAviones, eMarca arrayM[],int tamM, eViajes arrayV[], int tamV);
void informarAvionesBoeing(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
void mostrarAvionPorMatriculaYMarca(eAvion arrayA, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
void informarAvionesNeuquen(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
void informarKmTotalDeAvionesATR(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
void informarCantTotalAsientosParaUnModelo(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
void informarPromediokmsAvionesQueViajaronEnXfecha(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
#endif /* INFORMES_H_ */
