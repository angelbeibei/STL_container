#include <memory>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
//初始化:
using namespace std;
namespace vector1 {
      void func1 ()
      {
        int array[] = {1, 2, 3, 4, 5};
        std::vector<int> c1(array, array + 3);
        std::vector<int>c2;
        c2.assign(3,1);
        std::cout << c1.at(2) << std::endl;
        copy(c2.begin(),c2.end(),ostream_iterator<int>(cout," "));
        cout << endl;

    };
}

namespace vector2{
    void func2(){
        vector<string>sentence;
        sentence.reserve(3);
        sentence.push_back("hello");
        sentence.push_back("hhy");
        sentence.push_back("!");
        copy(sentence.begin(),sentence.end(),ostream_iterator<string>(cout," "));
        cout << endl;
        cout << "max_size" << sentence.max_size() << endl;
        cout << "capacity" << sentence.capacity() << endl;
        //交换元素
        swap(sentence[0],sentence[1]);
        //insert 元素在! 之前
        sentence.insert(find(sentence.begin(),sentence.end(),"!"),"hahah");

        sentence.back()="!!";

        for(auto i=sentence.begin(); i!=sentence.end();i++){
            cout << *i << " ";
        }
        cout << endl;
        copy(sentence.begin(),sentence.end(),ostream_iterator<string>(cout," "));
        cout << endl;

        cout << "max_size" << sentence.max_size() << endl;
        cout << "capacity" << sentence.capacity() << endl;



    }
}
int main(int argc,char**argv)
{
    vector1::func1();
    vector2::func2();
}