#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

void showAndWrite(cv::Mat, std::string name);
void colorCycle(std::vector<cv::Mat>& monocolor, cv::Mat& outMat);

int main(int argc, const char* argv[])
{

	cv::Mat imMat, outMat, GBR, BRG, HSV;

	imMat = cv::imread("C:\\Users\\admin\\Documents\\new\\Parrots.tiff");

	std::vector<cv::Mat> monocolor;


	if (imMat.empty() == true) {
		printf("error");
	}
	else {
		cv::split(imMat, monocolor);

		colorCycle(monocolor, GBR);
		showAndWrite(GBR, "ex6-1_GBR");

		colorCycle(monocolor, BRG);
		showAndWrite(BRG, "ex6-1_BRG");

		cv::cvtColor(BRG, HSV, cv::COLOR_BGR2HSV);
		cv::split(HSV, monocolor);
		monocolor.at(0) -= 90;
		monocolor.at(1) *= 0.75;
		monocolor.at(2) *= 1.25;
		cv::merge(monocolor, HSV);
		cv::cvtColor(HSV, outMat, cv::COLOR_HSV2BGR);
		showAndWrite(outMat, "ex6-2");

		cv::split(BRG, monocolor);
		cv::inRange(monocolor[0], 144, 196, monocolor[0]);
		cv::inRange(monocolor[1], 64, 128, monocolor[1]);
		cv::inRange(monocolor[2], 128, 144, monocolor[2]);
		cv::merge(monocolor,outMat);
		showAndWrite(outMat, "ex6-3");

		cv::fastNlMeansDenoisingColored(outMat, outMat, 30, 30, 30, 30);
		showAndWrite(outMat, "ex6-4");
	}

	return 0;
}

void showAndWrite(cv::Mat mat, std::string name) {
	std::string path = "C:\\Users\\admin\\Documents\\new\\";
	std::string extension = ".jpg";
	cv::imshow("Matrix image", mat);
	cv::imwrite(path + name + extension, mat);
	cv::waitKey(0);
}

void colorCycle(std::vector<cv::Mat>& monocolor, cv::Mat& outMat) {
	monocolor.push_back(monocolor[2]);
	monocolor[2] = monocolor[1];
	monocolor[1] = monocolor[0];
	monocolor[0] = monocolor[3];
	monocolor.pop_back();
	cv::merge(monocolor, outMat);
}