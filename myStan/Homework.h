
#include <string>
#include <map>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

class Homework {
public:
    int homework_id;
    int course_id;
    string description;
    map<int, string> submissions;
    map<int, int> grades;
};