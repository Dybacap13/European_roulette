#include "../include/map.h"
#include "std_msgs/String.h"
#include <European_roulette/RequestRoulette.h>
#include <European_roulette/ServiceRoulette.h>
#include <cstdlib>
#include <math.h>
#include <ros/ros.h>
#include <string>

void findErrorsParam(bool errors, std::string param) {
  if (errors)
    return;
  ROS_ERROR("Error in parameter -> %s", param.c_str());
}

class RandomRoulette {
private:
  ros::NodeHandle &nh;
  ros::ServiceServer service_;
  ros::Publisher pub;

  bool randomNumber(int);
  bool randomColor(std::string);
  std::string resultRandom(bool, bool);
  bool init_service(European_roulette::ServiceRoulette::Request &req,
                    European_roulette::ServiceRoulette::Response &res);
  void rouletteCallback(std_msgs::String call);

public:
  ros::ServiceClient client_;
  RandomRoulette(ros::NodeHandle &nh_, std::string what_need) : nh(nh_) {
      std::string signal_client_service;
      findErrorsParam(nh.getParam("signal_client_service", signal_client_service),
                      "signal_client_service");
    if (what_need == "service") {

        std::string topic_reading_answer;

        findErrorsParam(nh.getParam("topic_reading_answer", topic_reading_answer),
                        "topic_reading_answer");
      pub = nh_.advertise<std_msgs::String>(topic_reading_answer, 1000);
      service_ = nh_.advertiseService(signal_client_service,
                                      &RandomRoulette::init_service, this);
    } else
      client_ = nh_.serviceClient<European_roulette::ServiceRoulette>(
          signal_client_service);
  }
};

bool RandomRoulette::init_service(
    European_roulette::ServiceRoulette::Request &req,
    European_roulette::ServiceRoulette::Response &res) {
  European_roulette::RequestRoulette rate;
  rate.number = req.bid.number;
  rate.color = req.bid.color;
  res.anser =
      resultRandom(randomNumber(req.bid.number), randomColor(req.bid.color));
  std_msgs::String msg_str;
  msg_str.data = res.anser;
  pub.publish(msg_str);
  return true;
}

bool RandomRoulette::randomNumber(int rand_y) {
  int success = 0 + rand() % 2000;
  if (fabs(success - rand_y) <= 100)
    return true;
  return false;
}

bool RandomRoulette::randomColor(std::string rand_y) {
  int success = 0 + rand() % 20;
  for (auto count = color_list.begin(); count != color_list.end(); ++count) {
    auto key_pair = count->first;
    if (rand_y == key_pair.first or rand_y == key_pair.second) {
      if (success == count->second)
        return true;
    } else if (success == 20)
      return true;
  }
  return false;
}
std::string RandomRoulette::resultRandom(bool number, bool color) {
  std::string resolt;
  if (number and color)
    return "Incredible! You really guessed right!";
  else if (number == true and color == false)
    return "You guessed the number, but not the color. Try again.";
  else if (number == false and color == true)
    return "You guessed the color, but not the number. Try again.";
  else
    return "You guessed nothing. Better luck next time.";
}


