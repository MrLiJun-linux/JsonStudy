#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "json11.hpp"
#include <cassert>
#include <list>
#include <set>
#include <unordered_map>
using namespace std;
using namespace json11;
using std::string;

int main(int argc, char **argv) 
{

    Json my_json = Json::object {
        { "key1", "value1" },
        { "key2", false },
        { "key3", Json::array { 1, 2, 3 } },
    };
    std::string json_str = my_json.dump();
    cout << json_str << endl;

    json11::Json json;
    std::string  err;
    auto Json = json.parse("{\"mac\":\"11:22:33\"}", err);
    if (!err.empty())
    {
        cout << "json parse failed! " << err << endl;
    }
    else 
    {
        cout << "mac " << Json["mac"].string_value() << endl;
    }
    return 0;
}
