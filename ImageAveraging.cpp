#include<bits/stdc++.h>
using namespace std;
int main(int argc,char *argv[])
{
	// IMAGE OUTPUT
	FILE *fo = fopen("lenaNew1.bmp","wb");
    int i;
	// IMAGE INPUT
	FILE *streamIn1;streamIn1 = fopen("158.bmp", "rb");
	FILE *streamIn2;streamIn2 = fopen("159.bmp", "rb");
	FILE *streamIn3;streamIn3 = fopen("160.bmp", "rb");
    // CHECK OPENED SUCCESSFULLY OR NOT
 	unsigned char header1[54],header2[54],header3[54]; // to store the image header
	unsigned char colorTable1[1024],colorTable2[1024],colorTable3[1024]; // to store the colorTable, if it exists.
 	int count = 0;
 	//READ BMP HEADER
 	for(i=0;i<54;i++)
    {
        header1[i] = getc(streamIn1);
        header2[i] = getc(streamIn2);
        header3[i] = getc(streamIn3);
 	}
 	int width = *(int*)&header1[18];
 	int height = *(int*)&header1[22];
	int bitDepth = *(int*)&header1[28]; // no. of bits/pixel
    if(bitDepth <= 8)
    {
        //WRITE IMAGE HEADER
        fwrite(header1, sizeof(unsigned char), 54, fo);
        //READ THEN WRITE COLOR TABLE
        fread(colorTable1, sizeof(unsigned char), 1024, streamIn1);
        fwrite(colorTable1, sizeof(unsigned char), 1024, fo);
        //READ IMAGE
        unsigned char *newImageData,*oldImage1,*oldImage2,*oldImage3;
        oldImage1 = (unsigned char*)malloc(width*height*sizeof(unsigned char));
        oldImage2 = (unsigned char*)malloc(width*height*sizeof(unsigned char));
        oldImage3 = (unsigned char*)malloc(width*height*sizeof(unsigned char));
        newImageData = (unsigned char*)malloc(width*height*sizeof(unsigned char));
        fread( oldImage1, sizeof(unsigned char), width*height, streamIn1);
        fread( oldImage2, sizeof(unsigned char), width*height, streamIn2);
        fread( oldImage3, sizeof(unsigned char), width*height, streamIn3);
        //MANIPULATE IMAGE
        int sum=0,k1=0;
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                sum=oldImage1[i*width+j]+oldImage2[i*width+j]+oldImage3[i*width+j];
                sum/=3;
                newImageData[i*width+j]=sum;
            }
        }
        //WRITE IMAGE
        fwrite( newImageData, sizeof(unsigned char), width*height, fo);
	}
	fclose(fo);
 	fclose(streamIn1);
 	fclose(streamIn2);
 	fclose(streamIn3);
}
