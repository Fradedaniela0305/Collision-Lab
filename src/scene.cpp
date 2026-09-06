#include "scene.h"

#include "nlohmann/json.hpp"
#include <fstream>
#include "object.h"

using json = nlohmann::json;


std::vector<Object3D> loadScene(const std::string& filename) {

    std::ifstream file(filename);
json data;
file >> data;

}