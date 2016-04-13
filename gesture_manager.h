#ifndef GESTUREMANAGER_H
#define GESTUREMANAGER_H

#include "opencv2/opencv.hpp"

class Detected_Object {
public:
	//Constructors & Destructors
    Detected_Object();
    Detected_Object(int x, int y, int width, int height, int hand_type, int id);
    ~Detected_Object();
    
    //Class Variables
    int x_, y_, xc_, yc_, width_, height_, id_, hand_type_;

};

class Gesture
{
public:
    //Constructors
    Gesture();
    Gesture(int camera);

    //Class Variables
    cv::Mat frame_;
    cv::VideoCapture camera_;

    //Methods
    std::vector<Detected_Object> detect(int hand_type);
    std::vector<Detected_Object> detect(cv::Mat &frame, int hand_type);

    std::vector<Detected_Object> tracking_detect(std::vector<int> hand_types);
    std::vector<Detected_Object> tracking_detect(cv::Mat &frame, std::vector<int> hand_types);

    //Settter methods
    void show_frame();
    void set_time_to_count_detection(double time);
    void set_time_to_discard_detection(double time);
    void set_one_hand(bool one_hand);
    void set_draw(bool draw);
    void set_show(bool show);
    void set_kalman(bool kalman);
    void set_frame_flip(bool flip_frame);
    void detection_quality(int quality);
    void stop_video_capture();

};

#endif // GESTERMANAGER_H