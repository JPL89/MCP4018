// @File		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		Brazil
// @Date		04/12/22
//
//
// Copyright (C) 2022  JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//

#include "config.h"
#include "ks0066.h"
#include "utils.h"
#include "mcp4018.h"

void SET( unsigned char value )
{
    MCP401X_Set(0, value); // : volts / 0,039
    
    KS0066_Clear(0);
    KS0066_Clear(1);
    
    KS0066_Goto(0, 0);
    KS0066_Int(MCP401X_Get());
    
    KS0066_Goto(0, 1);
    KS0066_Float( (float) MCP401X_Get() * 0.039, 2);
    KS0066_String("v");
}

int main(void) 
{
    // WAIT VCC
    __delay_ms(250);
   
    // CLEAR PORTS
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    
    // CLEAR DATA LATCHES
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    
    // A/D PORT CONFIGURAION CONTROL BIT
    // (0x0F) DIGITAL I/O
    ADCON1 = 0x0F;
    
    // TURN OFF THE COMPARATORS
    CMCON = 0x07;

    // DEFINE BUTTONS
    TRISC0 = 1; // RIGHT
    TRISC1 = 1; // LEFT
    TRISC2 = 1; // UP
    TRISC3 = 1; // DOWN
    TRISC4 = 1; // ENTER
    TRISC5 = 1; // BACK
    
    // I2C_INIT
    I2C_Init();

    // INIT DISPLAY
    KS0066_Init();
    
    // CLEAR LINE 1
    KS0066_Clear(0);
    
    // CLEAR LINE 2
    KS0066_Clear(1);
    
    // SET POT VALUE 0
    SET( 0 );
    
    while(1)
    {
        if( BUTTON_5 ){
            SET( 47 );
            __delay_ms( 250 );
        }
        
        if( BUTTON_4 ){
            SET( 66 );
            __delay_ms( 250 );
        }
        
        if( BUTTON_3 ){
            SET( 93 );
            __delay_ms( 250 );
        }
        
        if( BUTTON_2 ){
            SET( 127 );
            __delay_ms( 250 );
        }
    }
}