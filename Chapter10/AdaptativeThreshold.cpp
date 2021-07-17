#include <iostream>
#include <opencv2\opencv.hpp>
#include <vector>
#include <array>

int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;
    std::string winname="ThA";
    std::string winnameM="ThAM";

    cv::namedWindow(winname,cv::WINDOW_FREERATIO);
    cv::namedWindow(winnameM,cv::WINDOW_FREERATIO);
    cv::Mat image=cv::imread(filename,cv::IMREAD_COLOR);
;
    cv::Mat chan[3],chanout1[3],chanout2[3];
    cv::split(image,chan);
    cv::split(image,chanout1);
    cv::split(image,chanout2);

    cv::adaptiveThreshold(chan[0],chanout1[0],210,cv::ADAPTIVE_THRESH_GAUSSIAN_C,cv::THRESH_BINARY,3,20);
    cv::adaptiveThreshold(chan[1],chanout1[1],210,cv::ADAPTIVE_THRESH_GAUSSIAN_C,cv::THRESH_BINARY,3,20);
    cv::adaptiveThreshold(chan[2],chanout1[2],210,cv::ADAPTIVE_THRESH_GAUSSIAN_C,cv::THRESH_BINARY,3,20);
    cv::adaptiveThreshold(chan[0],chanout2[0],210,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,3,20);
    cv::adaptiveThreshold(chan[1],chanout2[1],210,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,3,20);
    cv::adaptiveThreshold(chan[2],chanout2[2],210,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,3,20);

    cv::merge(chanout1,3,image);
    cv::imshow(winname,image);
    cv::merge(chanout2,3,image);
    cv::imshow(winnameM,image);
    
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}