/*
// 2024124 nekocat-Felis
// ex13-1
*/

#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

void showAndWrite(cv::Mat, std::string name);

int main(int argc, const char* argv[])
{

	cv::Mat imMat, outMat, HSV;

	imMat = cv::imread("C:\\Users\\admin\\Documents\\new\\Mandrill.tiff");

	std::vector<cv::Mat> monocolor;


	if (imMat.empty() == true) {
		printf("error");
	}
	else {
		cv::split(imMat, monocolor);

		cv::cvtColor(imMat, HSV, cv::COLOR_BGR2HSV);
		cv::split(HSV, monocolor);
		monocolor.at(2) = (2024124 / (double)1500000) * monocolor.at(2) + (102 + 5);
		cv::merge(monocolor, HSV);
		cv::cvtColor(HSV, outMat, cv::COLOR_HSV2BGR);

		showAndWrite(outMat, "ex13-1");
	}

	return 0;
}

void showAndWrite(cv::Mat mat, std::string name) {
	std::string path = "C:\\Users\\admin\\Documents\\new\\";
	std::string extension = ".png";
	cv::imshow("Matrix image", mat);
	cv::imwrite(path + name + extension, mat);
	cv::waitKey(0);
}