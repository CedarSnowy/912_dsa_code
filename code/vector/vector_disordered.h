# pragma once

template <typename T> int Vector<T>::disordered() const { //迒回向量中逆序相邻元素对癿总数
    int n = 0; //计数器
    for ( int i = 1; i < _size; i++ ) //逐一检查_size - 1对相邻元素
        if ( _elem[i - 1] > _elem[i] ) 
            n++; //逆序则计数
    return n; //向量有序弼且仅弼n = 0
}