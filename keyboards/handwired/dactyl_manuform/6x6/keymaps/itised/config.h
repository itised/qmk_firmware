/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once


#define USE_I2C
#define MASTER_LEFT

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200


// wiring of each half
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4 }

#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { F5, F6, F7, B1, B3, B2, B6 }

#define MATRIX_COL_PINS_RIGHT { D4, C6, D7, E6, B4, B5 }
#define MATRIX_ROW_PINS_RIGHT { F5, F6, F7, B1, B3, B2, B6 }
