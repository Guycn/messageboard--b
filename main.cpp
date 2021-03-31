#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;
const unsigned int MAX_NUM = 100000000;
/*
0:         \\|||||//        
1:         ( O   O )        
2: |--ooO-----(_)----------|
3: |     Message Board     |
4: |      Guy Cohen        |
5: |      301198099        |
6: |                       |
7: |                       |
8: |------------------Ooo--|
9:         |__|  |__|       
10:          ||    ||        
11:         ooO    Ooo 

*/
int main() {
	ariel::Board board;
    unsigned int option = -1;
    unsigned int shape=0, row, col, flag = 1, message_lenght;
    std::string buffer;
    while(option != 4){
        std::cout << "Welcome to my Message board.\nSelect one option from below:\n" << endl;
        std::cout << "a.Enter 1 to add new message.\nb.Enter 2 to read message from the board.\n";
        std::cout << "c.Enter 3 to show the entire message board.\nd.Enter 4 to close the program." << endl;
        std::cin >> option;
        
        if(option == 1){
            std::string message;
            while(shape!=1 && shape!=2){
                std::cout << "In what direction would you like to post the message?" << endl;
                std::cout << "a.Enter 1 for Horizontal direction.\nb.Enter 2 for Vertical direction." << endl;
                std::cin >> shape;
                if(shape!=1 && shape!=2){
                    std::cout << "Wrong cohice, Shape can be Horizontal(By typing 1) or Vertical(by typing 2)\nTry again..." << endl;
                }
            }
            while(flag==1){
                std::cout << "Enter the row where you want the message to appear(Must be a positive number):" << endl;
                std:: cin >> row;
                std::cout << "Enter the column where you want the message to appear(Must be a positive number):" << endl;
                std:: cin >> col;
                cin.clear();
                fflush(stdin);
                getline (cin, buffer);
                std::cout << "Enter the message:" << endl;
                getline (cin, message);
                if(!((row>=0 && row<MAX_NUM) && (col>=0 && col<MAX_NUM))){
                std::cout << "Wrong location, Try again..." << endl;
                }   
                else{
                    flag = 0;
                }
            }
            if(shape == 1){
                board.post(row,col,Direction::Horizontal,message);
                shape = 0;
                flag = 1;
            }
            if(shape == 2){
                board.post(row,col,Direction::Vertical,message);
                shape = 0;
                flag = 1;
            }


        }
        if(option == 2){
            while(shape!=1 && shape!=2){
                std::cout << "In what direction would you like to read from message board?" << endl;
                std::cout << "a.Enter 1 for Horizontal direction.\nb.Enter 2 for Vertical direction." << endl;
                std::cin >> shape;
                if(shape!=1 && shape!=2){
                    std::cout << "Wrong cohice, Shape can be Horizontal(By typing 1) or Vertical(by typing 2)\nTry again..." << endl;
                }
            }
            while(flag==1){
                std::cout << "Enter the row where you want read from the board(Must be a positive number):" << endl;
                std:: cin >> row;
                std::cout << "Enter the column where you want read from the board(Must be a positive number):" << endl;
                std:: cin >> col;
                std::cout << "Enter the message lenght(Must be a positive number):" << endl;
                std:: cin >> message_lenght;
                if(!((row>=0 && row<MAX_NUM) && (col>=0 && col<MAX_NUM))){
                std::cout << "Wrong location, Try again..." << endl;
                }   
                else{
                    flag = 0;
                }
            }
            if(shape == 1){
                std::cout << board.read(row,col,Direction::Horizontal,message_lenght) << "\n" << endl;
                shape = 0;
                flag = 1;
            }
            if(shape == 2){
                std::cout << board.read(row,col,Direction::Vertical,message_lenght)<< "\n" << endl;;
                shape = 0;
                flag = 1;
            }
        }
        if(option == 3){
            board.show();
        }
    }
}