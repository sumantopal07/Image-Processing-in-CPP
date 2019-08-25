#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[])
{
	// IMAGE OUTPUT
	FILE *fo = fopen("lenaNew.bmp","wb");
    int i;
	// IMAGE INPUT
	FILE *streamIn;streamIn = fopen("lena512.bmp", "rb");
    // CHECK OPENED SUCCESSFULLY OR NOT
    if (streamIn == (FILE *)0)
	{
	    printf("File opening error occurred. Exiting program.\n");
        exit(0);
 	}
 	unsigned char header[54]; // to store the image header
	unsigned char colorTable[1024]; // to store the colorTable, if it exists.
 	int count = 0;
 	//READ BMP HEADER
 	for(i=0;i<54;i++)
 		header[i] = getc(streamIn);
 	int width = *(int*)&header[18];
 	int height = *(int*)&header[22];
	int bitDepth = *(int*)&header[28]; // no. of bits/pixel

	if(bitDepth <= 8)
    {
        //WRITE IMAGE HEADER
        fwrite(header, sizeof(unsigned char), 54, fo);
        //READ THEN WRITE COLOR TABLE
        fread(colorTable, sizeof(unsigned char), 1024, streamIn);
        fwrite(colorTable, sizeof(unsigned char), 1024, fo);
        //READ THEN WRITE IMAGE DATA
        unsigned char buf[height * width];
        fread(buf, sizeof(unsigned char), (height * width), streamIn);//STREAMIN->BUFFER
        fwrite(buf, sizeof(unsigned char), (height * width), fo);

	}
	fclose(fo);
 	fclose(streamIn);
}
