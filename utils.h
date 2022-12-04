// @File		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		Brazil
// @Date		04/12/22
//
//
// Copyright (C) 2021  JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//

#ifndef UTILS_H
#define UTILS_H

#include <xc.h>

#define BUTTON_0        (PORTCbits.RC0 == 0)
#define BUTTON_1        (PORTCbits.RC1 == 0)
#define BUTTON_2        (PORTCbits.RC2 == 0)
#define BUTTON_3        (PORTCbits.RC3 == 0)
#define BUTTON_4        (PORTCbits.RC4 == 0)
#define BUTTON_5        (PORTCbits.RC5 == 0)

#endif // UTILS_H