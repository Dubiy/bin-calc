Bin calc
========

## Interface

* byte 1 - 8 bit (8 leds, 8 switches or buttons)
* byte 2 - 8 bit (8 leds, 8 switches or buttons)
* result:
	* leds 16bit - (16 leds)
	* 5*7seg indicators
* operations: (10 operations )
  * add +
  * sub -
  * div /
  * mul *
  * xor ^
  * and &
  * or  |
  * not ~
  * shr >>
  * shl <<

## Steps

1. set byte1 and byte2
2. press operation button
3. show result on 16 leds
4. show decimal result on 7-seg
5. (optional) show result on LCD
6. (optional) show info on lcd (describe every operation, )


## Materials
* arduino uno
* atmega 328 - dip
* 32 * leds
* 16 * switches
* 16 * micro-buttons  

* 74HC165 — входной сдвиговый регистр 3шт
або
* MCP23017 - 2шт
або
* PCF8574T - 3шт

* 74HC595 выходной сдвиговый регистр - 2шт
* 7шт * npn transistors (КТ3102А, BC546, BC547 )
* 7шт * 1000 Ом
* 24шт * 180 ОМ
