// Mouthdetection.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include "cv.h"
#include <opencv2/core/core.hpp>   
#include <opencv2/highgui//highgui.hpp>   
#include <opencv2/objdetect/objdetect.hpp>   
#include <string>   
#include <vector>   
using namespace std;

int main()
{

	cv::CascadeClassifier mFaceDetector;
	cv::CascadeClassifier mEyeDetector;
	cv::CascadeClassifier mMouthDetector;
	cv::CascadeClassifier mNoseDetector;
	//载入四个人脸特征分类器文件，可以从opencv的安装目录中找到   
	if (mFaceDetector.empty())
		mFaceDetector.load("haarcascade_frontalface_default.xml");
	if (mEyeDetector.empty())
		mEyeDetector.load("haarcascade_mcs_eyepair_big.xml");
	if (mNoseDetector.empty())
		mNoseDetector.load("haarcascade_mcs_nose.xml");
	if (mMouthDetector.empty())
		mMouthDetector.load("haarcascade_mcs_mouth.xml");

	double t = 0;
	double fps;
	char string[10];  // 用于存放帧率的字符串

	//打开视频文件   
	//cv::VideoCapture capture("bike.avi");   
	//0 open default camera   
	cv::VideoCapture capture(0);
	//检查视频是否打开   
	if (!capture.isOpened())
		return 1;

	// 得到帧率   
	double rate = capture.get(CV_CAP_PROP_FPS);
	bool stop(false);
	cv::Mat frame; // 现在的视频帧   
	cv::Mat mElabImage;//备份frame图像   

	cv::namedWindow("Extracted Frame");

	// 两帧之间的间隔时间   
	int delay = 1000 / rate;
	// 循环播放所有的帧   
	while (!stop) {
		t = (double)cv::getTickCount();
		// 读下一帧   
		if (!capture.read(frame))
			break;
		frame.copyTo(mElabImage);
		//检测脸   
		//缩放因子   
		float scaleFactor = 3.0f;
		vector< cv::Rect > faceVec;
		mFaceDetector.detectMultiScale(frame, faceVec, scaleFactor);
		int i, j;
		for (i = 0; i<faceVec.size(); i++)
		{
			cv::rectangle(mElabImage, faceVec[i], CV_RGB(255, 0, 0), 2);
			cv::Mat face = frame(faceVec[i]);
			//检测眼睛   
			vector< cv::Rect > eyeVec;
			mEyeDetector.detectMultiScale(face, eyeVec);

			for (j = 0; j<eyeVec.size(); j++)
			{
				cv::Rect rect = eyeVec[j];
				rect.x += faceVec[i].x;
				rect.y += faceVec[i].y;

				cv::rectangle(mElabImage, rect, CV_RGB(0, 255, 0), 2);
			}
			//检测鼻子   
			vector< cv::Rect > noseVec;

			mNoseDetector.detectMultiScale(face, noseVec, 3);

			for (j = 0; j<noseVec.size(); j++)
			{
				cv::Rect rect = noseVec[j];
				rect.x += faceVec[i].x;
				rect.y += faceVec[i].y;

				cv::rectangle(mElabImage, rect, CV_RGB(0, 0, 255), 2);
			}

			//检测嘴巴   
			vector< cv::Rect > mouthVec;
			cv::Rect halfRect = faceVec[i];
			halfRect.height /= 2;
			halfRect.y += halfRect.height;

			cv::Mat halfFace = frame(halfRect);

			mMouthDetector.detectMultiScale(halfFace, mouthVec, 3);

			for (j = 0; j<mouthVec.size(); j++)
			{
				cv::Rect rect = mouthVec[j];
				rect.x += halfRect.x;
				rect.y += halfRect.y;

				cv::rectangle(mElabImage, rect, CV_RGB(255, 255, 255), 2);
			}
		}

		t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
		fps = 1.0 / t;
		sprintf(string, "%.2f", fps);      // 帧率保留两位小数,每秒变化的画面数
		std::string fpsString("FPS:");
		fpsString += string;                    // 在"FPS:"后加入帧率数值字符串
		// 将帧率信息写在输出帧上
		putText(mElabImage, // 图像矩阵
			fpsString,                  // string型文字内容
			cv::Point(5, 20),           // 文字坐标，以左下角为原点
			cv::FONT_HERSHEY_SIMPLEX,   // 字体类型
			0.5, // 字体大小
			cv::Scalar(255, 255, 255));       // 字体颜色	

		//在窗口中显示图像   
		cv::imshow("Extracted Frame", mElabImage);
		// 按任意键停止视频播放   
		//if (cv::waitKey(delay)>=0)   
		//    stop= true;   
		cv::waitKey(20);
	}
	// 关闭视频文件   
	capture.release();
	return 0;
}

