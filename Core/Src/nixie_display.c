// Includes
#include "nixie_diplay.h"

// Static function prototypes
static void ClearShiftRegister();
static void StoreToStorageRegister();
static void ShiftBit();
static void SetSerialBit(int state);

/**
 * Turns off display and toggles nSRCLR and RCLK
 */
void InitializeDisplay() {
  // Start with outputs disabled
  TurnOffDisplay();

  // Clear shift register and storage register
  ClearShiftRegister();
  StoreToStorageRegister();
}

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
 *
 */
void DisplayNumber(int n) {
  if(n >= 0 && n <= 9) {
    ClearShiftRegister();
    SetSerialBit(HIGH);
    ShiftBit();
    SetSerialBit(LOW);

    // Shift out n-1 times
    while(n > 0) {
      ShiftBit();
      n--;
    }

    StoreToStorageRegister();
  } else {
    // TODO some sort of out of bounds error handling
  }

}

/* STATIC FUNCITONS */

/**
 * Sets nSRCLR low to clear shift register
 */
static void ClearShiftRegister() {
  HAL_GPIO_WritePin(nSRCLR_GPIO_Port, nSRCLR_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(nSRCLR_GPIO_Port, nSRCLR_Pin, GPIO_PIN_SET);
}

/**
 * Rising edge on RCLK stores shift register data to storage register
 */
static void StoreToStorageRegister() {
  HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, GPIO_PIN_RESET);
}


/**
 * Rising edge on SRCLK shifts bits through shift register
 */
static void ShiftBit() {
  HAL_GPIO_WritePin(SRCLK_GPIO_Port, SRCLK_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(SRCLK_GPIO_Port, SRCLK_Pin, GPIO_PIN_RESET);
}

/**
 * Sets SER pin high or low
 */
static void SetSerialBit(int state) {
  if(state == HIGH) {
    HAL_GPIO_WritePin(SER_GPIO_Port, SER_Pin, GPIO_PIN_SET);
  } else if(state == LOW){
    HAL_GPIO_WritePin(SER_GPIO_Port, SER_Pin, GPIO_PIN_RESET);
  } else {
    // TODO some sort of error handling?
  }
}


