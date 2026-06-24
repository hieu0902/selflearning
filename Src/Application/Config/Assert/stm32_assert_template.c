#include <stdint.h>
#include <stdio.h>
#include "stm32_assert_template.h"

void assert_failed(uint8_t* file, uint32_t line)
{
    printf("Wrong parameters value: file %s on line %ld\r\n", file, line);
    /* Infinite loop */
}