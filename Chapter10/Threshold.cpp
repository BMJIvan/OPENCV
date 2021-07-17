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
    std::vector<std::string> names={
        {{"imagen"}},
        {{"Imagen1"}},
        {{"Imagen2"}},
        {{"imagen3"}},
        {{"Imagen4"}},
        {{"Imagen5"}}
    };
    
    int Threshold[8]={
    cv::THRESH_BINARY,
    cv::THRESH_BINARY_INV,
    cv::THRESH_TRUNC,
    cv::THRESH_TOZERO,
    cv::THRESH_TOZERO_INV,
    cv::THRESH_TRIANGLE};

    std::vector<cv::Mat> images;
    cv::Mat Chan[3],Chanout;
    float thr=200;
    float MaxV=220;
 
    images.push_back(cv::imread(filename,cv::IMREAD_COLOR));
    
    for(int i=0;i<6;i++)
    {   
        cv::split(images[0],Chan);
        cv::threshold(Chan[0],Chan[0],thr,MaxV,Threshold[i]);
        cv::threshold(Chan[1],Chan[1],thr,MaxV,Threshold[i]);
        cv::threshold(Chan[2],Chan[2],thr,MaxV,Threshold[i]);
        cv::merge(Chan,3,Chanout);
        cv::namedWindow(names[i],cv::WINDOW_FREERATIO);
        cv::imshow(names[i],Chanout);
    }

    cv::waitKey();

    cv::destroyAllWindows();
    return 0;
}
