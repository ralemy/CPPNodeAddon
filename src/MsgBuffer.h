//
// Created by Reza Alemy on 6/23/17.
//

#ifndef OBJECTWRAP_NAN_MSGBUFFER_H
#define OBJECTWRAP_NAN_MSGBUFFER_H


#include <condition_variable>
#include <deque>

template <typename MsgType>
class MsgBuffer {
public:
    void Write(MsgType msg){
        std::unique_lock<std::mutex> lock(mu);
        queue.push_back(msg);
        lock.unlock();
        c_var.notify_all();
    };
    MsgType Read(){
        std::unique_lock<std::mutex> lock(mu);
        c_var.wait(lock,[this](){return queue.size()>0;});
        MsgType m = queue.front();
        queue.pop_front();
        lock.unlock();
        c_var.notify_all();
        return m;
    };
    void ReadAll(std::deque<MsgType>& m){
        std::unique_lock<std::mutex> lock(mu);
        std::copy(queue.begin(),queue.end(),std::back_inserter(m));
        queue.clear();
        lock.unlock();
        c_var.notify_all();
    };
    MsgBuffer(){}
    ~MsgBuffer(){}
private:
    std::mutex mu;
    std::condition_variable c_var;
    std::deque<MsgType> queue;
};



#endif //OBJECTWRAP_NAN_MSGBUFFER_H
