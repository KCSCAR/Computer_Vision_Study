#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <iostream>


using namespace std;
using namespace cv;





int main()
{
	
	Mat original_img = imread("histogram.jpg",CV_LOAD_IMAGE_COLOR);

	vector<Mat> channels;//채널 분리해서 넣을 벡터
	Mat histogram_equalized;
	
	cvtColor(original_img, histogram_equalized, CV_BGR2YCrCb);
	/*밝기를 평활화 하기 위해 밝기와 색상이 분리되는 YCrCb 모델로 변경*/


	split(histogram_equalized, channels);//밝기 분리 하기 위해 각 채널 분리


	equalizeHist(channels[0], channels[0]);//히스토그램 평활화

	merge(channels, histogram_equalized);//분리했던 채널들 다시 합쳐준다


	cvtColor(histogram_equalized, histogram_equalized, CV_YCrCb2BGR);//imshow는 rgb모델만 출력 가능해서 다시 색상 모델 변경

	namedWindow("original", CV_WINDOW_AUTOSIZE);	
	namedWindow("equalized", CV_WINDOW_AUTOSIZE);

	imshow("original",original_img);
	imshow("equalized", histogram_equalized);

	waitKey(0);//key 입력때까지 기다린다 

	destroyAllWindows();


	


	return 0;
}



