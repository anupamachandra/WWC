#pragma once
#pragma once
#include<iostream>
#include <assert.h>

using _Vbase = size_t;	// word type for vector<bool> representation
constexpr int _VBITS = 8 * sizeof(_Vbase);

template<typename T, typename Alloc = std::allocator<T>>
class _Vector {
    T *vbuffer = nullptr;
    size_t vsize = 0;
    size_t vcapacity = 0;
    using vType = T;
public:
    class _Iter {
    public:
        _Iter(const _Vector<T> *vec, size_t nIndex);
        bool operator!=(const _Iter &other) const;
        const auto operator*() const;
        _Iter &operator++();

    private:
        const _Vector<T> *vIterVec;
        size_t vIterIndex = -1;
    };
    _Vector() {
        std::cout << "Default Constructor" << std::endl;
    };

    _Vector(size_t numElements, T val) {
        std::cout << "Initialize Constructor" << std::endl;
        for (size_t i = 0; i < numElements; i++) {
            push_back(val);
        }
    };

    _Vector(const _Vector& vec) {
        std::cout << "Copy Constructor" << std::endl;
        this->~_Vector();
        this->vbuffer = new T[vec.vcapacity];
        this->vcapacity = vec.vcapacity;
        for (size_t i = 0; i < vec.vsize; i++) {
            push_back(vec.vbuffer[i]);
        }
    }

    _Vector* operator=(const _Vector& vec) {
        std::cout << "Copy assignment" << std::endl;
        if (this == &vec) {
            return this;
        }
        this->~_Vector();
        this->vbuffer = new T[vec.vcapacity];
        this->vcapacity = vec.vcapacity;
        for (size_t i = 0; i < vec.vsize; i++) {
            push_back(vec.vbuffer[i]);
        }
        return this;
    }

    _Vector(_Vector&& vec) {
        std::cout << "Move constructor" << std::endl;
        this->~_Vector();
        std::swap(vsize, vec.vsize);
        std::swap(vcapacity, vec.vcapacity);
        std::swap(vbuffer, vec.vbuffer);
    }

    _Vector* operator=(_Vector&& vec) {
        std::cout << "Move assignment" << std::endl;
        this->~_Vector();
        std::swap(vsize, vec.vsize);
        std::swap(vcapacity, vec.vcapacity);
        std::swap(vbuffer, vec.vbuffer);
        return this;
    }

    ~_Vector() {
        std::cout << "Destructor" << std::endl;
        delete[] vbuffer;
        this->vbuffer = nullptr;
        this->vcapacity = 0;
        this->vsize = 0;
    }

    void push_back(T val) {
        if (vsize == vcapacity) {
            vcapacity = vcapacity * 2 + 1;
            T* newVBuffer = new T[vcapacity];
            for (size_t i = 0; i < vsize; i++) {
                newVBuffer[i] = vbuffer[i];
            }
            if (vbuffer != nullptr) {
                delete[] vbuffer;
                vbuffer = nullptr;
            }
            vbuffer = newVBuffer;
            newVBuffer = nullptr;
        }
        vbuffer[vsize++] = val;
    }

    size_t size() const {
        return vsize;
    }

    void pop_back() {
        if (vsize == 0) {
            assert("Popping empty buffer");
            return;
        }
        vsize--;
        if (vsize == 0) {
            if (vbuffer != nullptr) {
                delete[] vbuffer;
                vbuffer = nullptr;
                vcapacity = 0;
            }
        }
    }

    T back() {
        assert(vsize != 0);
        T val = vbuffer[vsize - 1];
        return val;
    }

    T operator[](size_t index) {
        assert(index >= 0 && index < vsize);
        return vbuffer[index];
    }

    bool is_empty() {
        return vsize == 0;
    }

    _Iter begin() const {
        return _Iter(this, 0);
    }

    _Iter end() const {
        return _Iter(this, vsize);
    }
};

template<typename T, typename Alloc>
_Vector<T, Alloc>::_Iter::_Iter(const _Vector<T> *vec, size_t nIndex) {
    vIterVec = vec;
    vIterIndex = nIndex;
}

template<typename T, typename Alloc>
bool _Vector<T, Alloc>::_Iter::operator!=(const _Iter &other) const {
    return vIterIndex != other.vIterIndex;
}

template<typename T, typename Alloc>
const auto _Vector<T, Alloc>::_Iter::operator*() const {
    return vIterVec->vbuffer[vIterIndex];
}

template<typename T, typename Alloc>
typename _Vector<T, Alloc>::_Iter & _Vector<T, Alloc>::_Iter::operator++() {
    ++vIterIndex;
    return *this;
}

