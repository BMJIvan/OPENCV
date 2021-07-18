#include "RSimage.h"

RSimage::RSimage(std::string &named,std::string &namei,type type)
{
    imagename=namei;
    filename=named+imagename;
    image=cv::imread(filename,type);
    if(image.empty()) std::cout<<"image not found"<<std::endl;
};

RSimage::~RSimage()
{

};

void RSimage::Show(std::string windowname)
{
    if(image.empty()) return;
    cv::imshow(windowname,image);
    cv::waitKey();
    cv::destroyWindow("Ejemplo");
};