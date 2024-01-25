#include "main.h"

void fnd(int current_floor)
{
	if (current_floor == 1)
	{
		HAL_GPIO_WritePin(FND_a_GPIO_Port, FND_a_Pin, 1);
		HAL_GPIO_WritePin(FND_b_GPIO_Port, FND_b_Pin, 0);
		HAL_GPIO_WritePin(FND_c_GPIO_Port, FND_c_Pin, 0);
		HAL_GPIO_WritePin(FND_d_GPIO_Port, FND_d_Pin, 1);
		HAL_GPIO_WritePin(FND_e_GPIO_Port, FND_e_Pin, 1);
		HAL_GPIO_WritePin(FND_f_GPIO_Port, FND_f_Pin, 1);
		HAL_GPIO_WritePin(FND_g_GPIO_Port, FND_g_Pin, 1);
	}
	else if (current_floor == 2)
	{
		HAL_GPIO_WritePin(FND_a_GPIO_Port, FND_a_Pin, 0);
		HAL_GPIO_WritePin(FND_b_GPIO_Port, FND_b_Pin, 0);
		HAL_GPIO_WritePin(FND_c_GPIO_Port, FND_c_Pin, 1);
		HAL_GPIO_WritePin(FND_d_GPIO_Port, FND_d_Pin, 0);
		HAL_GPIO_WritePin(FND_e_GPIO_Port, FND_e_Pin, 0);
		HAL_GPIO_WritePin(FND_f_GPIO_Port, FND_f_Pin, 1);
		HAL_GPIO_WritePin(FND_g_GPIO_Port, FND_g_Pin, 0);
	}
	else if (current_floor == 3)
	{
		HAL_GPIO_WritePin(FND_a_GPIO_Port, FND_a_Pin, 0);
		HAL_GPIO_WritePin(FND_b_GPIO_Port, FND_b_Pin, 0);
		HAL_GPIO_WritePin(FND_c_GPIO_Port, FND_c_Pin, 0);
		HAL_GPIO_WritePin(FND_d_GPIO_Port, FND_d_Pin, 0);
		HAL_GPIO_WritePin(FND_e_GPIO_Port, FND_e_Pin, 1);
		HAL_GPIO_WritePin(FND_f_GPIO_Port, FND_f_Pin, 1);
		HAL_GPIO_WritePin(FND_g_GPIO_Port, FND_g_Pin, 0);
	}
	else if (current_floor == 4)
	{
		HAL_GPIO_WritePin(FND_a_GPIO_Port, FND_a_Pin, 1);
		HAL_GPIO_WritePin(FND_b_GPIO_Port, FND_b_Pin, 0);
		HAL_GPIO_WritePin(FND_c_GPIO_Port, FND_c_Pin, 0);
		HAL_GPIO_WritePin(FND_d_GPIO_Port, FND_d_Pin, 1);
		HAL_GPIO_WritePin(FND_e_GPIO_Port, FND_e_Pin, 1);
		HAL_GPIO_WritePin(FND_f_GPIO_Port, FND_f_Pin, 0);
		HAL_GPIO_WritePin(FND_g_GPIO_Port, FND_g_Pin, 0);
	}
	else
	{
		HAL_GPIO_WritePin(FND_a_GPIO_Port, FND_a_Pin, 1);
		HAL_GPIO_WritePin(FND_b_GPIO_Port, FND_b_Pin, 1);
		HAL_GPIO_WritePin(FND_c_GPIO_Port, FND_c_Pin, 1);
		HAL_GPIO_WritePin(FND_d_GPIO_Port, FND_d_Pin, 1);
		HAL_GPIO_WritePin(FND_e_GPIO_Port, FND_e_Pin, 1);
		HAL_GPIO_WritePin(FND_f_GPIO_Port, FND_f_Pin, 1);
		HAL_GPIO_WritePin(FND_g_GPIO_Port, FND_g_Pin, 1);
	}
}
