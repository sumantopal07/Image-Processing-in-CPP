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
        //READ IMAGE
        unsigned char *newImageData,*oldImage;
        oldImage = (unsigned char*)malloc(width*height*sizeof(unsigned char));
        newImageData = (unsigned char*)malloc(width*height*sizeof(unsigned char));
        fread( oldImage, sizeof(unsigned char), width*height, streamIn);
        //MANIPULATE IMAGE
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
                newImageData[i*width + j] = 255 - oldImage[i*width + j];
        }
        //WRITE IMAGE
        fwrite( newImageData, sizeof(unsigned char), width*height, fo);
	}
	fclose(fo);
 	fclose(streamIn);
}
