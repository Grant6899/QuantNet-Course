//===============================================================
// Level 2 Section 2.8 Exercise 2.8.5
// Author: Grant Liu
// Create Date: 1/14/2017
// Description: BitMatrix class - h file
//===============================================================
#include<iostream>
#include<bitset>
#include<array>

template<std::size_t N, std::size_t M>
class BitMatrix {
private:
	std::array<std::bitset<M>, N> _data; // BitMatrix data

public:

	BitMatrix<N, M>() = default;
	BitMatrix<N, M>(const BitMatrix<N, M>& source) = default; // copy ctor
	BitMatrix<N, M>& operator = (const BitMatrix <N, M>& source); // copy assignment operator

	BitMatrix<N, M>(BitMatrix<N, M>&& source); // move ctor
	BitMatrix<N, M>& operator = (BitMatrix <N, M>&& source); // move assignment operator
	
	BitMatrix<N, M>(std::string source);

	void set(); // set all bits in BitMatrix
	void set(int pos); // set bits in row pos
	void reset(); // reset all bits in BitMatrix
	void reset(int pos); // reset bits in row pos

	void flip(); // flip all bits in BitMatrix
	void flip(int pos); // flip bits in row pos

	bool all(); // test if all bits are set
	bool all(int pos); // test if all bits are set in row pos
	bool any(); // test if any bit is set
	bool any(int pos); // test if any bit is set in row pos
	bool none(); // test if no bit is set
	bool none(int pos); // test if no bit is set in row pos

	std::bitset<M> operator[] (int pos) const;

	int count(); // count the number of set bits
	int count(int pos); // count the number of set bits in row pos

	void print(); // print the matrix to console
	void setBitset(const std::bitset<M>& source, int pos);

	BitMatrix<N, M>& operator &= (const BitMatrix<N, M>& other);
	BitMatrix<N, M>& operator |= (const BitMatrix<N, M>& other);
	BitMatrix<N, M>& operator ^= (const BitMatrix<N, M>& other);
};

// String Constructor
template<std::size_t N, std::size_t M>
BitMatrix<N, M>::BitMatrix(std::string source) {

	std::bitset<M> rawData(source);
	for (int i = 0; i < N; ++i)
		_data[i] = rawData;
}

// copy assignment operator 
template<std::size_t N, std::size_t M>
BitMatrix<N, M>& BitMatrix<N, M>::operator = (const BitMatrix <N, M>& source) {
	for (int i = 0; i < N; ++i)
		_data[i] = source[i];
	return *this;
}


// move ctor 
template<std::size_t N, std::size_t M>
BitMatrix<N, M>::BitMatrix(BitMatrix<N, M>&& source) {
	for (int i = 0; i < N; ++i)
		_data[i] = std::move(source[i]);
}


// move assignment operator 
template<std::size_t N, std::size_t M>
BitMatrix<N, M>& BitMatrix<N, M>::operator = (BitMatrix <N, M>&& source) {
	for (int i = 0; i < N; ++i)
		_data[i] = std::move(source[i]);
	return *this;
}

// void set()
template<std::size_t N, std::size_t M>
    void BitMatrix<N,M>::set(){
    for (int i=0; i<N; ++i)
        _data[i].set();
}

// void set(int pos)
template<std::size_t N, std::size_t M>
    void BitMatrix<N,M>::set(int pos){
    _data[pos].set();
}

// void reset()
template<std::size_t N, std::size_t M>
    void BitMatrix<N,M>::reset(){
    for (int i=0; i<N; ++i)
        _data[i].reset();
}

// void reset(int pos)
template<std::size_t N, std::size_t M>
    void BitMatrix<N,M>::reset(int pos){
    _data[pos].reset();
}

// void flip()
template<std::size_t N, std::size_t M>
    void BitMatrix<N,M>::flip(){
    for (int i=0; i<N; ++i)
        _data[i].flip();
}

// void flip(int pos)
template<std::size_t N, std::size_t M>
    void BitMatrix<N,M>::flip(int pos){
    _data[pos].flip();
}

// bool all()
template<std::size_t N, std::size_t M>
    bool BitMatrix<N,M>::all(){
    for (int i=0; i<N; ++i)
        if (!_data[i].all()) return false;
    return true;
}

// bool all(int pos)
template<std::size_t N, std::size_t M>
    bool BitMatrix<N,M>::all(int pos){
    return _data[pos].all();
}

// bool any()
template<std::size_t N, std::size_t M>
    bool BitMatrix<N,M>::any(){
    for (int i=0; i<N; ++i)
        if (_data[i].any()) return true;
    return false;
}

// bool any(int pos)
template<std::size_t N, std::size_t M>
    bool BitMatrix<N,M>::any(int pos){
    return _data[pos].any();
}

// bool none()
template<std::size_t N, std::size_t M>
    bool BitMatrix<N,M>::none(){
    for (int i=0; i<N; ++i)
        if (_data[i].any()) return false;
    return true;
}

// bool none(int pos)
template<std::size_t N, std::size_t M>
    bool BitMatrix<N,M>::none(int pos){
    return _data[pos].none();
}

// operator[](int pos) const
template<std::size_t N, std::size_t M>
    std::bitset<M> BitMatrix<N, M>::operator[](int pos) const{

    return _data[pos];
}

// int count()
template<std::size_t N, std::size_t M>
    int BitMatrix<N, M>::count(){
    int sum = 0;
    for (int i=0; i<N; ++i)
         sum += _data[i].count();
    return sum;
}

// int count(int pos)
template<std::size_t N, std::size_t M>
    int BitMatrix<N,M>::count(int pos){
    return _data[pos].count();
}

template<std::size_t N, std::size_t M>
    std::ostream& operator<<(std::ostream& os, const BitMatrix<N, M>& bitm){

    for (int i=0; i<N; ++i)
        os << bitm[i] <<'\n';

    return os;
    }

// void print()
template<std::size_t N, std::size_t M>
    void BitMatrix<N, M>::print(){
    std::cout<<"+";
    for (int i=0; i<N; ++i)
        std::cout<<"-";
    std::cout<<"+\n";

    for (int i=0; i<N; ++i)
        std::cout<<"|"<< _data[i]<<"|"<<std::endl;

    std::cout<<"+";
    for (int i=0; i<N; ++i)
        std::cout<<"-";
    std::cout<<"+\n";
}

// void setBitset
template<std::size_t N, std::size_t M>
    void BitMatrix<N ,M>::setBitset (const std::bitset<M>& source, int pos){
    _data[pos] = source;
}

template<std::size_t N, std::size_t M>
    BitMatrix<N, M>& BitMatrix<N ,M>::operator &= (const BitMatrix<N, M>& other){
    for (int i=0; i<N; ++i)
         _data[i] &= other[i];
    return *this;
}

template<std::size_t N, std::size_t M>
    BitMatrix<N, M>& BitMatrix<N ,M>::operator |= (const BitMatrix<N, M>& other){
    for (int i=0; i<N; ++i)
        _data[i] |= other[i];
    return *this;
}

template<std::size_t N, std::size_t M>
    BitMatrix<N, M>& BitMatrix<N ,M>::operator ^= (const BitMatrix<N, M>& other){
    for (int i=0; i<N; ++i)
        _data[i] ^= other[i];
    return *this;
}

// AND operation
template<std::size_t N, std::size_t M>
    BitMatrix<N,M> operator&(const BitMatrix<N, M>& lhs, const BitMatrix<N, M>& rhs){

    BitMatrix<N,M> result;

    for (int i=0; i<N; ++i)
        result.setBitset(lhs[i] & rhs[i], i);

    return result;
}

// OR operation
template<std::size_t N, std::size_t M>
    BitMatrix<N,M> operator|(const BitMatrix<N, M>& lhs, const BitMatrix<N, M>& rhs){

    BitMatrix<N,M> result;

    for (int i=0; i<N; ++i)
        result.setBitset(lhs[i] | rhs[i], i);

    return result;
}

// XOR operation
template<std::size_t N, std::size_t M>
    BitMatrix<N,M> operator^(const BitMatrix<N, M>& lhs, const BitMatrix<N, M>& rhs){

    BitMatrix<N,M> result;

    for (int i=0; i<N; ++i)
        result.setBitset(lhs[i] ^ rhs[i], i);

    return result;
}
