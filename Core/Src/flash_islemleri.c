//hazır bazı fonksiyonları kullandım.

#include "stm32f3xx_hal.h"

#define FLASH_TEST_ADDRESS  0x0800FC00U

uint16_t read_data = 0;

void Flash_Test(void)
{
    uint16_t written_data = 0x017A; // assii table'dan bir kelimenin harfleri toplamının hexadecimal ifadesi
   // uint16_t read_data = 0;
    uint32_t PageError = 0;

    FLASH_EraseInitTypeDef EraseInitStruct; //neyi, hangi adresten, kaç sayfa sileceğiz?

    //1. ADIM = KİLİDİ AÇ
    HAL_FLASH_Unlock();


    //2. ADIM SAYFAYI SİLME için yapılandırmalar
    EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.PageAddress = FLASH_TEST_ADDRESS;
    EraseInitStruct.NbPages     = 1;

    // 2. ADIM SAYFAYI SİLME
    HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);

    // 3. HALF WORD VERİ YAZMA (16 BİT)
    HAL_FLASH_Program(
        FLASH_TYPEPROGRAM_HALFWORD,
		FLASH_TEST_ADDRESS,
        written_data
    );

    // 4. ADIM TEKRRA KİLİT
    HAL_FLASH_Lock();

    // 5. ADIM OKUMA
    read_data = *(volatile uint16_t *)FLASH_TEST_ADDRESS;
}

