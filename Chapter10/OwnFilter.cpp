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
        {{"imagen4"}}
    };
    cv::Mat image=cv::imread(filename,cv::IMREAD_COLOR);
    cv::Mat images;
    cv::Mat chan[3],chanout[3];
    cv::split(image,chanout);

    if(image.empty()) return -1;
    
    for(std::string name:names)
    {
        cv::namedWindow(name,cv::WINDOW_FREERATIO);
    }
    cv::Point2i point(-1,-1);
    cv::Size2i size(5,5);
    cv::Mat kx,ky;
    cv::Scalar sum;

    cv::Mat shape1=cv::getStructuringElement(cv::MORPH_RECT,size,point);
    shape1.convertTo(shape1,CV_32FC1);
    sum=cv::sum(shape1);
    shape1=shape1/sum(0);

    cv::Mat shape2=cv::getStructuringElement(cv::MORPH_ELLIPSE,size,point);
    shape2.convertTo(shape2,CV_32FC1);
    sum=cv::sum(shape2);
    shape2=shape2/sum(0);

    cv::Mat shape3=cv::getStructuringElement(cv::MORPH_CROSS,size,point);
    shape3.convertTo(shape3,CV_32FC1);
    sum=cv::sum(shape3);
    shape3=shape3/sum(0);
    //cv::sepFilter2D 1-by-n row kernel & M-by-1 cplumn kernel
    
    //cv::getDerivKernels(kx,ky,1,1,3,true,CV_8UC1);
    cv::Mat shape4=cv::getGaussianKernel(5,1,CV_32FC1);
    shape4.convertTo(shape4,CV_32FC1);
    sum=cv::sum(shape4);
    shape4=shape4/sum(0);

    int k=0;
    cv::imshow(names[k++],image);
    
    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::filter2D(chan[j],chanout[j],CV_8UC1,shape1,point,0,cv::BORDER_DEFAULT); 
    cv::merge(chanout,3,images); 
    cv::imshow(names[k++],images);
    
    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::filter2D(chan[j],chanout[j],CV_8UC1,shape2,point,0,cv::BORDER_DEFAULT);
    cv::merge(chanout,3,images);   
    cv::imshow(names[k++],images);
    
    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::filter2D(chan[j],chanout[j],CV_8UC1,shape3,point,0,cv::BORDER_DEFAULT);
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);
    
    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::filter2D(chan[j],chanout[j],CV_8UC1,shape4,point,0,cv::BORDER_DEFAULT);
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);
    
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}