#include <iostream>
#include <opencv2\opencv.hpp>
#include <array>


int main(int argc,char *argv[])
{     
    std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string nameimagejpg="imagenes\\RWBYn.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    std::string filename=namedir+nameimage;
    std::string filenamepng=namedir+nameimagejpg;

    cv::Mat image=cv::imread(filename,cv::IMREAD_COLOR);
    if(image.empty()) return -1;

    cv::namedWindow("Mod",cv::WINDOW_FREERATIO);
    cv::namedWindow("imageno",cv::WINDOW_FREERATIO);
    cv::namedWindow("imagenn",cv::WINDOW_FREERATIO);

    int post1=255,post2=255,post3=255;
    cv::createTrackbar("Td1","Mod",&post1,255,NULL);
    cv::createTrackbar("Td2","Mod",&post2,255,NULL);
    cv::createTrackbar("Td3","Mod",&post2,255,NULL);

    int th1=255,th2=255,th3=255;
    int th1a=255,th2a=255,th3a=255;
    char exit;

    cv::Mat chan[3],chanout[3];
    cv::split(image,chan);
    cv::split(image,chanout);
    bool play=true;
    
    cv::imshow("imageno",image);
    cv::imshow("imagenn",image);
    
    while(play)
    {
        th1=cv::getTrackbarPos("Td1","Mod");
        th2=cv::getTrackbarPos("Td2","Mod");
        th3=cv::getTrackbarPos("Td3","Mod");

        if(th1!=th1a||th2!=th2a||th3!=th3a)
        {   
            if((th1-th1a)!=0)   cv::threshold(chan[0],chanout[0],(double)th1a,(double)th1a,cv::THRESH_TRUNC);
            if((th2-th2a)!=0)   cv::threshold(chan[1],chanout[1],(double)th2a,(double)th2a,cv::THRESH_TRUNC);
            if((th3-th3a)!=0)   cv::threshold(chan[2],chanout[2],(double)th3a,(double)th3a,cv::THRESH_TRUNC);
            cv::merge(chanout,3,image);
            cv::imshow("imagenn",image);
            th1a=th1;
            th2a=th2;
            th3a=th3;
        }
        exit=cv::waitKey(16);
        if(exit==27) play=false;
    }

    cv::imwrite(filenamepng,image);
    //../../imagenes/RWBY.png
    cv::destroyAllWindows();
    //system("pause");
    return 0;
}


//b_max=20;
//img[img[:,:,0]>b_max,0]=b_max