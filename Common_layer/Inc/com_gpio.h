/*
 * com_gpio.h
 *
 *  Created on: May 29, 2026
 *      Author: ksree
 */

#ifndef INC_COM_GPIO_H_
#define INC_COM_GPIO_H_

typedef enum
{
  gpio_pin_reset = 0,
  gpio_pin_set
}gpio_pinstate;


#define  gpioa          GPIOA
#define  gpiob          GPIOB
#define  gpioc          GPIOC
#define  gpiod          GPIOD
#define  gpioe          GPIOE
#define  gpiof          GPIOF
#define  gpiog          GPIOG
#define  gpioh          GPIOH



#define gpio_pin_0           GPIO_PIN_0                   /* Pin 0 selected    */
#define gpio_pin_1           GPIO_PIN_1                   /* Pin 1 selected    */
#define gpio_pin_2           GPIO_PIN_2                  /* Pin 2 selected    */
#define gpio_pin_3           GPIO_PIN_3                   /* Pin 3 selected    */
#define gpio_pin_4           GPIO_PIN_4                  /* Pin 4 selected    */
#define gpio_pin_5           GPIO_PIN_5                   /* Pin 5 selected    */
#define gpio_pin_6           GPIO_PIN_6                   /* Pin 6 selected    */
#define gpio_pin_7           GPIO_PIN_7                   /* Pin 7 selected    */
#define gpio_pin_8           GPIO_PIN_8                   /* Pin 8 selected    */
#define gpio_pin_9           GPIO_PIN_9                   /* Pin 9 selected    */
#define gpio_pin_10          GPIO_PIN_10                  /* Pin 10 selected   */
#define gpio_pin_11          GPIO_PIN_11                  /* Pin 11 selected   */
#define gpio_pin_12          GPIO_PIN_12                 /* Pin 12 selected   */
#define gpio_pin_13          GPIO_PIN_13                  /* Pin 13 selected   */
#define gpio_pin_14          GPIO_PIN_14                  /* Pin 14 selected   */
#define gpio_pin_15          GPIO_PIN_15                  /* Pin 15 selected   */
//#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

void GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, gpio_pinstate PinState);

gpio_pinstate GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


void MY_GPIO_Init(void);
void my_SystemClock_Config(void);
void MY_USART2_UART_Init(void);
//void MY_USART2_UART_Init(void)
//extern UART_HandleTypeDef huart2;

#endif /* INC_COM_GPIO_H_ */
