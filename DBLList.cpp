#pragma once
/*
By Yevgeniy Sumaryev
3/20/21
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include "DBLList.h" 
using namespace std;

/*
most of those methods are same
as in the list created in Problem 1
except for a few methods such as
insert that required to adjust 2 links
instead of 1
*/

//constructor
template<class T>
DBLList<T>::DBLList(){
		first = last = nullptr;
		count = 0;
}

//copy constructor
template<class T>
DBLList<T>::DBLList(const DBLList<T>& otherList) {
		first = nullptr;
		copyList(otherList);
}

//destructor
template<class T>
DBLList<T>::~DBLList() {
		destroyList();
}

//assignment operator
template<class T>
const DBLList<T>& DBLList<T>::operator=(const DBLList<T>& otherList) {
		if (this != &otherList) {
			copyList(otherList);
		}
		return *this;
}

template<class T>
void DBLList<T>::print(){
		dnode<T>* current;
		current = first;

		while (current != last) {
			cout << current->info << " ";
			current = current->forwardLink;
		}
}

template<class T>
T DBLList<T>::front() {
		assert(first != nullptr);
		return first->info;
}

template<class T>
T DBLList<T>::back(){
		assert(last != nullptr);
		return last->info;
}

template<class T>
dnode<T>* DBLList<T>::getFirst(){
		assert(first != nullptr);
		return first;
}

template<class T>
dnode<T>* DBLList<T>::getLast(){
		assert(last != nullptr);
		return last;
}

template<class T>
void DBLList<T>::destroyList() {
		dnode<T>* temp;

		while (first != last) {
			temp = first;
			
			//last->forwardLink = first->forwardLink;
			first = first->forwardLink;
			delete temp;
		}
		first = last = nullptr;
		count = 0;
}

template<class T>
void DBLList<T>::initializeList() {
		destroyList();
}

template<class T>
bool DBLList<T>::isEmptyList() const {
		return (first == nullptr);
}



//copies the list, position by position
template<class T>
void DBLList<T>::copyList(const DBLList<T>& otherList) {
		dnode<T>* newNode;
		dnode<T>* current;

		//empty our list if it is not empty already
		if (first != nullptr) {
			destroyList();
		}

		if (otherList.first == nullptr) {
			first = last = nullptr;
			count = 0;
		}
		else {
			current = otherList.first;
			count = otherList.count;

			first = new dnode<T>;
			first->info = current->info;
			first->link = nullptr;

			last = first;

			current = current->link;

			while (current != nullptr) {
				newNode = new dnode<T>;
				newNode->info = current->info;
				newNode->link = nullptr;

				last->link = newNode;
				last = newNode;

				current = current->link;
			}
		}
}

//search element using only forwardLink
template<class T>
bool DBLList<T>::search(const T& searchItem) const {
		dnode<T>* current;
		bool found = false;

		current = first;
		while (current != last) {
			if (current->info == searchItem) {
				return true;
			}
			else {
				current = current->forwardLink;
			}
		}
		return false;
}

	
//Inserting into a doubly linked list 
//requires adjustment of 2 links, backward and forward link
template<class T>
void DBLList<T>::insertFirst(const T& newItem) {
		dnode<T>* newNode;
		//initialize new node
        newNode = new dnode<T>;
		newNode->info = newItem;

		if(first == nullptr){
			first = last = newNode;
		}
		else {
        //set newnode's links to
        //links pointed by first and last
		newNode->forwardLink = first;
		newNode->backwardLink = last;
		first->backwardLink = newNode; 
        //change first and last to new node
		first = newNode;
		//if the list were empty then newNode would also be the last node in the list
		last->forwardLink = first;
		}
		
		count++;

		
}


//deleting a node can have several options
//the list is empty, the first node is to be deleted, a subsequent node is to be deleted, the info is not in the list
template<class T>
void DBLList<T>:: deleteNode(const T& deleteItem) {
		dnode<T>* current;
		dnode<T>* trailCurrent;
		bool found;

		if (first == nullptr) {
			cout << "Can't delete from an empty list." << endl;
		}
		else {
			if (first->info == deleteItem) {   //if found in first spot
				current = first;
                //move first and last link 1 link to the right
				first = first->forwardLink;
                first->backwardLink = last;
                last->forwardLink = first;
				count--;

				if (first == nullptr) last = nullptr; //if the list has only one node
				delete current;
			}
			else {
				found = false;
				trailCurrent = first;

				current = first->forwardLink;

                //keep looking until node is found
                //or the end of list is reached 
				while (current != last && !found) {
					if (current->info != deleteItem) {
						trailCurrent = current;
						current = current->forwardLink;
					}
					else {
						found = true;
					}
				}

				if (found) {
					trailCurrent->forwardLink = current->forwardLink;
                    (current->forwardLink)->backwardLink = trailCurrent;
					count--;
					
					if (last == current) last = trailCurrent; //if deleted node was the last node
					delete current;
				}
				else {
					cout << "Item not found in list." << endl;
				}
			}
		}
}

