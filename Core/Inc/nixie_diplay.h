/*
 * nixie_diplay.h
 *
 *  Created on: Jan 9, 2022
 *      Author: Arjun Venkatesh
 */

#ifndef INC_NIXIE_DIPLAY_H_
#define INC_NIXIE_DIPLAY_H_

// Includes
#include "main.h"


/**
 * Initializes the shift register for the 10 digit Nixie display.
 *
 * Makes sure the outputs are disabled, then clears the shift and storage
 * registers
 */
void InitializeDisplay();

/**
 * Turns the display on.
 */
void TurnOnDisplay();

/**
 * Turns the display off.
 */
void TurnOffDisplay();


#endif /* INC_NIXIE_DIPLAY_H_ */
