#include "string"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include<chrono>
#include<fstream>
#include<string>
#include<ctime>
#include <conio.h>


using namespace std;

void introduction();
////////student_login_page///////
void student_login_page();
////////manager_login_page/////////
void manager_login_page();
////////student_list////////////////////
void student_list(string);
////// student_general_info//////////
void student_general_info(string);
////////managerdashboard////////////
void managerdashboard(string);
//Enter your Student information
void Enter_student_info();
//Enter Lesson information
void Enter_lesson_info();
//See Average of all Lessons that you have already added
void see_average();
//Save your information which you have entered at previous section
void save_info();
//Load your information
void load_info();
//Show information
void show_info();
//////////////////////
void average_result();
//////////////////////
void average_lesson();
//Saving Entered informatiom about lastname, name, ID and so on;
void saving_information();
//Showing information for each student;
void showing_information();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Based class
class Lesson {

public:
	//Each Lesson has 3 parts :1-name 2-Unit 3-Mark
	string name;
	int unit;
	double mark;


};
//Derived class 
class Student {

public:
	//Each student has  three public particular features that are 1.First Name,2-Last Name,3-Identification number
	string student_name;
	string ID;
	string student_last_name;
	Lesson student_mark[100];// Array related to class <<Lesson>>
	double average;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//To get access to the Private Part of this class I have to declare two separated class
	void set_finantial() {
		cout << "How much money do you have ? (e.g. 20$) <<This will be shown only to manager even you yourself won't be able to see it again>>\n";
		double user;
		cin >> user;
		financial = user;
	}
	double get_finanatial()
	{
		return financial;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//finantial is confidential which is displayed only to Manager
private:
	double financial;

};
//It must be declared after Class otherwise it won't work
static Student student[1000];
int i;
// Declared as Global array cuz I want to use it to get the average of Lessons
int lesson_number_array[1000];//number of lessons that each student has;



	// Through this array the result of each student gets saved in specified file (It's Global because in following function I wanna save its element individually )
double  static average_results[1000];


// through this array the finantial status of student will be saved and shown only to Manager (It gets declared globally because I wanna save  it in specified file which is only shown to Manager  )
double finantial_student[1000];



int main() {
	system("cls");
	cout << endl;
	cout << endl;
	cout << "-----------------------------------Welcome to Our Login System-----------------------------------\n";
	//Gets second since January 1970
	time_t now= time(NULL);
	// Gives us system time
	char *string_now = ctime(&now);
	cout <<"                                                                                    "<<string_now << endl;
	cout << endl;
	cout << endl;
	cout << "                              Please choose your role to start with\n";
	cout << endl;
	cout << "                                         1.Manager\n";                                                                                                    
	cout << "                                         2.Student\n";
	cout << "                                         3.Log Out\n";
	
 	int inputuser;
	cin >> inputuser;
	switch (inputuser)
	{
	case 1:
		manager_login_page(); //Manager login page
		break;
	case 2:
		student_login_page();//Student login page
		break;
	case 3:
		system("pause"); 
		break;
	default:
		cout << "You've pressed Wrong key please Enter to try again\n";
		cin.ignore();
		cin.get();

	}
	return 0;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void manager_login_page() {
	system("cls");
	cout << endl;
	cout << endl;
	cout << "----------------------Welcome Manager to your dashboard----------------------\n";
	string manager_username, manager_password;
	time_t now = time(NULL);
	char*string_now = ctime(&now);
	cout << endl;
	cout << "                                                                             "<<string_now << endl;
	cout << endl;
	cout << "Please write your username and password in given space:\n";
	cout << "Username:\n";
	cin >>manager_username;
	cout << "Password:\n";
	cin >> manager_password;
	//We check whether the password and username are matched or not
	if (manager_username == "ali"&& manager_password == "1190325829")
	{
		//If the Password and username comparison was successful the user will transported to manager dashboard
		managerdashboard(manager_username);
	}
	else
	{
		cout << "Sorry, The Username or Password is wrong\n";
		//We give user another chance of trying to Log in
		cout << "To try again please press 0 or If you want to return to login page press number 1 \n ";
		int identifier;
		cin >> identifier;
		if (identifier == 0)
		{
			manager_login_page();
		}
		else if (identifier == 1)
		{
			main();
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void managerdashboard(string manager) {
	system("cls");
	cout << endl;
	cout << endl;
	cout << "           -------------------------Welcome " << manager << " ------------------------\n";
	time_t now = time(NULL);
	char *string_now = ctime(&now);
	cout << endl;
	cout << "                                                                               " << string_now << endl;
	cout << endl;
	cout << "                     Press the item number to satrt with \n";
	cout << endl;
	cout << "                         1.Studutents'information\n";
	cout << "                         2.Studutents'information with their name\n";
	cout << "                         3.Log out\n";
	int manager_input;
	cin >> manager_input;
	//Through Switch case the user will see diffrent part later
	switch (manager_input)
	{
	case 1:
		// The manager can see list of all student with their identification number
	     student_list(manager);
		break;
	case 2:
		// The Manger is able to see all details that each student has entered in advance
		 student_general_info(manager);
		break;
	case 3:
		main();
		break;
	}


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void student_login_page() {
	system("cls");
	cout << endl;
	cout << endl;
	cout << "       -----------------------Welcome to student login page-----------------------\n";
	time_t now = time(NULL);
	char *string_now = ctime(&now);
	cout << endl;
	cout << "                                                                               " << string_now << endl;
	cout << endl;
	cout << "                   Please Enter the item number that you want to start with\n";
	cout << endl;
	cout << "                           1.Enter your Student information\n";
	cout << "                           2.Enter Lesson information\n";
	cout << "                           3.See Average of all Lessons that you have already added\n";
	cout << "                           4.Save your information which you have entered at previous section \n";
	cout << "                           5.Load information\n";
	cout << "                           6.Show information\n";
	cout << "                           7.Log Out\n";
	int studentinput;
	cin >> studentinput;
	switch (studentinput) {

	case 1:
		// The student enters his/her name , last name and identification number
		Enter_student_info();
		break;
	case 2:
		// The student enters the lesson information which includes name , unit , and score out of 20
		Enter_lesson_info();
		break;
	case 3:
		// The student can see the average
		average_result();
		break;
	case 4:
		// The student saves his/her information manually
		saving_information();
		break;
	case 5:
		// The student can see his/her own information
		load_info();
		break;
	case 6:
		//This part displays student information as soon as the student has entered information by pressing key number 1
		showing_information();
		break;
	case 7:
		// Uswer can log out here
		main();
		break;
	default:
		cout << "Wrong KeyPress, Please Enter to try again\n";
		cin.ignore();
		cin.get();
		student_login_page();

	}



}
//////////////////At first we count how many student have been registered up to now///////////////////////////////////////////////////////////////
void introduction() {
	//At first we count how many student have been registered up to now
	ifstream saving_info("SAVINGINFO.text", ios::in);
	int counter = 0;
	string line;
	while (getline(saving_info, line))
	{
		counter++;
	}
	saving_info.close();
	//<<i>> is the specifier for getting and saving information in following part
	i = counter;
	// Finally we close the opened file
	

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Enter_student_info() {
	//Clearing console display
	system("cls");
	cout << "-----------------------Welcome to Entering your personal information Part-----------------------\n ";
	cout << endl;
	time_t now = time(NULL);
	char *string_now = ctime(&now);
	cout << "                                                                               " << string_now << endl;
	// Ignores the enter from user at previous dashboard
	cin.ignore();
	cout << "Plase Enter your  first name : \n";
	// Using Getline to get string (first name )
	getline(cin, student[i].student_name);
	// Using Getline to get string (family name )
	cout << "Plase Enter your family name : \n";
	getline(cin, student[i].student_last_name);
	cout << "Please enter your student identification number\n";
	// Getting identification number(e.g. 981763511 )
	cin >> student[i].ID;
	cout << endl;

	// Here I make a Class to get access to Private part of Student class 
	Student Private_part_finantial;
	Private_part_finantial.set_finantial();
	//It gets private part of Student class
	double finantial = Private_part_finantial.get_finanatial();
	//
	finantial_student[i] = finantial;
	system("cls");
	cout << "------------------------The registeration has been successful------------------------\n";
	cout << endl;
	cout << "To return to student login page press enter\n";
	// Ignoring previous Enter keypass from user
	cin.ignore();
	//The User Enters and then he/she goes to student login page >> >> >> (student_login_page())
	cin.get();
	student_login_page();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Enter_lesson_info() {
	system("cls");
	cout << "-------------------------------------Welcome to  your Entering lesson information-------------------------------------\n";
	cout << endl;
	time_t now = time(NULL);
	char *string_now = ctime(&now);
	cout << "                                                                               " << string_now << endl;
	//Asking student about intended lessons number
	cout << "How many Lessons You want to add ?\n";
	int student_lesson_input;
	//Getting number of Lessons
	cin >> student_lesson_input;
	//lesson_number_counter++;//position number in array (e.g. 0,1,2..,999)
	lesson_number_array[i] = student_lesson_input;
	// Using for loop to get lesson information
	
	for (int j = 0; j < student_lesson_input; j++)
	{
		cin.ignore();
		cout << "Please Enter your Lesson name :\n";
		// Getting lesson name
		getline(cin,student[i].student_mark[j].name);
		cout << "Please Enter the lesson unit :\n";
		// Getting lesson unit (e.g. 1,2,3,...)
		cin >> student[i].student_mark[j].unit;
		cout << "Please Enter the score that you could get from " << student[i].student_mark[j].name << ":\n";
		// Getting lesson mark (It's double)
		cin >> student[i].student_mark[j].mark;
		cout << "----------------------------------------------------------------------------------------------------------------------\n";
	}
	/////Following Function will immediately calculates the average after Ending putting lesson information///////////
	average_lesson();
	////////////////
	system("cls");
	cout << "-----------------------------------------Adding Lesson was sucessful--------------------------\n";
	cout << endl;
	cout << "Press Enter to return back to the login page\n";
	// Ignoring previous Enter keypass from user
	cin.ignore();
	//The User Enters and then he/she goes to student login page >> >> >> (student_login_page())
	cin.get();
	student_login_page();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void average_lesson() {
	///////////////////////////////The function calculates average of user's lessons/////////////////////////////////////////////
	double sum_lesson = 0;
	double averarge_lesson1 = 0;
	int total_lesson_unit = 0;
	// Using for loop to sum up all scores and units
	for (int j = 0; j < lesson_number_array[i]; j++)
	{
		sum_lesson += ((student[i].student_mark[j].unit)*(student[i].student_mark[j].mark));
		total_lesson_unit += student[i].student_mark[j].unit;
	}
	// Eventually the average will be serive from following formula
	averarge_lesson1 = sum_lesson / total_lesson_unit;
	// Assign to student[i].average
	student[i].average = averarge_lesson1;
	

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void average_result() {
	
	system("cls");
	cout << endl;
	cout << endl;
	time_t now = time(NULL);
	char *string_now = ctime(&now);
	cout << "                                                                               " << string_now << endl;
	cout << "what is your identification number\n";
	string id_student_result;
	cin >> id_student_result;
	int student_identifier;
	for (int z = 0; z < 1000; z++)
	{
		if ((id_student_result == student[z].ID))
		{
			student_identifier = z;
		}
	}
	cout << "Here is your average of " << lesson_number_array[student_identifier] << " lessons " << ":" << endl;
	cout << student[student_identifier].average << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << endl;
	cout << "Press Enter to return to student login page\n";
	cin.get();
	cin.get();
	student_login_page();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void saving_information() {
	system("cls");
	
	ofstream saving_info("SAVINGINFO.text", ios::app);//This file saves personal student information (Name,ID,Last Name)
	if (saving_info.is_open())
	{

		saving_info << student[i].student_name << " " << student[i].student_last_name << " " << student[i].ID << endl;

		saving_info.close();
	}
	//////////////////////////////////////////*THIS IS FOR MANAGER*///////////////////////////////////////////////////////////////////////////
	
	ofstream saving_info_manager("STUDENTLIST.text", ios::app);//This file saves student infoemation for manger to see all at once
	if (saving_info_manager.is_open())
	{
		saving_info_manager<<" First Name : "<< student[i].student_name<<"-/ Last Name : "<< student[i].student_last_name<<"-/ Identification Number : " << student[i].ID << endl;
		saving_info_manager << "---------------------------------------------------------------------\n";
		saving_info_manager.close();
	}
	ofstream saving_general_info_manager("GENERALINFORMATION.text", ios::app);//This file contains general information (Lesson list and personal student information)
	if (saving_general_info_manager.is_open())
	{
		saving_general_info_manager << " First Name : " << student[i].student_name << "-/ Last Name : " << student[i].student_last_name << "-/ Identification Number : " << student[i].ID << endl;
		saving_general_info_manager << endl;
		for (int a = 0; a < lesson_number_array[i]; a++)
		{
			saving_general_info_manager << " Lesson Name : "<< student[i].student_mark[a].name << " ------ Lesson Unit : " << student[i].student_mark[a].unit << " ------ Lesson Mark : " << student[i].student_mark[a].mark << endl;
			saving_general_info_manager << "\n";
		}
		saving_general_info_manager << " The Average of this student is : " << student[i].average << endl;
		saving_general_info_manager << endl;
		saving_general_info_manager << " The finantial status is "<<finantial_student[i]<<"$" << endl;
		saving_general_info_manager << "------------------------------------------------------------------------------------------\n";
		saving_general_info_manager.close();

	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ofstream saving_info_lesson("SAVINGLESSONINFO.text", ios::app);//This is for loading lesson information ;Saving Lesson information executting here 
	if (saving_info_lesson.is_open())
	{
		for (int a = 0; a < lesson_number_array[i]; a++)
		{
			saving_info_lesson << student[i].ID << " " << student[i].student_mark[a].name << " " << student[i].student_mark[a].unit << " " << student[i].student_mark[a].mark << endl;
		}
		saving_info_lesson.close();
	}
	ofstream saving_info_result("SAVINGRESULT.text", ios::app);//This is saving result which allows students to see their results at loading section
	if (saving_info_result.is_open())
	{
		saving_info_result << student[i].ID << " " << student[i].average << endl;
		saving_info_result.close();
	}
	cout << endl;
	cout << endl;
	cout << "                           ***Saving information was successful, Please Enter to return***\n";
	time_t now = time(NULL);
	char *string_now = ctime(&now);
	cout << "                                                                                                   " << string_now << endl;
	cin.ignore();
	cin.get();
	student_login_page();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void showing_information() {
	//Showing Entered information 
	system("cls");
	cout << endl;
	cout << endl;
	time_t now = time(NULL);
	char *string_now = ctime(&now);
	cout << "                                                                                                                                                                                          " << string_now << endl;
	cout << " Personal Information : \n";
	cout << endl;
	cout << " Name : " << student[i].student_name << " Last Name : " << student[i].student_last_name << " Identification No : " << student[i].ID << endl;
	cout << endl;
	cout << " ----------------------------------------------------------------------------\n";
	cout << endl;
	cout << " Here is Lessons List that You Have Entered : \n";
	for (int c = 0; c < lesson_number_array[i]; c++)
	{
		cout << " Lesson Name : " << student[i].student_mark[c].name << " -----Lesson Unit : " << student[i].student_mark[c].unit << " -----Lesson Mark : " << student[i].student_mark[c].mark << endl;
		cout << endl;
	}
	cout<< " ----------------------------------------------------------------------------\n";
	cout << " Here is the Average of All Lessons\n";
	cout << " "<<student[i].average << endl;
	
	cout << " Press Enter to back to login dashboard\n";
	cin.ignore();
	cin.get();
	student_login_page();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Loading {
	/*This Structure has 3 parts :
	1.First_Name
	2.Family_Name
	3.identification_number
	*/
	string Loading_First_Name;
	string Loading_Family_Name;
	string Loading_identification_number;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void load_info() {
	system("cls");
	Loading load[1000];// structure Array 
	int line_getter = 0;/* Using to determine the postion of each element in Laod array (e.g. 0 , 1 , ..., 999)*/
	ifstream saving_info("SAVINGINFO.text", ios::in);

	string First_name_Getter, second_last_name_Getter, third_identification_getter;
	// We define a source to lines in file
	ifstream source_checking_line1("SAVINGINFO.text");
	// We insert First_name_Getter, second_last_name_Getter, third_identification_getter into structure array
	while (source_checking_line1 >> First_name_Getter >> second_last_name_Getter >> third_identification_getter)
	{

		load[line_getter].Loading_First_Name = First_name_Getter;
		load[line_getter].Loading_Family_Name = second_last_name_Getter;
		load[line_getter].Loading_identification_number = third_identification_getter;
		line_getter++;
	}
	string User_identification_number_for_loading;
	// We ask user to Enter  his/her identification number 
	cout << endl;
	cout << "Please Enter your identification number : \n";
	cin >> User_identification_number_for_loading;
	int times = 0;
	int identifier = 0;
	bool identification_checker = 1;
	while (times<line_getter)
	{

		// When identification number matches with data base the nex condition will  be executed
		if (User_identification_number_for_loading == load[times].Loading_identification_number)
		{
			identifier = times;
			identification_checker = 0;
			break;
		}
		times++;
	}
	// If user identification number is not compatible with saved file data
	if (identification_checker==1)
	{
		system("cls");
		cout << endl;
		cout << "According to our data base there is no identical identification number with yours \n";
		cout << "\n";
		cout << "If you want to try again please enter number 1 otherwise press Zero\n";
		int user_input_loading;
		cin >> user_input_loading;
		switch (user_input_loading)
		{
		case 1:
			load_info();
			break;
		case 0:
			student_login_page();
			break;
		}
	}
	system("cls");
	cout << endl;
	cout << "information about you\n";
	cout << endl;
	cout << "Name : " << load[identifier].Loading_First_Name << " ------- " << " Family Name : " << load[identifier].Loading_Family_Name << " ------- " << " ID : " << load[identifier].Loading_identification_number << endl;



	cout << "-----------------------------------------------------------------\n";
	ifstream saving_info_lesson("SAVINGLESSONINFO.text", ios::in);//Read from lesson information file
	ifstream source_checking_line2("SAVINGLESSONINFO.text");// Read from lesson  information file as source to make comparisopn
	string first_checking_line2,second_checking_line2,third_checking_line2,forth_checking_line2;
	string line;
	cout << "Here is your lesson report : \n";
	cout << endl;
	while (source_checking_line2>>first_checking_line2>>second_checking_line2>>third_checking_line2>>forth_checking_line2)
	{
		//First we check whether the identification number of user is matched with lesson data infomation or not
		if (first_checking_line2 == User_identification_number_for_loading) {
			getline(saving_info_lesson, line);
			cout <<"Lesosn Name : " << second_checking_line2 <<" -----Lesosn Unit : " << third_checking_line2<<" -----Lesosn Mark : " << forth_checking_line2<<endl;
			cout << endl;
		}
		else if (first_checking_line2 != User_identification_number_for_loading) {
			getline(saving_info_lesson, line);
		}
	}
		cout << "-----------------------------------------------------------------\n";
	
	
	
	cout << "Here is your Average result of your lessons :\n";
	cout << endl;
	ifstream saving_info_result("SAVINGRESULT.text", ios::in);//Read from result file
	string checking_line3, checking_second_line3,printing_line3;
	ifstream source_checking3("SAVINGRESULT.text");
	while (source_checking3>>checking_line3>>checking_second_line3)
	{
		if (checking_line3==User_identification_number_for_loading)
		{
			getline(saving_info_result, printing_line3);
			cout << " "<<checking_second_line3 <<" out of 20"<< endl;
			cout << endl;
		}
		getline(saving_info_result, printing_line3);
	}



	cout << "-----------------------------------------------------------------------\n";
	cout << "Press Enter to return back to the dashboard\n";
	cin.get();
	cin.get();
	student_login_page();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void student_list( string manager) {
	/*Reading file for manager Contains identification Number and first name and last name */
	system("cls");
	ifstream saving_info_manager("STUDENTLIST.text", ios::in);
	string Reading_line;
	cout << endl;
	while (getline(saving_info_manager, Reading_line))
	{
		cout << Reading_line << endl;
	}
	cout << endl;
	cout << "Enter to return back to manager dashboard\n";
	cin.get();
	cin.get();
	managerdashboard(manager);


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void student_general_info(string manager) {
	/*Reading file for manager which contains lesson information */
	system("cls");
	ifstream saving_general_info_manager("GENERALINFORMATION.text", ios::in);
	string Reading_line;
	cout << endl;
	while (getline(saving_general_info_manager, Reading_line))
	{
		cout << Reading_line << endl;
	}
	cout << endl;
	cout << "Enter to return back to manager dashboard\n";
	cin.get();
	cin.get();
	managerdashboard(manager);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////




