#include <iostream>
#include <time.h>
#include <opencv2\opencv.hpp>


int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;

    cv::namedWindow("ejemplo");
    cv::VideoCapture cap;
    bool ini=true;
    cap.open(1);
    if(cap.isOpened()) std::cout<<"camara Web"<<std::endl;
    
    cv::Mat frame;
    
    for(;;)
    {
        cap>>frame;
        cv::imshow("ejemplo",frame);
        char c=cv::waitKey(16);
        if(c==27) break;
    }

    /*cv::Mat imageout;
    cv::namedWindow("image out",cv::WINDOW_NORMAL);
    cv::imshow("image out",imageout);*/

    cap.release();
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}