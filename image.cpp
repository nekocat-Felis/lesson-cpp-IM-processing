/*
// 2024124 nekocat-Felis
// ex13-2
*/

#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

void showAndWrite(cv::Mat, std::string name);

int main(int argc, const char* argv[])
{
	cv::Mat mat(512, 512, CV_8UC3);
	cv::rectangle(mat, cv::Point(0, 0), cv::Point(512, 512), cv::Scalar(255, 255, 255), -1);

	cv::rectangle(mat, cv::Point(0, 0), cv::Point(255, 255), cv::Scalar(255, 150, 0), -1);
	cv::rectangle(mat, cv::Point(256, 256), cv::Point(511, 511), cv::Scalar(0, 150, 255), -1);
	cv::circle(mat, cv::Point(383, 128), 127, cv::Scalar(50, 200, 50), -1, 1, 0);
	cv::circle(mat, cv::Point(128, 383), 127, cv::Scalar(0, 200, 200), -1, 1, 0);

	showAndWrite(mat, "ex13-2");

	return 0;
}

void showAndWrite(cv::Mat mat, std::string name) {
	std::string path = "C:\\Users\\admin\\Documents\\new\\";
	std::string extension = ".png";
	cv::imshow("Matrix image ", mat);
	cv::imwrite(path + name + extension, mat);
	cv::waitKey(0);
}