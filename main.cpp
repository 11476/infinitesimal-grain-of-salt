//
//  main.cpp
//  infinitesimal grain of salt
//
//  Created by Gavin Yu on 2025-04-30.
//

#include <iostream>
#include <bitset>
#define pos 7*r+c
#define red 0
#define yellow 1
//7c 6r
//phenylalanine
typedef struct twice_bitset_42{
    std::bitset<42> filled;
    std::bitset<42> colors;
    inline bool is_red(int r, int c){
        return (filled[pos] and colors[pos] == red);
    }
    inline bool is_yellow(int r, int c){
        return (filled[pos] and colors[pos] == yellow);
    }
    inline bool is_empty(int r, int c){
        return not filled[pos];
    }
    inline int get_state(int r, int c){
        if (not filled[pos]) return 0;
        return 1+colors[pos];
    }
} board;
int main(int argc, const char * argv[]) {

}
