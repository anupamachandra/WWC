template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

int main() {
    ::min(10, 20);
    //::min(myclass{10}, myclass{20});
    ::min<int>(10, 20);
    ::min(10.0, 20.0);
    ::min<float>(10.0, 20.0);
    ::min<char>('x', 20.0);
    return 0;
}
