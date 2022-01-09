#include "nixie_diplay.h"

/**
 * Sets nOE bit high
 */
void TurnOffDisplay() {
	HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_SET);
}

/**
 * Set nOE bit low.
 */
void TurnOnDisplay() {
	HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_RESET);
}

/**
 * Turns off display and toggles nSRCLR and RCLK
 */
void InitializeDisplay() {
	// Start with outputs disabled
	TurnOffDisplay();

	// Clear shift register and storage register
	HAL_GPIO_WritePin(nSRCLR_GPIO_Port, nSRCLR_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(nSRCLR_GPIO_Port, nSRCLR_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, GPIO_PIN_RESET);
}
