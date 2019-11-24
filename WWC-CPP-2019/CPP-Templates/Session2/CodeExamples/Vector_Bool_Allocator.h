#pragma once
#pragma once
#include "Vector_Allocator.h"

template<typename _Alloc>
class _Vector<bool, _Alloc> {
    size_t *vbuffer = nullptr;
    size_t vsize = 0;
    size_t vcapacity = 0;
    using vType = bool;
public:
    class _Iter {
    public:
        _Iter(const _Vector<bool> *vec, size_t nIndex);
        bool operator!=(const _Iter &other) const;
        const bool operator*() const;
        _Iter &operator++();

    private:
        const _Vector<bool> *vIterVec;
        size_t vIterIndex = -1;
    };

    _Vector() {
        std::cout << "Default Bool Constructor" << std::endl;
    };
    _Vector(size_t numElements, bool val) {
        std::cout << "Bool Value Constructor" << std::endl;
        for (size_t i = 0; i < numElements; i++) {
            push_back(val);
        }
    }

    _Vector(const _Vector& vec) {
        std::cout << "Bool Copy Constructor" << std::endl;
        this->~_Vector();
        this->vbuffer = new size_t[vec.vcapacity / _VBITS]();
        this->vcapacity = vec.vcapacity;
        for (size_t i = 0; i < vec.vsize; i++) {
            size_t elemIdx = i / _VBITS;
            push_back((vec.vbuffer[elemIdx] >> (i%_VBITS)) & 1);
        }
    }

    _Vector* operator=(const _Vector& vec) {
        std::cout << "Bool Copy Assignment" << std::endl;
        if (this == &vec) {
            return this;
        }
        this->~_Vector();
        this->vbuffer = new size_t[vec.vcapacity / _VBITS]();
        this->vcapacity = vec.vcapacity;
        for (size_t i = 0; i < vec.vsize; i++) {
            size_t elemIdx = i / _VBITS;
            push_back((vec.vbuffer[elemIdx] >> (i%_VBITS)) & 1);
        }
        return this;
    }

    _Vector(_Vector&& vec) {
        std::cout << "Bool Move Constructor" << std::endl;
        this->~_Vector();
        std::swap(vsize, vec.vsize);
        std::swap(vcapacity, vec.vcapacity);
        std::swap(vbuffer, vec.vbuffer);
    }

    _Vector* operator=(_Vector&& vec) {
        std::cout << "Bool Move Assignment" << std::endl;
        this->~_Vector();
        std::swap(vsize, vec.vsize);
        std::swap(vcapacity, vec.vcapacity);
        std::swap(vbuffer, vec.vbuffer);
        return this;
    }

    ~_Vector() {
        std::cout << "Default Bool Destructor" << std::endl;
        delete[] vbuffer;
        this->vbuffer = nullptr;
        this->vcapacity = 0;
        this->vsize = 0;
    }

    void push_back(bool val) {
        if (vsize == vcapacity) {
            size_t newVCapacity = ((vcapacity / _VBITS) + 1)*_VBITS;
            size_t* newVBuffer = new size_t[newVCapacity / _VBITS]();
            for (size_t i = 0; i < vcapacity / _VBITS; i++) {
                newVBuffer[i] = vbuffer[i];
            }

            if (vbuffer != nullptr) {
                delete[] vbuffer;
                vbuffer = nullptr;
            }
            vcapacity = newVCapacity;
            vbuffer = newVBuffer;
            newVBuffer = nullptr;
        }
        size_t elemIdx = vsize / _VBITS;
        vbuffer[elemIdx] = vbuffer[elemIdx] | (val << (vsize%_VBITS));
        vsize++;
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
        size_t elemIdx = vsize / _VBITS;
        //vbuffer[elemIdx] = vbuffer[elemIdx] & ~(1 << (vsize%_VBITS));
        if (vsize == 0) {
            if (vbuffer != nullptr) {
                delete[] vbuffer;
                vbuffer = nullptr;
                vcapacity = 0;
            }
        }
    }

    bool back() {
        assert(vsize != 0);
        size_t elemIdx = (vsize - 1) / _VBITS;
        bool val = (vbuffer[elemIdx] >> ((vsize - 1) % _VBITS)) & 1;
        return val;
    }

    bool operator[](size_t index) {
        assert(index >= 0 && index < vsize);
        size_t elemIdx = index / _VBITS;
        return ((vbuffer[elemIdx] >> (index%_VBITS)) & 1);
    }

    bool is_empty() {
        return vsize == 0;
    }

    _Vector::_Iter begin() const {
        return _Iter(this, 0);
    }

    _Vector::_Iter end() const {
        return _Iter(this, vsize);
    }
};

template<typename _Alloc>
_Vector<bool, _Alloc>::_Iter::_Iter(const _Vector<bool> *vec, size_t nIndex) {
    vIterVec = vec;
    vIterIndex = nIndex;
}

template<typename _Alloc>
bool _Vector<bool, _Alloc>::_Iter::operator!=(const _Iter &other) const {
    return vIterIndex != other.vIterIndex;
}

template<typename _Alloc>
const bool _Vector<bool, _Alloc>::_Iter::operator*() const {
    size_t elemIdx = vIterIndex / _VBITS;
    return ((vIterVec->vbuffer[elemIdx] >> (vIterIndex%_VBITS)) & 1);
}

template<typename _Alloc>
typename _Vector<bool, _Alloc>::_Iter &_Vector<bool, _Alloc>::_Iter::operator++() {
    ++vIterIndex;
    return *this;
}