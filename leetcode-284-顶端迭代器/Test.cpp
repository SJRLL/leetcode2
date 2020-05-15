给定一个迭代器类的接口，接口包含两个方法： next() 和 hasNext()。设计并实现一个支持 peek() 操作的顶端迭代器 -- 其本质就是把原本应由 next() 方法返回的元素 peek() 出来。

示例 :

假设迭代器被初始化为列表 [1, 2, 3]。

调用 next() 返回 1，得到列表中的第一个元素。
现在调用 peek() 返回 2，下一个元素。在此之后调用 next() 仍然返回 2。
最后一次调用 next() 返回 3，末尾元素。在此之后调用 hasNext() 应该返回 false。

//解题思路：复制一个当前状态的迭代器，并调用next，使得目前的迭代器位置不变

// Returns the next element in the iteration without advancing the iterator.
int peek() {
	if (hasNext()){
		Iterator it(*this);
		return it.next();
	}
	return 0;
}

