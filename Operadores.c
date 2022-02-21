#include "defs.h"
#include <stdio.h>
#include <stdlib.h>				//  Para usar system()

void bases()
{
	a = 179;		//  base 10
	printf("179 Base 10 es %o en base 8\n", a);
	printf("179 Base 10 es %X en base 16\n", a);

	b = 0263;		//  base 8
	printf("263 Base 8 es %d en base 10\n", b);
	printf("263 Base 8 es %X en base 16\n", b);

	c = 0xB3;		//  base 16
	printf("B3 Base 16 es %d en base 10\n", c);
	printf("B3 Base 16 es %o en base 8\n", c);
}

void primarios() 
{
	// Jeraquía nivel 1 - Operadores Primarios

	//  Operador llama a función ( () )
	bases();		// Invocar a función

	NL;
	PRINT1(f, 5.0 / 9 * 80 - 32);		//  Error
	PRINT1(f, 5.0 / 9 * (80 - 32) );	//  Correcto!
	PRINT1(d, (2 + 2) - (3 + 3) );		// Asociatividad

	//  Operador Índice de Arreglo ( [] )
	PR(d,arreglo[5]); NL;

	//  Operador Punto ( . )
	juanito.edad = 25;				//  Acceder a los campos de una estructura

	//  Operdor Flecha ( -> )
	ptrJuanito = &juanito;
	ptrJuanito->edad = 26;
}
int main()
{
	//  Jerarquía nivel 2 - Operadores Unarios

	// Operador negación lógica ( ! )
	a = 'a';
	if( "" ) 
		PR(s, "verdadero");
	else
		PR(s, "falso" );
	NL;
	a = 1;
	if( a ) 
		PR(s, "verdadero");
	else
		PR(s, "falso" );

	system("pause");
}