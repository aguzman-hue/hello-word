#include "stm32f4xx_hal.h"

#define BUTTON_PIN GPIO_PIN_13
#define BUTTON_PORT GPIOC
#define LED_PIN GPIO_PIN_5
#define LED_PORT GPIOA

int main(void)
{
  HAL_Init();
  
  // Habilitar clocks
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  
  // Configurar botón (PC13) como entrada con pull-up
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = BUTTON_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BUTTON_PORT, &GPIO_InitStruct);
  
  // Configurar LED (PA5) como salida
  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
  
  while (1)
  {
    // Leer botón - LOW cuando está presionado (pull-up)
    if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_RESET)
    {
      HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET); // Encender LED
    }
    else
    {
      HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET); // Apagar LED
    }
    
    HAL_Delay(10); // Pequeño delay
  }
}