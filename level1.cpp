#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int main(){

    int n; fin >> n;

    vector<int> timestamps(n);
    vector<double> lat(n);
    vector<double> longt(n);
    vector<double> alt(n);

    for(int i = 0; i < n; i++){
        fin >> timestamps[i] >> lat[i] >> longt[i] >> alt[i];
    }

    fout << *min_element(timestamps.begin(), timestamps.end()) << " ";
    fout << *max_element(timestamps.begin(), timestamps.end()) << '\n';
    fout << setprecision(5) << *min_element(lat.begin(), lat.end()) << " ";
    fout << setprecision(5) << (*max_element(lat.begin(), lat.end())) << '\n';
    fout << setprecision(5) << (*min_element(longt.begin(), longt.end())) << " ";
    fout << setprecision(5) << (*max_element(longt.begin(), longt.end())) << '\n';
    fout << setprecision(5) << (*max_element(alt.begin(), alt.end()));

return 0;
}
