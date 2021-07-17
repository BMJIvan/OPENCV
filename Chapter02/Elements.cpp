#include <iostream>
#include <time.h>
#include <opencv2\opencv.hpp>


int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;

    cv::Mat m1=cv::Mat::eye(10,10,CV_32FC1);
    float element=m1.at<float>(3,3);

    cv::Mat m2=cv::Mat::eye(10,10,CV_32FC2);
    float element1=m2.at<cv::Vec2f>(3,3)[0];
    float element2=m2.at<cv::Vec2f>(3,3)[1];

    cv::Mat m3=cv::Mat::eye(10,10,cv::DataType<cv::Complexf>::channels);
    std::cout<<m3.at<cv::Complexf>(9,9).re<<std::endl;
    std::cout<<m3.at<cv::Complexf>(9,9).im<<std::endl;

    int sz[3]={4,4,4};
    cv::Mat m4(3,sz,CV_32FC3);
    cv::randu(m4,-1.0f,1.0f);

    cv::imread(filename,cv::IMREAD_COLOR);
   
    cv::waitKey();
    cv::destroyAllWindows();
    system("pause");
    return 0;
}


/*
 If matrix is of type `CV_8U` then use `Mat.at<uchar>(y,x)`.
- If matrix is of type `CV_8S` then use `Mat.at<schar>(y,x)`.
- If matrix is of type `CV_16U` then use `Mat.at<ushort>(y,x)`.
- If matrix is of type `CV_16S` then use `Mat.at<short>(y,x)`. 
- If matrix is of type `CV_32S` then use `Mat.at<int>(y,x)`. 
- If matrix is of type `CV_32F` then use `Mat.at<float>(y,x)`. 
- If matrix is of type `CV_64F` then use `Mat.at<double>(y,x)`.
*/