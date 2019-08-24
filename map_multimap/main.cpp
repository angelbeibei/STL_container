#include <iostream>
#include <string>
#include <map>
#include <algorithm>
//根据键值来排序
using namespace std;

//以键值下标初始化map
namespace map01{
    void func1(){
        typedef map<string,float>stringfloatmap;
        stringfloatmap hhy;
        //插入元素
        hhy["BASF"] = 369.50;
        hhy["VW"] = 413.50;
        hhy["Daimler"] = 819.00;
        hhy["kkk"] = 834.00;
        hhy["lll"] = 842.20;
        //打印出来
        stringfloatmap::iterator pos;
        for(pos = hhy.begin();pos!=hhy.end();++pos){
            cout << "hhy" << pos->first << "\t"
                << "prices: " << pos->second << endl;
        }
        cout << endl;
        //所有的值乘以2
        for(auto pose = hhy.begin(); pose!=hhy.end();++pose){
            pose->second *=2;
        }
        for(pos = hhy.begin();pos!=hhy.end();++pos){
            cout << "hhy" << pos->first << "\t"
                 << "prices: " << pos->second << endl;
        }
        cout << endl;
        //把"VW"改为"VWM"
        hhy["VWM"] = hhy["VW"];
        hhy.erase("VW");

        for(pos = hhy.begin();pos!=hhy.end();++pos){
            cout << "hhy" << pos->first << "\t"
                 << "prices: " << pos->second << endl;
        }

    }
}

//搜寻特定value的元素,使用findif

namespace map02{
    template <class K,class V>
    class value_equal{
    private:
        V value;
    public:
        value_equal(const V& v):value(v){
        }
        bool operator()(pair<const K,V>elem){
            return elem.second ==value;
        }

    };
    void func2(){
        typedef std::map<float,float> floatfloatmap;
        floatfloatmap coll;
        floatfloatmap::iterator pos;
        coll[1]=7;
        coll[2]=4;
        coll[3]=2;
        coll[4]=3;
        coll[5]=6;
        coll[6]=1;
        coll[7]=3;
        //找寻key值等于3的元素
        pos = coll.find(3.0);
        if(pos!=coll.end()){
            cout << pos->first << ": "
            << pos->second << endl;
        }
        //找寻value值为3.0的元素
        pos = find_if(coll.begin(),coll.end(),value_equal<float,float>(3.0));

        if(pos!=coll.end()){
            cout << pos->first << ": "
                 << pos->second << endl;

        }
    }

}

int main(int argc, char* argv[]){
    map01::func1();
    map02::func2();
}