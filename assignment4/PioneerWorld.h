//FileName:		PioneerWorld.h
//Project:		Assignment 4
//Author:		Alex Guerrero	
//Date:			April 11, 2014
//Description:	This class inherits from PioneerAM and implents its own 
//				methods for scanUp(), scanDown() and displaySettings
//
//	


#ifndef _PIONEERWORLD_H
#define _PIONEERWORLD_H

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
#include"PioneerAM.h"

//disables warnings
#pragma warning(disable: 4996)//#pragma warning used for depricated functions





class PioneerWorld : public PioneerAM
{
	private:

	public:
		//constructor
		PioneerWorld::PioneerWorld()
		{
			PioneerCarRadio::PioneerCarRadio();
		}
		//destructor
		virtual PioneerWorld::~PioneerWorld(void)
		{
			printf("Destroying Pioneer XS440-WRLD Radio\n");
		}
		//method



		//methods()
		//FunctionName:	ScanUp()
		//Project:		assignment 4
		//Parameters:	void 
		//Description:	Scans up to find a radio frequency, if at the last station wrap around
		//returns:		void
		void PioneerWorld::ScanUp()
		{
			if (strcmp("AM", AmFmRadio::GetFrequency()) == 0)
			{
				//if current_station is 1700, the current_station becomes 530
				if (AmFmRadio::GetStation() >= 1700)
				{
					AmFmRadio::SetCurrentStation(530);
				}
				else
				{
					//otherwise increment to the next station
					AmFmRadio::SetCurrentStation(AmFmRadio::GetStation() + 9);
				}
			}
		}

		//methods()
		//FunctionName:	ScanDown()
		//Project:		assignment 4
		//Parameters:	void 
		//Description:	Scans down to find a radio frequency, if at the last station wrap around
		//returns:		void
		void PioneerWorld::ScanDown()
		{
			if (strcmp("AM", AmFmRadio::GetFrequency()) == 0)
			{
				//if current_station is 1700, the current_station becomes 530
				if (AmFmRadio::GetStation() <= 530)
				{
					AmFmRadio::SetCurrentStation(1700);
				}
				else
				{
					AmFmRadio::SetCurrentStation(AmFmRadio::GetStation() - 9);
				}
			}

		}



		//methods()
		//FunctionName:	DisplayRadio()
		//Project:		assignment 4
		//Parameters:	void 
		//Description:	displays readio setting for this class
		//returns:		void
		virtual void PioneerWorld::DisplayRadio()
		{
			
			//initialize variables
			struct Freqs * currentButtons;
			bool value = false;
			system("cls");//clear the screen
			printf("Pioneer XS440-Wrld\n");//print to screen
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
};
#endif