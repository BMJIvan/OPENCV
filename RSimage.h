#ifndef RSimage_H
#define RSimage_H

#include <iostream>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

class RSimage
{
    private:
        std::string imagename;
        std::string filename;
        cv::Mat image;
    
    public:
        enum type {Gray,Color};

    public:
        RSimage(std::string &,std::string &,type);
        ~RSimage();
        void Show(std::string);
};

#endif