#include <string>
#include <iostream>

using namespace std;



string parseIp(string ip){
    string new_ip = "";
    int start = 0, pos;
    for(pos = 0;pos<ip.length();pos++){
        if(ip[pos] != '.' && ip[pos] != ':') continue;
        string part = ip.substr(start,pos-start);
        int precision = 3 - part.length();
        new_ip += string(precision, '0').append(part);
        start = pos+1;
    }
    pos++;
    string part = ip.substr(start,pos-start);
    int precision = 4 - part.length();
    new_ip += string(precision, '0').append(part);

    return new_ip;
}

int main() {
    string ip = "1.2.3.4:56";
    cout << ip << " = " << parseIp(ip);

    string curr = "111";
    int precision = 3 - curr.length();
    string num = string(precision, '0').append(curr);
    cout << endl << "test: " << num;

    return 0;
}