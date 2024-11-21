/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Ponga su nombre y numero de cuenta aqui.
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/


#include "stdafx.h"
#include <string.h>
#include "corrector.h"
//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario	
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario			(char *szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int &iNumElementos)
{

	//Sustituya estas lineas por su código
	FILE* fpDiccionario;
	char caracter;
	int contaLetras=0;
	char palabraCompleta[TAMTOKEN];
	fopen_s(&fpDiccionario, szNombre, "r");
	iNumElementos=1;
	if (fpDiccionario != NULL)
	{
		while ((caracter = fgetc(fpDiccionario)) != EOF)
		{
			if (caracter == ' ' || caracter == '\t' || caracter == '\n'||caracter==',' ||caracter==';'||caracter=='('||caracter==')'||caracter=='\r')//si es alguno de estos, palabra terminada
			{
				int palabraExiste = 1;
				if (contaLetras != 0)
				{
					palabraCompleta[contaLetras] = '\0';
					for (int i = 0; i < iNumElementos; i++)
					{

						if (strcmp(palabraCompleta, szPalabras[i]) == 0)
						{
							palabraExiste = 0;
							iEstadisticas[i]++;
						}
					}
					if (palabraExiste == 1) {
						strcpy_s(szPalabras[iNumElementos], sizeof(palabraCompleta), palabraCompleta);
						iEstadisticas[iNumElementos] = 1;
						contaLetras = 0;
						iNumElementos++;
					}
				}	
			}
			else
			{
				if (caracter >= 65 && caracter <= 90)
					caracter = towlower(caracter);
				palabraCompleta[contaLetras] = caracter;
				contaLetras++;
			}
		}
	}
	for (int a = 0; a < iNumElementos - 1; a++)
	{
		for (int b = 0; b < iNumElementos - a - 1; b++) {
			if (strcmp(szPalabras[b], szPalabras[b+1])>0)
			{
				char aux1[TAMTOKEN];
				int aux2;
				strcpy_s(aux1,szPalabras[b]);
				aux2=iEstadisticas[b];
				strcpy_s(szPalabras[b], szPalabras[b + 1]);
				iEstadisticas[b] = iEstadisticas[b + 1];
				strcpy_s(szPalabras[b + 1], aux1);
				iEstadisticas[b + 1] = aux2;
			}
		}
	}
}

/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void	ListaCandidatas		(
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
{

	//Sustituya estas lineas por su código
	strcpy(szListaFinal[0], szPalabrasSugeridas[ 0] ); //la palabra candidata
	iPeso[0] = iEstadisticas[0];			// el peso de la palabra candidata
	
	iNumLista = 1;							//Una sola palabra candidata
}

/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/
void	ClonaPalabras(
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
{
	//Sustituya estas lineas por su código
	strcpy(szPalabrasSugeridas[0], szPalabraLeida); //lo que sea que se capture, es sugerencia
	iNumSugeridas = 1;							//Una sola palabra sugerida
}
