#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

void showAndWrite(cv::Mat, std::string name);

int main(int argc, const char * argv[])
{

	cv::Mat imMat, outMat;

	imMat = cv::imread("C:\\Users\\admin\\Documents\\md.tiff");

	if (imMat.empty() == true) {
		printf("error");
	}else {
		cv::cvtColor(imMat, imMat, cv::COLOR_RGB2GRAY);
		showAndWrite(imMat, "input");

		cv::GaussianBlur(imMat, outMat, cv::Size(15, 15), 1.0, 1.0);
		showAndWrite(outMat, "gaus");

		cv::addWeighted(outMat,2.0, imMat, -2.0,20,outMat);
		showAndWrite(outMat, "unsp");
	}

	return 0;
}

void showAndWrite(cv::Mat mat, std::string name) {
	std::string path = "C:\\Users\\admin\\Documents\\";
	std::string extension = ".jpg";
	cv::imshow("Matrix image", mat);
	cv::imwrite(path + name + extension, mat);
	cv::waitKey(0);
}