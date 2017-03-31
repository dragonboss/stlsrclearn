/*************************************************************************
	> File Name: __malloc_alloc_template.cpp
	> Author:lotuswhl 
	> Mail:2857978398@qq.com 
	> Created Time: Wed 29 Mar 2017 11:29:29 PM PDT
 ************************************************************************/
#pragma once
#include<malloc.h>
#include <iostream>
#define __THROW_BAD_ALLOC std::cerr << "out of memory" << std::endl;exit(1);


//下面是第一季空间配置器的定义，使用malloc完成空间分配

template<int inst>
class __malloc_alloc_template{
public:
    static void *allocate(size_t size){
        void *ret = malloc(size);
        //if failed ,call oom_malloc to handle this
        if(0 == ret){
            ret = oom_malloc(size);
        }
        return ret;
    } 
    

    static void *reallocate(void *p,size_t old_size,size_t new_size){
        void *ret = realloc(p,new_size);
        if(0 == ret){
            ret = oom_realloc(p,new_size);
        }
        return ret;
    }


    static void deallocate(void *p,size_t){
        free(p);
    }

    static void (*set_malloc_handler(void (*fp)()))(){
        auto old_handler = __malloc_alloc_oom_handler;
        __malloc_alloc_oom_handler = fp;
        return old_handler;
    }



private:
    //handling out of memory

    static void *oom_malloc(size_t size);
    static void *oom_realloc(void *p,size_t old_size,size_t new_size);
    static void (*__malloc_alloc_oom_handler)();
};

//give statics definition

template<int inst>
void *__malloc_alloc_template<inst>:: oom_malloc(size_t size){
    void (*my_malloc_handler)();
    void * ret;
    while(true){
        my_malloc_handler = __malloc_alloc_oom_handler;
        if(0 == my_malloc_handler){
            __THROW_BAD_ALLOC; // 如果客户端没有定义oom处理，那么直接抛出异常
        }
        //调用客户端设置的oom处理器，看看能不能做点什么来提供内存
        (*my_malloc_handler)();
        ret = malloc(size);
        if(ret){
            return ret;
        }
    }
}

template<int inst>
void * __malloc_alloc_template<inst>::oom_realloc(void*p,size_t old_size,size_t new_size){
    void (*my_malloc_handler)();
    void *ret;
    while(true){
        my_malloc_handler = __malloc_alloc_oom_handler;
        if(0 == my_malloc_handler){
            __THROW_BAD_ALLOC;
        }
        (*my_malloc_handler)();
        ret = realloc(p,new_size);
        if(ret){
            return ret;
        }
    }
}

template<int inst>
void (*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;


typedef __malloc_alloc_template<0> malloc_alloc;

