#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

void printlist(const list<int>& l1,const list<int>& l2)
{
    cout << "list1: ";
    copy(l1.begin(),l1.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    cout << "list2: ";
    copy(l2.begin(),l2.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}

int main(int argc,char* argv[])
{
    list<int>list1,list2;

    for(int i = 0; i<6; i++)
    {
        list1.push_back(i);
        list2.push_front(i);
    }
    printlist(list1,list2);

    //将list1中的所有元素都插入到list2中元素值为3的位置的前面
    list2.splice(find(list2.begin(),list2.end(),3),list1);
    printlist(list1,list2);   //此时list1为空

    //将list2中的头部元素移植到尾部
    list2.splice(list2.end(),list2,list2.begin());
    printlist(list1,list2);

    //sort排序
    list2.sort();
    list1 = list2;
    list2.unique();
    printlist(list1,list2);

    //list2反序
    list2.reverse();

    printlist(list1,list2);

    //merge用法
    list2.sort();
    list1.merge(list2);
    printlist(list1,list2);

}