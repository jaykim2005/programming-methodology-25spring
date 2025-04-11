#include "todo.h"
#include <stdexcept>
#include <iostream>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for(int i = 0;i<MAX_TASKS;i++){
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for(int i = 0;i<MAX_TASKS;i++){
        delete tasks[i];
    }

    for(int i = 0;i<MAX_TASKS;i++){
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    return count;
    return 0;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    dest = new char[MAX_TASKS];
    int count = 0;
    while(src[count] != '\0'){
        dest[count] = src[count];
    }
    dest[count] = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    int count1 = 0;
    int count2 = 0;
    while(count1 < MAX_TASKS && tasks[count1] != nullptr && *tasks[count1] != '\0'){
        count1++;
        //std::cout << "count1 = " << count1 << std::endl;
    }
    while(task[count2] != '\0'){
        count2++;
    }

    if(count1>=MAX_TASKS) throw std::out_of_range("it's full");


    tasks[count1] = new char[count2+1];
    for(int j=0;j<count2;j++){
        tasks[count1][j] = task[j];
    }
    tasks[count1][count2] = '\0';

}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    int count = 0;
    while(tasks[count] != nullptr && *tasks[count] != '\0'){
        count++;
    }
    count ++; //for the last '\0'.

    if(index < 0 || index>=count){
        throw std::out_of_range("Out of Range Error");
    }

    delete tasks[index];
    for(int i = index;i<count-1;i++){
        tasks[i] = tasks[i+1];
    }

    tasks[count-1] = nullptr;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = 0;
    while(tasks[count] != nullptr && *tasks[count]!= '\0'){
        count++;
    }

    const char** task_collection = new const char*[count];
    for(int i =0;i<count;i++){
        task_collection[i] = tasks[i];
    }
    
    return task_collection;
    return nullptr;
}