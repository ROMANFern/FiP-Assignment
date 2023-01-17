#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

struct Item						//Structure for ITEM
{
	string itemID;
	string itemName;
	float itemPrice;
	int itemQ;
};
Item newI[100];					//Define Structure array

struct Service					//Structure for SERVICE
{
	string serviceID;
	string serviceName;
	float servicePrice;
};
Service newS[100];				//Define Structure array


//BUSINESS HEADER
void B_head() 
{
	cout << "__________________________________________________________________________________________________\n"
		<< "\t\t\t\t\tBEST AUTO PART\n\n"
		<< "\t\t\t\t337 A, Galle Road, Colombo 03\n" << endl
		<< "\t\t   Tel: 0115938812\t\t   Email: bestapcol@gmail.com\n"
		<< "__________________________________________________________________________________________________\n" << endl << endl;
}


//DECLARED FUNCTIONS
int main();


void itemList();				//Function declaration for List of items included in the application
void serviceList();				//Function declaration for List of services included in the application

void Admin_menu();				//Function declaration for Admin Main menu
void Emp_menu();				//Function declaration for Employee Main menu

void Admin_View_IS();			//Function declaration for Admin View Items/ Services Main menu
void Emp_View_IS();				//Function declaration for Employee View Items/ Services Main menu
void View_Item();				//Function declaration for View Items
void View_Service();			//Function declaration for View Services
void View_FL();					//Function declaration for View Items and Service

void Add_IS();					//Function declaration for Add Items/ Services Main menu
void Add_Item();				//Function declaration for Add Items
void Add_Service();				//Function declaration for Add Services

void Update_IS();				//Function declaration for Delete Items/ Services Main menu
void Update_Item();				//Function declaration for Delete Items
void Update_Service();			//Function declaration for Delete Services

void Admin_Search_IS();			//Function declaration for Admin Search Items/ Services Main menu
void Emp_Search_IS();			//Function declaration for Employee Search Items/ Services Main menu
void Search_Item();				//Function declaration for Search Items
void Search_Service();			//Function declaration for Search Services

void Delete_IS();				//Function declaration for Delete Items/ Services Main menu
void Delete_Item();				//Function declaration for Delete Items
void Delete_Service();			//Function declaration for Delete Services

void Admin_Exit();				//Function declaration for Admin Exit
void Emp_Exit();				//Function declaration for Employee Exit

void Admin_Logout();			//Function declaration for Admin Logout
void Emp_Logout();				//Function declaration for Employee Logout


//VIEW MENU
void View_Item()
{
	cout << "\t\t\t\t*****ITEMS*****" << endl;
	cout<< "ITEM ID"<< "    " << left << setw(50) << "ITEM NAME" <<  setw(12) << "    PRICE    QUANTITY" << endl;

	string line_;
	ifstream itemlist("itemlist.txt");				//Open itemlist.txt file for reading data
	if (itemlist.is_open())
	{
		while (getline(itemlist, line_))			//Retrieve data line by line
		{
			cout << line_ << endl;					//Display data on screen
		}
		itemlist.close();							//Close file after reading
	}
	else
		cout << "\t\tFile not found or created. Contact maintenance\n";
		cin.get();

	string pw;
	cout << endl << "\t\tEnter login password: ";		//Process of returning to menu
	cin >> pw;
	if (pw == "1234")
	{
		system("cls");
		B_head();
		Admin_View_IS();								//If Admin logged in, return to Admin View Item/ Service
	}
	else if (pw == "emp123")
	{
		system("cls");
		B_head();
		Emp_View_IS();									//If Employee logged in, return to Employee View Item/ Service
	}
	else
	{
		cout << "Invalid password";
		system("pause");
		main();											//If incorrect password is entered, the program will return to login menu
	}
}
void View_Service()
{
	cout << "\t\t\t\t*****SERVICES*****\n" << endl;
	cout << "SERVICE ID" << "    " << left << setw(50) << "SERVICE NAME" << setw(12) << " PRICE" << endl;

	string line_;
	ifstream servicelist("servicelist.txt");				//Open itemlist.txt file for reading data
	if (servicelist.is_open())
	{
		while (getline(servicelist, line_))			//Retrieve data line by line
		{
			cout << line_ << endl;					//Display data on screen
		}
		servicelist.close();						//Close file after reading
	}
	else
		cout << "\t\tFile not found or created. Contact maintenance\n";
	cin.get();

	string pw;
	cout << endl << "\t\tEnter login password: ";		//Process of returning to menu
	cin >> pw;
	if (pw == "1234")
	{
		system("cls");
		B_head();
		Admin_View_IS();								//If Admin logged in, return to Admin View Item/ Service
	}
	else if (pw == "emp123")
	{
		system("cls");
		B_head();
		Emp_View_IS();									//If Employee logged in, return to Employee View Item/ Service
	}
	else
	{
		cout << "Invalid password";
		system("pause");
		main();											//If incorrect password is entered, the program will return to login menu
	}
}
void View_FL()
{
	cout << "\t\t\t\t*****ITEMS*****" << endl;
	cout << "ITEM ID" << "    " << left << setw(50) << "ITEM NAME" << setw(12) << "    PRICE    QUANTITY" << endl;
	
	string line_;
	ifstream itemlist("itemlist.txt");				//Open itemlist.txt file for reading data
	if (itemlist.is_open())
	{
		while (getline(itemlist, line_))			//Retrieve data line by line
		{
			cout << line_ << endl;					//Display data on screen
		}
		itemlist.close();							//Close file after reading
	}
	else
		cout << "\t\tFile not found or created. Contact maintenance\n";
	cin.get();


		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


	cout << "\t\t\t\t*****SERVICES*****\n" << endl;
	cout << "SERVICE ID" << "    " << left << setw(50) << "SERVICE NAME" << setw(12) << " PRICE" << endl;

	ifstream servicelist("servicelist.txt");				//Open itemlist.txt file for reading data
	if (servicelist.is_open())
	{
		while (getline(servicelist, line_))			//Retrieve data line by line
		{
			cout << line_ << endl;					//Display data on screen
		}
		servicelist.close();						//Close file after reading
	}
	else
		cout << "\t\tFile not found or created. Contact maintenance\n";
	cin.get();

	string pw;
	cout << endl << "\t\tEnter login password: ";		//Process of returning to menu
	cin >> pw;
	if (pw == "1234")
	{
		system("cls");
		B_head();
		Admin_View_IS();								//If Admin logged in, return to Admin View Item/ Service
	}
	else if (pw == "emp123")
	{
		system("cls");
		B_head();
		Emp_View_IS();									//If Employee logged in, return to Employee View Item/ Service
	}
	else
	{
		cout << "Invalid password";
		system("pause");
		main();											//If incorrect password is entered, the program will return to login menu
	}
}

//ADD MENU
void Add_Item()
{
	int num = 0, x;
	Item newI[5];
	ifstream newone("itemlist.txt");		//Open itemlist.txt file
	if (newone.is_open())
	{
		{
			system("cls");
			B_head();
			cout << "\t\t\t******ADD ITEMS******\n\n" << endl << "\tYou can add 5 items at once" << endl << "\tUse _ for spaces" << endl << "\tEnter the number of items: ";
			cin >> x;
			while (x > 5 || x < 1)																				//Spaces should be used because itemName variable is a string variable
			{
				cout << endl << "\tPlease enter a number between 1-5" << endl << "\t\tNumber: ";
				cin >> x;
			}
		}
		for (int num = 0;num < x;num++)								//Data entry to the array
		{
			cout << endl << "Item ID: ";
			cin >> newI[num].itemID;
			cout << "Item Name: ";
			cin >> newI[num].itemName;
			cout << "Price: ";
			cin >> newI[num].itemPrice;
			cout << "Quantity: ";
			cin >> newI[num].itemQ;
			cout << "\n";
		}
		for (int num = 0;num < x;num++)
		{
			fstream newone("itemlist.txt", fstream::app);			//Writing data in the file
			newone << setprecision(1) << fixed;
			newone << "\n" << newI[num].itemID << "    " << left << setw(50) << newI[num].itemName << right << setw(12) << newI[num].itemPrice << right << setw(5) << newI[num].itemQ << endl;
			newone.close();
		}
		cout << "\t\tItem(s) added successfully\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\t\tFile is not found or created. Contact Maintainance" << endl;
		system("pause");
		system("cls");
	}
	B_head();
	Add_IS();
}
void Add_Service()
{
	int num = 0, x;
	Service newservice[5];
	ifstream newone("servicelist.txt");		//Open servicelist.txt file
	if (newone.is_open())
	{
		{
			system("cls");
			B_head();
			cout << "\t\t\t******ADD SERVICES******\n\n" << endl << "\tYou can add 5 services at once" << endl << "\tUse _ for spaces" << endl << "\tEnter the number of services: ";
			cin >> x;
			while (x > 5 || x < 1)																				//Spaces should be used because serviceName variable is a string variable
			{
				cout << endl << "\tPlease enter a number between 1-5" << endl << "\t\tNumber: ";
				cin >> x;
			}
		}
		for (int num = 0;num < x;num++)								//Data entry to the array
		{
			cout << endl << "Service ID: ";
			cin >> newservice[num].serviceID;
			cout << "Service Name: ";
			cin >> newservice[num].serviceName;
			cout << "Price: ";
			cin >> newservice[num].servicePrice;
			cout << "\n";
		}
		for (int num = 0;num < x;num++)
		{
			fstream newone("servicelist.txt", fstream::app);			//Writing data in the file
			newone << setprecision(1) << fixed;
			newone << "\n" << newservice[num].serviceID << "    " << left << setw(50) << newservice[num].serviceName << right << setw(12) << newservice[num].servicePrice << endl;
			newone.close();
		}
		cout << "\t\tService(s) added successfully\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\t\tFile is not found or created. Contact Maintainance" << endl;
		system("pause");
		system("cls");
	}
	B_head();
	Add_IS();
}

//UPDATE MENU
void Update_Item()
{
	Item updateI;
	string updateID, line;
	cout << "\t\t\t******UPDATE ITEMS******" << endl;
	
	ifstream fin;
	fin.open("itemlist.txt");						//Opening itemlist.txt file
	ofstream temp;
	temp.open("tempI.txt");							//Creating and opening a temporary file called tempI.txt
	cout << "\t\tInsert Item ID: ";					//Input the Item ID that needs to be updated
	cin >> updateID;

	cout << "Enter Updating Item Details\nUse _ for Spaces\n" << endl			//Enter new details
		<< "Item ID: ";
	cin >> updateI.itemID;
	cout << "Item Name: ";
	cin >> updateI.itemName;
	cout << "Price: ";
	cin >> updateI.itemPrice;
	cout << "Quantity: ";
	cin >> updateI.itemQ;

	while (getline(fin, line))
	{
		string id(line.begin(), line.begin() + line.find(" "));			//Finding the given Item ID
		if (id != updateID)												//If the ID doesn't match, the relevent line is written to tempI.txt file
			temp << line << endl;										//If the ID matches, that line won't be written to tempI.txt
	}
	temp << setprecision(1) << fixed;									//After finishing, the relevent details stored in the array are written on tempI.txt
	temp << updateI.itemID << "    " << left << setw(50) << updateI.itemName << right << setw(12) << updateI.itemPrice << right << setw(5) << updateI.itemQ << endl;
	temp.close();
	fin.close();
	cout << "\n\t\tItem updated successfully\n";						//Success message
	remove("itemlist.txt");												//The itemlist.txt file is deleted
	rename("tempI.txt", "itemlist.txt");								//tempI.txt is renamed to itemlist.txt
	system("pause");
	system("cls");
	Update_IS();														//Return to Update main menu

}
void Update_Service()
{
	Service updateS;
	string updateID, line;
	cout << "\t\t\t******UPDATE SERVICES******" << endl;

	ifstream fin;
	fin.open("servicelist.txt");						//Opening servicelist.txt file
	ofstream temp;
	temp.open("tempS.txt"); 							//Creating and opening a temporary file called tempS.txt
	cout << "\t\tService ID: ";							//Input the Service ID that needs to be updated
	cin >> updateID;

	cout << "\tEnter Updating Service Details\n\tUse _ for Spaces\n" << endl			//Enter new details
		<< "Service ID: ";
	cin >> updateS.serviceID;
	cout << "Service Name: ";
	cin >> updateS.serviceName;
	cout << "Price: ";
	cin >> updateS.servicePrice;

	while (getline(fin, line))
	{
		std::string id(line.begin(), line.begin() + line.find(" "));			//Finding the given Service ID
		if (id != updateID)														//If the ID doesn't match, the relevent line is written to tempS.txt file
			temp << line << endl;												//If the ID matches, that line won't be written to tempS.txt
	}
	temp << setprecision(1) << fixed;											//After finishing, the relevent details stored in the array are written on tempS.txt
	temp << updateS.serviceID << "    " << left << setw(50) << updateS.serviceName << right << setw(12) << updateS.servicePrice << endl;
	temp.close();
	fin.close();
	cout << "\n\t\tService updated successfully\n";								//Success message
	remove("servicelist.txt");													//The servicelist.txt file is deleted
	rename("tempS.txt", "servicelist.txt");										//tempS.txt is renamed to servicelist.txt
	system("pause");
	system("cls");
	Update_IS();																//Return to Update main menu
}

//SEARCH MENU
void Search_Item()
{
	string searchID, line;
	cout << "\t\t\t******SEARCH ITEMS******\n\n" << endl << "\tYou can search one item at a time using the ITEM ID\n"
		<< "\t\tEnter Item ID: ";						//Input the Item ID
	cin >> searchID;

	ifstream fin;
	fin.open("itemlist.txt");							//Open itemlist.txt file
	
	while (getline(fin, line))							//Read line by line
	{
		std::string id(line.begin(), line.begin() + line.find(" "));
		if (id == searchID)								//Check whether the ID matches
		{
			cout << "Item found\n"						//If matching, display message
				<< line;								//Display the line on screen
			cout << "\n";
			break;										//End loop
		}
	}
	fin.close();

	string pw;
	cout << endl << "\tEnter login password: ";			//Process of returning to menu	
	cin >> pw;
	if (pw == "1234")
	{
		system("cls");
		B_head();
		Admin_Search_IS();								//If Admin logged in, return to Admin Search
	}
	else if (pw == "emp123")
	{
		system("cls");
		B_head();
		Emp_Search_IS();								//If Employee logged in, return to Employee Search
	}
	else
	{
		cout << "Invalid password";
		system("pause");
		main();											//If incorrect password is entered, the program will return to login menu
	}
}
void Search_Service()
{
	string searchID, line;
	cout << "\t\t\t******SEARCH SERVICES******\n\n" << endl << "\tYou can search one service at a time using the SERVICE ID\n"
		<< "\t\tEnter Service ID: ";								//Input the Item ID
	cin >> searchID;

	ifstream fin;
	fin.open("servicelist.txt");									//Open itemlist.txt file

	while (getline(fin, line))										//Read line by line
	{
		string id(line.begin(), line.begin() + line.find(" "));
		if (id == searchID)											//Check whether the ID matches
		{
			cout << "\t\tService found\n"							//If matching, display message
				<< line;											//Display the line on screen
			cout << "\n";
			break;													//End loop
		}
	}
	fin.close();

	string pw;
	cout << endl << "\tEnter login password: ";						//Process of returning to menu	
	cin >> pw;
	if (pw == "1234")
	{
		system("cls");
		B_head();
		Admin_Search_IS();											//If Admin logged in, return to Admin Search
	}
	else if (pw == "emp123")
	{
		system("cls");
		B_head();
		Emp_Search_IS();											//If Employee logged in, return to Employee Search
	}
	else
	{
		cout << "Invalid password";
		system("pause");
		main();														//If incorrect password is entered, the program will return to login menu
	}
}

//DELETE MENU
void Delete_Item()
{
	
	string deleteline;
	string line;
	cout << "\t\t\t******DELETE ITEMS******" << endl;


	ifstream fin;
	fin.open("itemlist.txt");						//Open itemlist.txt file
	ofstream temp;
	temp.open("tempI.txt");							//Create temporary file called tempI.txt
	cout << "\t\tItem ID: ";						//Input the Item ID
	cin >> deleteline;

	while (getline(fin, line))						//Read line by line until the final line of the file
	{
		std::string id(line.begin(), line.begin() + line.find(" "));
		if (id != deleteline)						//If ID is not the entered ID, write the data in tempI.txt
			temp << line << endl;					//If ID is the entered ID, skip it
	}

	temp.close();									//Close tempI.txt
	fin.close();									//Close itemlist.txt
	cout << "\n\tItem deleted successfully\n";		//Display message
	remove("itemlist.txt");							//Delete itemlist.txt
	rename("tempI.txt", "itemlist.txt");			//Rename tempI.txt to itemlist.txt
	system("pause");
	system("cls");
	Delete_IS();									//Return to Delete menu
	
}
void Delete_Service()
{
	string deleteline;
	string line;
	cout << "\t\t\t******DELETE SERVICES******" << endl;


	ifstream fin;
	fin.open("servicelist.txt");						//Open serv icelist.txt file
	ofstream temp;
	temp.open("tempS.txt");							//Create temporary file called tempS.txt
	cout << "\t\tService ID: ";						//Input the Service ID
	cin >> deleteline;

	while (getline(fin, line))						//Read line by line until the final line of the file
	{
		std::string id(line.begin(), line.begin() + line.find(" "));
		if (id != deleteline)						//If ID is not the entered ID, write the data in tempS.txt
			temp << line << endl;					//If ID is the entered ID, skip it
	}
	cout << "\n\tService deleted successfully\n";		//Display message
	temp.close();										//Close tempS.txt
	fin.close();										//Close servicelist.txt
	remove("servicelist.txt");							//Delete servicelist.txt
	rename("tempS.txt", "servicelist.txt");				//Rename tempS.txt to servicelist.txt
	system("pause");
	system("cls");
	Delete_IS();										//Return to Delete menu
}

//SERVICE LIST
void serviceList()
{
	newS[0] = { "S001", "Accident_&_Paint_Touchup_-_Car", 2500 };						//The array newS[] is declared earlier
	newS[1] = { "S002", "Accident_&_Paint_Touchup_-_Van", 3500 };
	newS[2] = { "S003", "Vehicle_Scanning_-_Car        ", 1000 };
	newS[3] = { "S004", "Vehicle_Scanning_-_Van        ", 1800 };
	newS[4] = { "S005", "Battery_Testing               ", 500 };
	newS[5] = { "S006", "Lube_Change                   ", 1000 };
	newS[6] = { "S007", "Oil_Change_-_Car              ", 500 };
	newS[7] = { "S008", "Oil_Change_-_Van              ", 600 };
	newS[8] = { "S009", "Light_Checking                ", 500 };
	newS[9] = { "S010", "Engine_Tune Up                ", 1500 };
	newS[10] = { "S011", "Brake_Pad_Replacement_-_Car   ", 1000 };
	newS[11] = { "S012", "Brake_Pad_Replacement_-_Van   ", 1200 };
	newS[12] = { "S013", "Wheel_Alignment               ", 2000 };
	newS[13] = { "S014", "Wiper_Replacement             ", 500 };
	newS[14] = { "S015", "Brake_Alignment               ", 500 };
	newS[15] = { "S016", "Sensor_Testing                ", 800 };
	newS[16] = { "S017", "Fuel_Pump_Replacement         ", 700 };
	newS[17] = { "S018", "Tyre_Replacement              ", 400 };
	newS[18] = { "S019", "Air_Conditioning_Service      ", 1000 };
	newS[19] = { "S020", "Transmission_Repair           ", 1500 };

	int servicecount = 20;

	ofstream file1_("servicelist.txt");													//Select servicelist.txt file for saving the service details
	if (file1_.is_open())																//Check whether the file is open
	{
		for (int i = 0; i < servicecount; ++i)											//FOR loop is used to insert the data to the file
		{
			file1_ << newS[i].serviceID << "    " << left << setw(50) << newS[i].serviceName << right << setw(12) << newS[i].servicePrice << endl;
		}
	}
	file1_.close();																		//File is closed
}

//ITEM LIST
void itemList()
{
	newI[0] = { "I001", "Havoline_Super_4T_1l", 1200, 10 };							//The array newI[] is declared earlier
	newI[1] = { "I002", "Havoline_PRO_DS_SAE_oW_3l", 5600, 5 };
	newI[2] = { "I003", "CX_Brake_&_Clutch_Fluid_250ml", 500, 12 };
	newI[3] = { "I004", "CX_Brake_&_Clutch_Fluid_500ml", 900, 8 };
	newI[4] = { "I005", "Brake_Pad_-_X-Trail", 5900, 4 };
	newI[5] = { "I006", "Wiper_Blade_-_Vitz", 1900, 10 };
	newI[6] = { "I007", "Wiper_Blade_-_WagonR", 1900, 10 };
	newI[7] = { "I008", "Wiper_Blade(Pair)_-_Prado", 2500, 6 };
	newI[8] = { "I009", "Wiper_Blade_-_Leaf", 1750, 5 };
	newI[9] = { "I010", "Wiper_Blade(Pair)_-_Fit", 2300, 5 };
	newI[10] = { "I011", "Fuel_Pump_-_Vitz", 9000, 3 };
	newI[11] = { "I012", "Fuel_Pump_-_WagonR", 12000, 4 };
	newI[12] = { "I013", "Fuel_Pump_-_Prado", 7500, 2 };
	newI[13] = { "I014", "Tyre_165/65_R15", 18000, 8 };
	newI[14] = { "I015", "Tyre_195/50_R15", 20500, 10 };
	newI[15] = { "I016", "Tyre_235/45_R18", 32000, 6 };
	newI[16] = { "I017", "Tyre_255/70_R15", 30000, 5 };
	newI[17] = { "I018", "Tyre_285/75_R16", 52750, 2 };
	newI[18] = { "I019", "Toyota_Gear_Oil_4l", 14900, 6 };
	newI[19] = { "I020", "Toyota_Gear_Oil_2l", 8500, 7 };

	int itemcount = 20;
	ofstream file_("itemlist.txt");													//Select itemlist.txt file for saving the item details
	if (file_.is_open())															//Check whether the file is open
	{
		for (int i = 0; i < itemcount; ++i)											//FOR loop is used to insert the data to the file
		{
			file_ << setprecision(1) << fixed;
			file_ << newI[i].itemID << "    " << left << setw(50) << newI[i].itemName << right << setw(12) << newI[i].itemPrice << right << setw(5) << newI[i].itemQ << endl;
		}
	}
	file_.close();																	//File is closed
}

//ADMIN FUNCTIONS
void Admin_View_IS()
{
	int option;
	cout << "\t\t\t******VIEW ITEMS/ SERVICES******" << endl
		<< "\t\t1. View Item\n"									//List of options
		<< "\t\t2. View Service\n"
		<< "\t\t3. View Full List\n"
		<< "\t\t4. Back\n"
		<< "\t\t  Enter the option: ";
	cin >> option;
	while ((option > 4) or (1 > option))
	{
		cout << "\tInvalid Option Number.\n\tEnter a valid number: ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		system("cls");
		B_head();
		View_Item();										//View Item call
		break;

	case 2:
		system("cls");
		B_head();
		View_Service();										//View Service call
		break;

	case 3:
		system("cls");
		B_head();
		View_FL();											//View Full list call
		break;

	case 4:
		system("cls");
		Admin_menu();										//Admin menu call
		break;
	}

}
void Add_IS()
{
	int option;
	cout << "\t\t\t******ADD ITEMS/ SERVICES******" << endl
		<< "\t\t1. Add Item\n"									//List of options
		<< "\t\t2. Add Service\n"
		<< "\t\t3. Back\n"
		<< "\t\t  Enter the option: ";
	cin >> option;
	while ((option > 4) or (1 > option))
	{
		cout << "\tInvalid Option Number.\n\tEnter a valid number: ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		system("cls");
		B_head();
		Add_Item();												//Add Item call
		break;

	case 2:
		system("cls");
		B_head();
		Add_Service();											//Add Service call
		break;

	case 3:
		system("cls");
		Admin_menu();											//Return to Admin menu call
		break;
	}
}
void Update_IS()
{
	int option;
	cout << "\t\t\t******UPDATE ITEMS/ SERVICES******" << endl
		<< "\t\t1. Update Item\n"									//List of options
		<< "\t\t2. Update Service\n"
		<< "\t\t3. Back\n"
		<< "\t\t  Enter the option: ";
	cin >> option;
	while ((option > 4) or (1 > option))
	{
		cout << "\tInvalid Option Number.\n\tEnter a valid number: ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		system("cls");
		B_head();
		Update_Item();												//Update Item call
		break;

	case 2:
		system("cls");
		B_head();
		Update_Service();											//Update Service call
		break;

	case 3:
		system("cls");
		Admin_menu();												//Return to Admin menu call
		break;
	}
}
void Admin_Search_IS()
{
	int option;
	cout << "\t\t\******SEARCH ITEMS/ SERVICES******" << endl
		<< "\t\t1. Search Item\n"									//List of options
		<< "\t\t2. Search Service\n"
		<< "\t\t3. Back\n"
		<< "\t\t  Enter the option: ";
	cin >> option;
	while ((option > 4) or (1 > option))
	{
		cout << "\tInvalid Option Number.\n\tEnter a valid number: ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		system("cls");
		B_head();
		Search_Item();												//Search Item call
		break;

	case 2:
		system("cls");
		B_head();
		Search_Service();											//Search Service call
		break;

	case 3:
		system("cls");
		Admin_menu();												//Return to Admin menu
		break;
	}
}
void Delete_IS()
{
	int option;
	cout << "\t\t\t******DELETE ITEMS/ SERVICES******" << endl
		<< "\t\t1. Delete Item\n"									//List of options
		<< "\t\t2. Deleet Service\n"
		<< "\t\t3. Back\n"
		<< "\t\t  Enter the option: ";
	cin >> option;
	while ((option > 4) or (1 > option))
	{
		cout << "\tInvalid Option Number.\n\tEnter a valid number: ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		system("cls");
		B_head();
		Delete_Item();												//Delete Item call
		break;

	case 2:
		system("cls");
		B_head();
		Delete_Service();											//Delete Service call
		break;

	case 3:
		system("cls");
		Admin_menu();												//Return to Admin menu
		break;
	}
}

void Admin_Exit()
{
	string ans;
	cout << "\t\t\t******EXIT PROGRAM******\n" << endl;
	cout << "\t\t\tDO YOU WANT TO EXIT?\n\n\t\t\t   Y=Yes   N=No" << endl << endl << "\t\t\tResponse: ";
	cin >> ans;
	while (!(ans == "Y" or ans == "y" or ans == "N" or ans == "n"))
	{
		cout << endl << "\t\tPlease enter Y=Yes   N=No" << endl << "\t\t\tResponse: ";						//Validating the response
		cin >> ans;
	}
	if (ans == "Y" or ans == "y")
	{
		cout << "\n\t\t\t   GOODBYE\n";				//Exiting the system
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		Admin_menu();								//Returning to Admin main menu
	}
}
void Admin_Logout()
{
	string ans;
	cout << "\t\t\t******LOG OUT******\n" << endl;
	cout << "\t\tARE YOU SURE YOU WANT TO LOG OUT?" << endl << "\t\t\tY=Yes        N=No" << endl << "\t\t\tResponse: ";
	cin >> ans;
	while (!(ans == "Y" or ans == "y" or ans == "N" or ans == "n"))						//Validating the response
	{
		cout << endl << "\t\tPlease enter Y=Yes   N=No" << endl << "\t\t\tResponse: ";
		cin >> ans;
	}
	if (ans == "Y" or ans == "y")
	{
		cout << "\n\t\t\t   LOGGING OUT\n";			//Logging out of the system
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		Admin_menu();								//Returning to Admin main menu
	}
}
void Admin_menu()
{
	B_head();
	int option;
	cout << "\t\t\t******ADMIN MENU******\n"
		<< "\t\t 1. View Items/ Services\n"									//List of options for the Admin
		<< "\t\t 2. Add Items/ Services\n"
		<< "\t\t 3. Update Items/ Services\n"
		<< "\t\t 4. Search Items/ Services\n"
		<< "\t\t 5. Delete Items/ Services\n"
		<< "\t\t 6. Exit\n"
		<< "\t\t 7. Log out\n" << endl
		<< "\t\t  Enter the option number: ";
	cin >> option;

	while ((option > 7) or (1 > option))
	{
		cout << "\tInvalid Option Number.\n\tEnter a valid number: ";
		cin >> option;
	}

	switch (option)											//SWITCH is used to increase efficiency of program
	{
	case 1:
		system("cls");										//Clear screen
		B_head();
		Admin_View_IS();									//View Items/ Services call
		break;

	case 2:
		system("cls");										//Clear screen
		B_head();
		Add_IS();											//Add Items/ Services call
		break;

	case 3:
		system("cls");										//Clear screen
		B_head();
		Update_IS();										//Update Items/ Services call
		break;

	case 4:
		system("cls");										//Clear screen
		B_head();
		Admin_Search_IS();									//Search Items/ Services call
		break;

	case 5:
		system("cls");										//Clear screen
		B_head();
		Delete_IS();										//Delete Items/ Services call
		break;

	case 6:
		system("cls");										//Clear screen
		B_head();
		Admin_Exit();										//Exit Program call
		break;

	case 7:
		system("cls");										//Clear screen
		B_head();
		Admin_Logout();										//Logout call
		break;
	}

}


//EMPLOYEE FUNCTIONS
void Emp_View_IS()
{
	int option;
	cout << "\t\t\t******VIEW ITEMS/ SERVICES******" << endl
		<< "\t\t1. View Item\n"									//List of options
		<< "\t\t2. View Service\n"
		<< "\t\t3. View Full List\n"
		<< "\t\t4. Back\n"
		<< "\t\t  Enter the option: ";
	cin >> option;
	while ((option > 5) or (1 > option))
	{
		cout << "\tInvalid Option Number.\n\tEnter a valid number: ";
		cin >> option;
	}

	switch (option)
	{
	case 1:
		system("cls");
		B_head();
		View_Item();										//View Item call
		break;

	case 2:
		system("cls");
		B_head();
		View_Service();										//View Service call
		break;

	case 3:
		system("cls");
		B_head();
		View_FL();											//View Full list call
		break;

	case 4:
		system("cls");
		Emp_menu();										//Admin menu call
		break;
	}
}

void Emp_Search_IS()
{
	int option;
	cout << "\t\t\t******SEARCH ITEMS/ SERVICES******" << endl
		<< "\t\t1. Search Item\n"									//List of options
		<< "\t\t2. Search Service\n"
		<< "\t\t3. Back\n"
		<< "\t\t  Enter the option: ";
	cin >> option;
	while ((option > 3) or (1 > option))
	{
		cout << "\tInvalid Option Number.\n\tEnter a valid number: ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		system("cls");
		B_head();
		Search_Item();												//Search Item call
		break;

	case 2:
		system("cls");
		B_head();
		Search_Service();											//Search Service call
		break;

	case 3:
		system("cls");
		Emp_menu();													//Return to Employee menu
		break;
	}
}
void Emp_Exit()
{
	string ans;
	cout << "\t\t\t******EXIT PROGRAM******" << endl;
	cout << "\t\t\tDO YOU WANT TO EXIT?\n\n\t\t\t   Y=Yes   N=No" << endl << endl << "\t\t\tResponse: ";
	cin >> ans;
	while (!(ans == "Y" or ans == "y" or ans == "N" or ans == "n"))						//Validating the response
	{
		cout << endl << "\t\tPlease enter Y=Yes   N=No" << endl << "\t\t\tResponse: ";
		cin >> ans;
	}
	if (ans == "Y" or ans == "y")
	{
		cout << "\n\t\t\t   GOODBYE\n";			//Exiting the system
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		Emp_menu();								//Returning to Employee main menu
	}
}
void Emp_Logout()
{
	string ans;
	cout << "\t\t\t******LOG OUT******\n" << endl;
	cout << "\t\tARE YOU SURE YOU WANT TO LOG OUT?" << endl << "\t\t\tY=Yes        N=No" << endl << "\t\t\tResponse: ";
	cin >> ans;
	while (!(ans == "Y" or ans == "y" or ans == "N" or ans == "n"))						//Validating the response
	{
		cout << endl << "\t\tPlease enter Y=Yes   N=No" << endl << "\t\t\tResponse: ";
		cin >> ans;
	}
	if (ans == "Y" or ans == "y")
	{
		cout << "\n\t\t\t   LOGGING OUT\n";			//Logging out of the system
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		Emp_menu();								//Returning to Employee main menu
	}
}
void Emp_menu()
{
	B_head();
	int option;
	cout << "\t\t\t******EMPLOYEE MENU******\n"
		<< "\t\t 1. View Items/ Services\n"									//List of options for the Employee
		<< "\t\t 2. Search Items/ Services\n"
		<< "\t\t 3. Exit\n"
		<< "\t\t 4. Log Out\n" << endl
		<< "\t\t  Enter the option number: ";
	cin >> option;
	while ((option > 5) or (1 > option))
	{
		cout << "\t\tInvalid Option Number.\n\t\tEnter a valid number: ";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		system("cls");										//Clear screen
		B_head();
		Emp_View_IS();										//View Items/ Services call
		break;

	case 2:
		system("cls");										//Clear screen
		B_head();
		Emp_Search_IS();									//Search Items/ Services call
		break;

	case 3:
		system("cls");										//Clear screen
		B_head();
		Emp_Exit();											//Exit Program call
		break;

	case 4:
		system("cls");										//Clear screen
		B_head();
		Emp_Logout();										//Logout call
		break;
	}
}




//MAIN FUNCTION
int main()
{
	string user, pw;
	int count = 0;
	B_head();
	cout << "\t\t\t******LOG IN******\n" << endl;
	while (count < 3) {																	//3 chances are given to login
		cout << "\t\tEnter username: ";
		cin >> user;
		cout << "\t\tEnter password: ";
		cin >> pw;

		if (user == "Admin" and pw == "1234")
		{
			cout << endl << "\tSuccessfully Logged in as Admin" << endl;
			system("pause");
			system("cls");
			Admin_menu();
			break;
		}
		else if (user == "Emp01" and pw == "emp123")
		{
			cout << endl << "\tSuccessfully Logged in as Employee" << endl;
			system("pause");
			system("cls");
			Emp_menu();
			break;
		}
		else if (count < 2)
		{
			cout << endl << "\tIncorrect Username or Password." << endl << "\tPlease Try Again." << endl << endl;
			++count;
		}
		else
		{
			cout << endl << "\tIncorrect Username or Password." << endl << "\tProgram will be terminated." << endl;
			break;															//The program will end if incorrect details are entered 3 times
			system("pause");
			system("cls");
		}
	}
	return 0;
}

