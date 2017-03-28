#ifndef CALORIES_LIBRARY_H
#define CALORIES_LIBRARY_H

class projection
{
private:
    static const int totalZoomLevels = 17;
    static const int minZoom = 0; // close to surface
    static const int maxZoom = 13; // far from surface
    static const int tileSize = 256;
    int worldMapPixelsAtZoom[totalZoomLevels + 1];
    int worldMapTilesPerHemiAtZoom[totalZoomLevels + 1];
    double radiansPerWorldMapPixelAtZoom[totalZoomLevels + 1];
public:
    projection();

    int longitudeToWorldMapPixelX(double longitude, int zoom);
    int latitudeToWorldMapPixelY(double latitude, int zoom);
};

#endif