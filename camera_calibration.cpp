/*
* 3calibration.cpp -- Calibrate 3 cameras in a horizontal line together.
*/
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <utility>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;


Vec3f rotationMatrixToEulerAngles(Mat &R)
{
	float sy = sqrt(R.at<double>(0, 0) * R.at<double>(0, 0) + R.at<double>(1, 0) * R.at<double>(1, 0));

	bool singular = sy < 1e-6; // If

	float x, y, z;
	if (!singular)
	{
		x = atan2(R.at<double>(2, 1), R.at<double>(2, 2));
		y = atan2(-R.at<double>(2, 0), sy);
		z = atan2(R.at<double>(1, 0), R.at<double>(0, 0));
	}
	else
	{
		x = atan2(-R.at<double>(1, 2), R.at<double>(1, 1));
		y = atan2(-R.at<double>(2, 0), sy);
		z = 0;
	}
	return Vec3f(x, y, z);
}
int main()
{
	int numBoards = 8;
	int numCornersHor= 12;
	int numCornersVer = 9;
	Size board_sz = Size(numCornersHor, numCornersVer);
	std::vector<std::vector<Point3f>> obj_point;
	std::vector<std::vector<Point2f>> img_point;
	std::vector<Point2f> corners;

	std::vector<Point3f> obj;

	for (int i = 0; i < numCornersHor*numCornersVer; i++)
	{
		obj.push_back(24*Point3f(i / numCornersHor, i%numCornersHor, 0.0f));
	}
	int successes = 0;
	
	std::vector<String> fn;
	std::vector<Mat> images;
	std::string path = "C:\\Users\\vkumarm\\Downloads\\images\\*.jpg";
	Size sz;
	glob(path, fn, true);
	for (auto k = 0; k < fn.size(); k++)
	{
		Mat imgRaw = imread(fn[k]);
		Mat imgResized = imgRaw;
		Mat gray, grayResized;
		//resize(imgRaw, imgResized, Size(imgRaw.cols / 6.0, imgRaw.rows / 6.0));
		sz.width = imgResized.cols;
		sz.height = imgResized.rows;
		cvtColor(imgRaw, gray, CV_BGR2GRAY);
		cvtColor(imgResized, grayResized, CV_BGR2GRAY);
		bool found = findChessboardCorners(imgResized, board_sz, corners);

		if (found)
		{
			drawChessboardCorners(imgResized, board_sz, corners, found);
			
			img_point.push_back(corners);
			obj_point.push_back(obj);
			std::cout << "Got it" << std::endl;
		}
		
		
	}
	Mat1d K;
	Mat D;
	std::vector<Mat> rvecs, tvecs;
	
	calibrateCamera(obj_point, img_point, sz, K, D, rvecs, tvecs);
	for (auto k = 0; k < fn.size(); k++)
	{
		Mat imge = imread(fn[k]);
		Mat imgRez = imge;
		//resize(imge, imgRez, Size(imge.cols / 6.0, imge.rows / 6.0));
		Mat und_img;
		std::vector<Point3f> ptf;
		std::vector<Point2f> zp;
		ptf.push_back(Point3f(0, 0, 100));
		undistort(imgRez, und_img, K, D);
		line(und_img, img_point[k][0], img_point[k][4], Scalar(0, 255, 0), 4, 8, 0);
		line(und_img, img_point[k][0], img_point[k][48], Scalar(0, 0, 255), 4, 8, 0);
		projectPoints(ptf, rvecs[k], tvecs[k], K, D, zp);
		line(und_img, img_point[k][0], zp[0], Scalar(255, 0, 0), 4, 8, 0);
		Mat rot_Mat;
		Rodrigues(rvecs[k], rot_Mat);
		Mat T= -rot_Mat.inv()*tvecs[k];
		ptf.pop_back();
		zp.pop_back();
		Vec3f eu;
		Mat N = rot_Mat.inv();
		eu = rotationMatrixToEulerAngles(N);
		//eu = eu * (180.0 / 3.141592); (in degrees)
		std::cout << "done!" << std::endl;
	}


	
	return 0;
}
