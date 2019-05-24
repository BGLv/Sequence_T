// stu_rec.cpp
// 24/7/98
// Demo of types
// Ken Brownsey
#include "pch.h"
#include "my_const.h"
#include "iostream"
#include "rd_str.h"
#include <string.h>
#include "data.h"

#define MaxStudents 6

using namespace std;

// PRE	TRUE
// POST	user is prompted for student key value which is returned
Key_T
Read_Key() {
	StuNum_T StuNum;

	cin >> StuNum;
	return(StuNum);
}


// PRE	TRUE
// POST	key value is written to screen
void
Write_Key(Key_T Key) {

	cout << Key;
}


// PRE	TRUE
// POST	RETURNS key value of Rec
Key_T
Get_Key(StudentRec_T	StRec) {

	return(StRec.StuNum);
}


// PRE	TRUE
// POST	Prompts user for mode of study by number
//		and returns mode read in defaulting to FullTimeMod */
enum StudyMode_T
	Read_Mode() {
	int	InData;
	StudyMode_T Result;

	cout << "\nFull Time Modular please enter 1 ";
	cout << "\nPart Time Modular please enter 2 ";
	cout << "\nFull Time Non-Modular please enter 3 ";
	cout << "\nPart Time Non-Modular please enter 4 ";
	cout << "\n ====>  ";
	cin >> InData;
	switch (InData) {

	case 1:
		Result = FullTimeMod;
		break;
	case 2:
		Result = PartTimeMod;
		break;
	case 3:
		Result = FullTimeNonMod;
		break;
	case 4:
		Result = PartTimeNonMod;
		break;
	default:
		Result = FullTimeMod;
		break;
	}
	return(Result);
}


// PRE	Mode has a valid value
// POST	Prints string for Mode
void
Write_Mode(enum StudyMode_T Mode) {
	switch (Mode) {

	case FullTimeMod:
		cout << "Full Time Modular";
		break;
	case PartTimeMod:
		cout << "\nPart Time Modular";
		break;
	case FullTimeNonMod:
		cout << "\nFull Time Non-Modular";
		break;
	case PartTimeNonMod:
		cout << "\nPart Time Non-Modular";
		break;
	default:
		break;
	}
}

//	PRE	TRUE
//	POST	prompts user for student record
//			which is read into StRec
void
Read_Rec(StudentRec_T &StRec) {

	cout << "\nNumber ==> ";
	cin >> StRec.StuNum;
	cout << "\nName ==> ";
	StRec.Name = Read_String();
	cout << "\nMode of study ";
	StRec.Mode = Read_Mode();
}



//	PRE	TRUE
//	POST	writes Rec to screen
void
Write_Rec(StudentRec_T Rec) {

	cout << "\nNumber is "
		<< Rec.StuNum
		<< "\nName is  "
		<< Rec.Name
		<< "\nMode of study is ";
	Write_Mode(Rec.Mode);
	cout << "\n";
}