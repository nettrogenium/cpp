// validates ip address
#include <iostream>
#include <string>

using namespace std;
bool valip(string s)
{
    bool result=true;
    string n;
    int octcount=0;
    for (auto c: s + '.')
    {
        if ('0' <= c && c <= '9')
        {
            n+=c;
        }
        else if (c=='.')
        {
            if(n.empty() || stoi(n)>255)
            {
                result=false;
                break;
            }
            octcount++;
            n="";
        }
        else
        {
            result=false;
            break;
        }
    }
    if (octcount!=4)
    {
        result=false;
    }
    return result;
}
