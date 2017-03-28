#include "main.h"
#include <iostream>
#include "library.h"

int main() {


    std::string lat_str;
    std::string lng_str;
    std::string zoom_str;

    std::cout << "Enter Lat:";
    getline(std::cin, lat_str);

    std::cout << "Enter Lng:";
    getline(std::cin, lng_str);

    std::cout << "Enter Zoom (0-13):";
    getline(std::cin, zoom_str);

    double lat = std::stod(lat_str);
    double lng = std::stod(lng_str);
    int zoom = std::stoi(zoom_str);

    projection proj;

    std::cout << "X= " << proj.longitudeToWorldMapPixelX(lng, zoom) << "\n";
    std::cout << "Y= " << proj.latitudeToWorldMapPixelY(lat, zoom) << "\n";
}

