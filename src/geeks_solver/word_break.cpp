#include<iostream>
bool check_word_break( const std::vector<std::string>& vec_input_string, const string& to_match )
{
    bool b_result_found= false;
    int n_match_idx = 0;
    for ( auto iter = vec_input_string.begin(); iter != vec_input_string.end(); ++iter ) {
        {
            std::string temp_string = *iter;
            bool match = true;
            for( int i= 0; i< temp_string.size() && n_match_idx< to_match.size(); iter++ ){
                if( temp_string[i] != to_match[n_match_idx++] )
                    match= false && break;
            }
            if( !match ) {
                n_match_idx = 0;
            }
            if( n_match_idx == to_match.size() ) {
                b_result_found = true;
                break;    
            }

        } 
    }
    return b_result_found;
}
 
