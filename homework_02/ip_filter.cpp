#include "ip_filter.h"
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

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



int sort_ip(vector< vector<string> >ip_pool)
{
    vector data {100, 50, 1, 75, 25, 0};

    ostream_iterator<int> oit(cout, " ");
    copy(begin(data), end(data), oit);
    cout << endl;
    
    sort(begin(data), end(data));
    //ostream_iterator<int> oit(cout, " ");
    copy(begin(data), end(data), oit);
    cout << endl;


    for(vector<vector<string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for(vector<string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                cout << ".";
            }
            cout << *ip_part;
        }
        cout << endl;
    }

    sort(begin(ip_pool), end(ip_pool));

    for(vector<vector<string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for(vector<string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                cout << ".";
            }
            cout << *ip_part;
        }
        cout << endl;
    }
    return 0;
}

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

// int read_file()
// {
//     cout << "reaf_file" << endl;

//     string line;
//     ifstream myfile("ip_filter.tsv");
//     if(myfile.is_open())
//     {
//         while(getline(myfile,line))
//         {
//             cout << line << '\n';
//         }
//         myfile.close();
//     }

//     else cout << "Unable to open file" << endl; 
//     return 0;
// }