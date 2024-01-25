#include "main.h"
#include "button.h"
#include "stdio.h"

extern void delay_us(unsigned long us);
extern int get_button(GPIO_TypeDef *GPIO, uint16_t GPIO_PIN, uint8_t button_number);
void set_rpm(int rpm);
void stepmotor_main_test(void);
void stepmotor_driver(int step);
void stepmotor_driver_test(int step);
void step_test(void);
// RPM (Revolutions Per Minutes) 분당회전수
// 1분 : 60sec : 1,000,000us * 60
// 1,000,000us : 1,000ms
// 4096 step : 1바퀴
// 4096 / 8(0.7도) : 512 sequence : 360도
// 1 sequence (8step) : 0.7도


// set_rpm(13)으로 지정시의 동작 상황
// 60,000,000us / 4096 / rpm
// 1126us (1스텝 idle 타임) x 4096 = 4.612.986us
//								  4.612ms
//								  4.6s
// 60 / 4.6						  13회전

void set_rpm(int rpm)	// rpm 1 ~ 13
{
	delay_us(60000000/4096/rpm);
	// 최대 speed 기준 (13) : delay_us(1126);
}

// 시계 방향으로 1회전 <-> 반시계 방향으로 1회전
void stepmotor_main_test(void)
{
	int direction = 0;
	while (1)
	{
		if (direction == 0 && get_button(BUTTON0_GPIO_Port, BUTTON0_Pin, 0) == BUTTON_PRESS)
		{
			direction = 1;
			printf("0\n");
		}
		if (direction == 1 && get_button(BUTTON0_GPIO_Port, BUTTON0_Pin, 0) == BUTTON_PRESS)
		{
			direction = 2;
		}
		if (direction == 1 && get_button(BUTTON1_GPIO_Port, BUTTON1_Pin, 1) == BUTTON_PRESS)
		{
			direction = 0;
			printf("1\n");
		}
		if (direction == 2 && get_button(BUTTON0_GPIO_Port, BUTTON0_Pin, 0) == BUTTON_PRESS)
		{
			direction = 1;
		}
		if (direction == 2 && get_button(BUTTON1_GPIO_Port, BUTTON1_Pin, 1) == BUTTON_PRESS)
		{
			direction = 0;
		}
		stepmotor_driver(direction);
	}
}

void step_test(void)
{
	// 시계 방향으로
	printf("front\n");
	for (int i = 0; i < 512; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			stepmotor_driver_test(j);
			set_rpm(13);
		}
	}

	// 반시계 방향으로
	printf("back\n");
	for (int i = 0; i < 512; i++)
	{
		for (int j = 7; j > -1; j--)
		{
			stepmotor_driver_test(j);
			set_rpm(13);
		}
	}
}

// direction : 0 - IDLE
//			   1 - clockwise
//			   2 -
void stepmotor_driver(int direction)
{
	static int step = 0;
	switch (step)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 1);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 1);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 1);
			break;
	}

	if (direction == 0)
	{
		step++;		// for (step=0; step < 0; step++
		step %= 8;
//		set_rpm(13);
	}
	else if (direction == 1)
	{
		step--;
		if (step < 0) step = 7;
//		set_rpm(13);
	}
}

void stepmotor_driver_test(int step)
{
	switch (step)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 1);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 1);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOD, IN1_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, IN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOD, IN4_Pin, 1);
			break;
	}
}
