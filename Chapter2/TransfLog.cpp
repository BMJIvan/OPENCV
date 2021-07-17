#include <iostream>
#include <time.h>
#include <opencv2\opencv.hpp>


int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+namevideo;

    cv::namedWindow("Original");
    cv::namedWindow("Polar");
    cv::VideoCapture cap(filename);
    cv::Mat frame;
    cv::Mat Polarframe;

    std::cout<<"problema conel nombre"<<std::endl;

    double fps=cap.get(cv::CAP_PROP_FPS);
    cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH),(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    cv::VideoWriter writter;
    //argv[2] name of the new file
    writter.open(argv[2],cv::VideoWriter::fourcc('P','I','M','1'),fps,size);
    if(writter.isOpened()){
    for(;;)
    {
        cap>>frame; if(frame.empty()) break;
        cv::imshow("original",frame);

        cv::logPolar(frame,Polarframe,cv::Point2f(size.width/2,size.height/2),80,cv::WARP_FILL_OUTLIERS);

        cv::imshow("Polar",Polarframe);
        writter<<Polarframe;

        char c=cv::waitKey(10);
        if(c==27) break;
    }
    }

    /*cv::Mat imageout;
    cv::namedWindow("image out",cv::WINDOW_NORMAL);
    cv::imshow("image out",imageout);*/

    cap.release();
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}