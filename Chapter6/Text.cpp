#include <iostream>
#include <time.h>
#include <opencv2\opencv.hpp>

int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;

    cv::Mat image=cv::imread(filename);

    cv::putText(image,"ruby",cv::Point2i(420,260),cv::FONT_HERSHEY_SCRIPT_COMPLEX,2,0,4,cv::LINE_AA,false);
    int baseline;
    cv::getTextSize("ruby",cv::FONT_HERSHEY_SCRIPT_COMPLEX,2,4,&baseline);
    std::cout<<baseline<<std::endl;

    cv::imshow("Poly",image);   
    cv::waitKey();
    cv::destroyAllWindows();
    system("pause");
    return 0;
}