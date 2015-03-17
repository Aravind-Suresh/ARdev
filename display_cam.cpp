#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

void properAspectRatioResize(int size[2], int newSize[2], int width, int height) {
	if(width == -1) {
		newSize[0] = height;
		newSize[1] = round((height/size[0]) * size[1]);
	}
	else if(height == -1) {
		newSize[1] = width;
		newSize[0] = round((width/size[1]) * size[0]);
	}
}
void disp_cam(Mat & bigimg,Mat &smallimg,Point start,Point end )
{
for(int j=start.x;j<end.x;j++)
	for(int i=start.y;i<end.y;i++)
		{
			bigimg.at<Vec3b>(i,j)[0]=smallimg.at<Vec3b>(i-start.y,j-start.x)[0];
			bigimg.at<Vec3b>(i,j)[1]=smallimg.at<Vec3b>(i-start.y,j-start.x)[1];
			bigimg.at<Vec3b>(i,j)[2]=smallimg.at<Vec3b>(i-start.y,j-start.x)[2];
}
}

int main(int argc, char** argv)
{

VideoCapture cap1(0);
VideoCapture cap2 = cap1;//cap2(0);
Mat cam1,cam2,cam1_temp,cam2_temp;
//namedWindow("cam1_cam2", CV_WINDOW_FULLSCREEN);
//namedWindow("cam2", WINDOW_AUTOSIZE);


if(!cap1.isOpened() || !cap2.isOpened()) return -1;

for(;;)
{
cap1 >> cam1;
cap2 >> cam2;
int newSize[2];
int currentSize[2];
//cam1.copyTo(cam2);
cam1.copyTo(cam1_temp);
//cout<<frame.rows<<" "<<frame.cols;
///////////1st try
//Mat roi(cam1, Rect(cam1.rows-5-cam2.rows,cam1.cols-5-cam2.cols,cam1.rows-5,cam1.cols-5));
//Mat roi(cam1, Rect(round(0.75*cam1.rows),round(0.75*cam1.cols),cam1.rows,cam1.cols));
//Mat roi(cam1, Rect(round(0.75*cam1.cols),round(0.75*cam1.rows),cam1.cols,cam1.rows));
// fill the ROI with (0,255,0) (which is green in RGB space);
// the original image will be modified


currentSize[0] = cam1.rows;
currentSize[1] = cam1.cols;
properAspectRatioResize(currentSize, newSize, 100, -1);

//Mat roi(cam1, Rect(currentSize[1] - newSize[1], currentSize[0] - newSize[0], currentSize[1],currentSize[0]));
//Mat roi(cam1, Rect(10, 10, 640, 480));
//cout<<roi.rows<<" "<<roi.cols;

//roi=Scalar(0,255,0);

//resize(cam2, cam2,Size(newSize[0],newSize[1]),0,0,CV_INTER_AREA);
resize(cam2, cam2,Size(),0.25,0.25,CV_INTER_AREA);
disp_cam(cam1_temp,cam2,Point(cam1.cols-cam2.cols,cam1.rows-cam2.rows),Point(cam1.cols,cam1.rows));
//cam2.copyTo(roi);

/////////2nd try
//cam2(Range::all(),Range::all()).copyTo(cam1(Range(10,10),Range(100,100)));
//cam2_temp.copyTo(roi);
//roi=Scalar(0,255,0);

/*Mat canvas(cam1.rows+10,cam1.cols+10,CV_8UC3,Scalar(255,255,255));
Rect roi(round(0.75*cam1.cols),round(0.75*cam1.rows),cam1.cols,cam1.rows))
Mat canvasRoi(canvas(roi));
cam1.copyTo(canvasRoi);*/

//////////3rd try
/*Rect roi(round(0.75*cam1.cols),round(0.75*cam1.rows),cam1.cols,cam1.rows);
Mat roiImg;
cam1(roi).copyTo(roiImg);*/


//cout<<cam1.rows<<"  "<<cam1.cols;
// fill the ROI with (0,255,0) (which is green in RGB space);
// the original 320x240 image will be modified

//Mat roiImg=Mat(cam1, Rect(round(0.75*cam1.cols),round(0.75*cam1.rows),cam1.cols,cam1.rows));
//cam2_temp.copyTo(roiImg);

/*/////////////////4th try
int startCol=10,startRow=10;
cam2_temp.copyTo(cam1.colRange(startCol,startCol+cam2_temp.cols).rowRange(s‌​tartRow,startRow+cam2_temp.rows));
imshow("cam1_cam2",cam1);
imshow("cam2",cam2_temp);
*/
namedWindow("roi", WINDOW_AUTOSIZE);
imshow("roi",cam1_temp);
//imshow("cam2",cam2);

if(waitKey(5)==27) break;

}
destroyAllWindows();
/*
destroyWindow("cam1_cam2");
destroyWindow("cam2");*/

return 0;
}