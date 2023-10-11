#include "../include/RandomRoulette.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "European_roulette_client");
  ros::NodeHandle nh;
  RandomRoulette random_roulette(nh, "client");
  European_roulette::ServiceRoulette srv;
  while (ros::ok()) {
    European_roulette::RequestRoulette you_request;
    std::cout << "Enter any integer from 0 to 2000 ";
    std::cin >> you_request.number;
    if (you_request.number < 0 or you_request.number > 2000) {
      std::cout << "You entered a number that is not within the required range. Chance to win 0% ";
    }
    std::cout << "Enter any color ";
    std::cin >> you_request.color;
    srv.request.bid = you_request;
    if (random_roulette.client_.call(srv))
      std::cout << srv.response.anser << std::endl;
    else {
      std::cout << "Failed to call service bid_in_European_roulette"
                << std::endl;
      return 1;
    }
  }
  return 0;
}
