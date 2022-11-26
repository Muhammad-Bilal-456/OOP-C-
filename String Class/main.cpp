#include"MyString.h"
#include<iostream>
using namespace std;
int main() {

	int n = 0;
	
	do {
		
		do {
			
			//Display Menu
			cout << "\n----------------------- Press ---------------------\n\n";
			cout << "1 for Display String\n";
			cout << "2 for Display Sub-String from a String\n";
			cout << "3 for find index Occurence of Sub-String in a String\n";
			cout << "4 for find index Occurence of Character  in a String\n";
			cout << "5 for string to  int  conversion\n";
			cout << "6 for string to char* conversion\n";
			cout << "7 for Operators Overloading\n";
			cout << "0 for Exit\n___________________________________________________\n\n";
			cin >> n;
                        system("cls");
		
		}
		while (n < 0 || n>7);
	
		if (n != 0) {

			//default constructor
			MyString obj;

			//character Array
			char ch[100] = { 'a','b','c','d','9','g','c','d','9','d','c','d','9' };

			//set Data member of instance
			obj.setStr(ch);

			//parameterized constructor
			MyString obj1 = MyString(ch);

			//Copy Constructor
			MyString obj2 = MyString(obj1);

			//making Sub-String from String
			obj2 = obj1.subString(2, 4);

			if (n != 7) {

				//display string
				cout << "\nString is : ";
				obj1.display();
				//display length of a string
				cout << "\nLength of string is : ";
				cout << obj1.getLength() << endl;

			}

			if (n == 2) {
			
				//Display Sub-String indexes in a string
				cout << "Starting index of Sub-String in a String is : 2\n";
				cout << "Ending   index of Sub-String in a String is : 4\n";
				//display sub string
				cout << "\n*** Sub-String is : ";
				obj2.display();
				//display length of sub string
				cout << "\n*** Length of sub string is : ";
				cout << obj2.getLength() << endl;

			}

			if (n == 3)
			{
				//display sub string
				cout << "Sub-String is : ";
				obj2.display();
				//display length of sub string
				cout << "\nLength of sub string is : ";
				cout << obj2.getLength() << "\n";

				//returns index of first occurence of substring in the string
				cout << "\n*** Index of start occurence of substring in the string : " << obj1.find(obj2);

				//returns index of first occurence of substring in the string after index 'start'
				cout << "\n*** Index of start occurence of substring in the string after index 'start' : " << obj1.find(obj2, 2);

				//returns index of last occurence of substring in the string 
				cout << "\n*** Index of last  occurence of substring in the string : " << obj1.rfind(obj2) << "\n";

			}

			if (n == 4)
			{

				cout << "Character is : c \n";
				
				//returns index of first occurence of char in the string
				cout << "\n*** Index of start occurence of char in the string : " << obj1.find('c');

				//returns index of last occurence of char in the string
				cout << "\n*** Index of last  occurence of char in the string : " << obj1.rfind('c') << "\n";

			}

			if (n == 5)
			{

				//conversion from 'MyString' to 'int'
				int Int = obj1;
				cout << "\n*** After coversion MyString to int : " << Int << "\n";

			}

			if (n == 6) {

				//conversion from 'MyString' to 'char*' (C-style string)
				char* Char = obj;
				cout << "\n*** After conversion from 'MyString' to 'char*' (C - style string) : " << Char << "\n";

			}

			if (n == 7)
			{
				
				int check = 0;
				
				do {		
					
					do {
					
						//Display Operators-Overloading menu
						cout << "\n<<--------------------- Press -------------------->>\n\n";
						cout << "1 for Equal to             '==' operator overloading\n";
						cout << "2 for Less than             '<' operator overloading\n";
						cout << "3 for Less than or Equal to'<=' operator overloading\n";
						cout << "4 for Addition              '+' operator overloading\n";
						cout << "5 for Increment            '++' operator overloading\n";
						cout << "6 for Addition-Assignment  '+=' operator overloading\n";
						cout << "7 for Stream Extraction    '>>' operator overloading\n";
						cout << "8 for Stream Insertion     '<<' operator overloading\n";
						cout << "9 for Assignment            '=' operator overloading\n";
						cout << "0 for Exit\n____________________________________________________\n\n";
						cin >> check;
						system("cls");
					
					} while (check < 0 || check > 9);
					
					if (check != 0) {
					
						if (check == 1 || check == 2 || check == 3 || check == 4) {

							//display string
							cout << "\nString is : ";
							obj1.display();
							//display length of a string
							cout << "\nLength of string is : " << obj1.getLength();

						}

						if (check != 7 && check != 8 && check != 9) {

							//display substring
							cout << "\nSub-String is : ";
							obj2.display();
							//display length of a substring
							cout << "\nLength of Sub-String is : " << obj2.getLength() << endl;

						}

						if (check == 1) {

							//overloaded == operator
							if (obj1 == obj2)
								cout << "\n*** String and Sub string are Equal\n";
							else
								cout << "\n*** String and Sub string are not equal\n";

						}

						if (check == 2) {

							//overloading < operator
							if (obj2 < obj1)
								cout << "\n*** Sub string is less than String\n";
							else
								cout << "\n*** String is greater than or Equal to Sub String\n";

						}

						if (check == 3) {

							//overloading <= operator
							if (obj1 <= obj2)
								cout << "\n*** String is Less than or equal to Sub-String\n";
							else
								cout << "\n*** String is greater than Sub-String\n";

						}

						if (check == 4) {

							//overloaded concatenation operator
							obj = obj1 + obj2;
							cout << "\n*** After Concatenate String and Sub-String : " << obj << "\n";

						}

						if (check == 5) {

							//overloaded ++ operator
							obj = obj2;
							++obj;
							cout << "\n*** After increment in Sub-String  : " << obj << "\n";

						}

						if (check == 6) {

							//overloaded += operator
							obj = obj2;
							obj += obj;
							cout << "\n*** After Addition-Assignment (+=) operator with Sub-String : " << obj << "\n";

						}

						if (check == 7) {

							//overloading stream extraction operator as friend function 
							cout << "\n*** Overloading Stream Extraction Operator as friend function\n";
							cin >> obj;

						}

						if (check == 8) {

							//overloading stream insertion operator as friend function
							cout << "\n*** Overloading Stream Insertion Operator as friend function String is : " << obj <<"\n";

						}

						if (check == 9) {

							//overloading assignment operator
							MyString obj3;
							obj3 = obj;
							cout << "\n*** After Overloading Assignment Operator String is : " << obj3 << "\n";

						}
					}
				} while (check);
			}
		}
	} while (n);

	return 0;
}