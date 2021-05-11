

template <class T>
class Container
{
public:
    Container();
    ~Container();
    void addBegin(T obj); //добавить новый элемент в начало
    void addEnd(T obj); //добавить новый элемент в конец
    void deleteFirst(); // удалить первый элемент;
    void deleteLast(); //  удалить последний элемент;
    int length();    // узнать кол-во элементов
    T& operator[](int index); // перебрать все элементы (получить в цикле все элементы по ссылке);
    void clear(); //очистить контейнер.
    T&  getFirst(); //получить значение первого  элемента;
    T& getLast();  // получить значение последнего элемента;
    bool IsEmpty(); // проверить на пустоту
    void Reverse(); //переставить все элементы в обратном порядке
    void getCopy(Container &other); //поменять содержимое с другим экземпляром контейнера

private:
    int array_size = 0;
    T* ptr;
};


template <typename T>
Container<T>::Container()
{
    ptr = new T[array_size];
}

template <typename T>
void Container<T>::addBegin(T obj)
{
    array_size += 1;
    T* new_ptr = new T[array_size];
    for (int i = 0; i < array_size - 1; i++) {
        new_ptr[i + 1] = ptr[i];
    }
    new_ptr[0] = obj;
    delete ptr;
    ptr = new_ptr;
}

template <typename T>
void Container<T>::addEnd(T obj)
{
    array_size += 1;
    T* new_ptr = new T[array_size];
    for (int i = 0; i < array_size - 1; i++) {
        new_ptr[i] = ptr[i];
    }
    new_ptr[array_size - 1] = obj;
    delete ptr;
    ptr = new_ptr;
}

template <typename T>
void Container<T>::deleteFirst()
{
    if (IsEmpty())
    {
        array_size -= 1;
        T* new_ptr = new T[array_size];
        for (int i = 0; i < array_size; i++) {
            new_ptr[i] = ptr[i + 1];
            //std::cout << ptr[i+1] << "\n";
        }
        delete ptr;
        ptr = new_ptr;
    }
}

template <typename T>
void Container<T>::deleteLast()
{
    if (IsEmpty())
    {
        array_size -= 1;
        T* new_ptr = new T[array_size];
        for (int i = 0; i < array_size; i++) {
            new_ptr[i] = ptr[i];
            //std::cout << ptr[i+1] << "\n";
        }
        delete ptr;
        ptr = new_ptr;
    }
}



template <typename T>
T& Container<T>::operator[](int index)
{
    return ptr[index];
}

template <typename T>
int Container<T>::length() {
    return array_size;
}

template <typename T>
void Container<T>::clear() {
    array_size = 0;
    delete ptr;
    ptr = new T[array_size];
}

template <typename T>
T& Container<T>::getFirst() {
    if (IsEmpty())
    {
        return ptr[0];
    }
}

template <typename T>
T& Container<T>::getLast() {
    if (IsEmpty())
    {
        return ptr[array_size - 1];
    }
}

template <typename T>
bool Container<T>::IsEmpty() {
    return array_size != 0;
}

template <typename T>
void Container<T>::Reverse() {
    // 1 option
    /*T t;
    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size - 1 -i; j++)
        {
            t = ptr[j];
            ptr[j] = ptr[j + 1];
            ptr[j + 1] = t;
        }
    }*/

    //2 option
    T* new_ptr = new T[array_size];
    for (int i = 0; i < array_size; i++) {
        new_ptr[i] = ptr[array_size - 1 - i];
        //std::cout << ptr[i+1] << "\n";
    }
    delete ptr;
    ptr = new_ptr;

}

template <typename T>
void Container<T>::getCopy(Container& other)
{
    array_size = other.length();
    ptr = new T[array_size];
    for (int i = 0; i < array_size; i++)
    {
        ptr[i] = other[i];
    }
}


template <typename T>
Container<T>::~Container()
{
    delete ptr;
}
#pragma once
