#ifndef __RRDGLCD_H
#define __RRDGLCD_H

/*  
      This file is part of Smoothie (http://smoothieware.org/). The motion control part is heavily based on Grbl (https://github.com/simen/grbl).
      Smoothie is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
      Smoothie is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
      You should have received a copy of the GNU General Public License along with Smoothie. If not, see <http://www.gnu.org/licenses/>. 
*/

/**
 * Based loosely on st7920.h from http://mbed.org/users/Bas/code/ST7920 and parts of the Arduino U8glib library.
 * Written by Jim Morris
 */

#include <mbed.h>
#include "libs/Kernel.h"
#include "libs/utils.h"
#include <libs/Pin.h>


class RrdGlcd {
public:
    /**
    *@brief Constructor, initializes the lcd on the respective pins.
    *@param mosi mbed pinname for mosi
    *@param sclk mbed name for sclk
    *@param cd Smoothie Pin for cs
    *@return none
    *@  ----> pin PSB @ Gnd for Serial/SPI bus mode.
    */
    RrdGlcd (PinName mosi, PinName sclk, Pin cs);

    virtual ~RrdGlcd();

    void setFrequency(int f);

    /**
     *@brief Display initialization
     *
     *@param none
     *@return none
     *
     */
    void initDisplay(void);

    void clearScreen(void);

    /**
    *@brief Places a string on the screen with internal characters from the HCGROM
    *@
    *@param row, column, string
    *@return none
    *
    */
    void displayString(int Row,int Column, const char *ptr,int length);

    /**
    *@brief Places a character on the screen with an internal character from the HCGROM
    *@
    *@param row, column, character
    *@return none
    *
    */    
    void displayChar(int Row, int Column,char inpChr);
    void refresh();

     /**
    *@brief Fills the screen with the graphics described in a 1024-byte array
    *@
    *@param bitmap 128x64, bytes horizontal
    *@return none
    *
    */
    void fillGDRAM(const uint8_t *bitmap);
    
private:
    Pin cs;
    mbed::SPI* spi;
    uint8_t fb[1024];
    bool inited;
};
#endif

