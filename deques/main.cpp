#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
int main(int argc,char*agrv[])
{
    deque<string>s;
    s.assign(3,string("hhy"));
    s.push_back("lucky");
    s.push_front("fight");

    copy(s.begin(),s.end(),ostream_iterator<string>(cout," "));
    cout << endl;

    s.pop_front();
    s.pop_back();
    //在每个string前插入"another"
    for(int i=0; i< s.size(); i++){
        s[i] = "another" + s[i];
    }

    copy(s.begin(),s.end(),ostream_iterator<string>(cout," "));
    cout << endl;
    //另外一种for的用法
    for(auto &elem : s){
        elem = elem + "fight";
    }
    copy(s.begin(),s.end(),ostream_iterator<string>(cout," "));
    cout << endl;
    //resize to 4
    s.resize(4,"resize");

    copy(s.begin(),s.end(),ostream_iterator<string>(cout," "));
    cout << endl;
}