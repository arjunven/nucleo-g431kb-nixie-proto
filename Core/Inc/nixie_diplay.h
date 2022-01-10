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


// Constants
#define HIGH 1
#define LOW 0


/**
 * Initializes the shift register for the 10 digit Nixie tube.
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

/**
 * Writes the input number between 0 and 9 to the Nixie Display
 */
void DisplayNumber(int n);

#endif /* INC_NIXIE_DIPLAY_H_ */
