#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int main(){

    int n; fin >> n;

    vector<int> timestamps(n);
    vector<double> lat(n);
    vector<double> longt(n);
    vector<double> alt(n);
    map<pair<string, string>, vector<int> > routes;

    for(int i = 0; i < n; i++){
        fin >> timestamps[i] >> lat[i] >> longt[i] >> alt[i];
        string a, b;
        int takeoff;

        fin >> a >> b >> takeoff;

        routes[make_pair(a, b)].push_back(takeoff);
    }

    for(auto i : routes){
       vector<int>::iterator ip;

        ip = std::unique(i.second.begin(), i.second.end());

        i.second.resize(std::distance(i.second.begin(), ip));

        fout << i.first.first << " " << i.first.second << " " << i.second.size() << "\n";
    }


    return 0;
}
