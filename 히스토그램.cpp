#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>
#include <iostream>


using namespace std;
using namespace cv;





int main()
{
	
	Mat original_img = imread("histogram.jpg",CV_LOAD_IMAGE_COLOR);

	vector<Mat> channels;//ä�� �и��ؼ� ���� ����
	Mat histogram_equalized;
	
	cvtColor(original_img, histogram_equalized, CV_BGR2YCrCb);
	/*��⸦ ��Ȱȭ �ϱ� ���� ���� ������ �и��Ǵ� YCrCb �𵨷� ����*/


	split(histogram_equalized, channels);//��� �и� �ϱ� ���� �� ä�� �и�


	equalizeHist(channels[0], channels[0]);//������׷� ��Ȱȭ

	merge(channels, histogram_equalized);//�и��ߴ� ä�ε� �ٽ� �����ش�


	cvtColor(histogram_equalized, histogram_equalized, CV_YCrCb2BGR);//imshow�� rgb�𵨸� ��� �����ؼ� �ٽ� ���� �� ����

	namedWindow("original", CV_WINDOW_AUTOSIZE);	
	namedWindow("equalized", CV_WINDOW_AUTOSIZE);

	imshow("original",original_img);
	imshow("equalized", histogram_equalized);

	waitKey(0);//key �Է¶����� ��ٸ��� 

	destroyAllWindows();


	


	return 0;
}



