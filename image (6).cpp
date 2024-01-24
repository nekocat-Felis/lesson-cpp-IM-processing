#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

void showAndWrite(cv::Mat, std::string name);

int main(int argc, const char* argv[])
{

	cv::Mat imMat, outMat, RGB, HSV;

	imMat = cv::imread("C:\\Users\\admin\\Documents\\new\\Parrots.tiff");

	std::vector<cv::Mat> monocolor;

	if (imMat.empty() == true) {
		printf("error");
	}
	else {
		std::string ABName[] = { "Alpha","Beta" };

		double AB[2];

		std::cout << "HSV tuned" << std::endl;
		for (int i = 0; i < 2; i++) {
			std::cout << "input " + ABName[i] + " = ";
			std::cin >> AB[i];
		}
		cv::cvtColor(imMat, HSV, cv::COLOR_BGR2HSV);
		cv::split(HSV, monocolor);
		monocolor.at(2) = AB[0] * monocolor.at(2) + AB[1];
		cv::merge(monocolor, HSV);
		cv::cvtColor(HSV, HSV, cv::COLOR_HSV2BGR);

		std::cout << "HSVtuned output" << std::endl << std::endl;
		showAndWrite(HSV, "ex9-1");

		std::cout << "RGB tuned" << std::endl;
		cv::split(imMat, monocolor);

		for (int i = 0; i < 3; i++) {
			monocolor.at(i) = AB[0] * monocolor.at(i) + AB[1];
		}

		cv::merge(monocolor, RGB);

		std::cout << "RGBtuned output" << std::endl << std::endl;
		showAndWrite(RGB, "ex9-2");

		std::string mima[] = { "minimum","Maximum" };
		int pixel,pival[2];
		unsigned char c;

		std::cout << "RGB fine tuned" << std::endl;
		for (int i = 0; i < 2; i++) {
			std::cout << "input " + mima[i] + " pixel value = ";
			std::cin >> pival[i];
		}
		for (int y = 0; y < imMat.rows; y++) {
			for (int x = 0; x < imMat.cols; x++) {
				for (int i = 0; i < 3; i++) {
					pixel = imMat.at<cv::Vec3b>(y, x)[i];
					if (pixel >= pival[0] && pixel <= pival[1]) {
						pixel = (int)std::round(AB[0] * pixel + AB[1]);
						if (pixel <= 0) {
							pixel = 0;
						}
						else if (pixel >= 255) {
							pixel = 255;
						}
					}
					c = pixel;
					imMat.at<cv::Vec3b>(y, x)[i] = c;
				}
			}
		}

		std::cout << "RGBfinetuned output" << std::endl << std::endl;
		showAndWrite(imMat, "ex9-3");
	}
	return 0;
}

void showAndWrite(cv::Mat mat, std::string name) {
	std::string path = "C:\\Users\\admin\\Documents\\new\\";
	std::string extension = ".jpg";
	cv::imshow("Matrix image " + name, mat);
	cv::imwrite(path + name + extension, mat);
	cv::waitKey(0);
}