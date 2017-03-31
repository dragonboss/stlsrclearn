/*************************************************************************
	> File Name: myallocator.h
	> Author:lotuswhl 
	> Mail:2857978398@qq.com 
	> Created Time: Wed 29 Mar 2017 04:51:43 AM PDT
 ************************************************************************/

#ifndef _MYALLOCATOR_H
#define _MYALLOCATOR_H
#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace mine{
    template<typename T>
    inline
    T* _allocate(ptrdiff_t size,T*){
        T* tmp = static_cast<T*>(::operator new((size_t)size*sizeof(T)));
        if(tmp == 0){
            std::cerr << "out of memory" << std::endl;
            exit(1);
        }
        return tmp;
    }


    template<typename T>
    inline
    void _deallocate(T*p){
        ::operator delete(p);
    }


    template<typename Type,typename Value>
    inline
    void _construct(Type*p,const Value& value){
        new (p)Type(value);
    }

    template<typename T>
    inline
    void _destroy(T*p){
        p.~T();
    }

    
    template<typename T>
    class allocator{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

        template<typename U>
        struct rebind{
            typedef allocator<U> other;
        };

        pointer allocate(size_type size,const_pointer hint=0){
            _allocate((ptrdiff_t)size,(pointer)0);
        }

        void destory(pointer p){
            _destroy(p);
        }

        void deallocate(pointer p,size_type size){
            _deallocate(p);
        }

        void construct(pointer p,const_reference value){
            _construct(p,value);
        }

        pointer address(reference robj) const{
            return (pointer)&robj;
        }

        const_pointer address(const_reference crobj)const{
            return (const_pointer)&crobj;
        }
        size_type max_size()const{
            return size_type(UINT_MAX/sizeof(T));
        }
    };

}



#endif
