#include <iostream>
#include <opencv2\opencv.hpp>
#include <vector>

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
    {{"Imagen5"}},
    {{"imagen6"}},
    {{"Imagen7"}},
    {{"Imagen8"}},
    };

    int Borders[8]={
    cv::BORDER_CONSTANT,
    cv::BORDER_DEFAULT,
    cv::BORDER_ISOLATED,
    cv::BORDER_REFLECT101,
    cv::BORDER_REFLECT,
    cv::BORDER_REPLICATE,
    cv::BORDER_WRAP,
    cv::BORDER_TRANSPARENT};

    std::vector<cv::Mat> images;
    
    images.push_back(cv::imread(filename,cv::IMREAD_COLOR));
    int rows=images[0].rows;
    int cols=images[0].cols;

    for(int i=1;i<=7;i++)
    {   
        images.push_back(cv::Mat::zeros(cv::Size2i(rows,cols),CV_8UC3));
        cv::copyMakeBorder(images[0],images[i],200,200,200,200,Borders[i-1]);
    }
    
    for(int i=0;i<=7;i++)
    {
        cv::namedWindow(names[i],cv::WINDOW_FREERATIO);
        cv::imshow(names[i],images[i]);
    }
 
    cv::waitKey();

    cv::destroyAllWindows();
    return 0;
}