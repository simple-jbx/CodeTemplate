#include<bits/stdc++.h>

using namespace std;


/*
题目一：LRU缓存机制
方法一：哈希+双向链表
链接：https://leetcode-cn.com/problems/lru-cache/solution/lruhuan-cun-ji-zhi-by-leetcode-solution/
来源：力扣（LeetCode）
时间复杂度：O(1)
空间复杂度：O(N) N == capacity
*/

struct DLinkedNode
{
	int key, value;
	DLinkedNode *prev, *next;
	DLinkedNode() :key(0), value(0), prev(nullptr), next(nullptr) {}
	DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
	unordered_map<int, DLinkedNode*> cache;
	int capacity, cacheSize;
	DLinkedNode *head, *tail;
public:
	LRUCache(int _capacity) : capacity(_capacity), cacheSize(0) {
		//使用伪头结点和尾结点，方便操作
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (!cache.count(key))
		{
			return -1;
		}

		//如果key存在，通过哈希表定位，再移到头部
		DLinkedNode* data = cache[key];
		moveToHead(data);
		return data->value;
	}

	void put(int key, int value) {
		if (!cache.count(key))
		{
			cacheSize++;
			//如果key不存在，创建新节点
			DLinkedNode *newData = new DLinkedNode(key, value);
			cache[key] = newData;
			//添加至双向链表的头部
			addToHead(newData);
			if (cacheSize > capacity)
			{
				//超出容量，删除双向链表的尾部结点，同时删除哈希表里的映射
				cacheSize--;
				DLinkedNode* eraseData = removeTail();
				cache.erase(eraseData->key);
			}
		}
		else
		{
			//key存在，先通过哈希表定位，再修改value最终移至链表头部
			DLinkedNode* data = cache[key];
			data->value = value;
			moveToHead(data);
		}
	}

	void addToHead(DLinkedNode* data)
	{
		data->prev = head;
		data->next = head->next;
		head->next->prev = data;
		head->next = data;
	}

	void removeNode(DLinkedNode* data)
	{
		data->prev->next = data->next;
		data->next->prev = data->prev;
	}

	void moveToHead(DLinkedNode* data)
	{
		removeNode(data);
		addToHead(data);
	}

	DLinkedNode* removeTail()
	{
		DLinkedNode* data = tail->prev;
		removeNode(data);
		return data;
	}
};
