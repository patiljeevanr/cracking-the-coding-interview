//
// Created by Alex Hagiopol on 7/30/18.
//
#pragma once
#include "../chapter_02_linked_lists/SinglyLinkedNode.h"

namespace chapter_03{
    template <typename T>
    class Stack{
    protected:
        chapter_02::SinglyLinkedNode<T>* _head;
    public:
        Stack(){_head = nullptr;}
        // compare values in stack top-to-bottom to values in vector front-to-back for easy unit testing
        bool operator==(const std::vector<T>& vector){
            chapter_02::SinglyLinkedNode<T>* temp = _head;
            for (T item : vector){
                if (temp == nullptr || item != temp->getValue()){
                    return false;  // vector length > stack height
                }
                if (item != temp->getValue()){
                    return false;  // value inequality
                }
                temp = temp->getNext();
            }
            if (temp != nullptr) return false; // stack height > vector length
            std::cerr << "Returning true." << std::endl;
            return true;
        }
        bool operator!=(const std::vector<T>& vector){
            return !(*this==vector);
        }
        // check if stack is empty
        bool isEmpty() {return _head == nullptr;}
        // add item to top of stack
        virtual void push(const T& data) {
            chapter_02::SinglyLinkedNode<T>* node = new chapter_02::SinglyLinkedNode<T>(data, _head);
            _head = node;
        }
        // remove item from top of stack
        virtual T pop(){
            if (_head != nullptr){
                chapter_02::SinglyLinkedNode<T>* temp = _head;
                T tempValue =  temp->getValue();
                _head = _head->getNext();
                delete temp;
                return tempValue;
            } else {
                return static_cast<T>(0);  // nothing to return if stack is empty;
            }

        }
        // inspect item at top of stack without removing
        T peek(){
            if (_head != nullptr){
                return _head->getValue();
            } else {
                return static_cast<T>(0);  // nothing to return if stack is empty;
            }
        }
        // destructor
        ~Stack(){
            while (_head != nullptr){
                chapter_02::SinglyLinkedNode<T>* temp = _head;
                _head = _head->getNext();
                delete temp;
            }
        }
    }; // class Stack
};
