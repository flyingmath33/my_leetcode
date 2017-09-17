/*
    Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.
    Notes:
    You must use only standard operations of a queue -- which means only push to back, 
    peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively. 
    You may simulate a queue by using a list or deque (double-ended queue), 
    as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(m_queue.size() < 2) {
            if(m_queue.size() == 1) {
                m_queue_backup.push(m_queue.front());
                m_queue.pop();
            }

            while(!m_queue_backup.empty()) {
                m_queue.push(m_queue_backup.front());
                m_queue_backup.pop();
            }
        }
        
        m_queue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(m_queue.empty()) {
            while(!m_queue_backup.empty()) {
                m_queue.push(m_queue_backup.front());
                m_queue_backup.pop();
            }
        } 
        
        if(m_queue.size() > 1) {
            while(m_queue.size() > 1) {
                m_queue_backup.push(m_queue.front());
                m_queue.pop();
            }
        }
        
        m_queue.pop();
    }

    // Get the top element.
    int top() {
        if(m_queue.empty()) {
            while(!m_queue_backup.empty()) {
                m_queue.push(m_queue_backup.front());
                m_queue_backup.pop();
            }
        } 
        
        if(m_queue.size() > 1) {
            while(m_queue.size() > 1) {
                m_queue_backup.push(m_queue.front());
                m_queue.pop();
            }
        }
        
        return m_queue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return (m_queue.empty() && m_queue_backup.empty());
    }
    
private:
    queue<int> m_queue;
    queue<int> m_queue_backup;
};
