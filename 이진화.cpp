#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <iostream>


using namespace std;
using namespace cv;


Vec3f params;
int cx, cy, r;


int main()
{
	Mat gray_image = imread("number.jpg",IMREAD_GRAYSCALE);

	namedWindow("입력 이미지", WINDOW_AUTOSIZE);

	namedWindow("이진화된 이미지", WINDOW_AUTOSIZE);

	
	Mat result;

	threshold(gray_image,result,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);//오츄 알고리즘 사용
	/* 원본 이미지, 결과 이미지, ,임계값보다 클 경우 픽셀에 줄 값, 임계값 정하는 방식 
	 Binary type 같은 경우 임계값 보다 작은 경우 0 , 임계값 보다 큰 경우 maxvalue로 준다

	 0을 매개변수롤 주는 이유는 원래 임계값을 적는 부분인데 , 오츄 알고리즘을 사용하므로 
	 적어줄 필요가 없어 버리는 값으로 0을 그냥 써준 것 */




	imshow("이진화된 이미지", result);
	imshow("입력 이미지", gray_image);


	while (cvWaitKey(0) < 0);



	return 0;
}



