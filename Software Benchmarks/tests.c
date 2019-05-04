#include <stdio.h>
#include <time.h>	// for clock_t, clock()

#define columns 352
#define rows 288

#define C1 1004
#define C3 851
#define C5 569
#define C6 392
#define S6 946
#define C7 200
#define R2 181

// Code based on code at https://stackoverflow.com/questions/16345140/why-this-implementation-of-foward-dct-of-lofflers-version-doesnt-work
void dct(int in[8][8], int dct[8][8], int xpos, int ypos) {
    
    float row[8][8];

    int x0, x1, x2, x3, x4, x5, x6, x7;
    int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;

    int tmp10, tmp11, tmp12, tmp13;
    int z1, z2, z3, z4, z5;

    /* transform rows */
    for (int i = 0; i < 8; i++) {

        x0 = in[xpos + 0][ypos + i];
        x1 = in[xpos + 1][ypos + i];
        x2 = in[xpos + 2][ypos + i];
        x3 = in[xpos + 3][ypos + i];
        x4 = in[xpos + 4][ypos + i];
        x5 = in[xpos + 5][ypos + i];
        x6 = in[xpos + 6][ypos + i];
        x7 = in[xpos + 7][ypos + i];

        tmp0 = x0 + x7;
        tmp7 = x0 - x7;
        tmp1 = x1 + x6;
        tmp6 = x1 - x6;
        tmp2 = x2 + x5;
        tmp5 = x2 - x5;
        tmp3 = x3 + x4;
        tmp4 = x3 - x4;

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        row[i][0] = tmp10 + tmp11;
        row[i][4] = tmp10 - tmp11;

        row[i][2] = (R2 * (tmp12 * C6 + tmp13 * S6)) >> 17;
        row[i][6] = (R2 * (tmp13 * C6 - tmp12 * S6)) >> 17;
        
        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = (z3 + z4) * R2 * C3;

        tmp4 = tmp4 * R2 * (-C1 + C3 + C5 - C7);
        tmp5 = tmp5 * R2 * (C1 + C3 - C5 + C7);
        tmp6 = tmp6 * R2 * (C1 + C3 + C5 - C7);
        tmp7 = tmp7 * R2 * (C1 + C3 - C5 - C7);

        z1 = z1 * R2 * (C7 - C3);
        z2 = z2 * R2 * (-C1 - C3);
        z3 = z3 * R2 * (-C3 - C5);
        z4 = z4 * R2 * (C5 - C3);

        z3 += z5;
        z4 += z5;

        row[i][7] = (tmp4 + z1 + z3) >> 17;
        row[i][5] = (tmp5 + z2 + z4) >> 17;
        row[i][3] = (tmp6 + z2 + z3) >> 17;
        row[i][1] = (tmp7 + z1 + z4) >> 17;
    }

    /* transform columns */
    for (int i = 0; i < 8; i++) {

        x0 = row[0][i];
        x1 = row[1][i];
        x2 = row[2][i];
        x3 = row[3][i];
        x4 = row[4][i];
        x5 = row[5][i];
        x6 = row[6][i];
        x7 = row[7][i];

        tmp0 = x0 + x7;
        tmp7 = x0 - x7;
        tmp1 = x1 + x6;
        tmp6 = x1 - x6;
        tmp2 = x2 + x5;
        tmp5 = x2 - x5;
        tmp3 = x3 + x4;
        tmp4 = x3 - x4;

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        dct[0][i] = (tmp10 + tmp11) >> 3;
        dct[4][i] = (tmp10 - tmp11) >> 3;

        dct[2][i] = (R2 * (tmp12 * C6 + tmp13 * S6)) >> 20;
        dct[6][i] = (R2 * (tmp13 * C6 - tmp12 * S6)) >> 20;

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = (z3 + z4) * R2 * C3;

        tmp4 = tmp4 * R2 * (-C1 + C3 + C5 - C7);
        tmp5 = tmp5 * R2 * (C1 + C3 - C5 + C7);
        tmp6 = tmp6 * R2 * (C1 + C3 + C5 - C7);
        tmp7 = tmp7 * R2 * (C1 + C3 - C5 - C7);

        z1 = z1 * R2 * (C7 - C3);
        z2 = z2 * R2 * (-C1 - C3);
        z3 = z3 * R2 * (-C3 - C5);
        z4 = z4 * R2 * (C5 - C3);

        z3 += z5;
        z4 += z5;

        dct[7][i] = (tmp4 + z1 + z3) >> 20;
        dct[5][i] = (tmp5 + z2 + z4) >> 20;
        dct[3][i] = (tmp6 + z2 + z3) >> 20;
        dct[1][i] = (tmp7 + z1 + z4) >> 20;
    }

}

void YCrCb(unsigned char input[columns][rows][3],
                  unsigned char output[columns][rows][3]) {

	for(int k = 0; k < 10; k++){
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				    int R1 = 1052 * input[i][j][0];
				int r2 = 1799 * input[i][j][0];
				int R3 = -607 * input[i][j][0];
				
				int G1 = 2065 * input[i][j][1];
				int G2 = -1507 * input[i][j][1];
				int G3 = -1192 * input[i][j][1];
				
				int B1 = 401 * input[i][j][2];
				int B2 = -292 * input[i][j][2];
				int B3 = 1799 * input[i][j][2];
				
				output[i][j][0] = (65536+R1+G1+B1)>>12;
				output[i][j][1] = (524288+r2+G2+B2)>>12;
				output[i][j][2] = (524288+R3+G3+B3)>>12;
			}
		}
	}

	return;
}

// C program to find the execution time of code
int main()
{
	unsigned char data[columns][rows][3];
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			data[i][j][0] = 255;
			data[i][j][1] = 255;
			data[i][j][2] = 255;
		}
	}
	unsigned char out[columns][rows][3];

	int DCT[8][8];
    int in[8][8] = {12, 16, 19, 12, 12, 27, 51, 47,
                    16, 24, 12, 19, 12, 20, 39, 51,
                    24, 27, 8,  39, 35, 34, 24, 44,
                    40, 17, 28, 32, 24, 27, 8,  32,
                    34, 20, 28, 20, 12, 8,  19, 34,
                    19, 39, 12, 27, 27, 12, 8,  34,
                    8,  28, -5, 39, 34, 16, 12, 19,
                    20, 27, 8,  27, 24, 19, 19, 8};
	
	double time_spent = 0.0;
	clock_t begin = clock();	
	int y;
	for(int k = 0; k<400; k++){
	    YCrCb(data, out);
		// for(int i = 0; i<44; i++){
		// 	for(int j = 0; j<36; j++){ 
	    //         dct(in, DCT, 0, 0);
		// 	} 
		// }
	}
	clock_t end = clock();

	time_spent += (double)((end - begin)*1000) / CLOCKS_PER_SEC ;

	printf("Time elpased is %f milliseconds\n", time_spent);
	printf("Av case time is %f milliseconds\n", time_spent/400);

	return 0;
}
