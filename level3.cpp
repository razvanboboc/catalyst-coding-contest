#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>

#include <math.h>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int main(){

    int n; fin >> n;

    for(int i = 0; i < n; i++){
        const float pi = std::acos(-1);

        double lat, longt, alt;
        fin >> setprecision(5) >> lat >> setprecision(5) >> longt >> setprecision(5) >> alt;

        float latr = (pi / 180.0) * lat;
        float longtr = (pi / 180.0) * longt;

        float earthRadius = 6371000.0;

        float coslat = cos(latr);
        float coslong = cos(longtr);
        float sinlong = sin(longtr);
        float sinlat = sin(latr);

        float x = coslat*coslong*earthRadius;
        float y = coslat*sinlong*earthRadius;
        float z = earthRadius * sinlat;
        fout<< fixed;
        fout<< setprecision(10) << x  << " ";
        fout<< setprecision(10) << y << " ";
        fout<< setprecision(10) << z<< "\n";
    }



    return 0;
}
