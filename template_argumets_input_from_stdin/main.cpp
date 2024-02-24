#include <iostream>
#include <vector>
#include <iterator>
#include <tuple>

template <size_t I,typename T>
struct tuple_n{
    template< typename...Args> using type = typename tuple_n<I-1, T>::template type<T, Args...>;
};
template <typename T>
struct tuple_n<0, T> {
    template<typename...Args> using type = std::tuple<Args...>;
};
template <size_t I,typename T>  using tuple_of = typename tuple_n<I,T>::template type<>;

// template<typename IstreamType, typename... Args>
// std::tuple<Args...> read_in_args(std::istream_iterator<IstreamType> &&it){}


template<typename IstreamType, typename TTuple>
TTuple read_in_args(std::istream_iterator<IstreamType> &&it){
    const std::istream_iterator<IstreamType> eof; 
    TTuple ans;
    auto it_tuple = ans.begin();
    size_t i = 0;
    
    while(it != eof){
        *it_tuple = *it;
        ++it;
        ++tuple_iterator;
    }
    return ans;
}



/*TODO: GET RECOURSIVE CALL TO UNPACK VALUE FROM STDIN*/
// template<typename IstreamType, typename ValueType, size_t I>
// std::tuple<tuple_n<I, ValueType>> read_in_args(std::istream_iterator<IstreamType> &&it){
//     return std::make_tuple(*it, *(it++));
// }

int main(){
    // note. input args sequence is reversed
    using return_arguments_template = tuple_of<2, int>;
    auto [b, a] = read_in_args<int, return_arguments_template>(std::istream_iterator<int>(std::cin));

    std::cout << a << " " << b;
    return 0;
}