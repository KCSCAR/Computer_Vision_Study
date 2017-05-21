#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
 
using namespace std;
using namespace cv;
 
int main() {
	Mat origin = imread("c:/ESD/dog.jpg");
	Mat result1;
	Mat result2;
	Mat result3;
 
	namedWindow("입력 영상", WINDOW_AUTOSIZE);
	namedWindow("출력 영상1", WINDOW_AUTOSIZE);
	namedWindow("출력 영상2", WINDOW_AUTOSIZE);
	namedWindow("출력 영상3", WINDOW_AUTOSIZE);
 
	Canny(origin, result1, 50, 50, 3);
	Canny(origin, result2, 100, 100, 3);
	Canny(origin, result3, 200, 200, 3);
 
	imshow("입력 영상", origin);
	imshow("출력 영상1", result1);
	imshow("출력 영상2", result2);
	imshow("출력 영상3", result3); 
 
	waitKey(0);
 
	return 0;
}
