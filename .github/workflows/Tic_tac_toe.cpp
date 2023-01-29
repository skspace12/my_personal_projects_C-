#include <iostream>
#include <vector>

using namespace std;

typedef  vector < vector<int> > Matrix;

void print_array(int a, int b, bool player, bool initial, Matrix &game_board);
void input_data(Matrix &game_board, bool z);
bool victor_checker(Matrix &game_board);
int main()
{
    Matrix game_board{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << "Welcome to Tic Tac Toe created by Zotam "<<'\n'<<"Player 1 Starts"<<'\n';
    print_array(0, 0, 0, 0,game_board);
    input_data(game_board, 0);
    return 0;
}
bool victor_checker(Matrix &game_board){
    vector<int>v1={1, 1, 1};
    vector<int>v2={2, 2, 2};
    int count{0};
    for (auto i:game_board){
        if( i == v1){ //row check
            cout << "Victor Player 1";
            return 1;
        }
        if (i == v2)
        { // row check
            cout << "Victor Player 2";
            return 1;
        }
        for (int j{0}; j < i.size();++j){
            if(i[j]!= 0){
                count += 1;
            }
        }
    }
    if(count>=9){
        cout << "\nMatch Drawn!! Please Restart";
        return 1;
    }
    for (int i{0}; i < 1;++i){ //column check and diaognal check
        for (int j{0}; j <3; ++j)
        {
            if((game_board[i][j]==1)&&(game_board[i+1][j] == 1 ) && (game_board[i+2][j] == 1)){
                cout << "Victor Player 1";
                return 1;
            }
            if ((game_board[i][j] == 2) && (game_board[i+1][j] == 2) && (game_board[i + 2][j] == 2))
            {
                cout << "Victor Player 2";
                return 1;
            }
            if ((game_board[i][j] == 2) && (game_board[i + 1][j+1] == 2) && (game_board[i + 2][j+2] == 2))
            {
                cout << "Victor Player 2";
                return 1;
            }
            if ((game_board[i][j] == 1) && (game_board[i + 1][j + 1] == 1) && (game_board[i + 2][j + 2] == 1))
            {
                cout << "Victor Player 1";
                return 1;
            }
            if ((game_board[i][j+2] == 1) && (game_board[i + 1][j + 1] == 1) && (game_board[i + 2][j] == 1))
            {
                cout << "Victor Player 1";
                return 1;
            }
            if ((game_board[i][j+2] == 2) && (game_board[i + 1][j + 1] == 2) && (game_board[i + 2][j] == 2))
            {
                cout << "Victor Player 2";
                return 1;
            }
        }
    }
        return 0;
}   
void input_data(Matrix &game_board,bool player)
{
    int x{};
    int y{};
    cout << "Enter the row and column you wanna play,Both should be between 0 and 1 ";
    cin >> x >> y;
    if ( x || y > 2){
        cout << "Please enter the right numbers Restart the game";
        return;
    }
    switch (player){
        case 0:
            print_array(x, y,player,1,game_board);
            player = 1;
            break;
        case 1:
            print_array(x, y,player,1,game_board);
            player = 0;
            break;
    }
    if(victor_checker(game_board)){
            return;}
            input_data(game_board, player);
}
void print_array(int a, int b, bool player, bool initial, Matrix &game_board)
{
    int game_board_initial[3][3]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    if (!initial)
    { // print initial state of the game_board
            for (int i{0}; i < 3; ++i)
            {
                for (int j{0}; j < 3; ++j)
                {
                    cout << game_board_initial[i][j] << '\t';
                }
                cout << '\n';
            }
    }
    else{
     game_board[a][b] = (player== 0) ? 1 : 2; // player input check
    for (int i{0}; i < 3; ++i)
    {
            for (int j{0}; j < 3; ++j)
            {
                cout << game_board[i][j] << '\t';
            }
            cout << '\n';
    }
    }
}
