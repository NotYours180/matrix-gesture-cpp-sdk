#include "gesture_manager.h"
#include <unistd.h>
#include "iostream"
#include <math.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

inline double getticks() { return (double)getTickCount()/getTickFrequency(); }

template <typename T>
std::string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

int main(int argc, char* argv[])
{
	//Init Gesture and set vars
    //Gesture g(0);
    Gesture g;
    VideoCapture capture = VideoCapture(0);
    g.set_show(true);
    g.set_draw(true);
    g.set_one_hand(true);

    Mat frame;
    std::vector<Detected_Object> det_obj;
    vector<double> times;

    for(;;){
        capture >> frame;
        cout << frame.rows<<"x"<<frame.cols<<endl;

        double t = getticks();

        //Method Vars
        int palm = 0; int pinch = 1; int thumb_up = 2;
        vector<int> hand_types = {palm, pinch, thumb_up};

        //-----Runable Methods-----//
        //det_obj = g.detect(frame, 0); //Need to construct gesture w/o camera
        //det_obj = g.detect(palm);
        det_obj = g.tracking_detect(frame, hand_types); //Need to construct gesture w/o camera
        //det_obj = g.tracking_detect(hand_types);

        /*---Timing ----*/
        double t1 = (1000*(getticks()-t));
        times.push_back(t1);
        if(times.size() > 50){
            times.clear();
        }
        double avg = 0;
        for(int i = 0; i < times.size(); ++i){
            avg += times[i];
        }
        avg = avg/times.size();
        cout << "Time: " << avg << endl;

        //gm.draw_gestures(frame,PALM,true);

        cout << "---- Detected Objects: " << endl;
        //print successes
        for(int i = 0; i < det_obj.size(); ++i){
            cout << det_obj[i].xc_ << " x " << det_obj[i].yc_ << endl;
            cout << "hand type: " << det_obj[i].hand_type_ << " - ID: " << det_obj[i].id_ << endl;
        }

        //g.show_frame(true);

        imshow("Camera input", frame);
        if(waitKey(1) > 0 ) return 0;
    }

    return 0;
}
