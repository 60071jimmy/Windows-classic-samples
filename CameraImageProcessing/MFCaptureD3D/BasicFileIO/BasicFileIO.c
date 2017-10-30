/*	檔案基礎I/O函式庫
	Basic File Input & Output Library
	
	Develop by Jimmy HU
	This program is licensed under GNU General Public License v3.
 */
//-----引入標頭檔-----
#include <math.h>														//	引入標頭檔math.h
#include <stdbool.h>													//	引入標頭檔stdbool.h
#include <stdio.h>														//	引入標頭檔stdio.h
#include <stdlib.h>														//	引入標頭檔stdlib.h
#include <string.h>														//	引入標頭檔string.h
#include <unistd.h>														//	引入標頭檔unistd.h
//-----副程式實作-----
bool FileExistCheck(char *file_name)									//	FileExistCheck(檔案存在檢查)副程式
{																		//	進入FileExistCheck(檔案存在檢查)副程式
	if( access( file_name, F_OK ) != -1 )								//	若檔案存在
	{																	//	進入if敘述
    	return true;													//	傳回true
	} 																	//	結束if敘述
	else 																//	若檔案不存在
	{																	//	進入else敘述
	    return false;													//	回傳false
	}																	//	結束else敘述
} 																		//	結束FileExistCheck(檔案存在檢查)副程式
bool FileReadPermissionCheck(const char *file_name)						//	FileReadPermissionCheck(檔案讀取權限檢查)副程式
{																		//	進入FileReadPermissionCheck(檔案讀取權限檢查)副程式
	if( access( file_name, R_OK ) != -1 )								//	若檔案可讀取
	{																	//	進入if敘述
    	return true;													//	傳回true
	} 																	//	結束if敘述
	else 																//	若檔案不可讀取
	{																	//	進入else敘述
		return false;													//	回傳false
	}																	//	結束else敘述
} 																		//	結束FileReadPermissionCheck(檔案讀取權限檢查)副程式
bool FileWritePermissionCheck(const char *file_name)					//	FileWritePermissionCheck(檔案寫入權限檢查)副程式
{																		//	進入FileWritePermissionCheck(檔案寫入權限檢查)副程式
	if( access( file_name, W_OK ) != -1 )								//	若檔案可讀取
	{																	//	進入if敘述
    	return true;													//	傳回true
	} 																	//	結束if敘述
	else 																//	若檔案不可讀取
	{																	//	進入else敘述
	    return false;													//	回傳false
	}																	//	結束else敘述
} 																		//	結束FileWritePermissionCheck(檔案寫入權限檢查)副程式

bool FileWrite(const char *file_name,const char *input_str,const char *mode)
//	FileWrite(檔案寫入)副程式，執行文字檔案寫入
//	file_name為欲寫入檔案檔名
// 	input_str為欲寫入檔案之指標形式字串資料
//	mode為寫入檔案模式設定，可傳入"w"或"a"，"w"為新增/覆蓋模式，"a"為擴充模式
//	回傳結果：若檔案寫入成功回傳true，若寫入失敗回傳false
{																		//	進入FileWrite(檔案寫入)副程式
	FILE *file_point;													//	宣告一file_point指標，控制檔案讀寫
	if (strcmp(mode, "w") != 0 && strcmp(mode, "a") != 0 && strcmp(mode, "w+") != 0 && strcmp(mode, "a+") != 0)
	//	若mode參數不為"w"亦不為"a"亦不為"w+"亦不為"a+"
	{																	//	進入if敘述
		printf("FileWrite:mode ERROR!\n");								//	顯示"FileWrite:mode ERROR!"並換行
		return false;													//	回傳false並結束副程式返回
	}																	//	結束if敘述
	if( strcmp(mode, "a") == 0 || strcmp(mode, "a+") == 0 )				//	若mode參數為"a"或"a+"(擴充模式)
	{																	//	進入if敘述
		if (FileWritePermissionCheck(file_name) == false)				//	若檔案無法寫入
		{																//	進入if敘述
			printf("FileWrite:permission ERROR!\n");					//	顯示"FileWrite:permission ERROR!"並換行
			return false;												//	回傳false並結束副程式返回
		}																//	結束if敘述
	}																	//	結束if敘述
	file_point = fopen(file_name, mode);								//	以mode模式打開檔案
	//	fprintf或fputs語法二擇一使用
	fprintf(file_point, input_str);										//	以fprintf語法寫入檔案
	//fputs(input_str, file_point);										//	以fputs語法寫入檔案
	fclose(file_point); 												//	關閉檔案
	return true;														//	回傳true並結束副程式返回
}																		//	結束FileWrite(檔案寫入)副程式