#include <stack>

class MyQueue {
public:
    std::stack<int> stck1;
    std::stack<int> stck2;

    MyQueue() {
    }
    
    void push(int x) {
        stck1.push(x);
    }
    
    int pop() {
        if (stck2.empty()) {
            while (!stck1.empty()) {
                stck2.push(stck1.top());
                stck1.pop();
            }
        }
        int tp = stck2.top();
        stck2.pop();
        return tp;
    }
    
    int peek() {
        if (stck2.empty()) {
            while (!stck1.empty()) {
                stck2.push(stck1.top());
                stck1.pop();
            }
        }
        return stck2.top();
    }
    
    bool empty() {
        return stck1.empty() && stck2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
