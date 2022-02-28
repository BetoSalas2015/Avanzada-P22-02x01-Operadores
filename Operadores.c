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
	// Jeraqu�a nivel 1 - Operadores Primarios

	//  Operador llama a funci�n ( () )
	bases();		// Invocar a funci�n

	NL;
	PRINT1(f, 5.0 / 9 * 80 - 32);		//  Error
	PRINT1(f, 5.0 / 9 * (80 - 32) );	//  Correcto!
	PRINT1(d, (2 + 2) - (3 + 3) );		// Asociatividad

	//  Operador �ndice de Arreglo ( [] )
	PR(d,arreglo[5]); NL;

	//  Operador Punto ( . )
	juanito.edad = 25;				//  Acceder a los campos de una estructura

	//  Operdor Flecha ( -> )
	ptrJuanito = &juanito;
	ptrJuanito->edad = 26;
}
int main()
{
	//  Jerarqu�a nivel 2 - Operadores Unarios

	// Operador negaci�n l�gica ( ! )
	a = 0;
	if( a ) 
		PR(s, "verdadero");
	else
		PR(s, "falso" );
	NL;
	a = 1;
	if( a ) 
		PR(s, "verdadero");
	else
		PR(s, "falso" );
	NL;

	a = 0;
	PRINT1(d, a);
	PRINT1(d, !a);
	PRINT1(d, !!a);
	PRINT1(d, !!!!!!!!!!!!!a);

	//  Operadores Mas unario ( + ) y Menos unario ( - )
	a = -3;
	b = +3;
	PRINT2(d, a, b);
	PRINT2(+d, a, b);

	// operador complemento a 1 ( ~ ) 
	a = 7;
	PRINT2(d, a, ~a);

	// Operador incremento ( ++ ) y decremento ( -- ) en uno
	a = 10;
	a++;
	PRINT1(d, a);
	a = 10;
	a--;
	PRINT1(d, a);
	a = 10;
	++a;
	PRINT1(d, a);
	a = 10;
	--a;
	PRINT1(d, a);

	a = 10;
	PRINT1(d, a++);
	PRINT1(d, a);

	a = 10;
	PRINT1(d, ++a);
	PRINT1(d, a);

	a = 10;
	b = 10;
	PRINT1(d, a++ + b); 
	PRINT2(d, a, b);

	a = 10;
	b = 10;
	PRINT1(d, a++ + ++b); 
	PRINT2(d, a, b);

	a = 5; b = 8; c = 0;
	d = a++ + b-- + !c;
	PRINT1(d, d);
	PRINT4(d, a,b,c,d);
	
	// Operador "Tama�o de..." ( sizeof )
	printf("El tama�o de del tipo char es %d bytes.\n", sizeof(char));
	printf("El tama�o de del tipo int es %d bytes.\n", sizeof(int));
	printf("El tama�o de del tipo float es %d bytes.\n", sizeof(float));
	printf("El tama�o de del tipo double es %d bytes.\n", sizeof(double));
	printf("El tama�o de del arreglo es %d bytes.\n", sizeof(arreglo));
	printf("El tama�o de del arreglo[5] es %d bytes.\n", sizeof(arreglo[5]));
	printf("El tama�o de la struct Persona es %d bytes.\n", sizeof(struct Persona));
	printf("El tama�o de la variable Juanito es %d bytes.\n", sizeof(juanito));
	printf("El tama�o de del apuntador ptrJuanito es %d bytes.\n", sizeof(ptrJuanito));

	//  Operador direccion (de memoria) de... ( & ) - unario
	
	a = 50;
	ptr = &a;		//  LA direcci�n de memoria de a
	PRINT1(p, &a);
	PRINT1(p, ptr);

	juanito.edad = 25;				//  Acceder a los campos de una estructura
	ptrJuanito = &juanito;
	PRINT1(p, &juanito);
	PRINT1(p, ptrJuanito);

	// Operador indirecci�n ( Contenido de la direcci�n...) ( * )

	PRINT1(d, *ptr);
	PRINT1(d, juanito.edad);
	PRINT1(d, ptrJuanito->edad);

	a = 10;
	ptr = &a;
	PRINT1(d, ++(*ptr));

	// Operador Cast (Convertir...) ( (tipo Dato) )
	
	//  Promoci�n de tipos: char -> int -> float -> double
	car = 'H';
	a = car;
	e = a;
	h = e;

	// degradaci�n de tipos: double -> float - int -> char
	h = 3.1415924585;
	e = h;
	a = e;
	car = a;

	//  CAsting: Conversi�n de tipos:
	car = 'h';
	a = (int) car;
	e = (float) a;
	h = (double) e;


	system("pause");
}