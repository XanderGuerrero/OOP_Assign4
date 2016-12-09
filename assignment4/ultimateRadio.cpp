//FileName:			UltimateRadio.cpp.
//Project:			Assignment 4
//Author:			Alex Guerrero	
//Date:				March 23, 2014
//Description:		This program runs through the functions of a Car radio with menu input from the user
//					using inheritance dervived from the AmFmRadio class.  This .ccp file is used as the 
//					driver for the 3 derived classes.




//Include files
#include"amfmRadio.h"
#include"PioneerCarRadio.h"
#include"PioneerAM.h"
#include"PioneerWorld.h"
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//Constants
#define whichRadio 1


//prototype
PioneerCarRadio* createRadio( char* string  );




int main(int argc, char *argv[])
{
	//variables, instantiate an object of class PioneerCarRadio
	PioneerCarRadio *pRadio = NULL;
	bool _true = true;
	bool _false = false;
	int choice = NULL;
	int volume = 0;
	int num = 0;
	int scan = 0;




	while( _true )
	{
		//if the argument count is null or greater than 2
		if (((argv[1] != NULL) && (argv[1] == NULL)) || (argc > 2))
		{
			//print error
			printf("Usage: argument count\n");
			system("pause");
			break;
		}
		//if the user enters a x
		if( ( strcmp("x", argv[whichRadio] ) == 0 ) || ( strcmp("X", argv[whichRadio] ) == 0 ) ) 
		{	
			//exit the program
			break;
		}
		else
		{
			try
			{
				//create radio based on command line 
				//argument entered at the beginning of the program
				pRadio = createRadio( argv[whichRadio] );
			}
			catch(char* e )
			{
				printf("ERROR: Object not created\n");
				break;
			}

			//first show the user the current radio settings
			pRadio->DisplayRadio();
			//Main program loop
			do
			{
				// radio menu
				printf("\n");
				printf("\n\nMAIN MENU\n");
				printf("=========\n\n");
				printf("o.  Toggle Power\n");
				printf("+/_.  Set Volume Control\n");
				printf("b.  Toggle AM / FM\n");
				printf("=/-.  Scan Up/Down \n");
				printf("!,@,#,$,%.  Set a Preset \n");
				printf("1,2,3,4,5.  Select a Preset \n");				
				printf("x.  Quit Program\n");


				choice = getch();//get user input


				//if input is 1,2,3,4,5 select a station preset.
				if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5')
				{
					if (choice == '1')
					{
						choice = 1;
					}
					if (choice == '2')
					{
						choice = 2;
					}
					if (choice == '3')
					{
						choice = 3;
					}
					if (choice == '4')
					{
						choice = 4;
					}
					if (choice == '5')
					{
						choice = 5;
					}
					pRadio->SelectCurrentStation(choice);//turn on preset
					system("cls");//clear the screen
				}
				//if the input is !,@,#,$,%, set the current station to the appropriate button.
				if (choice == '!' || choice == '@' || choice == '#' || choice == '$' || choice == '%')
				{
					if (choice == '!')
					{
						choice = 1;
					}
					if (choice == '@')
					{
						choice = 2;
					}
					if (choice == '#')
					{
						choice = 3;
					}
					if (choice == '$')
					{
						choice = 4;
					}
					if (choice == '%')
					{
						choice = 5;
					}
					pRadio->SetButton(choice);//set current station to button preset
					system("cls");//clear the screen
				}
				switch (choice)
				{
				//case 1 turn power on and off
				case 'o':
					pRadio->PowerToggle();//method to toggle power
					system("cls");//clear the screen
					break;
				case '+'://set volume up
					volume = 1;//volume is positive one
					pRadio->SetVolume(volume);//pass the paramter to method to set volume up by one
					system("cls");//clear screen
					break;
				case '_'://set volume down
					volume = -1;//volume is negative one
					pRadio->SetVolume(volume);//pass parameter to method to lower volume by one
					system("cls");//clear screen
					break;
				case '='://scan up
					pRadio->ScanUp();//scan the station up one 
					system("cls");//clear screen
					break;
				case '-'://scan station down
					pRadio->ScanDown();//scan down one station
					system("cls");//clear screen
					break;
				case 'b'://change frequency
					pRadio->ToggleFrequency();//toggle frequency
					system("cls");//clear screen
					break;
				case 'x'://exit the program
					break;
				}

				//display the radio settings
				pRadio->DisplayRadio();
			} while (choice != 'x');

			//'x' was chosen, break out of loop
			printf("\n");
			break;
		}
	}
	//delete object
	delete pRadio;

	return 0;
}


//FunctionName:createRadio()
//Parameters:	char* string 
//Description:	creates object using a string
//returns:		int number
PioneerCarRadio* createRadio( char* string  )
{
	PioneerCarRadio* object = NULL;
	int choice = 0;

	//if the string matches one of these strings
	//create its object
	if( strcmp( string, "-car" ) == 0 )
	{
		choice = 1;
	}
	if( strcmp( string, "-am" ) == 0 )
	{
		choice = 2;
	}
	if( strcmp( string, "-wrld" ) == 0 )
	{
		choice = 3;
	}
	switch( choice )
	{

		case 1:
			//instanitate pioneercar radio assign to pRadio pointer
			try
			{
				object = new PioneerCarRadio;
				if( object == NULL )
				{
					throw "Object not created\n";
				}
			}
			catch( char* e )
			{
				printf("ERROR: Object not created\n");
				break;
			}
			break;
		case 2:
			//instanitate pioneerAM assign to pRadio pointer
			try
			{
				object = new PioneerAM;
				if( object == NULL )
				{
					printf("Object not created\n");
				}
			}
			catch( char* e )
			{
				printf("ERROR: Object not created\n");
				break;
			}

			break;
		case 3:
			//instanitate a PioneerWorld assign to pRadio pointer
			try
			{
				object = new PioneerWorld;
				if( object == NULL )
				{
					printf("Object not created\n");
				}
			}
			catch( char* e )
			{
				printf("ERROR: Object not created\n");
				break;
			}
			break;
	}
	return object;
}