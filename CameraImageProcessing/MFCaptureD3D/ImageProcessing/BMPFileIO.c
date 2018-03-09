/*	BMPFileIO.c file
	Declare some functions about BMP file read & write implementation
	Develop by Jimmy HU <s103360021@gmail.com>
	This program is licensed under GNU General Public License v3.
*/

//-----include header files, �ޤJ���Y��-----
#include "BMPFileIO.h"													//	include "BMPFileIO.h" header files, �ޤJBMPFileIO.h

//----BMP���ɤj�p(Byte)Ū���Ƶ{��----
unsigned long BmpReadFilesize(const char *filename, const bool FilenameExtension)
//	BmpReadFilesize�Ƶ{��
{																		//	�i�JBMP���ɤj�p(Byte)Ū���Ƶ{��
	//***�ˬd�Ƶ{���ǤJ�ɦW***
	if(filename == NULL)												//	�Y��Jfilename��NULL
	{																	//	�i�Jif�ԭz
		printf("�ɮ׸��|��J��NULL\n");									//	���"�ɮ׸��|��J��NULL"�ô���
		return 0;														//	�^�Ǽƭ�0�A�õ����Ƶ{��
	}																	//	����if�ԭz
	//***�Ѧ�FilenameExtension�ܼƱ����ɦW�B�z�覡***
	char fname_bmp[MAX_PATH];											//	�ŧi�ɮצW��fname_bmp�}�C�ܼ�(�̦hMAX_PATH�Ӧr��) 
	if(FilenameExtension == false)										//	�Y��J�Ѽ�fname_bmp������ɦW
	{																	//	�i�Jif�ԭz
		sprintf(fname_bmp, "%s.bmp", filename);							//	���ͧ����ɮ׸��|�æs���fname_bmp�}�C
	}																	//	����if�ԭz
	else																//	�Y��J�Ѽ�fname_bmp�w�]�t���ɦW
	{																	//	�i�Jelse�ԭz
		strcpy(fname_bmp,filename);										//	������J�ɦW���|
	}																	//	����else�ԭz
	printf("���bŪ���U�C�ɮפj�p(Byte)�G%s\n",fname_bmp);				//	��ܵ{�����檬�A
	FILE *fp;															//	�ŧi�ɮ׫���fp�ϰ��ܼ�
	fp = fopen(fname_bmp, "rb");										//	�Hrb(�G�i��Ū��)�Ҧ��}���ɮ�
	if (fp==NULL)														//	�Y�}���ɮץ��� 
	{																	//	�i�Jif�ԭz 
		printf("Ū���ɮץ��ѡI\n");										//	��ܿ��~�T�� 
		return -1;														//	�Ǧ^-1�A�õ����Ƶ{�� 
	}																	//	����if�ԭz	 
	unsigned char header[54]; 											//	�ŧi���Y�]�wheader�}�C 
	fread(header, sizeof(unsigned char), 54, fp);						//	Ū�����Y�]�w
	unsigned long BmpRead_file_size;									//	�ŧiŪ��BMP�Ϥ��ɮפj�p(Byte)�ܼơA���A��unsigned long 
	BmpRead_file_size= header[2] + (header[3] << 8) + ( header[4] << 16) + ( header[5] << 24);
	//	�p���JBMP�Ϥ��ɮפj�p(Byte�A�줸��) 
	fclose(fp);															//	�����ɮ�
	return BmpRead_file_size;											//	�N�p��X�ɮפj�p�ƭ�(Byte)�Ǧ^ 
}																		//	����BMP���ɤj�p(Byte)Ū���Ƶ{�� 
//----BMP����xsize(�e��)Ū���Ƶ{��----
unsigned long BmpReadXSize(const char *filename, const bool FilenameExtension)
//	BMP����xsize(�e��)Ū���Ƶ{��
{																		//	�i�JBMP����xsize(�e��)Ū���Ƶ{��
	char fname_bmp[MAX_PATH];											//	�ŧi�ɮצW��fname_bmp�}�C�ܼ�(�̦hMAX_PATH�Ӧr��) 
	if(FilenameExtension == false)										//	�Y��J�Ѽ�fname_bmp������ɦW
	{																	//	�i�Jif�ԭz
		sprintf(fname_bmp, "%s.bmp", filename);							//	���ͧ����ɮ׸��|�æs���fname_bmp�}�C
	}																	//	����if�ԭz
	else																//	�Y��J�Ѽ�fname_bmp�w�]�t���ɦW
	{																	//	�i�Jelse�ԭz
		strcpy(fname_bmp,filename);										//	������J�ɦW���|
	}																	//	����else�ԭz
	printf("���bŪ���U�C�ɮ�xsize(�e��)�G%s\n",fname_bmp);				//	��ܵ{�����檬�A
	FILE *fp;															//	�ŧi�ɮ׫���fp�ϰ��ܼ�
	fp = fopen(fname_bmp, "rb");										//	�Hrb(�G�i��Ū��)�Ҧ��}���ɮ�
	if (fp==NULL)														//	�Y�}���ɮץ��� 
	{																	//	�i�Jif�ԭz 
		printf("Ū���ɮץ��ѡI\n");										//	��ܿ��~�T�� 
		return -1;														//	�Ǧ^-1�A�õ����Ƶ{�� 
	}																	//	����if�ԭz	 
	unsigned char header[54]; 											//	�ŧi���Y�]�wheader�}�C 
	fread(header, sizeof(unsigned char), 54, fp);						//	Ū�����Y�]�w
	unsigned long BmpReadXSize;											//	�ŧiŪ��BMP�Ϥ��ɮת�x(�e��)�j�p(����)�ܼơA���A��unsigned long 
	BmpReadXSize= header[18] + (header[19] << 8) + ( header[20] << 16) + ( header[21] << 24);
	//	�p���JBMP�Ϥ��ɮ�x(�e��)�j�p(����) 
	fclose(fp);															//	�����ɮ�
	return BmpReadXSize;												//	�N�p��XBMP�Ϥ��ɮ�x(�e��)�j�p(����)�ƭȶǦ^ 
}																		//	����BMP����xsize(�e��)Ū���Ƶ{�� 

//----BMP����ysize(����)Ū���Ƶ{��----
unsigned long BmpReadYSize(const char *filename, const bool FilenameExtension)
//	BMP����ysize(����)Ū���Ƶ{��
{																		//	�i�JBMP����ysize(����)Ū���Ƶ{��
	char fname_bmp[MAX_PATH];											//	�ŧi�ɮצW��fname_bmp�}�C�ܼ�(�̦hMAX_PATH�Ӧr��) 
	if(FilenameExtension == false)										//	�Y��J�Ѽ�fname_bmp������ɦW
	{																	//	�i�Jif�ԭz
		sprintf(fname_bmp, "%s.bmp", filename);							//	���ͧ����ɮ׸��|�æs���fname_bmp�}�C
	}																	//	����if�ԭz
	else																//	�Y��J�Ѽ�fname_bmp�w�]�t���ɦW
	{																	//	�i�Jelse�ԭz
		strcpy(fname_bmp,filename);										//	������J�ɦW���|
	}																	//	����else�ԭz
	printf("���bŪ���U�C�ɮ�ysize(����)�G%s\n",fname_bmp);				//	��ܵ{�����檬�A
	FILE *fp;															//	�ŧi�ɮ׫���fp�ϰ��ܼ�
	fp = fopen(fname_bmp, "rb");										//	�Hrb(�G�i��Ū��)�Ҧ��}���ɮ�
	if (fp==NULL)														//	�Y�}���ɮץ��� 
	{																	//	�i�Jif�ԭz 
		printf("Ū���ɮץ��ѡI\n");										//	��ܿ��~�T�� 
		return -1;														//	�Ǧ^-1�A�õ����Ƶ{�� 
	}																	//	����if�ԭz	 
	unsigned char header[54]; 											//	�ŧi���Y�]�wheader�}�C 
	fread(header, sizeof(unsigned char), 54, fp);						//	Ū�����Y�]�w
	unsigned long BmpReadYSize;											//	�ŧiŪ��BMP�Ϥ��ɮת�y(����)�j�p(����)�ܼơA���A��unsigned long 
	BmpReadYSize= header[22] + (header[23] << 8) + ( header[24] << 16) + ( header[25] << 24);
	//	�p���JBMP�Ϥ��ɮ�y(����)�j�p(����) 
	fclose(fp);															//	�����ɮ�
	return BmpReadYSize;												//	�N�p��XBMP�Ϥ��ɮ�y(����)�j�p(����)�ƭȶǦ^ 
}																		//	����BMP����ysize(����)Ū���Ƶ{�� 
//----BMP����Ū���Ƶ{��---- 
char BmpRead(unsigned char *image,const int xsize,const int ysize, const char *filename, const bool FilenameExtension)
{																		//	�i�JBMP����Ū���Ƶ{��
	char fname_bmp[MAX_PATH];											//	�ŧi�ɮצW��fname_bmp�}�C�ܼ�(�̦hMAX_PATH�Ӧr��) 
	if(FilenameExtension == false)										//	�Y��J�Ѽ�fname_bmp������ɦW
	{																	//	�i�Jif�ԭz
		sprintf(fname_bmp, "%s.bmp", filename);							//	���ͧ����ɮ׸��|�æs���fname_bmp�}�C
	}																	//	����if�ԭz
	else																//	�Y��J�Ѽ�fname_bmp�w�]�t���ɦW
	{																	//	�i�Jelse�ԭz
		strcpy(fname_bmp,filename);										//	������J�ɦW���|
	}																	//	����else�ԭz
	unsigned char FillingByte;											//	�ŧi��R�줸���ܼ�
	FillingByte = BmpFillingByteCalc(xsize);							//	�I�sBmpFillingByteCalc�Ƶ{���p���R���줸�ռƶq
	printf("���bŪ���ɮסG%s\n",fname_bmp);								//	��ܵ{�����檬�A
	FILE *fp;															//	�ŧi�ɮ׫���fp�ϰ��ܼ�
	fp = fopen(fname_bmp, "rb");										//	�Hrb(�G�i��Ū��)�Ҧ��}���ɮ�
	if (fp==NULL)														//	�Y�}���ɮץ��� 
	{																	//	�i�Jif�ԭz 
		printf("Ū���ɮץ��ѡI\n");										//	��ܿ��~�T�� 
		return -1;														//	�Ǧ^-1�A�õ����Ƶ{�� 
	}																	//	����if�ԭz	 
	unsigned char header[54]; 											//	�ŧi���Y�]�wheader�}�C 
	fread(header, sizeof(unsigned char), 54, fp);						//	Ū�����Y�]�w
	fread(image, sizeof(unsigned char), (size_t)(long)(xsize * 3 + FillingByte)*ysize, fp);
	//	Ū�����ɸ�� 
	fclose(fp);															//	�����ɮ� 
	return 0;															//	�Ǧ^0�õ����Ƶ{�� 
}																		//	����BMP����Ū���Ƶ{��
BMPIMAGE BmpFileRead(const char *filename, const bool FilenameExtension)
//	BmpFileRead�Ƶ{��
{																		//	�i�JBmpFileRead�Ƶ{��
	BMPIMAGE OutputData;												//	�ŧi��X��ƪŶ�
	strcpy(OutputData.FILENAME, "");									//	��l��OutputData
	OutputData.XSIZE = 0;												//	��l��OutputData
	OutputData.YSIZE = 0;												//	��l��OutputData
	OutputData.IMAGE_DATA = NULL;										//	��l��OutputData
	//***�ˬd�Ƶ{���ǤJ�ɦW***
	if(filename == NULL)												//	�Y��Jfilename��NULL
	{																	//	�i�Jif�ԭz
		printf("�ɮ׸��|��J��NULL\n");									//	���"�ɮ׸��|��J��NULL"�ô���
		return OutputData;												//	�^��OutputData�A�õ����Ƶ{��
	}																	//	����if�ԭz
	//***���ɦW���***
	char fname_bmp[MAX_PATH];											//	�ŧi�ɮצW��fname_bmp�}�C�ܼ�(�̦hMAX_PATH�Ӧr��) 
	if(FilenameExtension == false)										//	�Y��J�Ѽ�fname_bmp������ɦW
	{																	//	�i�Jif�ԭz
		sprintf(fname_bmp, "%s.bmp", filename);							//	���ͧ����ɮ׸��|�æs���fname_bmp�}�C
	}																	//	����if�ԭz
	else																//	�Y��J�Ѽ�fname_bmp�w�]�t���ɦW
	{																	//	�i�Jelse�ԭz
		strcpy(fname_bmp,filename);										//	������J�ɦW���|
	}																	//	����else�ԭz
	//***�T�{�ɮצs�b�ΥiŪ��***
	if (FileExistCheck(fname_bmp) == false)								//	�Y�ɮפ��s�b 
	{																	//	�i�Jif�ԭz 
		printf("�ɮ�%s���s�b�I\n",fname_bmp);							//	��ܿ��~�T�� 
		return OutputData;												//	�^��OutputData�A�õ����Ƶ{��
	}																	//	����if�ԭz	 
	if (FileReadPermissionCheck(fname_bmp) == false)					//	�Y�ɮפ��iŪ��
	{																	//	�i�Jif�ԭz 
		printf("Ū���ɮ׿��~�I\n");										//	��ܿ��~�T��
		return OutputData;												//	�^��OutputData�A�õ����Ƶ{��
	}																	//	����if�ԭz
	//***��J���ɸ�T��OutputData***
	strcpy(OutputData.FILENAME, fname_bmp);								//	��J�ɮ׸��|(�t���ɦW)
	OutputData.XSIZE = (unsigned int)BmpReadXSize(OutputData.FILENAME,true);
	//	Ū����JBMP���ɼe��(���|�w�]�t���ɦW) 
	OutputData.YSIZE = (unsigned int)BmpReadYSize(OutputData.FILENAME,true);
	//	Ū����JBMP���ɰ���(���|�w�]�t���ɦW) 
	if( (OutputData.XSIZE == -1) || (OutputData.YSIZE == -1) )			//	�YXSIZE��YSIZE��-1(�N��Ū���ɮץ���)	
	{																	//	�i�Jif�ԭz 
		printf("Ū�����ɤj�p��T����!");								//	���"Ū�����ɤj�p��T����!"
		return OutputData;												//	�^��OutputData�A�õ����Ƶ{��
	}																	//	����if�ԭz
	else																//	�YXSIZE�PYSIZE�Ҥ���-1(���`Ū���ɮ�)
	{																	//	�i�Jelse�ԭz 
		printf("��J���ɼe�סG%d\n",OutputData.XSIZE);					//	��ܿ�J���ɼe�׼ƭ� 
		printf("��J���ɰ��סG%d\n",OutputData.YSIZE);					//	��ܿ�J���ɰ��׼ƭ� 
		printf("��J�v���j�p(Byte)�G%d\n",(size_t)OutputData.XSIZE * OutputData.YSIZE * 3);
		//	��ܿ�J�v���j�p�ƭ�(Byte) 
		OutputData.FILLINGBYTE = BmpFillingByteCalc(OutputData.XSIZE);	//	�I�sBmpFillingByteCalc�Ƶ{���p���R���줸�ռƶq
		OutputData.IMAGE_DATA = (unsigned char*)malloc((OutputData.XSIZE * 3 + OutputData.FILLINGBYTE) * OutputData.YSIZE * sizeof(unsigned char));
		//	�p��ëإ߼v���j�p�Ŷ� 
		if (OutputData.IMAGE_DATA == NULL) 								//	�Y�إ߼v���Ŷ����� 
		{																//	�i�Jif�ԭz 
			printf("�O������t���~!");									//	���"�O������t���~!" 
			return OutputData;											//	�^��OutputData�A�õ����Ƶ{��
		}																//	����if�ԭz 
		else															//	�Y���o�Ϳ��~ 
		{																//	�i�Jelse�ԭz 
			int loop_num = 0;											//	�ŧi�ϰ��ܼ�loop_num�Ѱj��ϥ� 
			for(loop_num=0;loop_num<((OutputData.XSIZE * 3 + OutputData.FILLINGBYTE) * OutputData.YSIZE);loop_num++)
			//	�Hfor�j���l�ƨC�ӹ��� 
			{															//	�i�Jfor�j�� 
				OutputData.IMAGE_DATA[loop_num]=255;						//	��J�w�]������m�ƭ� 
			}															//	����for�j�� 
			BmpRead(OutputData.IMAGE_DATA, OutputData.XSIZE, OutputData.YSIZE, OutputData.FILENAME,true);
			//	Ū�����ɸ��
		}																//	����else�ԭz
	}																	//	����else�ԭz
	return OutputData;													//	�^��Ū�����
}																		//	����BmpFileRead�Ƶ{��
//----BMP���ɼg�J�Ƶ{��---- 
/*	BmpWriteV1�Ƶ{���{������BMP���ɼg�J�Aheader�}�C��BMP���ɤ����Y 
 *
 *
 */
 
int BmpWriteV1(const unsigned char *image,const int xsize,const int ysize,const char *filename) 
{																		//	�i�JBmpWriteV1(BMP���ɼg�J)�Ƶ{�� 
	unsigned char FillingByte;											//	�ŧi��R�줸���ܼ�(FillingByte)
	FillingByte = BmpFillingByteCalc(xsize);							//	�I�sBmpFillingByteCalc�Ƶ{���p���R���줸�ռƶq
	unsigned char header[54] = 											//	�ŧi���Y�]�wheader�}�C(�@54Bytes)
	{																	//	header�}�C��l�ȳ]�w 
	0x42, 0x4d, 0, 0, 0, 0, 0, 0, 0, 0,									//	header�}�C��l�ȳ]�w
	54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0, 		//	header�}�C��l�ȳ]�w
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 		//	header�}�C��l�ȳ]�w
	0, 0, 0, 0															//	header�}�C��l�ȳ]�w
	};																	//	header�}�C��l�ȳ]�w
	unsigned long file_size = (long)xsize * (long)ysize * 3 + 54;		//	�ŧifile_size�ܼơA�]�w�ɮפj�p 
	unsigned long width, height;										//	�ŧiwidth�Pheight��unsigned long���A�ܼơA�Ω�p��Ϲ��ɮ׼e�סB����
	char fname_bmp[MAX_PATH];											//	�ŧi�ܼƥΥH�O����X�Ϥ��������ɦW(�̦hMAX_PATH�Ӧr��) 
	header[2] = (unsigned char)(file_size &0x000000ff);					//	�p�����Y��T(�Ϲ��ɮפj�p)
	header[3] = (file_size >> 8) & 0x000000ff;							//	�p�����Y��T(�Ϲ��ɮפj�p)
	header[4] = (file_size >> 16) & 0x000000ff;							//	�p�����Y��T(�Ϲ��ɮפj�p)
	header[5] = (file_size >> 24) & 0x000000ff;							//	�p�����Y��T(�Ϲ��ɮפj�p)
	
	width = xsize;														//	�N�Ϲ��e�׸�T��Jwidth�ܼ�
	header[18] = width & 0x000000ff;									//	�p�����Y��T(�Ϲ��e��)
	header[19] = (width >> 8) &0x000000ff;								//	�p�����Y��T(�Ϲ��e��)
	header[20] = (width >> 16) &0x000000ff;								//	�p�����Y��T(�Ϲ��e��)
	header[21] = (width >> 24) &0x000000ff;								//	�p�����Y��T(�Ϲ��e��)
	 
	height = ysize;														//	�N�Ϲ����׸�T��Jheight�ܼ�
	header[22] = height &0x000000ff;									//	�p�����Y��T(�Ϲ�����)
	header[23] = (height >> 8) &0x000000ff;								//	�p�����Y��T(�Ϲ�����)
	header[24] = (height >> 16) &0x000000ff;							//	�p�����Y��T(�Ϲ�����)
	header[25] = (height >> 24) &0x000000ff;							//	�p�����Y��T(�Ϲ�����)
	sprintf(fname_bmp, "%s.bmp", filename);								//	���͹��ɧ����ɦW���|
	FILE *fp;															//	�ŧi�ɮ׫���fp�ϰ��ܼơA�ΥH�O���g�J���ɸ��| 
	if (!(fp = fopen(fname_bmp, "wb"))) 								//	���եH�G�i��Ū�ɤ覡�}�ҹ��ɡA�Y�L�k���\�}��
	{																	//	�i�Jif�ԭz
		return -1;														//	�^��-1�A�õ����Ƶ{��
	}																	//	����if�ԭz
	
	fwrite(header, sizeof(unsigned char), 54, fp);						//	�g�JBMP�������Y��T(54Bytes)
	fwrite(image, sizeof(unsigned char), (size_t)(long)(xsize * 3 + FillingByte)*ysize, fp);
	//	�g�JBMP���ɼv�����
	fclose(fp);															//	�����ɮ׫���
	free((void*)image);
	image = NULL;
	return 0;															//	�Ǧ^0�õ����Ƶ{��
}																		//	����BmpWriteV1(BMP���ɼg�J)�Ƶ{��
int BmpWriteV2(const BMPIMAGE OutputFile)								//	BmpWriteV2�Ƶ{��
{																		//	�i�JBmpWriteV2�Ƶ{��
	return BmpWriteV1(OutputFile.IMAGE_DATA, OutputFile.XSIZE, OutputFile.YSIZE, OutputFile.FILENAME);
	//	�NOutputFile���c�ѪR���U���ѼƶǤJBmpWriteV1�Ƶ{��
}																		//	����BmpWriteV2�Ƶ{��