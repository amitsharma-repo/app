#include<set>
#include<iostream>
#include<queue>
#include<min_jump_to_reach_home.h>
#include<unordered_map>
struct info
{
    int curr;
    bool back_move;
    int count;
};
int minimumJumps(std::vector<int>& forbidden, int a, int b, int x)
{

    std::unordered_map<int,int> map_forbidden;
    for(int i=0;i<forbidden.size();i++)
        map_forbidden[forbidden[i]] = 1;
    std::queue<info> state_queue;
    state_queue.push({0,0,0});

    while(!state_queue.empty())
    {
        int cur_pos = state_queue.front().curr;
        int move_cnt = state_queue.front().count;
        bool state = state_queue.front().back_move;
        state_queue.pop();
        if( cur_pos == x )
            return move_cnt;
        if( cur_pos - b >= 0 && state == 0 && map_forbidden[cur_pos -b] == 0) {
            state_queue.push( {cur_pos - b, 1, move_cnt+1});
            map_forbidden[cur_pos-b] = 1;
        }
        if( cur_pos + a < 500 && map_forbidden[cur_pos + a] == 0){
            state_queue.push({cur_pos + a, 0, move_cnt+1});
            map_forbidden[cur_pos+a] = 1;
        }
    }
    return -1;
}
