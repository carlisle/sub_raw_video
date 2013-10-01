#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define RAW01_PATH "E:\\Work\\VS_Proj\\fpn\\fpn\\fpn\\raw01.raw"
#define RAW02_PATH "E:\\Work\\VS_Proj\\fpn\\fpn\\fpn\\raw02.raw"
#define RAW03_PATH "E:\\Work\\VS_Proj\\fpn\\fpn\\fpn\\raw03.raw"

int sub_raw_pic()
{

FILE *raw01 = fopen(RAW01_PATH,"rb");
FILE *raw02 = fopen(RAW02_PATH,"rb");
FILE *raw03 = fopen(RAW03_PATH,"wb");

char buf01[1];
char buf02[1];

int done01;
int done02;
int cnt = 0;

	done01 = fread(buf01,1,1,raw01);
	done02 = fread(buf02,1,1,raw02);

int sub_temp = 19;

while (done01 && done02)
{

	if(buf02[0] >= buf01[0])
			sub_temp = buf02[0] - buf01[0];
	else
			sub_temp = 0;
	

		fwrite(&sub_temp,1,1,raw03);

		done01 = fread(buf01,1,1,raw01);
		done02 = fread(buf02,1,1,raw02);

		cnt++;
}		

fclose(raw01);
fclose(raw02);
fclose(raw03);

return 0 ; 

}
