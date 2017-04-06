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

	namedWindow("�Է� �̹���", WINDOW_AUTOSIZE);

	namedWindow("����ȭ�� �̹���", WINDOW_AUTOSIZE);

	
	Mat result;

	threshold(gray_image,result,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);//���� �˰��� ���
	/* ���� �̹���, ��� �̹���, ,�Ӱ谪���� Ŭ ��� �ȼ��� �� ��, �Ӱ谪 ���ϴ� ��� 
	 Binary type ���� ��� �Ӱ谪 ���� ���� ��� 0 , �Ӱ谪 ���� ū ��� maxvalue�� �ش�

	 0�� �Ű������� �ִ� ������ ���� �Ӱ谪�� ���� �κ��ε� , ���� �˰����� ����ϹǷ� 
	 ������ �ʿ䰡 ���� ������ ������ 0�� �׳� ���� �� */




	imshow("����ȭ�� �̹���", result);
	imshow("�Է� �̹���", gray_image);


	while (cvWaitKey(0) < 0);



	return 0;
}



