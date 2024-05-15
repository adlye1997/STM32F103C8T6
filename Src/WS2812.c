#include "WS2812.h"
#include "RGBdata.h"
#include "tim.h"

#define WS2812_HTIM htim2			 // 定时器
#define WS2812_CHANNEL TIM_CHANNEL_1 // 定时器通道

#define WS2812_SET_CNT 65
#define WS2812_RESET_CNT 20

#define NUM_LEDS 8						  // 灯珠数量
#define NUM_LEDS_DATA (NUM_LEDS * 24 + 1) // 灯珠数据数量

uint16_t leds[NUM_LEDS_DATA]; // 存储灯珠数据

// 0x000000
void AllOff(void)
{
	for (uint16_t i = 0; i < NUM_LEDS_DATA - 1; i++)
	{
		leds[i] = WS2812_RESET_CNT;
	}
	leds[NUM_LEDS_DATA - 1] = 0;
	ShowLed(leds);
}

// 0x808080
void AllGrey(void)
{
	for (uint16_t i = 0; i < NUM_LEDS_DATA - 1; i++)
	{
		if (i % 8 == 0)
		{
			leds[i] = WS2812_SET_CNT;
		}
		else
		{
			leds[i] = WS2812_RESET_CNT;
		}
	}
	leds[NUM_LEDS_DATA - 1] = 0;
	ShowLed(leds);
}

// 0xFFFFFF
void AllWhite(void)
{
	for (uint16_t i = 0; i < NUM_LEDS_DATA - 1; i++)
	{
		leds[i] = WS2812_SET_CNT;
	}
	leds[NUM_LEDS_DATA - 1] = 0;
	ShowLed(leds);
}

void InitLedData(void)
{
	for (uint16_t i = 0; i < NUM_LEDS_DATA - 1; i++)
	{
		leds[i] = WS2812_RESET_CNT;
	}
	leds[NUM_LEDS_DATA - 1] = 0;
}

void ShowLed(uint16_t *led)
{
	HAL_TIM_PWM_Start_DMA(&WS2812_HTIM, WS2812_CHANNEL, (uint32_t *)led, NUM_LEDS_DATA);
}

void RGB2Leds(uint32_t RGB, uint8_t led)
{
}
