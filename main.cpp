#include "pch.h"
#include <iostream>
#include "Sequence_T.h"

typedef Sequence_T StudentDB_T;
using namespace std;


// PRE	TRUE
// POST	IF Q_Empty(DB)
//				Message to say so
//			ELSE
//				Message to say not empty
void
Test_Empty(StudentDB_T DB) {
	if (Q_Empty(DB)) {
		cout << "\nDatabase is empty\n";
	}
	else {
		cout << "\nDatabase is not empty\n";
	}
}


// PRE	TRUE
// POST	IF Q_Full(DB)
//				Message to say so
//			ELSE
//				Message to say not empty
void
Test_Full(StudentDB_T DB) {
	if (Q_Full(DB)) {
		cout << "\nDatabase is full\n";
	}
	else {
		cout << "\nDatabase is not full\n";
	}
}


// PRE	TRUE
// POST	IF NOT Q_Empty(DB)
//				IF Q_At_End(DB)
//					Message to say so
//				ELSE
//					Message to say not at end
//			ELSE
//				Message to say empty
void
Test_End(StudentDB_T DB) {
	if (!Q_Empty(DB)) {
		if (Q_At_End(DB)) {
			cout << "\nAt end of database\n";
		}
		else {
			cout << "\nNot at end of database\n";
		}
	}
	else {
		cout << "\nDatabase is empty\n";
	}
}



// PRE	TRUE
// POST  IF NOT Q_Full(DataBase) THEN
//				user is prompted for new record NewRec
//				DataBase' = Append_After_Current(NewRec, DataBase)
//			ELSE appropriate message
void
Put_AfterCurrent(StudentDB_T DataBase) {
	DataRec_T	NewRec;
	KAPRec_T		KAPRec;

	if (Q_Full(DataBase)) {
		cout << "Database is full";
	}
	else {
		cout << "Please type in new record\n";
		Read_Rec(NewRec);
		KAPRec = MakeKAPRec(NewRec);
		Append_After_Current(KAPRec, DataBase);
	}
}


// PRE	TRUE
// POST  IF NOT Q_Full(DataBase) THEN
//				user is prompted for new record NewRec
//				DataBase' = Insert_Before_Current(NewRec, DataBase)
//			ELSE appropriate message
void
Put_BeforeCurrent(StudentDB_T DataBase) {
	DataRec_T	NewRec;
	KAPRec_T		KAPRec;

	if (Q_Full(DataBase)) {
		cout << "Database is full";
	}
	else {
		if (Q_Empty(DataBase)) {
			cout << "Database is empty";
		}
		else {
			cout << "Please type in new record\n";
			Read_Rec(NewRec);
			KAPRec = MakeKAPRec(NewRec);
			Insert_Before_Current(KAPRec, DataBase);
		}
	}
}


// PRE	TRUE
// POST  IF NOT Q_Empty(DataBase) THEN
//				DataBase' = Delete_Current(DataBase)
//			ELSE appropriate message
void
Remove_Current(StudentDB_T DataBase) {

	if (Q_Empty(DataBase)) {
		cout << "Database is empty";
	}
	else {
		//		Free_RecMemory(Get_Current(DataBase));
		//		Restore after completing exercise
		Delete_Current(DataBase);
	}
}


// PRE	TRUE
// POST  IF NOT Q_Empty(DataBase) THEN
//				current element is printed to screen
//			ELSE appropriate message
void
Print_Current(StudentDB_T DataBase) {

	if (Q_Empty(DataBase)) {
		cout << "Database is empty";
	}
	else {
		Write_Rec(Get_DataRec(Get_Current(DataBase)));
	}
}


// PRE	TRUE
// POST  IF NOT Q_Empty(DataBase) AND NOT Q_At_End(DataBase)
//				DataBase' = Go_To_Next(DataBase)
//			ELSE appropriate message
void
Move_Forward(StudentDB_T DataBase) {

	if (Q_Empty(DataBase)) {
		cout << "Database is empty";
	}
	else {
		if (Q_At_End(DataBase)) {
			cout << "At end of database";
		}
		else {
			Go_To_Next(DataBase);
		}
	}
}


// PRE	TRUE
// POST  IF NOT Q_Empty(DataBase)
//				DataBase' = Go_To_Head(DataBase)
//			ELSE appropriate message
void
Move_ToHead(StudentDB_T DataBase) {

	if (Q_Empty(DataBase)) {
		cout << "Database is empty";
	}
	else {
		Go_To_Head(DataBase);
	}
}



// PRE	NOT Q_Empty_Sequence(DataBase)
// POST  RETURNS number of elements in DataBase
//			AND Q_At_End(DataBase')
// NOTES	this is a function with side effects
int
Find_Size(StudentDB_T DB) {

	int	Size;

	Go_To_Head(DB);
	for (Size = 1; !Q_At_End(DB); Size++) {
		Go_To_Next(DB);
	}
	return(Size);
}


// PRE	TRUE
// IF Q_Empty(DB) THEN
//		appropriate message
//	ELSE prints out number of elements in DB
//			AND DB' = Go_To_Head(DB)
void
Print_Size(StudentDB_T DB) {

	if (Q_Empty(DB)) {
		cout << "\nEmpty database - 0 records\n";
	}
	else {
		cout << "\nNumber of elements is "
			<< Find_Size(DB)
			<< "\n";
	}
}

//	PRE	TRUE
// POST	IF there exists an element of DBase such that
//			Get_KAPRecKey(El) = Key
//				El = Get_Current(DB)
//				AND RETURNS TRUE
//			ELSE
//				IF NOT Q_Empty(DB)
//					Q_At_End(DB)
//					AND RETURNS FALSE
BOOLEAN
Q_Present(Key_T Key, StudentDB_T DB) {
	BOOLEAN	Q_Found;

	if (Q_Empty(DB)) {
		return(FALSE);
	}
	else {
		Go_To_Head(DB);
		Q_Found = FALSE;
		for (; !Q_At_End(DB) && !Q_Found;) {
			if (Get_KAPRecKey(Get_Current(DB)) == Key) {
				Q_Found = TRUE;
				// NOT Q_At_End(DB)
			}
			else {
				Go_To_Next(DB);
			}
		}
		//	EITHER	Q_Found AND Get_KAPRecKey(Get_Current(DB)) = Key
		//	OR       Q_At_End(DB) AND Get_KAPRecKey(Get_Current(DB)) = Key
		//	OR			Q_At_End(DB) AND Get_KAPRecKey(Get_Current(DB)) <> Key
		return(Get_KAPRecKey(Get_Current(DB)) == Key);
	}
}


// PRE	TRUE
// POST	User is prompted for Key value Key
// 		IF there exists an element of DBase such that
//			Get_KAPRecKey(El) = Key
//				El = Get_Current(DB)
//				AND prints appropriate message
//			ELSE
//				IF NOT Q_Empty(DB)
//					Q_At_End(DB)
//				AND prints appropriate message
void
Check_Key(StudentDB_T DB) {
	Key_T	Key;

	cout << "\n\nPlease type in key value to check ==> ";
	cin >> Key;
	if (Q_Present(Key, DB)) {
		cout << "\nKey value "
			<< Key
			<< " has been located\n";
	}
	else {
		cout << "\nKey value "
			<< Key
			<< " is not in the database\n";
	}
}

//	PRE	TRUE
//	POST	IF DB is not empty all values are printed to screen
//			ELSE message to say that DB is empty
void
Print_All(StudentDB_T DB) {

	cout << "\nNow we want a function to print the lot"
		<< "\nThis does not need to make your neurones hot"
		<< "\nStart at head, go to end"
		<< "\nFrom this plan never bend"
		<< "\nBy finish be amazed at what you wot";
}


// PRE  -	TRUE
// POST -	menu displayed
void
Menu() {
	cout << "***	test to see if data base is (e)mpty *****\n"
		<< "***	test to see if data base is f(u)ll ******\n"
		<< "***	test to see if at e(n)d of data base ****\n"
		<< "***	(a)ppend a new record after current *****\n"
		<< "***	(i)nsert a new record before current ****\n"
		<< "***	(r)emove current ************************\n"
		<< "***	move current element (f)orward **********\n"
		<< "***	make current element (h)ead *************\n"
		<< "***	(p)rint current record     **************\n"
		<< "***	print (s)ize of database   **************\n"
		<< "***	(c)heck key present in database   *******\n"
		<< "***	print(t) all the database   *************\n"
		<< "***   e(x)it					      **************\n"
		<< "***   (m)enu						   **************\n";
}


// PRE	TRUE
// POST	Initialisation is done
void
Initialise(StudentDB_T &DBase) {

	DBase = Create_Sequence();
	cout << "Here we go !\n";
}


// PRE	TRUE
// POST Goes into a prompt, read and execute cycle
//		until 'x' is the character read
void
Loop(StudentDB_T DB) {

	char	Request;
	int	RequestCount;

	for (Request = 'm', RequestCount = 0; Request != 'x'; RequestCount++) {

		switch (Request) {

		case 'e':	Test_Empty(DB);
			break;
		case 'u':	Test_Full(DB);
			break;
		case 'n':	Test_End(DB);
			break;
		case 'a':	Put_AfterCurrent(DB);
			break;
		case 'i':	Put_BeforeCurrent(DB);
			break;
		case 'r':	Remove_Current(DB);
			break;
		case 'p':	Print_Current(DB);
			break;
		case 'f':	Move_Forward(DB);
			break;
		case 'h':	Move_ToHead(DB);
			break;
		case 's':	Print_Size(DB);
			break;
		case 'c':	Check_Key(DB);
			break;
		case 't':	Print_All(DB);
			break;
		case 'm': Menu();
			break;
		default:
			cout << "\n m for menu \n";
		}
		cout << "\n\nNext request ["
			<< RequestCount
			<< "] ==> ";
		cin >> Request;
	}
}


// PRE	TRUE
// POST	Clears up
void
Finalise(StudentDB_T DB) {
	//	for(;!Q_Empty(DB);) {
	//		Delete_Current(DB);
	//	}
	//	Free_Sequence(DB);
	// Reinstate this code after fixing Delete_Current
	cout << "That is it !\n";
}


void
main() {
	StudentDB_T	DataBase;

	Initialise(DataBase);
	Loop(DataBase);
	Finalise(DataBase);
}