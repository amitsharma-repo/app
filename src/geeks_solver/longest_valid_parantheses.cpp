#include<longest_valid_parantheses.h>
#include<stack>
int find_longest_valid_parantheses( const std::string& input_string )
{
    std::stack<int> stack_parantheses;
    int n_longest_parantheses = 0;
    for( int idx =0; idx < input_string.size(); ++idx ) {
        if(input_string[idx] == '(' ) {
            stack_parantheses.push( idx );
        }
        else {
            if( stack_parantheses.empty() || stack_parantheses.top() < 0 ) {
                int neg_idx = -idx;
                stack_parantheses.push( neg_idx ); 
            }
            else {
                int start_idx = stack_parantheses.top();
                stack_parantheses.pop();
                
                if( !stack_parantheses.empty() && stack_parantheses.top() >0 )
                {
                    int prev_paran_idx = stack_parantheses.top();
                    
                    if( prev_paran_idx != start_idx -1 )
                        start_idx = prev_paran_idx + 1;  
                }
                if( idx - start_idx > n_longest_parantheses ) {
                    n_longest_parantheses = idx - start_idx;
                }
            }
        }
    }
    return n_longest_parantheses + 1;
}
