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
        {{"imagen4"}},
        {{"imagen5"}},
        {{"Imagen6"}},
        {{"Imagen7"}},
        {{"Imagen8"}}
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
    cv::Size2i size(7,7);
    int k=0;
    cv::imshow(names[k++],image);
    
    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::morphologyEx(chan[j],chanout[j],cv::MORPH_OPEN,cv::Mat(),point,1,cv::BORDER_DEFAULT,cv::morphologyDefaultBorderValue()); 
    cv::merge(chanout,3,images); //erode->dilate
    cv::imshow(names[k++],images);
    
    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::morphologyEx(chan[j],chanout[j],cv::MORPH_BLACKHAT,cv::Mat(),point,1,cv::BORDER_DEFAULT,cv::morphologyDefaultBorderValue());
    cv::merge(chanout,3,images); //BlackHat=close(input)-input solate dimmer    
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::morphologyEx(chan[j],chanout[j],cv::MORPH_CLOSE,cv::Mat(),point,1,cv::BORDER_DEFAULT,cv::morphologyDefaultBorderValue());
    cv::merge(chanout,3,images); //dilate -> erode
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::morphologyEx(chan[j],chanout[j],cv::MORPH_DILATE,cv::Mat(),point,1,cv::BORDER_DEFAULT,cv::morphologyDefaultBorderValue());
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);
    
    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::morphologyEx(chan[j],chanout[j],cv::MORPH_ERODE,cv::Mat(),point,1,cv::BORDER_DEFAULT,cv::morphologyDefaultBorderValue());
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::morphologyEx(chan[j],chanout[j],cv::MORPH_GRADIENT,cv::Mat(),point,1,cv::BORDER_DEFAULT,cv::morphologyDefaultBorderValue());
    cv::merge(chanout,3,images); //gradient=dilate-erode
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::morphologyEx(chan[j],chanout[j],cv::MORPH_HITMISS,cv::Mat(),point,1,cv::BORDER_DEFAULT,cv::morphologyDefaultBorderValue());
    cv::merge(chanout,3,images);
    cv::imshow(names[k++],images);

    cv::split(image,chan);
    for(int j=0;j<3;j++)    cv::morphologyEx(chan[j],chanout[j],cv::MORPH_TOPHAT,cv::Mat(),point,1,cv::BORDER_DEFAULT,cv::morphologyDefaultBorderValue());
    cv::merge(chanout,3,images); //TopHat=input-open(input) isolate brighter
    cv::imshow(names[k++],images);

    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}