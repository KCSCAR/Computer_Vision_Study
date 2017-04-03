#include <iostream>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <cmath>

#ifdef _DEBUG
#pragma comment (lib, "opencv_world310d.lib")
#endif

using namespace std;
using namespace cv;

int main(int, char) {
    Mat img = imread("datafile/cat.jpg");
    Mat img_trans(img.rows, img.cols, CV_8UC1);
    long double histo[256] = { 0 };
    
    
    namedWindow("origin");
    namedWindow("trans");
    
    
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            unsigned char b = img.at <Vec3b>(i, j)[0];
            unsigned char g = img.at <Vec3b>(i, j)[1];
            unsigned char r = img.at <Vec3b>(i, j)[2];
            img_trans.at<uchar>(i, j) = unsigned char ((r + g + b) / 3);
            histo[int((r+g+b)/3)]++; //각 명암값을 가지면 +1해줌
            
        }
    }
    cout << img.rows << " "<<img.cols << endl;
    for (int i = 0; i < 255; i++){
        histo[i] /= double(222496);
        if (i != 0)
            histo[i] += histo[i - 1];
        //histo[i] *= 255;
        //unsigned int a = floor(histo[i] + double(0.5));
        //histo[i] = a;
        cout << histo[i]<<" ";
    }
    
    imshow("origin", img);
    imshow("trans", img_trans);
    
    waitKey(0);
    
    return 0;
}
