#include <stdio.h>

#define columns 352
#define rows 288

#define C1 1004
#define C3 851
#define C5 569
#define C6 392
#define S6 946
#define C7 200
#define R2 181
#define IR2 724
#define IR8 362
#define R8 2896
#define W1 2841 
#define W2 2676
#define W3 2408 
#define W5 1609
#define W6 1108 
#define W7 565 
#define S3 569
#define S1 200
#define S6 946


// Skeleton taken from https://stackoverflow.com/questions/16345140/why-this-implementation-of-foward-dct-of-lofflers-version-doesnt-work
void dct2D(int in[8][8], int dct[8][8], int xpos, int ypos) {
    
	loop: for(int k = 0; k< 1584; k++){
		float row[8][8];

		int x0, x1, x2, x3, x4, x5, x6, x7;
		int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;

		int tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17;
		int z1, z2, z3, z4, z5;

		/* transform rows */
		lp1: for (int i = 0; i < 8; i++) {

			x0 = in[xpos + 0][ypos + i];
			x1 = in[xpos + 1][ypos + i];
			x2 = in[xpos + 2][ypos + i];
			x3 = in[xpos + 3][ypos + i];
			x4 = in[xpos + 4][ypos + i];
			x5 = in[xpos + 5][ypos + i];
			x6 = in[xpos + 6][ypos + i];
			x7 = in[xpos + 7][ypos + i];

			//STAGE 1
			tmp0 = x0 + x7;
			tmp1 = x1 + x6;
			tmp2 = x2 + x5;
			tmp3 = x3 + x4;

			tmp4 = x3 - x4;
			tmp5 = x2 - x5;
			tmp6 = x1 - x6;
			tmp7 = x0 - x7;
			//printf("%d %d %d %d %d %d %d %d\n",tmp0 ,tmp1 ,tmp2 ,tmp3 ,tmp4 ,tmp5 ,tmp6 ,tmp7);

			//STAGE 2
			tmp10 = tmp0 + tmp3;
			tmp11 = tmp1 + tmp2;
			tmp12 = tmp1 - tmp2;
			tmp13 = tmp0 - tmp3;

			tmp14 = tmp4 * C3 + tmp7 * S3;
			tmp17 = tmp7 * C3 - tmp4 * S3;

			tmp15 = tmp5 * C1 + tmp6 * S1;
			tmp16 = tmp6 * C1 - tmp5 * S1;
			//printf("%d %d %d %d %d %d %d %d\n",tmp10 ,tmp11 ,tmp12 ,tmp13 ,x4 ,x5 ,x6 ,x7 );

			//STAGE 3

			tmp2 = tmp12 * C6 + tmp13 * S6;
			tmp3 = tmp13 * C6 - tmp12 * S6;
			tmp0 = tmp10 + tmp11;
			tmp1 = tmp10 - tmp11;

			tmp4 = tmp14 + tmp16;
			tmp5 = tmp17 - tmp15;
			tmp6 = tmp14 - tmp16;
			tmp7 = tmp17 + tmp15;
			//printf("%d %d %d %d %d %d %d %d\n",tmp0 ,tmp1 ,tmp2 ,tmp3 ,tmp4 ,tmp5 ,tmp6 ,tmp7);

			//STAGE 4

			int out0 = tmp0;
			int out1 = tmp1;
			int out2 = tmp2 >> 10;
			int out3 = tmp3 >> 10;
			int out4 = (tmp4 - tmp7);
			int out5 = (tmp5 * R2);
			int out6 = (tmp6 * R2);
			int out7 = (tmp4 + tmp7);

			//printf("%d %d %d %d %d %d %d %d\n",out0 ,out1 ,out2 ,out3 ,out4 ,out5 ,out6 ,out7);
			out4 = out4 >> 10;
			out5 = out5 >> 17;
			out6 = out6 >> 17;
			out7 = out7 >> 10;
			//printf("%d %d %d %d %d %d %d %d\n",out0 ,out1 ,out2 ,out3 ,out4 ,out5 ,out6 ,out7);

			row[i][0] = out0;//*IR8 >> 10;
			row[i][4] = out1;//*IR8 >> 10;
			row[i][2] = out2;//*IR8 >> 10;
			row[i][6] = out3;//*IR8 >> 10;
			row[i][7] = out4;//*IR8 >> 10;
			row[i][3] = out5;//*IR8 >> 10;
			row[i][5] = out6;//*IR8 >> 10;
			row[i][1] = out7;//*IR8 >> 10;
		}



		/* transform columns */
		lp2: for (int i = 0; i < 8; i++) {

			int x0, x1, x2, x3, x4, x5, x6, x7, x8;

			int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;

			int tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17;
			int z1, z2, z3, z4, z5;

			x0 = row[0][i];
			x1 = row[1][i];
			x2 = row[2][i];
			x3 = row[3][i];
			x4 = row[4][i];
			x5 = row[5][i];
			x6 = row[6][i];
			x7 = row[7][i];
	//        printf("%d %d %d %d %d %d %d %d\n",x0 ,x1 ,x2 ,x3 ,x4 ,x5 ,x6 ,x7);

			//STAGE 1
			tmp0 = x0 + x7;
			tmp1 = x1 + x6;
			tmp2 = x2 + x5;
			tmp3 = x3 + x4;

			tmp4 = x3 - x4;
			tmp5 = x2 - x5;
			tmp6 = x1 - x6;
			tmp7 = x0 - x7;
			//printf("%d %d %d %d %d %d %d %d\n",tmp0 ,tmp1 ,tmp2 ,tmp3 ,tmp4 ,tmp5 ,tmp6 ,tmp7);

			//STAGE 2
			tmp10 = tmp0 + tmp3;
			tmp11 = tmp1 + tmp2;
			tmp12 = tmp1 - tmp2;
			tmp13 = tmp0 - tmp3;

			tmp14 = tmp4 * C3 + tmp7 * S3;
			tmp17 = tmp7 * C3 - tmp4 * S3;

			tmp15 = tmp5 * C1 + tmp6 * S1;
			tmp16 = tmp6 * C1 - tmp5 * S1;
			//printf("%d %d %d %d %d %d %d %d\n",tmp10 ,tmp11 ,tmp12 ,tmp13 ,x4 ,x5 ,x6 ,x7 );

			//STAGE 3

			tmp2 = tmp12 * C6 + tmp13 * S6;
			tmp3 = tmp13 * C6 - tmp12 * S6;
			tmp0 = tmp10 + tmp11;
			tmp1 = tmp10 - tmp11;

			tmp4 = tmp14 + tmp16;
			tmp5 = tmp17 - tmp15;
			tmp6 = tmp14 - tmp16;
			tmp7 = tmp17 + tmp15;
			//printf("%d %d %d %d %d %d %d %d\n",tmp0 ,tmp1 ,tmp2 ,tmp3 ,tmp4 ,tmp5 ,tmp6 ,tmp7);

			//STAGE 4

			int out0 = tmp0;
			int out1 = tmp1;
			int out2 = tmp2 >> 10;
			int out3 = tmp3 >> 10;
			int out4 = (tmp4 - tmp7);
			int out5 = (tmp5 * R2);
			int out6 = (tmp6 * R2);
			int out7 = (tmp4 + tmp7);

			//printf("%d %d %d %d %d %d %d %d\n",out0 ,out1 ,out2 ,out3 ,out4 ,out5 ,out6 ,out7);
			out4 = out4 >> 10;
			out5 = out5 >> 17;
			out6 = out6 >> 17;
			out7 = out7 >> 10;
			//printf("%d %d %d %d %d %d %d %d\n",out0 ,out1 ,out2 ,out3 ,out4 ,out5 ,out6 ,out7);

			dct[0][i] = out0;//*IR8 >> 10;
			dct[4][i] = out1;//*IR8 >> 10;
			dct[2][i] = out2;//*IR8 >> 10;
			dct[6][i] = out3;//*IR8 >> 10;
			dct[7][i] = out4;//*IR8 >> 10;
			dct[3][i] = out5;//*IR8 >> 10;
			dct[5][i] = out6;//*IR8 >> 10;
			dct[1][i] = out7;//*IR8 >> 10;
		}


		for(int i = 0; i< 8; i++){
			for(int j = 0; j< 8; j++){
				dct[i][j] = dct[i][j]/8;
			}
		}
	}
}



// C program to find the execution time of code
int main()
{


	int DCT[8][8];
    int output[8][8];
    int in[8][8] = {8, 16, 24, 32, 40, 48, 56, 64,
                    16, 24, 12, 19, 12, 20, 39, 51,
                    24, 27, 8,  39, 35, 34, 24, 44,
                    40, 17, 28, 32, 24, 27, 8,  32,
                    34, 20, 28, 20, 12, 8,  19, 34,
                    19, 39, 12, 27, 27, 12, 8,  34,
                    8,  28, -5, 39, 34, 16, 12, 19,
                    20, 27, 8,  27, 24, 19, 19, 8};
	
//    loop: for(int i = 0; i<1584; i++){
    dct2D(in, DCT, 0, 0);
    for(int i = 0; i< 8; i++){
		for(int j = 0; j< 8; j++){
			printf("%d ", DCT[i][j]);
		}
		printf("\n");
	}
//    }

	return 0;
}
