#include "ip_filter.h"
#include <fstream>

using namespace std;

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
vector<string> split(const string &str, char d)
{
    vector<string> r;

    string::size_type start = 0;
    string::size_type stop = str.find_first_of(d);
    while(stop != string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

int read_file()
{
    cout << "reaf_file" << endl;

    string line;
    ifstream myfile("ip_filter.tsv");
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else cout << "Unable to open file" << endl; 
    return 0;
}