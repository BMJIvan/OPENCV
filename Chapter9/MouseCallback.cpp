#include <iostream>
#include <opencv2\opencv.hpp>
#include <array>

void MouseCallback(int event,int x, int y,int flags,void* param);
cv::Rect box;
bool drawingBox=false;
bool deleteRec=true;
void drawBox(cv::Mat &img,cv::Rect box);

struct images
{
    cv::Mat image;
    cv::Mat Pclean; 
};


int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;
    std::string windowname="Mouse";

    box=cv::Rect(-1,-1,0,0);
    images images;
    images.image=cv::imread(filename,cv::IMREAD_COLOR);
    cv::Mat temp;
    images.image.copyTo(temp);
    images.image.copyTo(images.Pclean);
    cv::namedWindow(windowname,cv::WINDOW_FREERATIO);
    cv::imshow(windowname,images.image);

    cv::setMouseCallback(windowname,MouseCallback,(void*)&images);

    for(;;)
    {
        images.image.copyTo(temp);
        if(drawingBox)
        {
            drawBox(temp,box);
            cv::imshow(windowname,temp);
        } 
        else
        {
            cv::imshow(windowname,images.image);
        }

        if(cv::waitKey(50)==27) break;
    }

    cv::destroyAllWindows();
    return 0;
}

void MouseCallback(int event,int x, int y,int flags,void* param)
{
    images* imgs=(images*) param;

    switch (event)
    {
        case cv::EVENT_MOUSEMOVE:
        {
            if(drawingBox)
            {
                box.width=x-box.x;
                box.height=y-box.y;
            } break;
        }
        case cv::EVENT_LBUTTONDOWN:
        {
            drawingBox=true;
            box=cv::Rect(x,y,0,0);
            if(deleteRec) imgs->Pclean.copyTo(imgs->image);
            deleteRec=false;
        } break;
        case cv::EVENT_LBUTTONUP:
        {
            drawingBox=false;
            deleteRec=true;
            if(box.width<0)
            {
                box.x+=box.width;
                box.width*=-1;
            }
            if(box.height<0)
            {
                box.y+=box.height;
                box.height*=-1;
            }
            drawBox(imgs->image,box);
        } break;
    }
}

void drawBox(cv::Mat &img,cv::Rect box)
{
    cv::rectangle(img,box.tl(),box.br(),cv::Scalar(0x00,0x00,0xff),3);
}