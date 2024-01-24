#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

void showAndWrite(cv::Mat, std::string name);

int main(int argc, const char* argv[])
{
	cv::Mat mat(1080,1080,CV_8UC3);

	for (int y = 0; y < mat.rows; y++) {
		for (int x = 0; x < mat.cols; x++) {
			for (int i = 0; i < 3; i++) {
				mat.at<cv::Vec3b>(y, x)[i] = 255;
			}
		}
	}

	int z = 5;

	for (int x = -1; x < 11; x++) {
		for (int y = -1; y < 11; y++) {
			if ((x + y) % 2 == 0) {
				cv::rectangle(mat, cv::Point(y * 108 + z, x * 108 + z), cv::Point((y + 1) * 108 - z, (x + 1) * 108 - z), cv::Scalar(255, 150, 0), 7);
				cv::rectangle(mat, cv::Point(y * 108 + z, x * 108 + z), cv::Point((y + 1) * 108 - z, (x + 1) * 108 - z), cv::Scalar(255, 0, 0), 3);
			}
			else {
				cv::circle(mat, cv::Point(y * 108 + 54, x * 108 + 54), 108 - z, cv::Scalar(255, 200, 0), 10, 1, 0);
				cv::circle(mat,cv::Point(y * 108 + 54, x * 108 + 54),108-z,cv::Scalar(255, 255, 0),6,1, 0);
				cv::putText(mat, "$", cv::Point(y * 108 + 22, x * 108 + 81), cv::FONT_HERSHEY_SCRIPT_COMPLEX, 3, cv::Scalar(0, 200, 200), 15, 1, false);
				cv::putText(mat, "$", cv::Point(y * 108 + 22, x * 108 + 81), cv::FONT_HERSHEY_SCRIPT_COMPLEX, 3, cv::Scalar(0, 255, 255), 8, 1, false);
			}
		}
	}

	showAndWrite(mat,"ex10");

	return 0;
}

void showAndWrite(cv::Mat mat, std::string name) {
	std::string path = "C:\\Users\\admin\\Documents\\new\\";
	std::string extension = ".jpg";
	cv::imshow("Matrix image ", mat);
	cv::imwrite(path + name + extension, mat);
	cv::waitKey(0);
}