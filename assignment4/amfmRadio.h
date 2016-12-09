//FileName:	AmFmRadio.h
//Project:		AmFmRadio
//Author:		Alex Guerrero	
//Date:		April 11, 2014
//Description:	This program runs through the functions of a radio with menu input from the user
//	
/* -- FILEHEADER COMMENTS -- 
	NAME	:	AmFmRadio
	PURPOSE :	This program uses a class to mimic radio functionailty.  The user can switch bands, 
				scan stations up and down, change volume levels set radio presets and toggle the radio on and off.

*/


//Include files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//disables warnings
#pragma warning(disable: 4996)//#pragma warning used for depricated functions



#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H



//structure
struct Freqs
{
	int AMFreq;//used to hold the am radio frequency
	double FMFreq;//used to hold the fm radio frequency
};


// 
// \class AmFmRadio
//
// The purpose of this class is to realistically model the functions of an AmFm radio.
//
// This comment block is <i>required</i> for all class declarations.  This is the place 
// where the <b>Class header Comment</b> appears. 
//
// \author A <i>Alex Guerrero</i>
//

//class
class AmFmRadio
{
private:
	Freqs button[5];//buttons used to hold radio presets
	double current_station;//holds the current radio station
	double previous_station;//holds the previous radio station
	char frequency[3];//am or fm band
	int volume;//volume will hold the cureent volume setting 
	bool radio_On;//bool parameter to set radio on or off
	int previous_volume;//previous volume holds the previous volume level

public:
	AmFmRadio::AmFmRadio( bool newRadio_On = false );
	AmFmRadio::AmFmRadio( bool newRadio_On, struct Freqs[], double newCurrent_station, int newVolume, char newFrequency[]  );
	//destructor
	virtual AmFmRadio::~AmFmRadio(void);

	//mutators
	bool AmFmRadio::SetCurrentStation( double newCurrentStation );
	int SetButton(int button_num);
	int SelectCurrentStation(int button_num);
	bool SetRadioOnOFF(bool state);
	//methods
	virtual void PowerToggle();
	int AmFmRadio::SetVolume( int newVolume );
	bool IsRadioOn() 
	{
		return radio_On;
	}
	int SetVolume();
	virtual void ToggleFrequency();
	void ShowCurrentSettings();
	virtual void ScanUp();
	virtual void ScanDown();
	//accessors
	double AmFmRadio::GetStation(void);
	double AmFmRadio::GetPreviousStation(void);
	bool AmFmRadio::GetRadioOn(void);
	int AmFmRadio::GetVolume(void);
	const char* AmFmRadio::GetFrequency(void);
	// Returns the current frequency buttons for AM and FM
	struct Freqs * AmFmRadio::GetButton(void)
	{
		return button;																	// Returns the AM and FM stations
	}
};
#endif