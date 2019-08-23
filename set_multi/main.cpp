#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

namespace set01{
    void func1(){
        set<int> c;
        c.insert(5);
        c.insert(10);
        c.insert(15);
        c.insert(20);
        c.insert(25);
        set<int>::iterator i;
        cout << "c.lower_bound(12): " << endl;
        for(i=c.lower_bound(12); i!=c.end(); i++)
        {
            cout << "c has:" << *i << "in this set" << endl;
        }
        cout << "c.upper_bound(12): " << endl;
        for(i=c.upper_bound(12); i!=c.end(); i++){
            cout << "c has:" << *i << "in this set" << endl;
        }
        cout << "c.upper_bound(16): " << endl;
        for(i=c.upper_bound(16); i!=c.end(); i++){
            cout << "c has:" << *i << "in this set" << endl;
        }
        cout << "c.equal_range(12): " << endl;
        for(i=c.equal_range(12).first; i!=c.end(); i++){
            cout << "c has:" << *i << "in this set" << endl;
        }
        cout << "c.equal_range(15): " << endl;
        for(i=c.equal_range(15).first; i!=c.equal_range(15).second; i++){
            cout << "c has:" << *i << "in this set" << endl;
        }
    }
}

namespace set02{
    void func2() {
        typedef set<int, greater<int>> hhyset;   //从大到小排序
        hhyset c2;
        c2.insert(4);
        c2.insert(3);
        c2.insert(5);
        c2.insert(1);
        c2.insert(6);
        c2.insert(2);
        c2.insert(5);

        hhyset::iterator pos;
        for(pos=c2.begin();pos!=c2.end();++pos)
        {
            cout << *pos << " ";
        }
        cout << endl;

        //insert 4 agian
        pair<hhyset::iterator,bool>status = c2.insert(4);
        if(status.second)
        {
            cout << "4 succeed insert"
                 << distance(c2.begin(),status.first)+1 << endl;
        }
        else
        {
            cout << "4 already in this set" << endl;
        }

        //assign elem to another set
        set<int> c3(c2.begin(),c2.end());

        copy(c3.begin(),c3.end(),ostream_iterator<int>(cout," "));
        cout << endl;

        //删除3之前的所有元素
        c3.erase(c3.begin(),c3.find(3));
        //删除所有等于5的元素
        int num;
        num = c3.erase(5);
        cout << num << "elem removed" <<endl;

        copy(c3.begin(),c3.end(),ostream_iterator<int>(cout," "));
        cout << endl;

    }

}

int main(int argc,char* argv[]){
    set01::func1();
    set02::func2();
}
