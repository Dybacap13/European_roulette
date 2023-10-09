#include <map>
typedef std::pair<std::string, std::string> pair;
std::map<pair, int> color_list = {
    {std::make_pair("Grey", "grey"), 0},
    {std::make_pair("blue", "Blue"), 1},
    {std::make_pair("Green", "green"), 2},
    {std::make_pair("Yellow", "yellow"), 3},
    {std::make_pair("pink ", "Pink "), 4},
    {std::make_pair("orange", "Orange"), 5},
    {std::make_pair("Brown ", "brown"), 6},
    {std::make_pair("White", "white"), 7},
    {std::make_pair("Black ", "black "), 8},
    {std::make_pair("Violet", "violet"), 9},
    {std::make_pair("Gold", "gold"), 10},
    {std::make_pair("Silver ", "silver"), 11},
    {std::make_pair("Lilac", "lilac"), 12},
    {std::make_pair("Coral", "coral"), 13},
    {std::make_pair("Vinous ", "vinous "), 14},
    {std::make_pair("Bronze ", "bronze"), 15},
    {std::make_pair("Sand", "sand "), 16},
    {std::make_pair("Chocolate ", "chocolate "), 17},
    {std::make_pair("Red", "red"), 18},
    {std::make_pair("purple", "Purple"), 19},
    {std::make_pair("another", "another"), 20},
};

std::map<std::string, int> support_list = {
    {"I have missed more than 9,000 shots in my career. I have lost almost 300 "
     "games. 26 times I have been trusted to take the game winning shot and "
     "missed. I have failed over and over and over again in my life, and that "
     "is why I succeed. Michael Jordan",
     1},
    {"It is hard to beat a person who never gives up.” Babe Ruth", 2},
    {"We need to accept that we wont always make the right decisions, that "
     "well screw up royally sometimes understanding that failure is not the "
     "opposite of success, its part of success. Arianna Huffington",
     3},
    {"When one door of happiness closes, another opens, but often we look so "
     "long at the closed door that we do not see the one which has been opened "
     "for us. Helen Keller ",
     4},
    {" Impossible is just an opinion. Paulo Coelho", 5},
};
