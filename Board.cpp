#include<iostream>
#include<string>
#include<array>
#include "Board.hpp"
using namespace ariel;
using namespace std;
using ariel::Direction;

const char EMPTY = '_';
const unsigned int MAX_NUM = 1000000;
const unsigned int INIT_NUM = INIT_NUM;

unsigned int notice_size = 0;
string clean = "_";
namespace ariel{
    Board:: Board(){
        board.resize(INIT_NUM,vector<char>(INIT_NUM, EMPTY));
    }
    void Board::post(unsigned int row, unsigned int col, Direction shape, string const & notice){
        unsigned int r = 0;
        unsigned int c = 0;
        notice_size = notice.size();
        if(row + notice_size > MAX_NUM){
            std:: cout << "out_of_bounds";
            throw std::exception();
        }
        if(col + notice_size > MAX_NUM){
            std:: cout << "out_of_bounds";
            throw std::exception();
        }


        if(shape == Direction::Vertical){
            if(row + notice_size > board.size()){
                r = row + notice_size;
                if(col > board[0].size()){
                    c = col + 1;
                }
                else{
                    c = board[0].size();
                }
                board.resize(r, vector<char>(c,EMPTY));
            }
            if(c > board[0].size()){
                for(uint i=0;i<board.size();i++){
                    board[i].resize(col,EMPTY);
                }
            }
        }
        else{
            if(board.size() < row + 1){
                board.resize(row + 1,vector<char>(col+1,EMPTY));
            }
            if(board[row].size() < col + notice_size){
                c = col + notice_size;
                for(uint i=0;i<board.size();i++){
                    board[i].resize(c,EMPTY);
                }
            
            }
        }
        if(shape == Direction::Horizontal){
            unsigned int i = 0;
            for(char dig : notice){
                board[row][col + i] = dig;
                i++;
            }
        }
        else{
            unsigned int i = 0;
            for(char dig : notice){
                board[row + i][col] = dig;
                i++;
            }
        }
    }
    string Board::read(unsigned int row, unsigned int col, Direction shape, unsigned int lenght){

        std::string str;
        unsigned int len = 0;
        if(shape == Direction::Horizontal){
            while(len<lenght){
                if(board.size() < row+1 || board[row].size() <= col + len){
                    str += "_";
                }
                else{
                    str +=board[row][col+len];
                }
                len++;
            }
        }
         if(shape == Direction::Vertical){
            while(len<lenght){
                if(row + len >= board.size() || col >= board[row].size()){
                    str += "_";
                }
                else{
                    str +=board[row+len][col];
                }
                len++;
            }
        }
        return str;
    }
    void Board::show(){
        int row = board.size();
        for(size_t i=0;i<row;i++){
            int col = board[i].size();
            cout << i << ": ";
            for(size_t j=0;j<col;j++){
                cout << board[i][j];
            }
            cout << endl;
        }
    }


}

