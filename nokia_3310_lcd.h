/*
*	nokia_3310_lcd.h
*/

#ifndef _NOKIA_3310_LCD_H
#define _NOKIA_3310_LCD_H

#include <inttypes.h>
#include <avr/pgmspace.h>
#include "Print.h"

#define USE_GRAPHIC
#define USE_BITMAP
#undef USE_JOYSTICK

// Define SPI port
#define LCD_RST PORTB1
#define SPI_SS  PORTB2	// must be high whilst SPCR is set.

// Default CS for nuelectronics shield
#define SPI_CS  PORTB2
#define SPI_CS_PORT  PORTB
#define SPI_CS_DDR  DDRB
// Alternative DIgital Pin 6 if you want to modify shield to use Ethernet at same time
//#define SPI_CS  PORTD6
//#define SPI_CS_PORT  PORTD
//#define SPI_CS_DDR  DDRD

#define SPI_MOSI PORTB3
#define SPI_SCK PORTB5
#define LCD_DC  PORTB0
#define LCD_BL  PORTD7		// Backlight control

//display mode -- normal / highlight
#define MENU_NORMAL	0
#define MENU_HIGHLIGHT 1
#define PIXEL_OFF 0
#define PIXEL_ON  1
#define PIXEL_XOR 2

#ifdef USE_JOYSTICK

#define NUM_KEYS 5

// joystick number
#define UP_KEY 3
#define LEFT_KEY 0
#define CENTER_KEY 1
#define DOWN_KEY 2
#define RIGHT_KEY 4
#endif

class Nokia_3310_lcd : public Print
{
  private:
	void writeCommand( unsigned char );
	void writeData( unsigned char );

  public:
  
  	Nokia_3310_lcd();
  	
  	// Init/Clear/position functions
	void init(void);
  	virtual void write(uint8_t byte);
	void clear(void);
	void gotoXY(unsigned char x, unsigned char y);
	void update(void);

	// String and character functions
	void writeString(unsigned char x,unsigned char y,char *s, char mode); 
	void writeStringP(unsigned char x,unsigned char y,
			const char *s, char mode); 
	void writeStringBig ( unsigned char x,unsigned char y,
			char *string, char mode );
	void writeCharBig (unsigned char x,unsigned char y,
			unsigned char ch, char mode);
	void writeChar(unsigned char ch, char mode);

	// Bitmap functions
#ifdef USE_BITMAP
	void drawBitmap(unsigned char x,unsigned char y,unsigned char *map,
                  unsigned char size_x,unsigned char size_y);
	void drawBitmapP(unsigned char x,unsigned char y, const prog_char *map,
                  unsigned char size_x,unsigned char size_y);
	void clearBitmap(unsigned char x,unsigned char y, 
                  unsigned char size_x,unsigned char size_y);
#endif

	// Graphic functions
#ifdef  USE_GRAPHIC
	void setPixel( unsigned char x, unsigned char y, unsigned char c );
	void drawLine(unsigned char x1, unsigned char y1,
			unsigned char x2, unsigned char y2, unsigned char c);
	void drawRectangle(unsigned char x1, unsigned char y1,
			unsigned char x2, unsigned char y2, unsigned char c);
	void drawFilledRectangle(unsigned char x1, unsigned char y1,
			unsigned char x2, unsigned char y2, unsigned char c);
	void drawCircle(unsigned char xc, unsigned char yc,
			unsigned char r, unsigned char c);
#endif

	// Joystick functions
#ifdef  USE_JOYSTICK
	char get_key() ;
#endif

	using Print::write;

};

#endif //_NOKIA_3310_LCD_H

