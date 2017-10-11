/*
 * LEDMatrix-MAX7219 
 * Version 1.0 Oct 2017
 * Author Aightech
 */

#ifndef _LEDMatrix_MAX7219_H_
#define _LEDMatrix_MAX7219_H_

#include "Arduino.h"

#define max7219_reg_noop        0x00
#define max7219_reg_digit0      0x01
#define max7219_reg_digit1      0x02
#define max7219_reg_digit2      0x03
#define max7219_reg_digit3      0x04
#define max7219_reg_digit4      0x05
#define max7219_reg_digit5      0x06
#define max7219_reg_digit6      0x07
#define max7219_reg_digit7      0x08
#define max7219_reg_decodeMode  0x09
#define max7219_reg_intensity   0x0a
#define max7219_reg_scanLimit   0x0b
#define max7219_reg_shutdown    0x0c
#define max7219_reg_displayTest 0x0f

class LEDMatrix
{
  private:
    byte data_pin;
    byte load_pin;
    byte clock_pin;
    byte nbMatX;
    byte nbMatY;
    int **LEDarr;
    
    void update();
	
  public:
    LEDMatrix(byte data, byte load, byte clock, byte nbMatX,byte nbMatY);
    
    void init();
    void test();
    void clear();
    void upload();
    void setCommand(byte command, byte value);
    void setIntensity(byte intensity);
    void setPoint(byte X, byte Y);
    void unsetPoint(byte X, byte Y);
    void setLine(byte xa, byte ya,byte xb, byte yb);
    void unsetLine(byte xa, byte ya,byte xb, byte yb);
};

#endif
