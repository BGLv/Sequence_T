#pragma once
// stu_rec.h
// 24/7/98
// Demo of types
// Ken Brownsey

typedef enum	StudyMode_T { FullTimeMod, PartTimeMod, FullTimeNonMod, PartTimeNonMod };

typedef int StuNum_T;
typedef char *Name_T;
typedef StuNum_T Key_T;

typedef struct {
	StuNum_T	StuNum;
	Name_T Name;
	enum 	StudyMode_T Mode;
} StudentRec_T;

typedef StudentRec_T DataRec_T;

// PRE	TRUE
// POST	user is prompted for student key value which is returned
Key_T
Read_Key();


// PRE	TRUE
// POST	key value is written to screen
void
Write_Key(Key_T Key);


// PRE	TRUE
// POST	RETURNS key value of Rec
Key_T
Get_Key(StudentRec_T	StRec);


/*	PRE	TRUE */
/*	POST	prompts user for student record
			which is read into StRec */
void
Read_Rec(StudentRec_T &StRec);


/*	PRE	TRUE */
/*	POST	writes Rec to screen */
void
Write_Rec(StudentRec_T Rec);
