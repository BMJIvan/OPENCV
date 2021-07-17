#include <iostream>
#include <time.h>
#include <opencv2\opencv.hpp>
#include "RSimage.h"

int SliderPos=0;
int run=1,dontset=0;
cv::VideoCapture capture;

void OnTrackBarSlide(int pos, void *);


int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYr.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+namevideo;
    
    cv::namedWindow("Ventana",cv::WINDOW_NORMAL);
    capture.open(filename);

    int fps=(int)capture.get(cv::CAP_PROP_FPS);
    int Frames=(int)capture.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw=(int)capture.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph=(int)capture.get(cv::CAP_PROP_FRAME_HEIGHT);

    std::cout<<"Video has "<<fps<<" frames of dimensions("
    <<tmpw<<","<<tmph<<")."<<std::endl;
    int n=120;
    cv::createTrackbar("Position","Ventana",&SliderPos,Frames,OnTrackBarSlide);
    cv::createTrackbar("extra","Ventana",&n,Frames,NULL);
    cv::Mat frame;
    for(;;)
    {
        if(run!=0)
        {
            capture>>frame; if(frame.empty()) break;
            int Current_Pos=(int)capture.get(cv::CAP_PROP_POS_FRAMES);
            dontset=1;

            cv::setTrackbarPos("Position","Ventana",Current_Pos);
            cv::imshow("Ventana",frame);
            run-=1;
        }
        char c=(char) cv::waitKey(10);
        if(c=='s')
        {
            run=1; std::cout<<"Single step, run = "<<run<<std::endl;
        }
        if(c=='r')
        {
            run=-1; std::cout<<"Run mode, run = "<<run<<std::endl;
        }
        if(c==27) break;
    }

    cv::destroyWindow("Ventana");
    //double time=(double(t1-t0)/CLOCKS_PER_SEC);
    //std::cout<<"Tiempo de ejecucion: "<<time*1000<<"ms"<<std::endl;
    system("pause");
    return 0;
}

void OnTrackBarSlide(int pos, void *){
    capture.set(cv::CAP_PROP_POS_FRAMES,pos);
    if(!dontset) 
    {
        run=1;
        dontset=0;
    }
};