///FileName:		CarDriver.cpp
///Project:		PioneerCarRadio
///Author:		Alex Guerrero	
///Date:			March 23, 2014
///Description:	This program runs through the functions of a Car radio with menu input from the user
///				using inheritance dervived from the AmFmRadio class.  This .ccp file is used as the main for the
///				pioneer class.
///	
/* -- FILEHEADER COMMENT -- 
NAME	:	PioneerCarRadio
PURPOSE :	This program uses a class to mimic radio functionailty.  The user can switch bands, 
scan stations up and down, change volume levels set radio presets and toggle the radio on and off.
This file contains the class for the pioneer car radio

*/



///Include files
#include"amfmRadio.h"
#include"PioneerCarRadio.h"
#include"PioneerAM.h"
#include <string.h>
#include <conio.h>

#include <iostream>
using namespace std;

//Constants
#define whichRadio 1


//prototype
PioneerCarRadio* createRadio( char* string  );



///This is commented out so that it doesnt interfer witht the other main
int main(int argc, char *argv[])
{
	///<variables, instantiate an object of class PioneerCarRadio
	PioneerCarRadio *pRadio = NULL;
	bool _true = true;
	bool _false = false;

	while( _true )
	{
		if( argc != 1 || argc != 2 || argc > 2 )
		{
			printf("Usage: argument count\n");
			//find a way to exit program	
			break;
		}
		if( ( strcmp("x", argv[whichRadio] ) == 0 ) || ( strcmp("X", argv[whichRadio] ) == 0 ) ) 
		{	
			printf("goodbye\n");
			break;
		}
		else
		{
			try
			{
				pRadio = createRadio( argv[whichRadio] );
			}
			catch(char* e )
			{
				printf("ERROR: Object not created\n");
				break;
			}
			if( pRadio != NULL )
			{

			}
			///< first show the user the current radio settings
			//pRadio.ShowSettings();
			//pRadio.userChoice();///<Get user input to change radio settings
			printf("goodbye\n");///<print to the screen to inform user program has been exited
		}
	}
	delete pRadio;

	return 0;
}



PioneerCarRadio* createRadio( char* string  )
{
	PioneerCarRadio* object = NULL;
	int choice = 0;

	if( strcmp( string, "-car" ) == 0 )
	{
		choice = 1;
	}
	if( strcmp( string, "-am" ) == 0 )
	{
		choice = 2;
	}
	if( strcmp( string, "-world" ) == 0 )
	{
		choice = 3;
	}
	switch( choice )
	{
		///<case 1 turn power on and off
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
	case 2:///<set volume up
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
	case 3:///<set volume down
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