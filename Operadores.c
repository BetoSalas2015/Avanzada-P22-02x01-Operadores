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
	// Jeraqu?a nivel 1 - Operadores Primarios

	//  Operador llama a funci?n ( () )
	bases();		// Invocar a funci?n

	NL;
	PRINT1(f, 5.0 / 9 * 80 - 32);		//  Error
	PRINT1(f, 5.0 / 9 * (80 - 32) );	//  Correcto!
	PRINT1(d, (2 + 2) - (3 + 3) );		// Asociatividad

	//  Operador ?ndice de Arreglo ( [] )
	PR(d,arreglo[5]); NL;

	//  Operador Punto ( . )
	juanito.edad = 25;				//  Acceder a los campos de una estructura

	//  Operdor Flecha ( -> )
	ptrJuanito = &juanito;
	ptrJuanito->edad = 26;
}
void unarios() 
{
	//  Jerarqu?a nivel 2 - Operadores Unarios

	// Operador negaci?n l?gica ( ! )
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
	
	// Operador "Tama?o de..." ( sizeof )
	printf("El tama?o de del tipo char es %d bytes.\n", sizeof(char));
	printf("El tama?o de del tipo int es %d bytes.\n", sizeof(int));
	printf("El tama?o de del tipo float es %d bytes.\n", sizeof(float));
	printf("El tama?o de del tipo double es %d bytes.\n", sizeof(double));
	printf("El tama?o de del arreglo es %d bytes.\n", sizeof(arreglo));
	printf("El tama?o de del arreglo[5] es %d bytes.\n", sizeof(arreglo[5]));
	printf("El tama?o de la struct Persona es %d bytes.\n", sizeof(struct Persona));
	printf("El tama?o de la variable Juanito es %d bytes.\n", sizeof(juanito));
	printf("El tama?o de del apuntador ptrJuanito es %d bytes.\n", sizeof(ptrJuanito));

	//  Operador direccion (de memoria) de... ( & ) - unario
	
	a = 50;
	ptr = &a;		//  LA direcci?n de memoria de a
	PRINT1(p, &a);
	PRINT1(p, ptr);

	juanito.edad = 25;				//  Acceder a los campos de una estructura
	ptrJuanito = &juanito;
	PRINT1(p, &juanito);
	PRINT1(p, ptrJuanito);

	// Operador indirecci?n ( Contenido de la direcci?n...) ( * )

	PRINT1(d, *ptr);
	PRINT1(d, juanito.edad);
	PRINT1(d, ptrJuanito->edad);

	a = 10;
	ptr = &a;
	PRINT1(d, ++(*ptr));

	// Operador Cast (Convertir...) ( (tipo Dato) )
	
	//  Promoci?n de tipos: char -> int -> float -> double
	car = 'H';
	a = car;
	e = a;
	h = e;

	// degradaci?n de tipos: double -> float - int -> char
	h = 3.1415924585;
	e = h;
	a = e;
	car = a;

	//  Casting: Conversi?n de tipos:
	car = 'h';
	a = (int) car;
	e = (float) a;
	h = (double) e;

	PRINT1(d, 5 / 2);
	PRINT1(f,  5 / (float) 2);

}
void multiplicativos() 
{
	//  Jerarqu?a nivel 3 - Operadores Multiplicativos
	//  Operadir multiplicaci?n ( * ) -  Binario
	PRINT1(d, 5 * 3);

	//  Operador divisi?n ( / ) 
	PRINT1(d, 5 / 2);		// Divisi?n entera: Entero / entero  = Entero
	PRINT1(f, 5.0 / 2);		// Divisi?n flotante
	PRINT1(f, 5 / 2.0 );
	PRINT1(f, 5.0 / 2.0 );

	// Operador M?dulo o Residuo de la divisi?n ( % )
	PRINT1(d, 370 % 500);
	// PRINT1(d, 1750.0 % 500);   Error!!! no pueden ser flotantes


}
void aditivos() 
{	
	//  Jerarqu?a nivel 4 - Operadores aditivos
	//  Operador suma ( + ) - Binaria
	PRINT1(d, 50 + 300);

	//  Operador resta ( - ) - Binaria
	PRINT1(d, 50 - 300);
}
void desplazamiento() 
{
	//  Jerarqu?a nivel 5 - Desplazamiento 
	//  Operador desplazamiento a la izquierda ( << ) 
	PRINT1(d, 25 << 1);
	PRINT1(d, 25 << 2);
	PRINT1(d, 25 << 3);
	PRINT1(d, 25 << 5);

	//  Operador desplazamiento a la derecha ( >> ) 
	PRINT1(d, 800 >> 1);
	PRINT1(d, 800 >> 2);
	PRINT1(d, 800 >> 3);
	PRINT1(d, 800 >> 5);

	PRINT1(d, 25 >> 1);
}
void relacionales() 
{
	//  Jerarqu?a nivel 6 - Relacionales
	PRINT1(d, 5 > 2);
	PRINT1(d, 5 >= 2);
	PRINT1(d, 5 < 2);
	PRINT1(d, 5 <= 2);

	a = 0;
	PRINT1(d, (!5 > a++) );
	a = 0;
	PRINT1(d, (!5 > ++a) );
	a = 0;
	PRINT1(d, (!!5 > a++) );
}
void igualdad() 
{
	//  Jerarqu?a nivel 7 - Igualdad
	// Operador Igual que  ( == ) y diferente de ( != )
	a = 20;
	b = 30;

	PRINT2(d, a, b);
	PRINT1(d, a == b);
	PRINT1(d, a != b);

	PRINT2(d, a, b);
	PRINT1(d, !a == !b);
	PRINT1(d, !a++ != !b--);
}
void deBits() 
{
	//  Jerarqu?a nivel 8 - AND de Bits ( & ) - Binaria
	PRINT1(d, 13 & 19);
	PRINT1(d, 35 & 18);

	//  Jerarqu?a nivel 9 - OR de Bits ( | ) 
	PRINT1(d, 13 | 19);
	PRINT1(d, 35 | 18);

	//  Jerarqu?a nivel 10 - XOR de Bits ( ^ ) 
	PRINT1(d, 13 ^ 19);
	PRINT1(d, 35 ^ 18);


	a = 15; b = 35;
	PRINT1(d, !a | b++);
	PRINT2(d, a, b);
	PRINT1(d, a++ ^ --b);
}
void logicos() {
	// Operadores l?gicos
	//  Jerarqu?a nivel 11 - AND l?gico ( && )
	PRINT1(d, 35 && 15);
	PRINT1(d, 0 && 15);

	//  Jerarqu?a nivel 12 - OR l?gico ( || )
	PRINT1(d, 35 || 15);
	PRINT1(d, 0 || 15);

	a = 5; b = 0; c = 2;
	PRINT1(d, a && b || c);
	PRINT1(d, a || b && c);
	PRINT1(d, a++ && b++ || c++);
	PRINT3(d, a, b, c);

	a = 0; b = 5; c = 2;
	PRINT3(d, a, b, c);
	PRINT1(d, (a++ == 1) && (b++ == 4) || (c++ != 3) );
	PRINT3(d, a, b, c);
}

void condicional()
{
	//  Jerarqu?a nivel 13 - Condicional ( ?: ) - Ternario
	// if( condici?n ) verdadero : falso;  
	a = 20;
	b = 10;
	( a < 10 ) ? PRINT1(d, a) : PRINT1(d, b);

	c = ( a % 2 ) ? a : b;
	PRINT1(d, c);
}

void asignacion() 
{
	//  Jerarqu?a nivel 14 - Asignaci?n 
	//  Asignacion simple ( = ) 
	a = 10;
	b = a * 10;

	a = b = c = d = 20;		// Asignaci?n m?ltiple
	PRINT4(d, a, b, c, d);

	// Asignaci?n Compuesta ( _= )
	a = 10;
	PRINT1(d, a);
	PRINT1(d, a += 5);
	PRINT1(d, a -= 5);
	PRINT1(d, a *= 5);
	PRINT1(d, a /= 5);
	PRINT1(d, a %= 7);
	PRINT1(d, a <<= 5);
	PRINT1(d, a >>= 5);
	PRINT1(d, a &= 5);
	PRINT1(d, a |= 5);
	PRINT1(d, a ^= 5);

	//  Tres maneras de hacer lo mismo:  Sumar o restar 1
	PRINT3(d, a = a + 1, a += 1, a++);

	//  Dos maneras de hacer lo mismo:
	PRINT2(d, a = a + 5, a += 5);

	a = b = c = 2;
	d = a -= b += c *= 2;
	PRINT4(d, a, b, c, d);
}
void coma() 
{
	//  Jerarqu?a nivel 15 - Coma ( , )
	int a, b, c, d;
	printf("%d\n", a);
}
int main()
{
    //  Ejercicios:
	a = 3;  b = 3; c = 0; d = -1; e = 3; f = 2;

	PRINT1(d, a*=2*a*++b );
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);

	PRINT1(d, b=++b+b++);
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);

	a = 3;  b = 3; c = 0; d = -1; e = 3; f = 2;

	PRINT1(f, e/=d+d++ );
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);
	
	PRINT1(d, d=d?d--:d++ );
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);
	
	a = 3;  b = 3; c = 0; d = -1; e = 3; f = 2;
	
	PRINT1(d, !a+!b+(d&&c) );
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);
	
	PRINT1(d , d=(a||b)&&!(c||(d &&!f)));
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);
	
	a = 3;  b = 3; c = 0; d = -1; e = 3; f = 2;
	
	PRINT1(d ,  a%b*c-d++ );
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);
	
	a = 3;  b = 3; c = 3; d = -1; e = 3; f = 2;
	
	PRINT1(d ,  a>>=b--&&c<<a );
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);
	
	a = 3;  b = 3; c = 0; d = -1; e = 3; f = 2;
	
	PRINT1(d ,  a &= b-- && (c <<= a & d) );
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);
	
	a = 3;  b = 3; c = 0; d = -1; e = 3; f = 2;
	
	PRINT1(d ,  a = b <<= sizeof (int) / b );
	PRINT4(d, a, b, c, d); PRINT2(f, e, f);
	
	system("pause");
}