#include "main.h"

int dotmatrix_main_test();
void init_dotmatrix(void);

GPIO_TypeDef *col_port[] =
{
		COL1_GPIO_Port, COL2_GPIO_Port, COL3_GPIO_Port, COL4_GPIO_Port,
		COL5_GPIO_Port, COL6_GPIO_Port, COL7_GPIO_Port, COL8_GPIO_Port
};

GPIO_TypeDef *row_port[] =
{
		ROW1_GPIO_Port, ROW2_GPIO_Port, ROW3_GPIO_Port, ROW4_GPIO_Port,
		ROW5_GPIO_Port, ROW6_GPIO_Port, ROW7_GPIO_Port, ROW8_GPIO_Port
};

uint16_t row_pin[] =
{
		ROW1_Pin, ROW2_Pin, ROW3_Pin, ROW4_Pin, ROW5_Pin, ROW6_Pin, ROW7_Pin, ROW8_Pin
};

uint16_t col_pin[] =
{
		COL1_Pin, COL2_Pin, COL3_Pin, COL4_Pin, COL5_Pin, COL6_Pin, COL7_Pin, COL8_Pin
};

const unsigned char blank[8] =
{
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
};

unsigned char number_data[20][10] =
{
	{
		0b01110000,	//0
		0b10001000,
		0b10011000,
		0b10101000,
		0b11001000,
		0b10001000,
		0b01110000,
	    0b00000000
	},
	{
		0b01000000,	//1
		0b11000000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b11100000,
	    6   // 점 0b00000110
	},
	{
		0b01110000,	//2
		0b10001000,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b11111000,
	    6
	},
	{
		0b11111000,	//3
	    0b00010000,
		0b00100000,
		0b00010000,
		0b00001000,
		0b10001000,
		0b01110000,
	    6
	},
	{
		0b00010000,	//4
		0b00110000,
		0b01010000,
		0b10010000,
		0b11111000,
		0b00010000,
		0b00010000,
	    6
	},
	{
		0b11111000,	//5
		0b10000000,
		0b11110000,
		0b00001000,
		0b00001000,
		0b10001000,
		0b01110000,
	    6
	},
	{
		0b00110000,	//6
		0b01000000,
		0b10000000,
		0b11110000,
		0b10001000,
		0b10001000,
		0b01110000,
	    6
	},
	{
		0b11111000,	//7
		0b10001000,
		0b00001000,
		0b00010000,
		0b00100000,
		0b00100000,
		0b00100000,
	    6
	},
	{
		0b01110000,	//8
		0b10001000,
		0b10001000,
		0b01110000,
		0b10001000,
		0b10001000,
		0b01110000,
	    6
	},
	{
		0b01110000,	//9
		0b10001000,
		0b10001000,
		0b01111000,
		0b00001000,
		0b00010000,
		0b01100000,
	    6
	},
	{
		0b00000000,    // hart
		0b01100110,
		0b11111111,
		0b11111111,
		0b11111111,
		0b01111110,
		0b00111100,
		0b00011000
	}
};

unsigned char elevator_up[8] =
{

	0b00000000,
	0b00001000,
	0b00001100,
	0b01111110,
	0b01111110,
	0b00001100,
	0b00001000,
	0b00000000
};

unsigned char elevator_down[8] =
{
	0b00000000,
	0b00010000,
	0b00110000,
	0b01111110,
	0b01111110,
	0b00110000,
	0b00010000,
	0b00000000
};

unsigned char display_data[8];	// 최종 8X8 출력할 데이터
//unsigned char scroll_buffer[50][8] = {0};	// 스크롤할 데이터가 들어있는 버퍼
//int number_of_character = 11;	// 출력할 문자 갯수

// 초기화 작업
// 1. display_data에 number_data[0]에 있는 데이터를 복사
// 2. number_data를 scroll_buffer에 복사
// 3. dotmatrix의 led를 off
//void init_dotmatrix(void)
//{
//	for (int i = 0; i < 8; i++)
//	{
//		display_data[i] = number_data[i];
//	}
//	for (int i = 1; i < number_of_character + 1; i++)
//	{
//		for (int j = 0; j < 8; j++)	// scroll_buffer[0] = blank
//		{
//			scroll_buffer[i][j] = number_data[i - 1][j];
//		}
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		HAL_GPIO_WritePin(col_port[i], col_pin[i], 1);	// led all off
//	}
//}


// all on 문자 정의
unsigned char all_on[] =
{
#if 0
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111,
		0b11111111

#else
		0b00000000,
		0b01111110,
		0b00001000,
		0b01111110,
		0b01111110,
		0b01000010,
		0b00111100,
		0b00000000
#endif
};

void write_column_data(int col)
{
	for (int i = 0; i < 8; i++)
	{
#if 1
		// common 애노우드
		if (i == col)
		{
			HAL_GPIO_WritePin(col_port[i], col_pin[i], 0);	// on
		}
		else
		{
			HAL_GPIO_WritePin(col_port[i], col_pin[i], 1);	// off
		}
	}
#else
		// common 캐소우드
		if (i == col)
		{
			HAL_GPIO_WritePin(col_port[i], col_pin[i], 1);	// on
		}
		else
		{
			HAL_GPIO_WritePin(col_port[i], col_pin[i], 0);	// off
		}
	}
#endif
}

// 0b00111100
void write_row_data(unsigned char data)
{
	unsigned char d;
	d = data;
	for (int i = 0; i < 8; i++)
	{
		if (d & (1 << i))
		{
			HAL_GPIO_WritePin(row_port[i], row_pin[i], 1);
		}
		else
		{
			HAL_GPIO_WritePin(row_port[i], row_pin[i], 0);
		}
	}
}

// scroll 문자 출력 프로그램
int dotmatrix_main_test()
{
	static int count = 0;	// 컬럼 count
	static uint32_t past_time = 0;	// 이전 tick 값 저장

//	init_dotmatrix();

		uint32_t now = HAL_GetTick();	// 1 msec timer
		// 처음 시작시 past_time = 0;
		// now : 500 --> past_time : 500
		if (now - past_time >= 100)		// 500msec scroll
		{
			past_time = now;
			for (int i = 0; i < 8; i++)
			{
				display_data[i] = (elevator_up[i] >> count) | (elevator_up[i] << (8 - count));
			}
			if (++count == 8)	// 8 column을 다 처리했으면 다음 scroll_buffer로 이동
			{
				count = 0;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			// common arrowed 공통 양육 방식
			// column에는 0을 row에는 1을 출력해
			write_column_data(i);
			write_row_data(display_data[i]);

			HAL_Delay(1);
		}

	return 0;
}

void dotmatrix_up(void)
{
	static int count = 0;	// 컬럼 count
	static uint32_t past_time = 0;	// 이전 tick 값 저장

	uint32_t now = HAL_GetTick();	// 1 msec timer
	// 처음 시작시 past_time = 0;
	// now : 500 --> past_time : 500
	if (now - past_time >= 100)		// 500msec scroll
	{
		past_time = now;
		for (int i = 0; i < 8; i++)
		{
			display_data[i] = (elevator_up[i] >> count) | (elevator_up[i] << (8 - count));
		}
		if (++count == 8)	// 8 column을 다 처리했으면 다음 scroll_buffer로 이동
		{
			count = 0;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		// common arrowed 공통 양육 방식
		// column에는 0을 row에는 1을 출력해
		write_column_data(i);
		write_row_data(display_data[i]);

		HAL_Delay(1);
	}
}

void dotmatix_down(void)
{
	static int count2 = 0;	// 컬럼 count
	static uint32_t past_time2 = 0;	// 이전 tick 값 저장

	uint32_t now2 = HAL_GetTick();	// 1 msec timer
	// 처음 시작시 past_time = 0;
	// now : 500 --> past_time : 500
	if (now2 - past_time2 >= 100)		// 500msec scroll
	{
		past_time2 = now2;
		for (int i = 0; i < 8; i++)
		{
			display_data[i] = (elevator_down[i] << count2) | (elevator_down[i] >> (8 - count2));
		}
		if (++count2 == 8)	// 8 column을 다 처리했으면 다음 scroll_buffer로 이동
		{
			count2 = 0;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		// common arrowed 공통 양육 방식
		// column에는 0을 row에는 1을 출력해
		write_column_data(i);
		write_row_data(display_data[i]);

		HAL_Delay(1);
	}
}

// 고정 문자 출력 demo program
void dotmatrix_stop(void)
{
	for (int i = 0; i < 8; i++)
	{
		// common arrowed 공통 양육 방식
		// column에는 0을 row에는 1을 출력해
		write_column_data(i);
		write_row_data(all_on[i]);

		HAL_Delay(1);
	}
}
