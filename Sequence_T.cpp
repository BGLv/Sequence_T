#include "Sequence_T.h"

#define MaxElements 8

typedef struct {
	Element_T Recs[MaxElements];
	int CurrentElement,
		NumberElements;
}SeqRec_T, *SeqRec_Ptr_T;

Sequence_T Create_Sequence()
{
	SeqRec_Ptr_T NewSeq;

	NewSeq = new SeqRec_T;
	NewSeq->NumberElements = 0;
	return((Sequence_T)NewSeq);
}

BOOLEAN Q_Full(Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;

	Seq = (SeqRec_Ptr_T)Sequence;
	return(Seq->NumberElements == MaxElements);
}

BOOLEAN Q_Empty(Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;
	Seq = (SeqRec_Ptr_T)Sequence;
	return (0 == Seq->NumberElements);
}

BOOLEAN Q_At_End(Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;

	Seq = (SeqRec_Ptr_T)Sequence;
	if (Seq->CurrentElement == Seq->NumberElements - 1)
		return TRUE;
	else
		return FALSE;
}

void Go_To_Head(Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;

	Seq = (SeqRec_Ptr_T)Sequence;
	Seq->CurrentElement = 0;
}

void Go_To_Next(Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;
	Seq = (SeqRec_Ptr_T)Sequence;
	Seq->CurrentElement++;
}

Element_T Get_Current(Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;

	Seq = (SeqRec_Ptr_T)Sequence;
	return Seq->Recs[Seq->CurrentElement];
}

//I thinc it is error here because if we try append in full Sequence we will get out of range error
void Append_After_Current(Element_T NewRec, Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;
	int Index;

	Seq = (SeqRec_Ptr_T)Sequence;
	if (Q_Empty(Seq)) {
		Seq->CurrentElement = 0;
		Seq->NumberElements = 1;
		Seq->Recs[0] = NewRec;
	}
	else {
		for (Index = Seq->NumberElements - 1;
			Index > Seq->CurrentElement;
			Index--) {
			Seq->Recs[Index + 1] = Seq->Recs[Index];
		}
		// Index = Seq->CurrentElement
		Seq->Recs[Seq->CurrentElement + 1] = NewRec;
		(Seq->NumberElements)++;
	}
}

void Insert_Before_Current(Element_T NewRec, Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;
	int Index;

	Seq = (SeqRec_Ptr_T)Sequence;
	if (Q_Empty(Seq)) {
		Seq->CurrentElement = 0;
		Seq->NumberElements = 1;
		Seq->Recs[0] = NewRec;
	}
	else {
		for (Index = 0;
			Index < Seq->CurrentElement;
			Index++) {
			Seq->Recs[Index - 1] = Seq->Recs[Index];
		}
		// Index = Seq->CurrentElement
		Seq->Recs[Seq->CurrentElement - 1] = NewRec;
		(Seq->NumberElements)++;
	}
}

void Delete_Current(Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;

	Seq = (SeqRec_Ptr_T)Sequence;
	
	for (int Index = Seq->NumberElements - 1; Index >= Seq->CurrentElement; Index--) {
		Seq->Recs[Index] = Seq->Recs[Index + 1];
	}
	Seq->NumberElements--;
}

void Free_Sequence(Sequence_T Sequence)
{
	SeqRec_Ptr_T Seq;

	Seq = (SeqRec_Ptr_T)Sequence;
	delete(Seq);
}
