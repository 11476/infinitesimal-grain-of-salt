//
//  main.cpp
//  infinitesimal grain of salt
//
//  Created by Gavin Yu on 2025-04-30.
//

#include <iostream>
#include <bitset>

//7c 6r
//phenylalanine
const bool red = false, yellow = true;
inline int P(int a, int b)
{
    return 7 * a + b;
}
class Board
{
    std::bitset<42> filled;
    std::bitset<42> colors;
    public:
    inline int get_state(int r, int c){
        if (not filled[P(r, c)]) return 0;
        return 1+colors[P(r, c)];
    }
    Board(){
        filled = std::bitset<42>(0);
        colors = std::bitset<42>(0);
    }
    void move (int c, bool player){
        int r1 = P(0, c);
        while (filled[r1]){
            r1 += 7;
        }
        filled[r1] = true;
        colors[r1] = player;
    }
};

void display(Board& board){
    using std::cout;
    using std::endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int state = board.get_state(i, j);
            if (state == 0) cout << ".";
            else if (state == 1) cout << "R";
            else if (state == 2) cout << "Y";
            else cout << "?";
        }
        cout << endl;
    }
}
int main(int argc, const char *argv[])
{
    // driver code
    Board board;
    display(board);
    board.move(3, red);
    display(board);
}
