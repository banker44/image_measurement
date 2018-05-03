#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void Saltapepper(cv::Mat &image, int n)
{
	int i, j;
	for (int k = 0; k < n; k++)
	{
		i = rand() % image.cols;
		j = rand() % image.rows;
		if (image.channels() == 1)
			image.at<uchar>(j, i) = 255;
		else if (image.channels() == 3)
		{
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
		}
		i = rand() % image.cols;
		j = rand() % image.rows;
		if (image.channels() == 1)
			image.at<uchar>(j, i) = 0;
		else if (image.channels() == 3)
		{
			image.at<cv::Vec3b>(j, i)[0] = 0;
			image.at<cv::Vec3b>(j, i)[1] = 0;
			image.at<cv::Vec3b>(j, i)[2] = 0;
		}
	}
}

void sort(int *src, int len)
{
	int tem;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
			if (src[j] > src[j + 1])
			{
				tem = src[j];
				src[j] = src[j + 1];
				src[j + 1] = tem;
			}
	}
}	

int main(int argc, char** argv)
{
	Mat image = imread("../images/lena.bmp", -1);
//    previous picture is like a grayscale picture but not a grayscale picture
//    Mat mat = imread("../images/lena.bmp", IMREAD_GRAYSCALE);
//    imwrite("../output/gray_image.bmp", mat);
	Mat ave_image = imread("../images/lena.bmp", -1);
	Mat mid_image = imread("../images/lena.bmp", -1);
	Mat max_image = imread("../images/lena.bmp", -1);
	Mat min_image = imread("../images/lena.bmp", -1);

	for (int i = 1; i < image.rows - 1; i++)
		for (int j = 1; j < image.cols - 1; j++)
		{
			int f[9];
			f[0] = image.at<uchar>(i, j + 1);
			f[1] = image.at<uchar>(i - 1, j + 1);
			f[2] = image.at<uchar>(i - 1, j);
			f[3] = image.at<uchar>(i - 1, j - 1);
			f[4] = image.at<uchar>(i, j - 1);
			f[5] = image.at<uchar>(i + 1, j - 1);
			f[6] = image.at<uchar>(i + 1, j);
			f[7] = image.at<uchar>(i + 1, j + 1);
			f[8] = image.at<uchar>(i, j);
			ave_image.at<uchar>(i, j) = (f[0] + f[1] + f[2] + f[3] + f[4] + f[5] + f[6] + f[7] + f[8]) / 9;
			sort(f, 9);
			mid_image.at<uchar>(i, j) = f[4];
			max_image.at<uchar>(i, j) = f[8];
			min_image.at<uchar>(i, j) = f[0];
		}
	namedWindow("origin");
	imshow("origin", image);
	namedWindow("ave_image", WINDOW_AUTOSIZE);
	imshow("ave_image", ave_image);
	imwrite("../output/ave_image.bmp", ave_image);
	namedWindow("mid_image", WINDOW_AUTOSIZE);
	imshow("mid_image", mid_image);
	imwrite("../output/mid_image.bmp", mid_image);
	namedWindow("max_image", WINDOW_AUTOSIZE);
	imshow("max_image", max_image);
	imwrite("../output/max_image.bmp", max_image);
	namedWindow("min_image", WINDOW_AUTOSIZE);
	imshow("min_image", min_image);
	imwrite("../output/min_image.bmp", min_image);


	Saltapepper(image, 5000);
	for (int i = 2; i < image.rows - 1; i++)
		for (int j = 2; j < image.cols - 1; j++)
		{
			int f[9];
			f[0] = image.at<uchar>(i, j + 1);
			f[1] = image.at<uchar>(i - 1, j + 1);
			f[2] = image.at<uchar>(i - 1, j);
			f[3] = image.at<uchar>(i - 1, j - 1);
			f[4] = image.at<uchar>(i, j - 1);
			f[5] = image.at<uchar>(i + 1, j - 1);
			f[6] = image.at<uchar>(i + 1, j);
			f[7] = image.at<uchar>(i + 1, j + 1);
			f[8] = image.at<uchar>(i, j);
			ave_image.at<uchar>(i, j) = (f[0] + f[1] + f[2] + f[3] + f[4] + f[5] + f[6] + f[7] + f[8]) / 9;
			sort(f, 9);
			mid_image.at<uchar>(i, j) = f[4];
			max_image.at<uchar>(i, j) = f[8];
			min_image.at<uchar>(i, j) = f[0];
		}
	namedWindow("salt_image");
	imshow("salt_image", image);
	imwrite("../output/salt_image.bmp", image);
	namedWindow("salt_ave_image", WINDOW_AUTOSIZE);
	imshow("salt_ave_image", ave_image);
	imwrite("../output/salt_ave_image.bmp", ave_image);
	namedWindow("salt_mid_image", WINDOW_AUTOSIZE);
	imshow("salt_mid_image", mid_image);
	imwrite("../output/salt_mid_image.bmp", mid_image);
	namedWindow("salt_max_image", WINDOW_AUTOSIZE);
	imshow("salt_max_image", max_image);
	imwrite("../output/salt_max_image.bmp", max_image);
	namedWindow("salt_min_image", WINDOW_AUTOSIZE);
	imshow("salt_min_image", min_image);
	imwrite("../output/salt_min_image.bmp", min_image);
	waitKey(0);
	return 0;
}

