#include "../include/RandomRoulette.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "European_roulette_server");
  ros::NodeHandle nh;
  RandomRoulette random_roulette(nh, "service");
  ros::spin();
  return 0;
}
