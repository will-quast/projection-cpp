#include "library.h"
#include <iostream>
#include <string>
#include <math.h>

inline double toDegrees(double radians)
{
    return radians * (180.0 / M_PI);
}

inline double toRadians(double degrees)
{
    return degrees / (180.0 * M_PI);
}

int projection::longitudeToWorldMapPixelX(double longitude, int zoom)
{
    double radians = toRadians(longitude);
    double radiansPerWorldMapPixel = radiansPerWorldMapPixelAtZoom[zoom];
    int x = (int) round((radians / radiansPerWorldMapPixel));
    return x;
}

int projection::latitudeToWorldMapPixelY(double latitude, int zoom)
{
    double radians = toRadians(latitude);
    double radiansPerWorldMapPixel = radiansPerWorldMapPixelAtZoom[zoom];
    double sinRads = sin(radians);
    int y = (int) round((-(0.5 * log((1 + sinRads) / (1 - sinRads))) / radiansPerWorldMapPixel));
    return y;
}

projection::projection()
{
    int worldMapPixelWidth = tileSize;

    for (int zoom = totalZoomLevels; zoom >= 0; zoom--) {
        worldMapPixelsAtZoom[zoom] = worldMapPixelWidth;
        worldMapTilesPerHemiAtZoom[zoom] = (worldMapPixelWidth / tileSize) / 2;
        radiansPerWorldMapPixelAtZoom[zoom] = (2 * M_PI) / worldMapPixelWidth;

        // double the size of the map at each zoom
        worldMapPixelWidth = worldMapPixelWidth * 2;
    }
}
