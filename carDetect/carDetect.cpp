#include <iostream>

#include <opencv/highgui.h>

#include <opencv2/opencv.hpp>



#ifdef _DEBUG

#pragma comment (lib, "opencv_world310d.lib")

#endif





using namespace cv;

using namespace std;



CascadeClassifier car_cascade;



void CarDetection(Mat video);



int main(int, char) {



	VideoCapture stream1("data/driver.mp4"); //영상파일로드

	//VideoCapture stream2("C:/ESD/passenger.mp4");

	//VideoCapture default(0);//디폴트 카메라 사용



	if (!car_cascade.load("data/cars.xml")) { cout << "Error xml loading" << endl; return -1; } //cascade load

	if (!stream1.isOpened()) { cout << "Cannot open the video file" << endl; return -1;} // 영상파일 load



	Mat video, cma, gray, edge;



	namedWindow("video");



	while (true) {

		stream1.read(video);

		resize(video, video, Size(384, 216), 0, 0, CV_INTER_LINEAR);



		if (!video.empty()) {

			CarDetection(video);

		}

		else {

			return -1;

		}



		//imshow("video", video);



		if (waitKey(30) >= 0) {

			break;

		}

	}

	destroyAllWindows();



	return 0;

}



void CarDetection(Mat video) {

	Mat gray;

	vector<Rect> vehicle;



	cvtColor(video, gray, CV_RGB2GRAY);

	car_cascade.detectMultiScale(gray, vehicle, 1.05, 2);



	for (cv::Rect object : vehicle) {

		cv::Point center(object.x + object.width / 2, object.y + object.height / 2);

		rectangle(video, object, Scalar(255,0,0), 3);

	}



	imshow("video", video);

}





//default.read(cam);

//imshow("camera", cam);





/*vector<Vec4i> lines;

HoughLinesP(edge, lines, 1, CV_PI / 180, 90, 30, 3);

for (int i = 0; i < lines.size(); i++) {

Vec4i L = lines[i];

line(video, Point(L[0], L[1]), Point(L[2], L[3]), Scalar(0, 0, 255), 1);

}*/
