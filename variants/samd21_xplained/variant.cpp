/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number +  ZERO Board pin  |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital Low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          | D0 -> RX         |  PB09  |                 | EXTINT[9]    GCLK_IO[7]  *SERCOM4/PAD[1]  SERCOM5/PAD[1]  TCC3/WO[7]  TC4/WO[0]
 * | 1          | D1 <- TX         |  PB08  |                 | EXTINT[8]    GCLK_IO[6]  *SERCOM4/PAD[0]  SERCOM5/PAD[0]  TCC3/WO[6]  TC4/WO[1]
 * | 2          | D2               |  PA20  |                 | EXTINT[4]    GCLK_IO[4]   SERCOM5/PAD[2]  SERCOM3/PAD[2]  TC7/WO[0]   TCC0/WO[6]
 * | 3          | D3               |  PA21  |                 | EXTINT[5]    GCLK_IO[5]   SERCOM5/PAD[3]  SERCOM3/PAD[3]  *TC7/WO[0]  TCC0/WO[7]
 * | 4          | D4               |  PB12  |                 | EXTINT[12]   GCLK_IO[6]   SERCOM4/PAD[0]  *TC4/WO[0]      TCC0/WO[6]  I2S/FS[1]
 * | 5          | D5               |  PB13  |                 | EXTINT[13]   GCLK_IO[7]   SERCOM4/PAD[1]  *TC4/WO[1]      TCC0/WO[7]
 * | 6          | D6               |  PB14  |                 | EXTINT[14]                SERCOM5/PAD[0]  *TCC0/WO[0]     TCC1/WO[0]
 * | 7          | D7               |  PB15  |                 | EXTINT[4]    AIN[12]      
 * +------------+------------------+--------+----------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital High     |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 8          | D8               |  PB06  |                 | EXTINT[5]    AIN[13]  
 * | 9          | D9               |  PB07  |                 | EXTINT[15]                SERCOM5/PAD[1]   *TCC0/WO[1]     TCC1/WO[3]
 * | 10         | D10              |  PA12  |                 | EXTINT[15]   GCLK_IO[0]                    *TCC3/WO[6]    
 * | 11         | D11              |  PA28  |                 | EXTINT[0]    AIN[8]       PTC/Y[6]         SERCOM5/PAD[2]  TC7/WO[0]
 * | 12         | D12              |  PA27  |                 | EXTINT[2]    AIN[10]      PTC/Y[8]         SERCOM5/PAD[0]  TC6/WO[0]   *TCC3/WO[2]
 * | 13         | D13              |  PB17  |                 | EXTINT[1]    AIN[9]       PTC/Y[7]         SERCOM5/PAD[3] *TC7/WO[1] 
 * +------------+------------------+----------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------
 * |            | Analog Connector |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 6          | A0               |  PA02  | A0              | EXTINT[9]     AIN[0]       PTC/Y[15]        SERCOM4/PAD[1]  TC4/WO[1]   TCC3/WO[7]
 * | 5          | A1               |  PA03  | A1              | EXTINT[8]     AIN[1]       PTC/Y[14]        SERCOM4/PAD[0]  TC4/WO[0]   TCC3/WO[6]
 * | 4          | A2               |  PB00  | A2              | NMI           AIN[8]       PTC/Y[15]        SERCOM4/PAD[1]  TC4/WO[1]
 * | 3          | A3               |  PB01  | A3              | EXTINT[9]     AIN[9]       AC/AIN[0]        SERCOM0/PAD[0]              TCC0/WO[0]
 * | 2          | A4               |  PA10  | A4              | EXTINT[7]     AIN[18]      AC/AIN[1]        SERCOM0/PAD[1]              TCC0/WO[1]
 * | 1          | A5               |  PA11  | A5              | EXTINT[6]     AIN[19]      PTC/Y[8]         SERCOM5/PAD[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Wire             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 20         | SDA              |  PA22  | SDA             | EIC/EXTINT[6]                        PTC/X[10] *SERCOM3/PAD[0] SERCOM5/PAD[0] TC4/WO[0] TCC0/WO[4]
 * | 21         | SCL              |  PA23  | SCL             | EIC/EXTINT[7]                        PTC/X[11] *SERCOM3/PAD[1] SERCOM5/PAD[1] TC4/WO[1] TCC0/WO[5]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |SPI (Legacy ICSP) |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 22         | 1                |  PA12  | MISO            | EIC/EXTINT[12] SERCOM2/PAD[0] *SERCOM4/PAD[0] TCC2/WO[0] TCC0/WO[6]
 * |            | 2                |        | 5V0             |
 * | 23         | 4                |  PB10  | MOSI            | EIC/EXTINT[10]                *SERCOM4/PAD[2] TC5/WO[0]  TCC0/WO[4]
 * | 24         | 3                |  PB11  | SCK             | EIC/EXTINT[11]                *SERCOM4/PAD[3] TC5/WO[1]  TCC0/WO[5]
 * |            | 5                |        | RESET           |
 * |            | 6                |        | GND             |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | LEDs             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 25         |                  |  PB03  | RX              |
 * | 26         |                  |  PA27  | TX              |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | USB              |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 27         |                  |  PA28  | USB_HOST_ENABLE | EIC/EXTINT[8]
 * | 28         |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 29         |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | EDBG             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 30         |                  |  PB22  | EDBG_UART TX    | *SERCOM5/PAD[2]
 * | 31         |                  |  PB23  | EDBG_UART RX    | *SERCOM5/PAD[3]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 32         |                  |  PA22  | EDBG_SDA        | Pin 20 (SDA)
 * | 33         |                  |  PA23  | EDBG_SCL        | Pin 21 (SCL)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 34         |                  |  PA19  | EDBG_MISO       | EIC/EXTINT[3] *SERCOM1/PAD[3] SERCOM3/PAD[3] TC3/WO[1]  TCC0/WO[3]
 * | 35         |                  |  PA16  | EDBG_MOSI       | EIC/EXTINT[0] *SERCOM1/PAD[0] SERCOM3/PAD[0] TCC2/WO[0] TCC0/WO[6]
 * | 36         |                  |  PA18  | EDBG_SS         | EIC/EXTINT[2] *SERCOM1/PAD[2] SERCOM3/PAD[2] TC3/WO[0]  TCC0/WO[2]
 * | 37         |                  |  PA17  | EDBG_SCK        | EIC/EXTINT[1] *SERCOM1/PAD[1] SERCOM3/PAD[1] TCC2/WO[1] TCC0/WO[7]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 38         | ATN              |  PA13  | EDBG_GPIO0      | EIC/EXTINT[13] SERCOM2/PAD[1] SERCOM4/PAD[1] *TCC2/WO[1] TCC0/WO[7]
 * | 39         |                  |  PA21  | EDBG_GPIO1      | Pin 7
 * | 40         |                  |  PA06  | EDBG_GPIO2      | Pin 8
 * | 41         |                  |  PA07  | EDBG_GPIO3      | Pin 9
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |                  |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | GND              |        |                 |
 * | 42         | AREF             |  PA03  |                 | EIC/EXTINT[3] *[ADC|DAC]/VREFA ADC/AIN[1] PTC/Y[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |32.768KHz Crystal |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |                  |  PA00  | XIN32           | EIC/EXTINT[0] SERCOM1/PAD[0] TCC2/WO[0]
 * |            |                  |  PA01  | XOUT32          | EIC/EXTINT[1] SERCOM1/PAD[1] TCC2/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */


#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[] = {
    // 0..13 - Digital pins
    // ----------------------
    // 0/1 - SERCOM/UART (Serial)
    { PORTB, 9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, // RX: SERCOM4/PAD[1]
    { PORTB, 8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, // TX: SERCOM4/PAD[0]

    // 2..7
    // Digital Low
    { PORTA, 20, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH6, TCC0_CH6, EXTERNAL_INT_4 }, // TCC0/WO[6]
    { PORTA, 21, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH7, TCC0_CH7, EXTERNAL_INT_5 }, // TCC0/WO[7]
    { PORTB, 12, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH0, TC4_CH0, EXTERNAL_INT_12 }, // TC4/WO[0]
    { PORTB, 13, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH1, TC4_CH1, EXTERNAL_INT_13 }, // TC4/WO[1]
    { PORTB, 14, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH0, TC5_CH0, EXTERNAL_INT_14 }, // TC5/WO[0]
    { PORTB, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH1, TC5_CH1, EXTERNAL_INT_15 }, // TC5/WO[1]

    // Digital High
    // 8..13
    { PORTB,   6, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG), ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },
    { PORTB,   7, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_ANALOG), ADC_Channel15, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 },
    { PORTA,  12, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_12 },
    { PORTA,  28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, 
    { PORTA,  27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 },
    { PORTB,  17, PIO_DIGITAL, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH5, TCC0_CH5, EXTERNAL_INT_1 }, // TCC0/WO[5]

    // 14..19 - Analog pins
    // --------------------
    { PORTB,  0, PIO_ANALOG, (PIN_ATTR_ANALOG), ADC_Channel8, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, // ADC/AIN[8]
    { PORTB,  1, PIO_ANALOG, (PIN_ATTR_ANALOG), ADC_Channel9, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, // ADC/AIN[9]
    { PORTA, 10, PIO_ANALOG, (PIN_ATTR_ANALOG), ADC_Channel18, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // ADC/AIN[18]
    { PORTA, 11, PIO_ANALOG, (PIN_ATTR_ANALOG | PIN_ATTR_PWM | PIN_ATTR_TIMER), ADC_Channel19, PWM0_CH1, TCC0_CH1, EXTERNAL_INT_11 },
    { PORTA,  2, PIO_ANALOG, (PIN_ATTR_ANALOG), ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // ADC/AIN[5]
    { PORTA,  3, PIO_ANALOG, (PIN_ATTR_ANALOG), ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // ADC/AIN[10]

    // 20..21 I2C pins (SDA/SCL and also EDBG:SDA/SCL)
    // ----------------------
    { PORTA, 8, PIO_SERCOM, PIN_ATTR_DIGITAL, ADC_Channel16, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI }, // SDA: SERCOM2/PAD[0]
    { PORTA, 9, PIO_SERCOM, PIN_ATTR_DIGITAL, ADC_Channel17, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, // SCL: SERCOM2/PAD[1]

    // 22..24 - SPI pins (ICSP:MISO,SCK,MOSI)
    // ----------------------
    { PORTA,  4, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel4, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, // MISO: SERCOM0/PAD[0]
    { PORTA,  6, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel6, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // MOSI: SERCOM0/PAD[2]
    { PORTA,  7, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel7, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // SCK: SERCOM0/PAD[3]


    // 25 LED Pin (PortB 30)
    { PORTB, 30, PIO_DIGITAL, (PIN_ATTR_DIGITAL| PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH2, TCC1_CH2, EXTERNAL_INT_14 },

    /*
      // 30..41 - EDBG
      // ----------------------
      // 30/31 - EDBG/UART
      { PORTB, 22, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // TX: SERCOM5/PAD[2]
      { PORTB, 23, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RX: SERCOM5/PAD[3]

      // 32/33 I2C (SDA/SCL and also EDBG:SDA/SCL)
      { PORTA, 22, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SDA: SERCOM3/PAD[0]
      { PORTA, 23, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCL: SERCOM3/PAD[1]

      // 34..37 - EDBG/SPI
      { PORTA, 19, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MISO: SERCOM1/PAD[3]
      { PORTA, 16, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MOSI: SERCOM1/PAD[0]
      { PORTA, 18, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SS: SERCOM1/PAD[2]
      { PORTA, 17, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCK: SERCOM1/PAD[1]

      // 38..41 - EDBG/Digital
      { PORTA, 13, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM0_CH5, NOT_ON_TIMER, EXTERNAL_INT_13 }, // EIC/EXTINT[13] *TCC2/WO[1] TCC0/WO[7]
      { PORTA, 21, PIO_PWM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM0_CH7, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // Pin 7
      { PORTA,  6, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM1_CH0, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // Pin 8
      { PORTA,  7, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM1_CH1, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // Pin 9

      // 42 (AREF)
      { PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DAC/VREFP

      // ----------------------
      // 43 - Alternate use of A0 (DAC output)
      { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // DAC/VOUT
    */

} ;

const void *g_apTCInstances[TCC_INST_NUM + TC_INST_NUM] = { TCC0, TCC1, TCC2, TC3, TC4, TC5} ;

// Multi-serial objects instantiation
SERCOM sercom0(SERCOM0) ;
SERCOM sercom1(SERCOM1) ;
SERCOM sercom2(SERCOM2) ;
SERCOM sercom3(SERCOM3) ;
SERCOM sercom4(SERCOM4) ;
SERCOM sercom5(SERCOM5) ;

Uart Serial(&sercom4, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX) ;

void SERCOM4_Handler()
{
    Serial.IrqHandler();
}

