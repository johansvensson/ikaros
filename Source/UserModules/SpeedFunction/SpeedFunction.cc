#include "SpeedFunction.h"
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

void SpeedFunction::Init()
{
  from = GetInputMatrix("FROM");
  to = GetInputMatrix("TO");
  speed = GetOutputMatrix("OUTPUT");
  Bind(norm, "norm");
  Bind(max, "max");
  rest = 0;
  x = from[0][0];
  past = -1.0;
}

void SpeedFunction::Tick() {
      float v1 = from[0][0];
      float v2 = to[0][0];

      if(past == past){
      if (x == x){
        x = x+0.01;
        speed[0][0]=pow(exp(1.0),x)/pow((pow(exp(1.0),x)+1.0),2.0);
      } else {
        speed[0][0] = 0.01;
      }} else {
        x = v1;
      }

      past = v1;


    // float v1 = from[0][0];
    // float v2 = to[0][0];
    // float dirAbs = fabs(v1 - v2);
    // float dirComp; //compensate for pos/neg direction
    // if(v2-v1 > 0){
    //   dirComp = 1.0;
    // } else {
    //   dirComp = 0.0;
    // }
    // dirComp = 0.0;
    // if(dirAbs < 5.0){
    //   speed[0][0] = 0.01;
    //   if(rest < 5){
    //     rest++;
    //   }
    // }
    // if(rest > 0 && dirAbs > 5.0){
    //   speed[0][0] = speed[0][0] + speed[0][0]/(float)rest;
    //   rest--;
    // } else {
    //   float temp = dirAbs/norm;
    //   if (temp > max){
    //     speed[0][0] = dirComp + max;
    //   } else {
    //     speed[0][0] = dirComp + temp;
    //   }
    // }
    // if(speed[0][0] < 0.01){
    //   speed[0][0] = 0.01;
    // }





// // // // // // // // //

    // float v1 = from[0][0];
    // float v2 = to[0][0];
    // if(fabs(v1 - v2) < 5.0){
    //   speed[0][0] = 0;
    //   if(rest < 5){
    //     rest++;
    //   }
    // }
    // cout << rest;
    // if(rest > 0  && fabs(v1 - v2) > 5.0){
    //   speed[0][0] = speed[0][0]/rest;
    //   rest--;
    // } else {
    //   float temp = fabs(v1 - v2)/norm;
    //   if (temp > max){
    //     if ((v1 - v2) > 0){ // && fabs(v1 - v2) > 5.0){
    //       speed[0][0] = 1.0 + max;
    //     } else {
    //       speed[0][0] = max;
    //     }
    //   } else {
    //     if ((v1 - v2) > 0){ // && fabs(v1 - v2) > 5.0){
    //       speed[0][0] = 1.0 + temp;
    //     } else {
    //       speed[0][0] = temp;
    //     }
    //   }
    // }



}

static InitClass init("SpeedFunction", &SpeedFunction::Create, "Source/UserModules/SpeedFunction/");
