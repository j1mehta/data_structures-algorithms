#include <iostream>
#include <tuple>
#include <string>
#include <array>
#include "MurmurHash3.h"
using byte = unsigned char;

template< typename T > std::array< byte, sizeof(T) >  get_bytes( const T& multiKeys )
{
    std::array< byte, sizeof(T) > byteArr ;
    const byte* start = reinterpret_cast< const byte* >( std::addressof(multiKeys) ) ;
    const byte* end = start + sizeof(T);
    std::copy(start, end, std::begin(byteArr));
    return byteArr;
}

template<typename... T>
class ComputeMurmur3 {
public:
    void apply(T... keyTypes){
        keys = std::tuple<T... >(keyTypes...);
        const auto bytes = get_bytes(keys);
        const byte* byte_init = bytes.data();
        MurmurHash3_x64_128(byte_init, sizeof bytes, seed, hashValue.data());
        for( uint64_t b : hashValue ) std::cout << b << ' ' ;
    }

private:
    std::tuple<T... > keys;
    uint32_t seed = 22;
    std::array<uint64_t, 2> hashValue;
};

int main() {
    ComputeMurmur3<int, std::string , double> cm3;
    ComputeMurmur3<int, int, int> cm3_1;
    cm3.apply(1,"hello",3.0);
    cm3_1.apply(1,1,3);
    return 0;
}
