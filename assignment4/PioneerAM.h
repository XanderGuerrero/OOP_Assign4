//FileName:		PioneerAM.h
//Project:		Assignment4
//Author:		Alex Guerrero	
//Date:			April 11, 2014
//Description:	This program runs through the functions of an AM radio with menu input from the user
//				using inheritance dervived from the PioneerCarRadio class.
//	
/* -- FILEHEADER COMMENT -- 
	NAME	:	PioneerAM
	PURPOSE :	This program inherits from the PioneerCarRadio class for its functionality
*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"PioneerCarRadio.h"



//disables warnings
#pragma warning(disable: 4996)//#pragma warning used for depricated functions



#ifndef _PIONEERAM_H
#define _PIONEERAM_H



// 
// \class PioneerAM
//
// \brief The purpose of this class is to realistically model the functions of an AmFm radio.
//
// This comment block is <i>required</i> for all class declarations.  This is the place 
// where the <b>Class header Comment</b> appears. 
//
// \author A <i>Alex Guerrero</i>
//
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
		printf("Destroying Pioneer XS440-AM Radio\n");
	}

		//method
		//void PioneerCarRadio::userChoice();//input validation



	// Function name: ShowSettings()
	// 
	// \details <b>Details</b>
	//
	// Description: This method is used to to print comments to the screen and inherit/call the abilities of
	//				 AmFmRadio::ShowCurrentSettings() to display the current settings of the radio.  This method
	//				 also gains access to the private data memeber IsRadioOn() to determine if the radio is on.
	//				 If so, show the current settings, if not, do not show the current setting bc radio is off.
	//	Parameters: void	
	// Returns: Nothing
	virtual void PioneerAM::DisplayRadio()
	{
		struct Freqs * currentButtons;
		//initialize variables
		bool value = false;
		system("cls");//clear the screen
		printf("Pioneer XS440-AM\n");//print to screen
									//get the pivate data member bool value to determine if radio is on
		value = AmFmRadio::IsRadioOn();
		//if value is true, show current settings
		if (value == true)
		{
			printf("Frequency: %s\n", AmFmRadio::GetFrequency());
			printf("Volume: %d\n", AmFmRadio::GetVolume());
			printf("Current Station: %.1f %s\n", AmFmRadio::GetStation(), AmFmRadio::GetFrequency());
			printf("AM Button Settings: ");
			currentButtons = AmFmRadio::GetButton();
			for (int i = 0; i < 5; ++i)
			{
				printf("%d) %6d ", i + 1, currentButtons[i].AMFreq);
			}
		}
		else
		{
			//otherwise, if radio is off, display to screen
			printf("Radio is off\n");
		}
	}


	// Function name: ToggleFrequency()
	// 
	// \details <b>Details</b>
	//
	// Description: This method is used prevent the frequency from changing to FM
	//	Parameters: void	
	// Returns: Nothing
	virtual void ToggleFrequency(void)
	{
		;
	}
};
#endif

