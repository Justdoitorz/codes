#include <iostream>
#include <unordered_map>
#include <list>
#include <stdlib.h>

using namespace std;

struct kv_node {
	struct kv_node *next;
	struct kv_node *prev;
    struct {
        int key;
        int value;
    };
};
/*
typedef struct {
    struct kv_node head;
	//map<int, struct kv_node*> fast;
    int capacity;
    int count;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = (LRUCache *)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->count = 0;
    obj->head.prev = &obj->head;
	obj->head.next = &obj->head;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    int value = -1;
    struct kv_node *head = &obj->head, *pos;
	for(pos = head->next; pos != head; pos = pos->next) {
		if (pos->key == key) {
			value = pos->value;

			pos->prev->next = pos->next;
			pos->next->prev = pos->prev;

			pos->prev = head;
			head->next->prev = pos;
			pos->next = head->next;
			head->next = pos;
			break;
		}
	}
	
    return value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (lRUCacheGet(obj, key) != -1) {
		obj->head.next->value = value;
		return;
	}

	struct kv_node *node, *head = &obj->head;
	if (obj->count < obj->capacity) {
		node = (struct kv_node *)malloc(sizeof(struct kv_node));
		obj->count++;
	} else {
		node = head->prev;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	node->next = head->next;
	head->next->prev = node;
	head->next = node;
	node->prev = head;

	node->key = key;
	node->value = value;
}

void lRUCacheFree(LRUCache* obj) {
	struct kv_node *head = &obj->head, *pos, *f;
	pos = head->next;
	while (pos != head) {
		f = pos;
		pos = pos->next;
		free(f);
	}
	free(obj);
}
*/

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity)
	{
    }
    
    int get(int key) 
	{
		int value = -1;
		auto piter = fast.find(key);
		if (piter != fast.end()) {
			value = piter->second->second;
			l.splice(l.begin(), l, piter->second);
		}
		return value;
    }
    
    void put(int key, int value) 
	{
		auto piter = fast.find(key);
		if (piter != fast.end()) {
			l.splice(l.begin(), l, piter->second);
			piter->second->second = value;
			return;
		}

		l.emplace_front(key, value);
		fast[key] = l.begin();

		if (fast.size() > cap) {
			fast.erase(l.back().first);
			l.pop_back();
		}
    }

private:
	list<pair<int, int> > l;
	unordered_map<int, decltype(l)::iterator> fast;
    int cap;
};

class None {

};


class TempFn {
public:
	TempFn(int p, int)
	{
		cout << p << endl;
	}
	TempFn(const TempFn & t)
	{
		cout << "???" << endl;
	}

	//TempFn(TempFn && t) = delete;

	int operator()()
	{
		return 3;
	}
};

struct fo {
	int operator()()
	{
		return 2;
	}
};

template <typename Fn>
void fn(Fn f)
{
	cout << f() << endl;
}

int foo()
{
	return 1;
}


int main()
{
	cout << 1 << endl;
    cout << 2 << endl;


	TempFn t(1, 2);
	TempFn d(t);
	
	TempFn c(d);

	fn(fo());
	fn(foo);
	return 0;
}
