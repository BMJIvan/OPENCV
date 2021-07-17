#include <iostream>
#include <opencv2\opencv.hpp>
#include <array>

int main(int argc,char *argv[])
{     
    //std::string namedir=argv[1];
    std::string nameimage="imagenes\\RWBYP.jpg";
    std::string namevideo="videos\\lostbelt.mp4";
    //std::string filename=namedir+nameimage;
    //cv::Mat Mat=cv::imread(filename,cv::IMREAD_COLOR);
    std::array<std::array<float,1>,7> Vecb={{
    {{1}},
    {{1}},
    {{1}},
    {{1}},
    {{1}},
    {{1}},
    {{1}}
    }};
    std::array<std::array<float,5>,7> Vec={{
    {{1,1,1,0,0}},
    {{3,3,3,0,0}},
    {{4,4,4,0,0}},
    {{5,5,5,0,0}},
    {{0,2,0,4,4}},
    {{0,0,0,5,5}},
    {{0,1,0,2,2}}
    }};

    cv::Mat A(7,5,CV_32FC1,&Vec,0);    
    cv::Mat b(7,1,CV_32FC1,&b,0);
    cv::Mat W;
    cv::Mat U;
    cv::Mat V;
    cv::SVD svd;
    svd.compute(A,W,U,V);
    //A=U*W*Vt
    /*std::cout<<A<<std::endl<<std::endl;
    std::cout<<W<<std::endl<<std::endl;
    std::cout<<U<<std::endl<<std::endl;*/
    //std::cout<<V<<std::endl<<std::endl;

    //cv::Mat x;    
    //svd.solveZ(A,x);  //A*x=0
    //svd.backSubst(b,x);   //U*W*Vt*x=b 
    //std::cout<<x<<std::endl;

    //cv::Mat Vt;
    cv::Mat Ar;
    //cv::transpose(V,Vt);
    Ar=U*cv::Mat::diag(W)*V;
    std::cout<<Ar<<std::endl;

    cv::Mat x;
    svd.backSubst(W,U,V,b,x); //x=Vt*diag(W)^-1*Ut*b~A^-1*b
    Ar=U*cv::Mat::diag(W)*V;
    std::cout<<Ar<<std::endl;

    cv::waitKey();
    cv::destroyAllWindows();
    //system("pause");
    return 0;
}
