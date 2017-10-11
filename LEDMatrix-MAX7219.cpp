/*
 * LEDMatrix-MAX7219 
 * Version 1.0 Oct 2017
 * Author Aightech
 */

#include "Arduino.h"
#include "LEDMatrix-MAX7219.h"

LEDMatrix::LEDMatrix(byte _data, byte _load, byte _clock, byte _nbx, byte _nbx) 
{
	data_pin = _data;
	load_pin = _load;
	clock_pin = _clock;
	nbMatX = _nbx;
  nbMatY = _nby;
}

void LEDMatrix::init()
{
	pinMode(data_pin,  OUTPUT);
	pinMode(clock_pin, OUTPUT);
	pinMode(load_pin,  OUTPUT);
	digitalWrite(clock_pin, HIGH); 

	setCommand(max7219_reg_scanLimit, 0x07);      
	setCommand(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
	setCommand(max7219_reg_shutdown, 0x01);    // not in shutdown mode
	setCommand(max7219_reg_displayTest, 0x00); // no display test
	
	// empty registers, turn all LEDs off
	clear();
	
	setIntensity(0x0f);    // the first 0x0f is the value you can set
}

void LEDMatrix::setIntensity(byte intensity)
{
	setCommand(max7219_reg_intensity, intensity);
}

void LEDMatrix::clear()
{
	
}

void LEDMatrix::setCommand(byte command, byte value)
{
	digitalWrite(load, LOW);    
	for (int i=0; i<nbMatX*nbMatY; i++) 
	{
		shiftOut(data_pin, clock_pin, MSBFIRST, command);
		shiftOut(data_pin, clock_pin, MSBFIRST, value);
	}
	digitalWrite(load, LOW);
	digitalWrite(load, HIGH);
}
