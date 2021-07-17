#include <iostream>
#include <opencv2\opencv.hpp>
#include <array>

int SwitchVal=1;
void SwitchOff(){std::cout<<"Pause\n";};
void SwitchON(){std::cout<<"Run\n";};
void SwitchCallback(int state,void *);


int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+namevideo;
    std::string windowname="Video";

    cv::Mat frame;
    cv::VideoCapture capture;
    capture.open(filename);
    if(capture.isOpened()!=true) return -1;

    cv::namedWindow(windowname,cv::WINDOW_FREERATIO);
    cv::createTrackbar("Switch",windowname,&SwitchVal,1,SwitchCallback);
     
    for(;;)
    {
        capture>>frame;
        if(frame.empty()) break;
        cv::imshow(windowname,frame);
        if(cv::waitKey(32)==27) break;
    }

    cv::destroyAllWindows();
    return 0;
}

void SwitchCallback(int state,void *)
{
    if(state==0)
    {
        SwitchOff();
    }
    else
    {
        SwitchON();
    }
}
