# function list, 副程式列表

## 圖檔讀取與寫入(BMPFileIO.h)
- BmpReadFilesize(BMP圖檔大小(Byte)讀取副程式)
- BmpReadXSize(BMP圖檔xsize(寬度)讀取副程式)
- BmpReadYSize(BMP圖檔ysize(高度)讀取副程式)
- BmpRead(BMP圖檔讀取副程式)
- BmpFileRead(BMP圖檔讀取副程式)
- BmpWriteV1(寫入圖檔副程式)
- BmpWriteV2(寫入圖檔副程式)

## 檢視圖檔

- ViewBMPImage(呼叫圖片檢視器開啟圖檔副程式)

## 圖檔初始化(建立空白圖檔)

- InitialIMGArray(圖檔初始化副程式)

## 圖檔資料格式轉換與處理

- RAWImageToArray(BMP圖檔之圖像資料轉換至RGB型態二維陣列)
- ArrayToRAWImage(將RGB型態圖像二維陣列轉換至符合BMP圖檔格式之圖像資料)
- BMP24RGBToHSV(將BMP24RGB型態之RGB像素資料轉換至HSV色彩空間)
- HSVToBMP24RGB(將HSV型態之像素資料轉換至BMP24RGB色彩空間)

## 圖像像素資料轉文字檔

- ImageDataToTxt(將圖像影像RGB資料寫入txt檔)
- HSVDataToTxt(將HSV型態影像資料寫入txt檔)

## 圖像像素基本運算

- ImgDifference2(兩BMP24RGB型態圖像像素之相減運算)
- BMP24RGB2or(兩BMP24RGB型態圖像像素之OR運算)

## 灰階轉換

- BmpToGraylevel(將BMP24RGB型態圖像轉為灰階圖像，使像素點R=G=B)

## 圖像摺積運算、濾波運算

- BmpConvolution33(圖像3*3遮罩摺積副程式)
- BmpConvolution55(圖像5*5遮罩摺積副程式)
- BmpConvolution77(圖像7*7遮罩摺積副程式)
- BmpConvolution(圖像摺積副程式，可給定任意遮罩大小)
- ImageSmoothing33V1(BMP圖檔3*3Mask平滑濾波 Version 1副程式)
- ImageSmoothing33V2(BMP圖檔3*3Mask平滑濾波 Version 2副程式)
- ImageSmoothing55(BMP圖檔5*5Mask平滑濾波副程式)
- ImageSmoothing77(BMP圖檔7*7Mask平滑濾波副程式)
- ImageSmoothing(BMP圖檔平滑濾波副程式，可給定任意遮罩大小)
- MedianFilter33(BMP圖檔3*3中值濾波副程式)
- GaussianBlur33V1(3*3高斯濾波 Version 1)
- GaussianBlur33V2(3*3高斯濾波 Version 2)
- GaussianBlur(圖像高斯濾波副程式，可給定任意遮罩大小)
- 
- GaussianFigure2D(建立二維高斯圖像)
- NormalDistribution2D(二維高斯函數)

## 其他影像處理副程式

### RGB色彩空間

- ImageOCR(影像文字辨識副程式)
- BMP24RGBGradient(梯度計算副程式)
- BMP24RGBSobelEdge(Sobel邊緣偵測副程式)
- RGBHistogramEqualization(直方圖等化副程式)
- BMPHaarWavelet(Haar小波轉換計算副程式)
- BMPHaarWavelet2(二階Haar小波轉換計算副程式)

### HSV色彩空間

- HSVHistogramEqualization(HSV之Value直方圖等化副程式)
- HueToBMP24RGB(將Hue轉換至圖檔)
- SaturationToBMP24RGB(將Saturation轉換至圖檔)
- ValueToBMP24RGB(將Value轉換至圖檔)
- HSVSkin(HSV色彩空間皮膚偵測副程式)

## 基礎副程式(檔案I/O、排序、字串處理、顯示等)

- BmpFillingByteCalc(BMP圖檔填補位元計算副程式)
- FileExistCheck(檔案存在檢查副程式)
- FileReadPermissionCheck(檔案讀取權限檢查副程式)
- FileWritePermissionCheck(檔案寫入權限檢查副程式)
- FileWrite(檔案寫入副程式)
- UCharBubbleSort(unsigned char型態變數氣泡排序副程式)
- Compare(變數比較副程式)
- CountCharPointStr(計算字串指標長度副程式)
- Show_char_point_str(顯示字串副程式)
- ShowUCharPointStr(顯示無號字串副程式)
- ShowLongDouble(顯示長浮點數副程式)

## 測試副程式(用於測試上列副程式功能)

- InitialIMGArrayTest(InitialIMGArray副程式測試)
- BmpReadFilesizeTest(BmpReadFilesize副程式測試)
- BmpReadXSizeTest(BmpReadXSizeTest副程式測試)
- BmpReadYSizeTest(BmpReadYSizeTest副程式測試)
- BmpReadTest(BmpReadTest副程式測試)
- BmpWriteV2Test(BmpWriteV2Test副程式測試)
- 
- 
- 
- 




