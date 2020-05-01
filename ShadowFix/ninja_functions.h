#pragma once
#include "stdafx.h"
#include "SA2ModLoader.h"
FastcallFunctionPointer(double, njCos, (signed int a1), 0x042AC30);
//FastcallFunctionPointer(signed int, __fastcall njPushMatrix, (NJS_MATRIX_PTR a1), 0x0077FE10);
FastcallFunctionPointer(double, njSin, (signed int a1), 0x0042AAB0);
FunctionPointer(int, __cdecl njCnkDrawModel, (NJS_CNK_MODEL *a1), 0x0056E1E0);
FunctionPointer(signed int, njPushMatrixEx, (), 0x00429710);
FunctionPointer(signed int, njPopMatrixEx, (), 0x00429000);
DataPointer(float*, MatrixBase, 0x01A557FC);
void  njCalcVector(NJS_VECTOR *a1, NJS_VECTOR *a2, NJS_MATRIX_PTR a3);

const int njTranslateVPtr = 0x00428A30;
void  njTranslateV(NJS_VECTOR *a1);

const int njCnkDrawObjectPtr = 0x0056E210;
void njCnkDrawObject(NJS_OBJECT * a1);