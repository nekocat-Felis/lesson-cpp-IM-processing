#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

void showAndWrite(cv::Mat, std::string name);

int main(int argc, const char * argv[])
{

	cv::Mat imMat, outMat,RGB,HSV;

	imMat = cv::imread("C:\\Users\\admin\\Documents\\new\\Parrots.tiff");
	
	std::vector<cv::Mat> monocolor;


	if (imMat.empty() == true) {
		printf("error");
	}else {
		cv::split(imMat, monocolor);

		std::string BGRName[] = {"R","G","B"};
		std::string ABName[] = { "Alpha","Beta" };
		double alpha[3];
		int beta[3];

		std::cout << "RGB tuned" << std::endl;
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 2; i++) {
				std::cout << "input " + ABName[i] + " " + BGRName[j] + " = ";
				if (i == 0) {
					std::cin >> alpha[2 - j];
				}
				else {
					std::cin >> beta[2 - j];
				}
			}
		}
		std::cout << "RGBtuned output" << std::endl;

		for (int i = 0; i < 3; i++) {
			monocolor.at(i) = alpha[i] * monocolor.at(i) + beta[i];
		}

		cv::merge(monocolor, RGB);
		showAndWrite(RGB, "ex7-1");

		double HSVAB[2];

		std::cout << "HSV tuned" << std::endl;
		for (int i = 0; i < 2; i++) {
			std::cout << "input " + ABName[i] + " " + " = ";
			std::cin >> HSVAB[i];
		}
		std::cout << "HSVtuned output" << std::endl;

		cv::cvtColor(imMat, HSV, cv::COLOR_BGR2HSV);
		cv::split(HSV, monocolor);
		monocolor.at(2) = HSVAB[0] * monocolor.at(2) + HSVAB[1];
		cv::merge(monocolor, HSV);
		cv::cvtColor(HSV, HSV, cv::COLOR_HSV2BGR);

		showAndWrite(HSV, "ex7-2");

		std::cout << "Diff output" << std::endl;
		cv::absdiff(RGB, HSV, outMat);

		showAndWrite(outMat, "ex7-3");
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