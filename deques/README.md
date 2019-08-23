# deques  
## deques--构造函数和析构函数:  
  (1) deques<Elem>c 产生一个空的deques  
  (2) deques<Elem>c1(c2) 产生另一个同类型的deques副本  
  (3) deques<Elem>c(n) 产生一个大小为n的deques  
  (4) deques<Elem>c(n,elem) 产生一个大小为n的deques,每个元素为elem  
  (5) deques<Elem>c(beg,end) 产生一个deques,以区间[beg,end]作为元素的初值  
   c.~deques<Elem>() 销毁所有元素,释放内存  
## 常用操作:  
   c.size()  
   c.empty()  
   c.max_size()  
   
## 赋值操作:  
   c1=c2  
   c.assign(n,elem) 复制n个elem,赋值给c  
   c.assign(beg,end) 将区间[beg,end]内的元素赋值给c  
   c.swap(c2) 将c1与c2互换  
   swap(c1,c2) 同上  
## 元素取值:  
  c.at(idx)  返回索引idx所标识的元素  
  c[idx] 返回索引idx所标识的元素,但不做范围检查  
  c.front() 返回第一个元素  
  c.back() 返回最后一个元素  
## 迭代器相关函数:  
  c.begin()  
  c.end()  
  c.rbegin() 返回一个逆向迭代器,指向逆向迭代的第一个元素  
  c.rend() 返回一个逆向迭代器,指向最后一个元素的下一位置  
## 安插/移除相关操作:  
  c.insert(pos,elem) 在pos位置上插入一个elem的副本,返回该元素的位置  
  c.insert(pos,n,elem) 在pos位置上插入n个elem的副本,无返回值  
  c.insert(pos,beg,end) 在pos位置上插入[beg,end]区间内所有元素的副本  
  c.push_back(elem) 在尾部添加一个elem的副本  
  c.pop_back() 移除最后一个元素  
  c.push_front(elem) 在头部插入Elem的一个副本  
  c.pop_front(elem) 移除头部元素  
  c.erase(pos) 删除pos上的元素,返回下一个元素的位置  
  c.erase(beg,end) 移除[beg,end]区间内的所有元素,返回下一个元素的位置  
  c.resize(num) 将元素的数量改为num  
  c.resize(num,elem) 将元素的数量改为num,如果size变大了,则多出来的都为elem的副本  
  c.clear() 移除所有元素,清空  
## 与vector的不同  
  deques不提供容量操作capacity()和reserve();  
