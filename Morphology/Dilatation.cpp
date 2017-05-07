#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <iostream>
 
 
using namespace std;
using namespace cv;
 
int main()
{
	Mat gray_image = imread("C:/ESD/milk.jpg",IMREAD_GRAYSCALE);
	Mat result;
 
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(1, 1));
	//모폴로지 침식,팽창연산에서 사용되는 필터(3*3의 정사각형 형태의 필터)
 
	namedWindow("입력 이미지", WINDOW_AUTOSIZE);
	namedWindow("출력 이미지1", WINDOW_AUTOSIZE);
	namedWindow("출력 이미지2", WINDOW_AUTOSIZE);
	namedWindow("출력 이미지3", WINDOW_AUTOSIZE);
	
 
	threshold(gray_image, result, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	//이진영상으로 바꿔줌, source이미지,결과이미지,최저값,최고값,오추알고리즘을 이용하여 이진영상으로
 
	dilate(result, result, element);
	//모폴로지 팽창연산을 한다.(source이미지, 결과 이미지, 필터)
	imshow("출력 이미지1", result);
 
	dilate(result, result, element);
	imshow("출력 이미지2", result);
 
	dilate(result, result, element);
	imshow("출력 이미지3", result);
 
	imshow("입력 이미지", gray_image);
 
 
	while (cvWaitKey(0) < 0);
 
	return 0;
}
