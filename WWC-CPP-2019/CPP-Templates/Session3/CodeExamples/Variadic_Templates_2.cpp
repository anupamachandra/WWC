#include <iostream>
#include <string>

const char* sep = " ";

/*template<typename T1>
void println(std::ostream& out, const T1& t1) {
    out << t1 << "\n";
}

template<typename T1, typename T2>
void println(std::ostream& out, const T1& t1, const T2& t2) {
    out << t1 << sep << t2 <<"\n";
}

template<typename T1, typename T2, typename T3>
void println(std::ostream& out, const T1& t1, const T2& t2, const T3& t3) {
    out << t1 << sep << t2 <<  sep << t3 <<"\n";
}*/

void println(std::ostream& out) {
    out << "\n";
}

template<typename T1, typename ... T2> 
void println(std::ostream& out, T1 t1, T2...t2) {
    out << t1;
    if (sizeof...(t2)) {
        out << ",";
        
    }
    println(out, t2...);
}

template<typename ... T2>
void println(std::ostream& out, T2 ...t2) {
    ((out << sep << t2), ...);
}

int main() {
    int i = 10;
    float f = 20.3f;
    std::string s = "Hello World!";

    println(std::cout, i, f, s);

    return 0;
}