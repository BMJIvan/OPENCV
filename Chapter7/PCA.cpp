#include <iostream>
#include <time.h>
#include <opencv2\opencv.hpp>

int main(int argc,char *argv[])
{     
    //std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    //std::string filename=namedir+nameimage;

    //cv::Mat Mat=cv::imread(filename,cv::IMREAD_COLOR);
    cv::Mat canvas(400,400,CV_8UC1,cv::Scalar(255));
    //cv::namedWindow("canvas",cv::WINDOW_FULLSCREEN);
    
    cv::Mat Mat1(2,100,CV_8UC1);
    cv::Mat Mat2(2,100,CV_8UC1);
    cv::randu(Mat1,cv::Scalar(80),cv::Scalar(115));
    cv::randu(Mat2,cv::Scalar(140),cv::Scalar(170));
    
    cv::Mat Mat1Col;
    cv::reduce(Mat1,Mat1Col,1,cv::REDUCE_AVG);
    cv::PCA pca1(Mat1,Mat1Col,cv::PCA::DATA_AS_COL,2);
    //std::cout<<pca1.mean<<std::endl; cv::PCA pca1(Mat1,cv::Mat(),cv::PCA::DATA_AS_COL,2);
    cv::Mat EValues1=pca1.eigenvalues.clone();
    cv::Mat EVectors1=pca1.eigenvectors.clone();

    cv::Mat Mat2Col;
    cv::reduce(Mat2,Mat2Col,1,cv::REDUCE_AVG);
    cv::PCA pca2(Mat2,Mat2Col,cv::PCA::DATA_AS_COL,2);
    cv::Mat EValues2=pca2.eigenvalues.clone();
    cv::Mat EVectors2=pca2.eigenvectors.clone();

    cv::Mat Mat1f;
    Mat1.convertTo(Mat1f,CV_32FC1);
    cv::Mat Mat2f;
    Mat2.convertTo(Mat2f,CV_32FC1);

    cv::Mat Mat1N=EVectors1*Mat1f;
    cv::Mat Mat2N=EVectors2*Mat2f;

    std::cout<<"Mostrar"<<std::endl;
    int px;
    int py;
    for(int i=0;i<100;i+=1)
    {
        px=Mat1.at<uchar>(0,i);
        py=Mat1.at<uchar>(1,i);
        cv::circle(canvas,cv::Point2i(px,py),2,0,1,cv::LINE_8,0);
        px=Mat2.at<uchar>(0,i);
        py=Mat2.at<uchar>(1,i);
        cv::circle(canvas,cv::Point2i(px,py),2,0,1,cv::LINE_8,0); 
        px=Mat1N.at<float>(0,i);
        py=Mat1N.at<float>(1,i);
        cv::circle(canvas,cv::Point2f(px,py),2,0,1,cv::LINE_8,0);
        px=Mat2N.at<float>(0,i);
        py=Mat2N.at<float>(1,i);
        cv::circle(canvas,cv::Point2f(px,py),2,0,1,cv::LINE_8,0); 
    }

    cv::imshow("canvas",canvas);
    cv::waitKey();
    cv::destroyAllWindows();
    //system("pause");
    return 0;
}
