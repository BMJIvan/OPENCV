#include <iostream>
#include <opencv2\opencv.hpp>
#include <array>

int main(int argc,char *argv[])
{     
    cv::VideoCapture capture;
    capture.open(0);
    if(capture.isOpened()==false) return -1;

    cv::namedWindow("Mod",cv::WINDOW_FREERATIO);
    cv::namedWindow("imagen",cv::WINDOW_FREERATIO);

    int post1=128,post2=129;
    cv::createTrackbar("bright","Mod",&post1,255,NULL);
    cv::createTrackbar("contrast","Mod",&post2,255,NULL);

    //cv::Mat chan[3],chanout[3];
    double bright=capture.get(cv::CAP_PROP_BRIGHTNESS);
    double contrast=capture.get(cv::CAP_PROP_CONTRAST);
    double hue=capture.get(cv::CAP_PROP_HUE);
    double gain=capture.get(cv::CAP_PROP_GAIN);
    double exposure=capture.get(cv::CAP_PROP_EXPOSURE);
    double balanB=capture.get(cv::CAP_PROP_WHITE_BALANCE_BLUE_U);
    double balanR=capture.get(cv::CAP_PROP_WHITE_BALANCE_RED_V);
    
    std::cout<<"bright: "<<bright<<std::endl;
    std::cout<<"contrast: "<<contrast<<std::endl;
    std::cout<<"hue: "<<hue<<std::endl;
    std::cout<<"gain: "<<gain<<std::endl;
    std::cout<<"exposure: "<<exposure<<std::endl;
    std::cout<<"balance Blue: "<<balanB<<std::endl;
    std::cout<<"balance Red: "<<balanR<<std::endl;

    int th1=128,th2=128,th3=128;
    cv::createTrackbar("Td1","Mod",&th1,255,NULL);
    cv::createTrackbar("Td2","Mod",&th2,255,NULL);
    cv::createTrackbar("Td3","Mod",&th3,255,NULL);

    cv::Mat frame,image;
    cv::Mat chan[3],chanout[3];
    char exit;    
    for(;;)
    {
        capture>>frame;
        if(frame.empty()) break;
        
        bright=(double)cv::getTrackbarPos("bright","Mod");
        contrast=(double)cv::getTrackbarPos("contrast","Mod");

        capture.set(cv::CAP_PROP_BRIGHTNESS,bright);
        capture.set(cv::CAP_PROP_CONTRAST,contrast);

        th1=cv::getTrackbarPos("Td1","Mod");
        th2=cv::getTrackbarPos("Td2","Mod");
        th3=cv::getTrackbarPos("Td3","Mod");
 
        cv::split(frame,chan);
        cv::threshold(chan[0],chanout[0],(double)th1,(double)th1,cv::THRESH_TRUNC);
        cv::threshold(chan[1],chanout[1],(double)th2,(double)th2,cv::THRESH_TRUNC);
        cv::threshold(chan[2],chanout[2],(double)th3,(double)th3,cv::THRESH_TRUNC);
        cv::merge(chanout,3,image);

        cv::imshow("imagen",image);
        exit=cv::waitKey(10);
        if(exit==27) break;
    }
    cv::destroyAllWindows();
    return 0;
}
