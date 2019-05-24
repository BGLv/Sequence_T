#include "Sequence_T.h"

#define MaxElements 8

typedef struct {
	Element_T Recs[MaxElements];
	int CurrentElement,
		NumberElements;
}SeqRec_T, *SeqRec_Ptr_T;