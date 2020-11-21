#pragma once
#include "stdio.h"
#include "iostream"
int continumax(char *outputstr, char *inputstr)
{
	int length = 0, max = 0; char *tempstr = inputstr;//C风格字符串需要分配内存
	while (*inputstr)
	{
		if (*inputstr>'9' || *inputstr<'0')
		{
			length = 0; inputstr++;
		}
		if (*inputstr <= '9'&&*inputstr >= '0')
		{
			tempstr[length] = *inputstr++;
			length = length + 1;
		}
		if (length>max)
		{
			max = length;
		}
	}
	outputstr = tempstr;
	outputstr[max] = '\0';
	return max;
}


int det_value = 0;
int temp_data[9] = {};

void print(int* data, int rows, int cols) {
	for (int i = 0; i < rows * cols; i++) {
		std::cout << data[i] << ", ";
	}
	std::cout << endl;
}

int det_linear_algera(int* data, int rows, int cols) {
	assert(rows == cols);
	if (rows == 2) {
		return  (data[0] * data[3] - data[1] * data[2]);
	}
#if 1
	if (rows == 3) {
		return data[0] * data[4] * data[8] + data[1] * data[5] * data[6] + data[2] * data[3] * data[7]
			- (data[2] * data[4] * data[6] + data[0] * data[5] * data[7] + data[1] * data[3] * data[8]);
	}
#endif
	int temp_sum = 0;
	if (rows >= 3) {
		int *temp = (int*)malloc((cols - 1) * (rows - 1) * sizeof(int));
		for (int i = 0; i < cols; i++) {
			int drows = 0;
			int idx = 0;
			for (int m = 0; m < rows; m++) {
				for (int n = 0; n < cols; n++) {
					if (m == drows) continue;
					if (n == i) continue;
					temp[idx] = data[m *cols + n];
					idx++;
				}
			}

			int temp_aa = data[drows * cols + i] * std::pow(-1., (drows + i + 2)) *det_linear_algera(temp, rows - 1, cols - 1);
			temp_sum += temp_aa;
		}
		free(temp);
		return temp_sum;
	}
}