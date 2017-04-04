#include <iostream>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <iomanip>
#include <cmath>
 
using namespace std;
using namespace cv;
 
double w_zero(float h, double &w_old) {
	double temp = (double)w_old + h;
	w_old = temp;
	return temp;
}
 
double u_zero(double w_old, double &u_old, float h, double wt) {
	if (wt == 0)
		return 0;
	double temp = double((w_old * u_old + (double)h) / wt);
	u_old = temp;
	return temp;
}
 
double u_one(double u, double wt, double ut) {
	if (wt == 1)
		return 0;
	double temp = (u - (wt * ut)) / (1 - wt);
	return temp;
}
 
 
int main() {
	Mat img = imread("datafile/otsu_1.jpg");
	Mat img_gray(img.rows, img.cols, CV_8UC1);
	Mat img_otsu(img.rows, img.cols, CV_8UC1);
	float level[256] = { 0 };
	double u = 0;
	double v_between = 0;
	double w_old = 0;
	double u_old = 0;
	int temp = 0;
	int t = 0;
 
	namedWindow("origin");
	namedWindow("gray");
	namedWindow("otsu");
	
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			unsigned char r = img.at <Vec3b>(i, j)[2];
			unsigned char g = img.at <Vec3b>(i, j)[1];
			unsigned char b = img.at <Vec3b>(i, j)[0];
			img_gray.at<uchar>(i, j) = unsigned char((r + g + b) / 3);
			level[(int)img_gray.at<uchar>(i, j)]++;
		}
	}
 
	for (int i = 0; i < 256; i++) {
		level[i] = level[i] / (img.rows * img.cols);
		u += i * (double)level[i];
	}
 
	w_old = level[0];
	
	for (int i = 1; i < 250; i++) {
		double wt = w_zero(level[i], w_old);
		double ut = u_zero(w_old, u_old, i*level[i], wt);
		double u1t = u_one(u, wt, ut);
		temp = int(wt * (1 - wt) * pow((ut - u1t), 2));
		//cout << wt << " " << ut << " " << u1t << endl;
		cout << temp << endl;
		if (temp > v_between) {
			v_between = temp;
			t = i;
		}
	}
 
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if ((int)img_gray.at<uchar>(i, j) < t) {
				img_otsu.at<uchar>(i, j) = unsigned char(0);
			}
			else {
				img_otsu.at<uchar>(i, j) = unsigned char(255);
			}
		}
	}
 
	cout << t << endl;
 
	imshow("origin", img);
	imshow("gray", img_gray);
	imshow("otsu", img_otsu);
 
	waitKey(0);
 
	return 0;
}
