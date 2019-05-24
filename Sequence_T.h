#pragma once
//PRE TRUE
//POST RETURNS initialized sequence SEQUENCE_T
Sequence_T Create_Sequence();

//PRE TRUE
//POST IF sequence (Sequence) is full
//		THEN return TRUE
//		ELSE return FALSE
BOOLEAN Q_Full(Sequence_T Sequence);

//PRE TRUE
//POST IF sequence (Sequence) is empty
//		THEN return TRUE
//		ELSE return FALSE
BOOLEAN Q_Empty(Sequence_T Sequence);

//PRE NOT Q_Empty(Sequence)
//POST IF current element is last element of Sequence
//		THEN RETURN TRUE
//		ELSE RETURN FALSE
BOOLEAN Q_At_End(Sequence_T Sequence);

//PRE NOT Q_Empty(Sequence)
//POST first element of Sequence become current
void Go_To_Head(Sequence_T Sequence);

//PRE NOT Q_Empty(Sequence) AND NOT Q_At_End(Sequence)
//POST the next element to current element in sequence become the current element of Sequence'
void Go_To_Next(Sequence_T Sequence);

//PRE NOT Q_Empty(Sequence)
//POST RETURNS current element of Sequence
Element_T Get_Current(Sequence_T Sequence);

//PRE TRUE
//POST Sequence' = Sequence with  NewRec inside
//AND IF Q_Empty(Sequence) THEN current element of Sequence' become his first element
//ELSE NewRec become next element to current element of Sequence'
void Append_After_Current(Element_T NewRec, Sequence_T Sequence);


//PRE NOT Q_Empty(Sequence)
//POST Sequence' = Sequence  with  NewRec inside
// AND NewRec become before to current in Sequence' 
void Insert_Before_Current(Element_T NewRec, Sequence_T Sequence);

//PRE NOT Q_Empty(Sequence)
//POST Sequence'= Sequence with deleted current element
//AND IF NOT (Q_Empty(Sequence'))
//the first element of Sequence' become the current
void Delete_Current(Sequence_T Sequence);

//PRE Q_Empty(Sequence)
//POST freed memory allocated for Sequence
//NOTE: for next use of Secuence we must reinitialize it by Create_Sequence()
void Free_Sequence(Sequence_T Sequence);