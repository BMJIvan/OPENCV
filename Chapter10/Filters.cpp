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
        {{"ImagenO"}},
        {{"Imagen1"}},
        {{"Imagen2"}},
        {{"imagen3"}},
        {{"Imagen4"}},
        {{"Imagen5"}},
    };
    cv::Mat image=cv::imread(filename,cv::IMREAD_COLOR);
    cv::Mat images;
    cv::Mat chan[3],chanout[3];
    cv::split(image,chan);
    cv::split(image,chanout);

    if(image.empty()) return -1;
    
    for(std::string name:names)
    {
        cv::namedWindow(name,cv::WINDOW_FREERATIO);
    }
    cv::Point2i point(-3,-3);
    cv::Size2i size(7,7);
    int i=0,k=0;
    int rows=image.rows;
    int cols=image.cols;

    cv::imshow(names[0],image);

    for(int j=0;j<3;j++)    cv::blur(chan[j],chanout[j],size,point,cv::BORDER_DEFAULT); 
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::boxFilter(chan[j],chanout[j],CV_8UC1,size,point,true,cv::BORDER_DEFAULT);
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);
    
    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::boxFilter(chan[j],chanout[j],CV_8UC1,size,point,true,cv::BORDER_DEFAULT);
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::medianBlur(chan[j],chanout[j],3);
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::GaussianBlur(chan[j],chanout[j],size,3,3);
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::bilateralFilter(chan[j],chanout[j],3,3,3,cv::BORDER_DEFAULT);
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);
    
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}