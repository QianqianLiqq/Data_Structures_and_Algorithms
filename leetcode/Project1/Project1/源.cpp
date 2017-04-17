// Mouthdetection.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//�����ĸ����������������ļ������Դ�opencv�İ�װĿ¼���ҵ�   
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
	char string[10];  // ���ڴ��֡�ʵ��ַ���

	//����Ƶ�ļ�   
	//cv::VideoCapture capture("bike.avi");   
	//0 open default camera   
	cv::VideoCapture capture(0);
	//�����Ƶ�Ƿ��   
	if (!capture.isOpened())
		return 1;

	// �õ�֡��   
	double rate = capture.get(CV_CAP_PROP_FPS);
	bool stop(false);
	cv::Mat frame; // ���ڵ���Ƶ֡   
	cv::Mat mElabImage;//����frameͼ��   

	cv::namedWindow("Extracted Frame");

	// ��֮֡��ļ��ʱ��   
	int delay = 1000 / rate;
	// ѭ���������е�֡   
	while (!stop) {
		t = (double)cv::getTickCount();
		// ����һ֡   
		if (!capture.read(frame))
			break;
		frame.copyTo(mElabImage);
		//�����   
		//��������   
		float scaleFactor = 3.0f;
		vector< cv::Rect > faceVec;
		mFaceDetector.detectMultiScale(frame, faceVec, scaleFactor);
		int i, j;
		for (i = 0; i<faceVec.size(); i++)
		{
			cv::rectangle(mElabImage, faceVec[i], CV_RGB(255, 0, 0), 2);
			cv::Mat face = frame(faceVec[i]);
			//����۾�   
			vector< cv::Rect > eyeVec;
			mEyeDetector.detectMultiScale(face, eyeVec);

			for (j = 0; j<eyeVec.size(); j++)
			{
				cv::Rect rect = eyeVec[j];
				rect.x += faceVec[i].x;
				rect.y += faceVec[i].y;

				cv::rectangle(mElabImage, rect, CV_RGB(0, 255, 0), 2);
			}
			//������   
			vector< cv::Rect > noseVec;

			mNoseDetector.detectMultiScale(face, noseVec, 3);

			for (j = 0; j<noseVec.size(); j++)
			{
				cv::Rect rect = noseVec[j];
				rect.x += faceVec[i].x;
				rect.y += faceVec[i].y;

				cv::rectangle(mElabImage, rect, CV_RGB(0, 0, 255), 2);
			}

			//������   
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
		sprintf(string, "%.2f", fps);      // ֡�ʱ�����λС��,ÿ��仯�Ļ�����
		std::string fpsString("FPS:");
		fpsString += string;                    // ��"FPS:"�����֡����ֵ�ַ���
		// ��֡����Ϣд�����֡��
		putText(mElabImage, // ͼ�����
			fpsString,                  // string����������
			cv::Point(5, 20),           // �������꣬�����½�Ϊԭ��
			cv::FONT_HERSHEY_SIMPLEX,   // ��������
			0.5, // �����С
			cv::Scalar(255, 255, 255));       // ������ɫ	

		//�ڴ�������ʾͼ��   
		cv::imshow("Extracted Frame", mElabImage);
		// �������ֹͣ��Ƶ����   
		//if (cv::waitKey(delay)>=0)   
		//    stop= true;   
		cv::waitKey(20);
	}
	// �ر���Ƶ�ļ�   
	capture.release();
	return 0;
}

