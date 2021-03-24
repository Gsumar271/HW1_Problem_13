#pragma once
/*
By Yevgeniy Sumaryev
3/20/21
*/

//a template node class
//with 2 links, forward and backward
//link
template<class T>
class dnode {
public:
	T info;
	dnode<T>* forwardLink;
    dnode<T>* backwardLink;
};


//this is a circular doubly linked list
template<class T>
class DBLList
{
    private:
        int count;
        dnode<T>* first;
	    dnode<T>* last;

    public:
        DBLList();
        //copy constructors
	    DBLList(const DBLList<T>& otherList);
        ~DBLList();

        bool search(const T& searchItem) const;
	    
        //modifier functions
        void insertFirst(const T& newItem);
	    void deleteNode(const T& deleteItem);

        //assignment operator
	    const DBLList<T>& operator=(const DBLList<T>& otherList);


        int getCount();
        int length() { return count; }
        void print();
        T front();
        T back();
        dnode<T>* getFirst();
        dnode<T>* getLast();
        void destroyList();
        void initializeList();
        bool isEmptyList() const;

        //copies the list, position by position
	    void copyList(const DBLList<T>& otherList);

        //an Iterator inside the List class
        //for easier access to variables
        class DBLL_iterator 
        { 
	    private: 
		    // Pointer to current node
		    dnode<T>* current;
	    public: 
		    DBLL_iterator() { current = nullptr; } 
		    DBLL_iterator(dnode<T>* ptr) { current = ptr; }
	    	bool operator==(const DBLL_iterator& right) const { return (current == right.current); } 
		    bool operator!=(const DBLL_iterator& right) const{ return (current != right.current); } 
		    T operator*() const { return current->info; } 
            T& operator*() { return current->info; } 
		    DBLL_iterator& operator++() { current = current->forwardLink; return *this; } 
            DBLL_iterator& operator--() { current = current->backwardLink; return *this; } 
	    }; 

        //returns an iterator to the first node in the list
	    DBLL_iterator begin() { DBLL_iterator temp(first); return temp; }
	    
        //returns an iterator to the last node in the list
	    DBLL_iterator end() { DBLL_iterator temp(last); return temp; }


};