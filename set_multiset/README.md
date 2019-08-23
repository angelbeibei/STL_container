#sets与multisets
  sets与multisets会根据特定的排序准则(默认为less),自动将元素排序.通常以平衡二叉树完成.两者的不同在于sets不允许有重复元素而multisets可以.
  但是自动排序的集合有一个限制,不能直接改变元素的值,因为这样会打乱原本正确的顺序.因此要改变元素的值,必须先删除旧元素,再插入新元素
##sets--构造函数和析构函数:
  (1) set c 产生一个空的set/multiset,内不含任何元素
  (2) set c(op) 以op为准则产生一个空的set/multiset
  (3) set c1(c2)  产生某个set/multiset的副本,所有元素均被复制
  (4) set c(beg,end) 以区间[beg,end]内的元素产生一个set/multiset
  (5) set c(beg,end,op) 以op为准则,利用区间[beg,end]作为元素生成一个set/multiset
   c.~sets() 销毁所有元素,释放内存
  其中set可以为以下形式:
   set<elem> 以less为排序准则
   set<elem,op> 以op为排序准则  如std::set<int,std::greater<int>> hhy;
   multiset<elem> 一个multiset,以less为排序准则
   multiset<elem,op> 一个multiset,以op为排序准则
##常用操作:
   c.size()
   c.empty()
   c.max_size()
##sets与multisets的搜寻操作函数
   count(elem) 返回元素值为elem的元素个数
   find(elem) 返回元素值为elem的第一个元素,如果找不到返回end()
   lower_bound(elem) 返回set中元素值>=elem的第一个元素的位置
   upper_bound(elem) 返回set中元素值>elem的第一个元素的位置
   equal_range(elem) 返回元素值==elem的元素空间,相当于将lower_bound与upper_bound的返回值做成一个pair返回
##赋值操作:
   c1=c2
   c.swap(c2) 将c1与c2互换
   swap(c1,c2) 同上
##迭代器相关函数:
  c.begin()
  c.end()
  c.rbegin() 返回一个逆向迭代器,指向逆向迭代的第一个元素
  c.rend() 返回一个逆向迭代器,指向最后一个元素的下一位置
##安插/移除相关操作:
  c.insert(elem) 安插一份elem的副本,返回新元素的位置
  c.insert(pos,elem) 安插一份elem的副本,返回新元素的位置(pos只是一个提示,支出安插操作的搜寻起点,可加快速度)
  c.insert(beg,end) 插入[beg,end]区间内所有元素的副本
  c.erase(elem) 移除与elem相等的所有元素,返回被移除的个数
  c.erase(pos) 移除迭代器pos所指位置上的元素,无返回值
  c.erase(beg,end) 移除区间[beg,end]内的所有元素,无返回值
  c.clear() 移除所有元素,清空

