#include "stdafx.h"
#include "ninja_functions.h"
void  njCalcVector(NJS_VECTOR *a1, NJS_VECTOR *a2, NJS_MATRIX_PTR a3)
{
	Float v3; // ST00_4
	Float v4; // ST04_4

	v3 = a3[M10] * a1->x + a3[M11] * a1->y + a3[M12] * a1->z;
	v4 = a3[M20] * a1->x + a3[M21] * a1->y + a3[M22] * a1->z;
	a2->x = a3[M01] * a1->y + *a3 * a1->x + a3[M02] * a1->z;
	a2->y = v3;
	a2->z = v4;
}


void  njTranslateV(NJS_VECTOR *a1)
{
	__asm
	{
		mov eax, a1
		call njTranslateVPtr
	}
}
void njCnkDrawObject(NJS_OBJECT* a1)
{
	__asm
	{
		mov esi, a1
		call njCnkDrawObjectPtr
	}
}