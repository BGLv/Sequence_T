#pragma once
// store.h
// 26/7/98
// Stores records and references them by key address pair records
// Ken Brownsey

#include "data.h"

typedef struct {
	Key_T	Key;
	DataRec_T *Address;
} KAPRec_T;

// PRE	TRUE
// POST	RETURNS a key adddress pair record with key that of record and
//			address that of location where record is stored
KAPRec_T
MakeKAPRec(DataRec_T Rec);


// PRE	TRUE
// POST	RETURNS key value of KAPRec
Key_T
Get_KAPRecKey(KAPRec_T KAPRec);



// PRE	TRUE
// POST	RETURNS record stored at address value of KAPRec
DataRec_T
Get_DataRec(KAPRec_T KAPRec);


// PRE	TRUE
// POST	Memory taken up by record referenced
//			by address attribute is freed up
void
Free_RecMemory(KAPRec_T KAPRec);




