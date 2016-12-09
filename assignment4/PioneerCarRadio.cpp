//FileName:		PioneerCarRadio.cpp
//Project:		PioneerCarRadio
//Author:		Alex Guerrero	
//Date:			March 23, 2014
//Description:	This program runs through the functions of a Car radio with menu input from the user
//				using inheritance dervived from the AmFmRadio class.
//	
/* -- FILEHEADER COMMENT -- 
	NAME	:	PioneerCarRadio
	PURPOSE :	This program uses a class to mimic radio functionailty.  The user can switch bands, 
				scan stations up and down, change volume levels set radio presets and toggle the radio on and off.

*/
//include files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"PioneerCarRadio.h"


// Function name: PioneerCarRadio
// \brief Called upon to <i>construct</i> a radio object - once it loses <b>scope</b>
// \details <b>Details</b>
//
// Description: This method calls the constructor from AmFmRadio to instantiate an object
//  and sets the each button to the lowest frequency, sets the current station, sets the
// frequency to AM, sets the volume to 0 and sets on to false
//	constructors
//	as soon as object is instantiated, set radio to off
//
//	Parameters: bool newRadio_On
// \return Returns:As this is a <i>constructor</i> nothing is returned
//
PioneerCarRadio::PioneerCarRadio() 
{
	AmFmRadio::AmFmRadio();
}



// Function name: ~PioneerCarRadio
// \brief Called upon to <i>destroy</i> a radio object - once it loses <b>scope</b>
// \details <b>Details</b>
// Description: This method destroys a Pioneer radio object
//	Parameters: void
// Returns: Nothing
PioneerCarRadio::~PioneerCarRadio(void)
{
	// print out a statement indicating 
	printf("Destroying PioneerCarRadio\n");
}



// Function name: ShowSettings()
// \brief Called upon to <i>destroy</i> a radio object - once it loses <b>scope</b>
// \details <b>Details</b>
//
// Description: This method is used to to print comments to the screen and inherit/call the abilities of
//				 AmFmRadio::ShowCurrentSettings() to display the current settings of the radio.  This method
//				 also gains access to the private data memeber IsRadioOn() to determine if the radio is on.
//				 If so, show the current settings, if not, do not show the current setting bc radio is off.
//	Parameters: void	
// Returns: Nothing
void PioneerCarRadio::DisplayRadio()
{
	struct Freqs * currentButtons;
	//initialize variables
	bool value = false;
	system("cls");//clear the screen
	printf("Pioneer XS440\n");///<print to screen
	//get the pivate data member bool value to determine if radio is on
	value = AmFmRadio::IsRadioOn();
	//if value is true, show current settings
	//using the AmFmRadio's public method
	if( value == true)
	{
		AmFmRadio::ShowCurrentSettings();
	}
	else
	{
		//otherwise, if radio is off, display to screen
		printf("Radio is off\n");
	}
	
}