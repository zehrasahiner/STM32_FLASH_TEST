///*
// * bootloader.c
// *
// *  Created on: Sep 9, 2026
// *      Author: ZSAHINER
// */
//
//
////KISA EVENT BASED CALLBACK
//
//#include "bootloader.h"
//#include "main.h"
//
//static uint8_t received_byte = 0;
//static volatile uint8_t received_event = 0;
//
//void Bootloader_Init(void) {
//
//	HAL_UART_Receive_IT(&huart1, &received_byte, 1);
//
//}
//
//void Bootload(void) {
//	if (received_event) //    if (uart_rx_event = 1)
//	{
//
//		received_event = 0;
//
//		HAL_UART_Transmit(&huart1, &received_byte, 1, 100);
//		HAL_UART_Receive_IT(&huart1, &received_byte, 1, 100);
//
//	}
//
//}
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//
//	if (huart == &huart1) {
//
//		received_event = 1;
//	}
//
//}
//
