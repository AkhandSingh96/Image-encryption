#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
    double x[102];
    double u;  //u is the control parameter for chaotic map,also known as population rate

    image = imread( "Image.jpg", 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    //Applying Logistic map
    u=3.94;   //It is the condition for logistic map
    x[0]=0.4; //Base condition for logistic map
    for (int i = 1; i <= 100; ++i)
        x[i]=u*x[i-1]*(1-x[i-1]);

    for (int i = 0; i<=100; ++i)
        cout<<x[i]<<" ";

    // reading image pixel
    for(int r = 0; r < image.rows; ++r) {
    for(int c = 0; c < image.cols; ++c) {
        cout << "Pixel at position (x, y) : (" << c << ", " << r << ") =";
        cout<<image.at<Vec3b>(r,c) <<endl;
    }
    }
    namedWindow("Shubham@shaurya", WINDOW_AUTOSIZE );
    imshow("Shubham@shaurya", image);
    waitKey(0);

    return 0;
}