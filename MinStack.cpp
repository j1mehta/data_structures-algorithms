#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    void push(int x) {
        if( s2.empty() or x <= s2.top()){
            s1.push(x);
            s2.push(x);
        }
        else
            s1.push(x);
    }

    void pop() {
        if(s1.empty())
            return;
        if(s2.top()==s1.top()){
            s2.pop();
            s1.pop();
        }
        else
            s1.pop();
    }

    int top() {
        if(s1.empty())
            return NULL;
        else
            return s1.top();
    }

    int getMin() {
        if(s1.empty())
            return NULL;
        else
            return s2.top();
    }
};

int main() {
    MinStack* obj = new MinStack();
    cout << obj->top();
    obj->push(512);
    obj->push(-1024);
    obj->push(-1024);
    obj->push(512);
    obj->pop();
    cout << obj->getMin() << " ";
    obj->pop();
    cout << obj->getMin() << " ";
    obj->pop();
    cout << obj->getMin() << " ";
    return 0;
}