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

#ifndef MCP4018_H
#define MCP4018_H

#include "i2c.h"

// MCP4017/18/19
#define MCP401X_SLA_W 0x5E
#define MCP401X_SLA_R 0x5F

void MCP401X_Set(unsigned char pot, unsigned char value)
{
    I2C_Start();
    I2C_Write(MCP401X_SLA_W); 
    I2C_Write(pot); 
    I2C_Write(value); 
    I2C_Stop();
}

unsigned char MCP401X_Get()
{
    unsigned char data = 0;
    
    I2C_Start();
    I2C_Write(MCP401X_SLA_R);  
    data = I2C_Nack();
    I2C_Stop();
    
    return( data);
}

#endif // MCP4018_H