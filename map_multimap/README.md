# maps与multimaps
  maps与multimaps会根据key/value pair 当做元素,进行管理  
  它可以根据key的排序准则自动将元素排序,map与mutimap的差别在于multimap允许重复元素  
  限制:不能直接改变元素的key,因为这会破坏正确的次序,底层以平衡二叉树实现,要修改key值必须先删除该key对应的元素,然后再插入  
## maps--构造函数和析构函数:
  (1) map c 产生一个空的map/multimap,内不含任何元素  
  (2) map c(op) 以op为准则产生一个空的map/multimap  
  (3) map c1(c2)  产生某个map/multimap的副本,所有元素均被复制  
  (4) map c(beg,end) 以区间[beg,end]内的元素产生一个map/multimap  
  (5) map c(beg,end,op) 以op为准则,利用区间[beg,end]作为元素生成一个map/multimap  
   c.~maps() 销毁所有元素,释放内存  
  其中map可以为以下形式:  
   map<key,elem> 一个map,以less为排序准则  
   map<key,elem,op> 以op为排序准则,如std::map<float,std::string,std::greater<float>>coll  
   multimap<key,elem> 一个multimap,以less为排序准则  
   multimap<key,elem,op> 一个multimap,以op为排序准则  
## 常用操作:
   c.size()  
   c.empty()  
   c.max_size()  
## maps与multimaps的搜寻操作函数
   count(key) 返回键值等于key的元素个数  
   find(key) 返回键值等于key的第一个元素,如果找不到返回end()  
   lower_bound(key) 返回键值等于key的元素的第一个可安插的位置,也就是键值>=key的第一个元素的位置  
   upper_bound(key) 返回键值为key的元素的最后一个可安插的位置,也就是键值>key的第一个元素的位置  
   equal_range(key) 返回键值为key的元素第一个可安插和最后一个可安插位置,也就是键值==key的元素空间  
   如果想按拥有特定的value值的元素进行操作,可使用一个简单的循环:  
   ```C
   std::multimap<std::string,float>coll;
   for(auto pos = coll.begin();pos!=coll.end();++pos)
   {
   	if(pos->second == value)
        {
            do_something();
         }
   }
   ```  
## 赋值操作:
   c1=c2  
   c.swap(c2) 将c1与c2互换  
   swap(c1,c2) 同上  
## 迭代器相关函数:
  c.begin()  
  c.end()  
  c.rbegin() 返回一个逆向迭代器,指向逆向迭代的第一个元素  
  c.rend() 返回一个逆向迭代器,指向最后一个元素的下一位置  
  不能运用sort等随机存取迭代器的函数
## 安插/移除相关操作:
  c.insert(elem) 安插一份elem的副本,返回新元素的位置  
  c.insert(pos,elem) 安插一份elem的副本,返回新元素的位置(pos只是一个提示,支出安插操作的搜寻起点,可加快速度)  
  c.insert(beg,end) 插入[beg,end]区间内所有元素的副本  
  c.erase(elem) 移除value与elem相等的所有元素,返回被移除的个数  
  c.erase(pos) 移除迭代器pos所指位置上的元素,无返回值  
  c.erase(beg,end) 移除区间[beg,end]内的所有元素,无返回值  
  c.clear() 移除所有元素,清空  
## 三种不同的方法将value传入map
  (1)运用value_type,明确传递的正确型别  
     std::map<std::string,float> coll;  
     coll.insert(std::map<std::string,float>::value_type("hhy",22.3));  
  (2)运用pair<>  
     std::map<std::string,float> coll;  
     coll.insert(std::pair<std::string,float>("hhy",22.3));  
  (3)运用make_pair  
     std::map<std::string,float> coll;  
     coll.insert(std::make_pair("hhy",22.3));  
## 移除迭代器所指元素
   ```C
   typedef std::map<std::string,float> stringfloatmap;
   stringfloatmap coll;
   stringfloatmap::iterator pos;
   //移除具有某个确定value值的元素
   for(pos = coll.begin();pos!=coll.end(); )
   {
   	if(pos->second == value){
          coll.erase(pos++);  //不能为pos,这样会使之后的pos不再是一个有效的迭代器
          }
         else{ ++pos;}  
    }
  ```
## maps提供索引下标
   m[key] 返回一个reference,指向键值为key的元素,如果该元素尚未存在,就安插该元素  
   
