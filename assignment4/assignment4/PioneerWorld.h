///FileName:	PioneerWorld.h
///Project:		PioneerCarRadio
///Author:		Alex Guerrero	
///Date:		April 11, 2014
///Description:	This program runs through the functions of a Car radio with menu input from the user
///				using inheritance dervived from the AmFmRadio class.
///	
/* -- FILEHEADER COMMENT -- 
	NAME	:	PioneerWorld
	PURPOSE :	This program proram inhertis from the PioneerAM radio for its functionality

*/

#ifndef _PIONEERWORLD_H
#define _PIONEERWORLD_H

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
#include"PioneerAM.h"

//disables warnings
#pragma warning(disable: 4996)///<#pragma warning used for depricated functions





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
		printf("Destroying Pioneer XS440-WRLD Radio");
	}
	//method
	void PioneerCarRadio::userChoice();//input validation
	void ShowSettings();
};
#endif