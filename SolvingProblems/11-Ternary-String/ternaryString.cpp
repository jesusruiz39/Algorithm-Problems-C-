#include <bits/stdc++.h>

using namespace std;

inline auto get_minmax_of_3_elements(const int x, const int y, const int z) -> pair<int, int>{
    auto [maybe_min, maybe_max] = std::minmax(x, y);
    int final_min = std::min(maybe_min, z);
    int final_max = std::max(maybe_max, z);
    return { final_min, final_max };

}

const auto big_and_invalid_num = numeric_limits<int>::max();
auto size_of_min_substring_with_123(const string& input) -> int{
    int last_time_i_saw_1 = 0, last_time_i_saw_2 = 0, last_time_i_saw_3 = 0;
    auto size_of_min_valid_substring = big_and_invalid_num;

    for (int i = 0; i < input.size(); ++i){
        if(input[i] == '1') last_time_i_saw_1 = i+1;
        if(input[i] == '2') last_time_i_saw_2 = i+1;
        if(input[i] == '3') last_time_i_saw_3 = i+1;

        if(last_time_i_saw_1 and last_time_i_saw_2 and last_time_i_saw_3){
            const auto [begin_of_substr, end_of_substr] = get_minmax_of_3_elements (last_time_i_saw_1, last_time_i_saw_2, last_time_i_saw_3);

            const auto candidate_substring_size = end_of_substr - begin_of_substr + 1;
            size_of_min_valid_substring = min(size_of_min_valid_substring, candidate_substring_size);
        }
    }

    if(size_of_min_valid_substring == big_and_invalid_num) return 0;
    return size_of_min_valid_substring;

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tests;
    std::cin>>tests;
    for(int test = 0; test < tests; ++test){
        std::string s;
        std::cin>>s;
        std::cout << size_of_min_substring_with_123(s)<<"\n";
    }
}