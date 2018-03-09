/*	BMPFileIO.h file
	Declare some functions about BMP file read & write implementation
	Develop by Jimmy HU <s103360021@gmail.com>
	This program is licensed under GNU General Public License v3.
*/
#pragma once
//-----include header files, �ޤJ���Y��-----
#include "DIPDefine.h"													//	include DIPDefine.h header files, �ޤJ���Y��DIPDefine.h
#include "..\\BasicFileIO\\BasicFileIO.h"								//	include BasicFileIO.h header files, �ޤJ���Y��BasicFileIO.h
#include <math.h>														//	�ޤJ���Y��math.h
#include <stdbool.h>													//	�ޤJ���Y��stdbool.h
#include <stdio.h>														//	�ޤJ���Y��stdio.h
#include <stdlib.h>														//	�ޤJ���Y��stdlib.h
#include <string.h>														//	�ޤJ���Y��string.h
#include "..\\unistd.h"													//	�ޤJ���Y��unistd.h

//-----funtion declaration, �Ƶ{���ŧi��-----

/*  BmpReadFilesize�Ƶ{���N��J���|�����ɤj�pŪ�X�öǦ^
	�Ƶ{����J����Ū���j�p�����ɸ��|(const char *���A�r��A����Ū�����ɦW, FilenameExtension���ɦW��T)
	�Ƶ{����X�����ɤj�p(unsigned long���A)
 */
unsigned long BmpReadFilesize(const char *, const bool);				//	�ŧiBMP���ɤj�p(Byte)Ū���Ƶ{��BmpReadFilesize

/*  BmpReadXSize�Ƶ{���N��J���|������xsize(�e��)Ū�X�öǦ^
	�Ƶ{����J����Ū���e�פj�p�����ɸ��|(const char *���A�A����Ū�����ɦW,FilenameExtension���ɦW��T)
	�Ƶ{����X�����ɼe��(unsigned long���A)
 */
unsigned long BmpReadXSize(const char *, const bool);					//	�ŧiBMP����xsize(�e��)Ū���Ƶ{��BmpReadXSize

/*  BmpReadYSize�Ƶ{���N��J���|������ysize(����)Ū�X�öǦ^
	�Ƶ{����J����Ū�����פj�p�����ɸ��|(const char *���A�A����Ū�����ɦW,FilenameExtension���ɦW��T)
	�Ƶ{����X�����ɰ���(unsigned long���A)
 */
unsigned long BmpReadYSize(const char *, const bool);					//	�ŧiBMP����ysize(����)Ū���Ƶ{��BmpReadYSize
/*	BmpRead�Ƶ{���Ω�Ū��BMP����
	�Ƶ{����J��(���s���l���ɸ�Ƥ�unsigned char���A����,��Ū�����ɤ��e��,��Ū�����ɤ�����,��Ū�������ɸ��|,FilenameExtension���ɦW��T)
	�Ƶ{����X�G�Y���QŪ�����ɫh�Ǧ^0�A�Ϥ��Ǧ^-1
 */
char BmpRead(unsigned char*,const int,const int, const char *, const bool);
//	�ŧiBmpRead(BMP����Ū��)�Ƶ{��
/*	BmpFileRead�Ƶ{����XBmpFillingByteCalc(BMP���ɶ�ɦ줸�p��)�Ƶ{���B
	BmpReadFilesize(BMP�����ɮפj�pŪ��)�Ƶ{���B
	BmpReadXSize(BMP�����ɮ׼e��Ū��)�Ƶ{���B
	BmpReadYSize(BMP�����ɮװ���Ū��)�Ƶ{���P
	BmpRead(BMP�����ɮ�Ū��)�Ƶ{�����\��A�Ω�Ū��BMP����
	�Ƶ{����J��(��Ū�������ɸ��|)�A�p�G"test.bmp"
	�Ƶ{����X��BMPIMAGE�v����Ƶ��c(�Ӽv����Ƶ��c�]�t�ɦW(FILENAME)�B
	�Ϲ��e��(XSIZE)�B�Ϲ�����(YSIZE)�B��ɦ줸(FILLINGBYTE)�P�Ϲ����(IMAGE_DATA))
 */
BMPIMAGE BmpFileRead(const char *, const bool);							//	�ŧiBmpFileRead�Ƶ{��
/*	BmpWriteV1�Ƶ{���Ω�g�JBMP����
	�Ƶ{����J��(���g�J���ɤ�unsigned char���A���и��,���g�J���ɤ��e��,���g�J���ɤ�����,���g�J�����ɸ��|)
	�Ƶ{����X�G�Y���Q�g�J���ɫh�Ǧ^0�A�Ϥ��Ǧ^-1
 */
int BmpWriteV1(const unsigned char*,const int,const int,const char*); 	//	�ŧiBmpWriteV1(BMP���ɼg�J)�Ƶ{��
/*	BmpWriteV2�Ƶ{���Ω�g�JBMP����
	���Ƶ{���NBmpWriteV1�Ƶ{������J�ѼƵ��c�ơA�HBMPIMAGE���c���ɸ�ƶǤJ�A���ϥΤ����W����i
	��@�W���I�sBmpWriteV1�Ƶ{���i����ɼg�J
	�Ƶ{����J��(���g�J��BMPIMAGE���c���ɸ��)
	�Ƶ{����X�G�Y���Q�g�J���ɫh�Ǧ^0�A�Ϥ��Ǧ^-1
 */
int BmpWriteV2(const BMPIMAGE); 										//	�ŧiBmpWriteV2(BMP���ɼg�J)�Ƶ{��




