/*
 * informes.c
 *
 *  Created on: 11 oct 2021
 *      Author: Luna Carlos Facundo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aviones.h"
#include "marcas.h"
#include "viajes.h"
#include "fecha.h"
#include "informes.h"

char menuInformes(){
	int opcionElegida;

		printf("------- MENU DE INFORMES -------\n");
		printf("\nIngrese una opcion para operar: \n");
		printf("[1] - Informar aviones Boeing.\n");
		printf("[2] - Informar aviones por marca.\n");
		printf("[3] - Informar matrícula y marca de los aviones que viajaron a Neuquen.\n");
		printf("[4] - Informar cantidad de km realizados por la marca ATR (No).\n");
		printf("[5] - Informar cantidad de asientos total para un modelo seleccionado.\n");
		printf("[6] - Informar promedio de kms para los aviones que viajaron en una fecha seleccionada(No).\n");
		printf("[8] - Salir del menu.\n");
		fflush(stdin);
		scanf("%d",&opcionElegida);
		opcionElegida = tolower(opcionElegida);

		return opcionElegida;
}

void informarAvionesPorMarca(eAvion aviones[], int tamAviones, eMarca arrayM[],
		int tamM, eViajes arrayV[], int tamV) {
	int cantAviones = 0;
	int resMarca;
	int i;
	system("cls");
	printf(
			"#######################################################################\n\n");
	printf(
			"##############################Lista de aviones de la misma marca######################### \n\n");

	if (arrayM != NULL && arrayV != NULL && aviones != NULL && tamAviones > 0 && tamM > 0 && tamV > 0) {
		listarMarcas(arrayM, tamM);
		utn_getNumero(&resMarca, "Ingrese id de la marca a mostrar", "Error.\n\n", 1000, 4000, 3);
			for (i = 0; i < tamAviones; i++) {
				if (resMarca == aviones[i].idMarca) {
					printf("ID   Matricula     Fecha       Viaje     Marca        Modelo                Asientos\n\n");
						mostrarAvion(aviones[i], arrayM, tamM, arrayV, tamV);
						cantAviones = 1;
				}
			}

		if (cantAviones == 0) {
			printf(
					"ID   Matricula     Fecha       IDviaje  Marca   Modelo    Asientos\n\n");
			printf(" No tiene aviones cargadas\n\n");
		}
	}
	printf(
			"#######################################################################\n\n");
}

/* Informe Nº1*/
void informarAvionesBoeing(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV) {
	int i;
	int flagBoeing=0;
	system("cls");
	printf(
				"#######################################################################\n\n");
		printf(
				"##############################Lista de aviones Boeing######################### \n\n");
		if (arrayM != NULL && arrayV != NULL && aviones != NULL && tamAviones > 0 && tamM > 0 && tamV > 0) {
			for (i = 0; i < tamAviones; i++){
				if(aviones[i].idMarca == 1000){
					printf("ID   Matricula     Fecha       Viaje     Marca        Modelo                Asientos\n\n");
					mostrarAvion(aviones[i], arrayM, tamM, arrayV, tamV);
					flagBoeing=1; //encontro un boeing
				}
			}
			printf(
						"#######################################################################\n\n");
			}
		}

/* Informe Nº2*/
void mostrarAvionPorMatriculaYMarca(eAvion arrayA, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV) {

	char marca[51];
	char nombreViajes[51];
	cargarDescripcionMarca(marca, arrayA.idMarca, arrayM, tamM);
	cargarDescripcionViajes(nombreViajes, arrayA.idViaje, arrayV, tamV);

	printf("    %10d         %10s   %9s  \n",
			 arrayA.matricula, nombreViajes, marca);

}

/* Informe Nº3*/
void informarAvionesNeuquen(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV){
	int i;
	int flagNeuquen=0;
	system("cls");
	printf(
					"#######################################################################\n\n");
			printf(
					"##############################Matricula y marca que viajaron a Neuquen######################### \n\n");
			if (arrayM != NULL && arrayV != NULL && aviones != NULL && tamAviones > 0 && tamM > 0 && tamV > 0){
				for (i = 0; i < tamAviones; i++){
								if(aviones[i].idViaje == 102){
									printf(" Matricula    Viaje     Marca  \n\n");
									mostrarAvionPorMatriculaYMarca(aviones[i], arrayM, tamM, arrayV, tamV);
									flagNeuquen=1; //encontro viaje a neuquen
					}
				}
					printf(
							"#######################################################################\n\n");
					}
				}

/* Informe Nº4*/
void informarKmTotalDeAvionesATR(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV){

	int i;
	int contadorKm=0;
	int flagATR=0;
	system("cls");
	printf(" º  km total de aviones ATR ##\n");

	if (arrayM != NULL && arrayV != NULL && aviones != NULL && tamAviones > 0 && tamM > 0 && tamV > 0){
		for (i = 0; i < tamAviones; i++){
			if(aviones[i].idMarca == 1002){
				contadorKm += arrayV[i].kms;
				flagATR=1;
			}
		}
	}
	printf("La marca ATR hizo un total de %.2f kms. \n\n", contadorKm);
}

/*Informe Nº 5*/
void informarCantTotalAsientosParaUnModelo(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV) {
		int i;
		int cantAsientos;
		int modeloAvion;

		system("cls");
		mostrarAviones(aviones, tamAviones, arrayM, tamM, arrayV, tamV);
		utn_getNumero(&modeloAvion," º Elegi un modelo: º\n"," º Error, Elegi entre [1999, 2000, 2009, 2010, 2020, 2021]\n",1999,2021,2);
		for(i=0;i<tamAviones;i++){
			if(aviones[i].modelo == modeloAvion){
				cantAsientos = aviones[i].cantAsientos;
			}
		}
		printf("La cantidad de asientos de ese modelo es %d.\n\n",cantAsientos);
		printf("\n\n");
}

/* Informe Nº6*/
void informarPromediokmsAvionesQueViajaronEnXfecha(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV){
	eFecha auxFecha;
	int auxAvion;
	int flagAvion=0;
	int indice;
	int i;
	system("cls");
	mostrarAviones(aviones, tamAviones, arrayM, tamM, arrayV, tamV);
	utn_getNumero(&auxFecha.dia, " º Ingrese el dia [1-31]: "," º Dia incorrecto, reingrese.\n",1,31,2);
	utn_getNumero(&auxFecha.mes, " º Ingrese el mes [1-12]: "," º Mes incorrecto, reingrese.\n",1,12,2);
	utn_getNumero(&auxFecha.anio, " º Ingrese el anio [2021-2022]: "," º Anio incorrecto, reingrese.\n",2021,2021,2);

	for(i=0;i<tamAviones;i++){
		if(aviones[i].idAvion >= 0 && aviones[i].fecha.dia == auxFecha.dia && aviones[i].fecha.mes == auxFecha.mes && aviones[i].fecha.anio == auxFecha.anio){
			indice = buscarEspacioLibre(aviones, tamAviones);
		}
	}
}


