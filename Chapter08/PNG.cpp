#include <iostream>
#include <opencv2\opencv.hpp>
#include <array>

int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string nameimagepng="imagenes\\RWBYP.png";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;
    std::string filenamepng=namedir+nameimagepng;
    cv::Mat image=cv::imread(filename,cv::IMREAD_COLOR);
    if(image.empty()) return -1;

    cv::Mat chan[3];
    cv::split(image,chan);
    cv::Mat alpha(image.rows,image.cols,CV_8UC1,cv::Scalar(50));
    //chan[4]=alpha;
    cv::Mat imageout;
    std::vector<cv::Mat> RGBA;
    RGBA.push_back(chan[0]);
    RGBA.push_back(chan[1]);
    RGBA.push_back(chan[2]);
    RGBA.push_back(alpha);
    cv::merge(RGBA,imageout);
    std::cout<<imageout.channels()<<","<<imageout.cols<<","<<imageout.rows<<std::endl;
    cv::imwrite(filenamepng,imageout);    
    //../../imagenes/RWBY.png
    cv::waitKey();
    cv::destroyAllWindows();
    //system("pause");
    return 0;
}
