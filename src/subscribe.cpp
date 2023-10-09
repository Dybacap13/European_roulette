#include "../include/RandomRoulette.h"

void rouletteCallback(std_msgs::String call) {
  if (call.data == "Incredible! You really guessed right!") {
    std::cout << "Impossible, you really won";
    return;
  }
  int k = 0 + rand() % 5;
  for (auto count = support_list.begin(); count != support_list.end();
       ++count) {
    if (k == count->second)
      ROS_INFO("-> %s", count->first.c_str());
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "consolation_node");
  ros::NodeHandle nh;
  std::string topic_reading_answer;
  findErrorsParam(nh.getParam("topic_reading_answer", topic_reading_answer),
                  "topic_reading_answer");

  ros::Subscriber sub_ = nh.subscribe("anser_to_topic", 1000, rouletteCallback);
  ros::spin();
  return 0;
}
