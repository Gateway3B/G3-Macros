/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published bynnnn
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

#undef TAPPING_TERM
#define TAPPING_TERM 250

#undef DEBOUNCE
#define DEBOUNCE 10

#define COMBO_COUNT 1

#undef MK_3_SPEED
#define MK_3_SPEED
#undef MK_MOMENTARY_ACCEL
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_2 64


#define USB_SUSPEND_WAKEUP_DELAY 0