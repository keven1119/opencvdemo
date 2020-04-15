//
//  main.cpp
//  opencvdemo
//
//  Created by yons on 15.4.20.
//  Copyright © 2020 yons. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int mfdain(int argc, const char * argv[]) {
    
    
    
    CascadeClassifier classifiter;
    //加载模型
    if(!classifiter.load("/Users/yons/Downloads/OpenCV-android-sdk/sdk/etc/lbpcascades/lbpcascade_frontalcatface.xml")){
        
        
        return -1;
        
        
    }
    
    Mat img = imread("/Users/yons/Downloads/many_preson.jpeg");
    Mat gray;
    

    //降噪
    cvtColor(img, gray, COLOR_BGR2GRAY);
    
//    printf("img piex size:%d\n", img.channels());
//    printf("gray piex size:%d\n", gray.channels());

//    imshow("原图", gray);

    equalizeHist(gray, gray);

//    imshow("灰度图", gray);
    
    std::vector<Rect> faces;
    classifiter.detectMultiScale(gray, faces);
        
    for (Rect face:faces){
        
    
        //画矩形
        rectangle(img, face,Scalar(255, 0, 255));
    }
    
    
    imshow("a", img);

    waitKey();
    
    return 0;
}
