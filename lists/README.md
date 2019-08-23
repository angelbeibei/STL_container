# lists  
## lists--构造函数和析构函数:  
  (1) lists<Elem>c 产生一个空的lists  
  (2) lists<Elem>c1(c2) 产生另一个同类型的lists副本  
  (3) lists<Elem>c(n) 产生一个大小为n的lists  
  (4) lists<Elem>c(n,elem) 产生一个大小为n的lists,每个元素为elem  
  (5) lists<Elem>c(beg,end) 产生一个lists,以区间[beg,end]作为元素的初值  
   c.~lists<Elem>() 销毁所有元素,释放内存  
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
  c.remove(val) 移除所有其值为val的元素  
  c.remove_if(op) 移除所有"造成op(elem)的结果为true"的元素  
  c.erase(pos) 移除迭代器pos所指的元素,返回下一个元素的位置  
  c.erase(beg,end) 移除区间[beg,end]内的所有元素  
  c.resize(num) 将元素的数量改为num  
  c.resize(num,elem) 将元素的数量改为num,如果size变大了,则多出来的都为elem的副本  
  c.clear() 移除所有元素,清空  
### lists remove与remove_if的用法:  
   lists<int>list;  
  (1)想要将所有等于val值的元素删除:  
     list.remove(val)  
  (2)使用remove_if,可以通过一个函数或者仿函数来定义元素移除的原则,其可以让每一个"令操作结果为true"的元素删除  
     list.remove_if(not1(bind2nd(modulus<int>(),2)))  

## Lists的特殊变动操作函数
  c.unique() 如果存在若干相邻而数值想等的元素,就移除重复的元素,只留下一个  
  c.unique(op) 如果储存在若干相邻的元素,都使op()的结果为true,则以处重复元素,只留下一个  
  c1.splice(pos,c2) 将c2内的所有元素转移到c1之内,迭代器pos之前  
  c1.splice(pos,c2,c2pos) 将c2内的c2pos所指元素转移到c1内的pos所指位置上  
  c1.splice(pos,c2,c2beg,c2end) 将c2内的[c2beg,c2end]区间内的所有元素转移到c1内的pos之前  
  c.sort() 排序  
  c.sort(op) 以op为准则,对所有元素排序  
  c1.merge(c2) 假设c1与c2均为已序的元素,将c2的全部元素转移到c1,并保证合并之后的list仍为有序  
  c1.merge(c2,op) 假设c1与c2都包含op()原则下的已序的元素,将c2的全部元素转移到c1,并保证合并之后的list在op()原则下仍为有序  
  c.reserse() 将所有的元素反序  
  注意:splice,merge之后,原来的c2相应位置的元素将变为空  
## 与vector,deques的不同  
  lists在任何位置执行元素的安插和删除特别快,因为无需移动其他的元素  
  lists的安插和删除操作并不会造成指向其他元素的各个pointer或者reference,iterator失效  
  不支持随机存取,既不提供下标操作符,也不提供at()函数  
