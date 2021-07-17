#include <iostream>
#include <time.h>
#include <opencv2\opencv.hpp>
#include "RSimage.h"


int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;

    cv::Mat image=cv::imread(filename,cv::IMREAD_COLOR);
    cv::namedWindow("image in",cv::WINDOW_AUTOSIZE);
    cv::namedWindow("image out",cv::WINDOW_AUTOSIZE);
    cv::imshow("image in",image);
    
    cv::Mat imagegray;
    cv::cvtColor(image,imagegray,cv::COLOR_BGR2GRAY);

    cv::Mat imageout;
    
    //GaussiaBlur(),blur(),median(), bilateralFilter()
    //cv::GaussianBlur(image,imageout,cv::Size(31,31),1,1);    
    //cv::pyrDown(image,imageout);//Gaussian filter 
    //cv::Canny(imagegray,imageout,1,120,3,true);
    cv::imshow("image out",imageout);

    
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}
