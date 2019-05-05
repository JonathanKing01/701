#include <stdio.h>

#define columns 352
#define rows 288

void sobel_filter(unsigned char input[columns][rows][3],
                  unsigned char output[columns][rows][3]) {

	// unsigned char data*** = new unsigned char**[columns];
	// for (int i = 0; i < columns; i++) {
	// 	data[i] = new unsigned char*[rows];
	// 	for (int j = 0; j < rows; j++) {
	// 		data[i][j] = new unsigned char*[3];
	// 	}
	// }

		lp: for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
//				int R1 = 1052 * input[i][j][0];
//				int R2 = 1799 * input[i][j][0];
//				int R3 = -607 * input[i][j][0];
//
//				int G1 = 2065 * input[i][j][1];
//				int G2 = -1507 * input[i][j][1];
//				int G3 = -1192 * input[i][j][1];
//
//				int B1 = 401 * input[i][j][2];
//				int B2 = -292 * input[i][j][2];
//				int B3 = 1799 * input[i][j][2];

				int R1 =  (input[i][j][0]<<10) + (input[i][j][0]<<4) + (input[i][j][0]<<3) + (input[i][j][0]<<2);
				int R2 =  (input[i][j][0]<<11) - (input[i][j][0]<<8) + (input[i][j][0]<<2) + input[i][j][0] + input[i][j][0] + input[i][j][0];
				int R3 =  -(input[i][j][0]<<9) - (input[i][j][0]<<6) - (input[i][j][0]<<5) + input[i][j][0];

				int G1 =  (input[i][j][1]<<11) + (input[i][j][1]<<4) + input[i][j][1];
				int G2 =  - (input[i][j][1]<<10) - (input[i][j][1]<<9) + (input[i][j][1]<<5) - input[i][j][1] - input[i][j][1] - input[i][j][1];
				int G3 =  -(input[i][j][1]<<10) - (input[i][j][1]<<7) - (input[i][j][1]<<5) - (input[i][j][1]<<3);

				int B1 =  (input[i][j][2]<<9) - (input[i][j][2]<<7) + (input[i][j][2]<<4) + input[i][j][2];
				int B2 =  - (input[i][j][2]<<8) - (input[i][j][2]<<5) - (input[i][j][2]<<2);
				int B3 =  (input[i][j][2]<<11) - (input[i][j][2]<<8) + (input[i][j][2]<<2) + input[i][j][2] + input[i][j][2] + input[i][j][2];
				
				output[i][j][0] = (65536+R1+G1+B1)>>12;
				output[i][j][1] = (524288+R2+G2+B2)>>12;
				output[i][j][2] = (524288+R3+G3+B3)>>12;
			}
		}

}

// C program to find the execution time of code
int main()
{
	unsigned char in[columns][rows][3];
	unsigned char out[columns][rows][3];
	sobel_filter(in, out);

	return 0;
}
