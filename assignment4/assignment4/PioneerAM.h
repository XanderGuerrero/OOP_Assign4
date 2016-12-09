///FileName:	PioneerAM.h
///Project:		Assignment4
///Author:		Alex Guerrero	
///Date:		April 11, 2014
///Description:	This program runs through the functions of an AM radio with menu input from the user
///				using inheritance dervived from the PioneerCarRadio class.
///	
/* -- FILEHEADER COMMENT -- 
	NAME	:	PioneerAM
	PURPOSE :	This program inherits from the PioneerCarRadio class for its functionality
*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"PioneerCarRadio.h"



//disables warnings
#pragma warning(disable: 4996)///<#pragma warning used for depricated functions



#ifndef _PIONEERAM_H
#define _PIONEERAM_H



/// 
/// \class PioneerAM
///
/// \brief The purpose of this class is to realistically model the functions of an AmFm radio.
///
/// This comment block is <i>required</i> for all class declarations.  This is the place 
/// where the <b>Class header Comment</b> appears. 
///
/// \author A <i>Alex Guerrero</i>
///
class PioneerAM : public PioneerCarRadio
{
private:

public:
//constuctor
PioneerAM() : PioneerCarRadio() 
{
	PioneerCarRadio::PioneerCarRadio();
}


//destructor
virtual PioneerAM::~PioneerAM()
{
	// print out a statement indicating 
	printf("Destroying Pioneer XS440-AM Radio");
}

	//method
	//void PioneerCarRadio::userChoice();//input validation



///FunctionName:ShowCurrentSettings()
///Parameters:	void 
///Description:	Shows the current settings of the radio
///returns:		void
void PioneerAM::ShowCurrentSettings()
{
	char* currentButton;
	///<if the radio is on.....
	if( radio_On == true )
	{
		printf("\n\nRadio is on. \n");///<display msg to screen
	}
	else
	{
		printf("\n\nRadio is off. \n");///<display msg to screen
	}
	///<this section of code prints out the frequency, volume, current station and the am and fm
	///<radio presets
	printf("\n\n\t\tPioneer XS440-AM\n");
	printf("Frequency: %s\n", "AM");
	printf("Volume: %d\n", AmFmRadio::GetVolume());
	printf("Current Station: %.1f %s\n", AmFmRadio::GetStation());
	printf("AM Button Settings: ");
	currentButton = AmFmRadio::GetButton();
	for( int i = 0; i < 5; ++i )
	{
		printf("%d) %6d ", i + 1, button[i].AMFreq);
	}
}
};
#endif

