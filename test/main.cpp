#include<iostream>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
void split(const string& s, vector<string>& sv,const char flag) {
    sv.clear();
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, flag)) {
        sv.push_back(temp);
    }
}
int main(){

 vector<string> vec;
 split("/test/33/", vec, '/');
  for(auto a:vec) {
    printf("%s\n", a.c_str());
  }

  return 0;
}