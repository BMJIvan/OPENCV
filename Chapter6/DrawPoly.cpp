#include <iostream>
#include <time.h>
#include <opencv2\opencv.hpp>

int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;

    std::vector<cv::Point2i> Vec;

    cv::Mat image=cv::imread(filename);
    //cv::Mat image=cv::Mat(4000,2000,CV_8UC3,cv::Scalar{255,255,255});
    cv::namedWindow("Poly",cv::WINDOW_AUTOSIZE);
    cv::circle(image,cv::Point2d(600,424),84,0,5,cv::LINE_8,0);
    //size=cv::Size2f(20,40);
    cv::ellipse(image,cv::Point2d(400,424),cv::Size2f(100,300),0,0,360,0,4,cv::LINE_8,0);
    cv::ellipse2Poly(cv::Point2d(800,400),cv::Size2f(100,300),0,0,360,90,Vec);
    cv::fillConvexPoly(image,Vec,0,cv::LINE_AA,0);

    std::vector<cv::Point2i> Vec2;
    Vec2.push_back(cv::Point2i(100,100));
    Vec2.push_back(cv::Point2i(115,130));
    Vec2.push_back(cv::Point2i(145,160));
    Vec2.push_back(cv::Point2i(115,190));
    //Vec2.push_back(cv::Point2i(100,100));
    cv::fillConvexPoly(image,Vec2,0,cv::LINE_AA,0);

    cv::imshow("Poly",image);   
    cv::waitKey();
    cv::destroyAllWindows();
    system("pause");
    return 0;
}