#pragma once

#include"Dictionary.h"

#define TEST_CREATE_01(x)	( (x) >= (DICTNAMEMAXSIZE) ) ? 1:0
#define TEST_CREATE_02(x)	( (x) > (DICTMAXSIZE) ) ? 1:0
#define TEST_ADDENTRY_03(x,y)	( (x) > (y) ) ? 1:0
#define TEST_ADDENTRY_04(x,y)	( (x) == (y)) ? 1:0
#define	TEST_GETENTRY_05 1
#define	TEST_GETENTRY_06 1
#define	TEST_UPDENTRY_07 1
#define	TEST_UPDENTRY_08(y,x,z)	( (y) != (x) && (x) == (z) ) ? 1:0

