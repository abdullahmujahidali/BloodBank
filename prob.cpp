#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
void newdonor(int);
using namespace std;
struct new_donor
{
	string id;
	string name;
	string bg;
	string date;
	string address;
	string number;
};

void newdonor(int choice)
{
	new_donor nd;
	cout << "Enter The ID :" << endl;
	cin.ignore();
	getline(cin, nd.id);
	cout << "Enter The Name :" << endl;
	getline(cin, nd.name);
	cout << "Enter The Blood Group :" << endl;
	getline(cin, nd.bg);
	cout << "Enter The Date :" << endl;
	getline(cin, nd.date);
	cout << "Enter The Address :" << endl;
	getline(cin, nd.address);
	cout << "Enter The Number :" << endl;
	getline(cin, nd.number);
	int ch;
	cout << "Press 1. To Save Data" << endl;
	cout << "Press 0. To Exit" << endl;
	cin >> ch;
	if (ch == 1)
	{
		ofstream file;
		file.open("newuser.txt",ios::app);
		file << nd.id << "," << nd.name << "," << nd.bg << "," << nd.date << "," << nd.address << "," << nd.number << endl;
		file.close();
	}
	else if (ch == 0)
	{
		exit(0);
	}
}
void del(int choice){
	new_donor nd;
	string line, usernamei;
	char ans;
	cout << "\tARE YOU SURE YOU WANT TO DELETE YOUR ACCOUNT? (Y/N) : ";
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		ifstream read;
		ofstream write;
		usernamei = nd.name;
		const char *del = nd.name.c_str();
		remove(del);
		read.open("newuser.txt");
		write.open("temptotal.txt", ios::app);
		while (getline(read, line))
		{
			if (line != usernamei)
				write << line << endl;

		}
		read.close();
		write.close();
		remove("newuser.txt");
		rename("temptotal.txt","newuser.txt");
		system("cls");
		cout << "\n\n\n\n\t\t\tPROFILE DELETED RESTART YOUR PROGRAM TO UPDATE INFORMATION\n";
		
		
	}


}
void updatedonor(int choice){
	new_donor admin;
	ifstream io;
	io.open("newuser.txt", ios::app);
	string ss, lline = "";
	bool found = false;
	cout << "\n----------------------------------" << endl;
	cout << "Enter User  Id you want to search : ";
	cin >> ss;
	while (getline(io, lline)){
		if (ss != lline){
			cout << "\tID : " << lline << endl;;
			getline(io, lline);
			cout << lline << '\n';
			cout << "Enter ID: ";
			cin.ignore();
			getline(cin, admin.id);
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, admin.name);
			cout << "\nName Updated\n";
			cout << "Enter new phone: ";
			cin.ignore();
			getline(cin, admin.number);
			cout << "Phone Updated";
			cout << "Enter new Adress: ";
			cin.ignore();
			getline(cin, admin.address);
			cout << "Adress Updated";
			cout << "Enter new Date\n";
			cin.ignore();
			getline(cin, admin.date);
			cout << "Enter new blood-group\n";
			cin.ignore();
			getline(cin, admin.bg);
			found = false;
			ifstream read;
			ofstream write;
			string line, usernamei;
			usernamei = admin.name;
			read.open("newuser.txt");
			write.open("temptotal.txt", ios::app);
			while (getline(read, line))
			{
				if (line != usernamei)
					write << line << endl;

			}
			write << admin.id << "," << admin.name << "," << admin.bg << "," << admin.date << "," << admin.address << "," << admin.number << endl;
			read.close();
			write.close();

			remove("newuser.txt");
			rename("temptotal.txt", "newuser.txt");
		}
	}
	if (found == false){
	
	}
	else if (found == true){
		cout << "\tNot Found " << endl;
	}

			
		
}
void print(){
	ifstream imm;
	string line = "";
	imm.open("newuser.txt");
	cout << "-----------------------" << endl;
	cout << "\t\tAll  DATA\n" << endl;
	while (getline(imm, line))
	{
		
		cout << line << '\n';
	}
	imm.close();
	system("PAUSE");
}
void search(){
	ifstream io;
	io.open("newuser.txt", ios::app);
	string ss, lline = "";
	bool found = false;
	cout << "\n----------------------------------" << endl;
	cout << "Enter User  Id you want to search : ";
	cin >> ss;
	while (getline(io, lline)){
		if (ss != lline){
			cout << "\tID : " << lline << endl;;
			cout << "\tOther Information  : ";
			getline(io, lline);
			cout << lline << '\n';
			found = false;
		}
	}
	if (found == false){
		cout << lline << endl;
	}
	else if (found == true){
		cout << "\tNot Found " << endl;
	}
	

	system("PAUSE");
}
int main()
{
	char again;
	int choice;
	do
	{
		cout << "                               BLOOD DONOR DIRECTORY                                           " << endl;
		cout << "********************************************************************************************** " << endl;
		cout << "*                                                                                            * " << endl;
		cout << "*                                   Main Menu                                                * " << endl;
		cout << "*                                                                                            * " << endl;
		cout << "********************************************************************************************** " << endl;
		cout << "Press 1 for New Donor" << endl;
		cout << "Press 2 Update an existing donor" << endl;
		cout << "Press 3 for Delete a record " << endl;
		cout << "Press 4 for Search For a Donor(using blood group) " << endl;
		cout << "Press 5 for list directory " << endl;
		cout << endl;
		cout << "Enter Your Choice" << endl;
		cin >> choice;
		if (choice == 1){
			newdonor(choice);
		}
		else if (choice == 2)	{
			updatedonor(choice);
		}	
		else if (choice == 3){
			del(choice);
		}
		else if (choice == 4){
			search();
		
		}
		else if (choice == 5){
			print();
		}
			system("CLS");
		cout << "Press Y to Use Again : " << endl;
		cout << "Press N to Exit" << endl;
		cin >> again;
	} while (again == 'y' || again == 'Y');
	return 0;
}