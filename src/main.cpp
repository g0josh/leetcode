#include<iostream>
#include <vector>
#include "arrays_easy.hpp"
#include "strings_easy.hpp"

// #define ARRAYS
#define STRINGS

//print a vector
template <typename T>
void printVector(std::vector<T>& V, int upto){
    (upto < 0)?upto = V.size():upto = upto;
    std::cout<<"[ ";
    for (int i = 0; i<upto; i++){
        std::cout<<V[i]<<" ";
    }
    std::cout<<"]";
}

int main(int argc, char** argv){
    //Arrays
    #ifdef ARRAYS
    #pragma region 
        std::vector<int> vi = {2,1,1,3};
        std::cout<<"Max profit of ";
        printVector(vi, -1);
        std::cout<< " = "<<arrays_easy::maxProfit(vi);

        vi = {4,9,5};
        std::cout<<"\nRotated ";
        printVector(vi, -1);
        std::cout<<" to ";
        arrays_easy::rotate(vi, 2);
        printVector(vi, -1);

        vi = {4,9,9,5, 7, 5, 4};
        std::cout<<"\nDuplicates in ";
        printVector(vi, -1);
        std::cout<< " = ";
        std::cout<<arrays_easy::containsDuplicate(vi);

        //find the only number that appears once
        std::cout <<"\nThe number that only appears once in ";
        printVector(vi, -1);
        std::cout<< " is "<<arrays_easy::singleNumber(vi);

        //find intersection of arrays
        std::vector<int> vi2 = {9,4,9,8,4};
        std::cout<<"\nIntersecting elements of ";
        printVector(vi, -1);
        std::cout<<" and ";
        printVector(vi2, -1);
        std::cout<<" = ";
        std::vector<int> vir = arrays_easy::intersect(vi, vi2);
        printVector(vir, -1);

        //plus one
        vi = {9,9,9};
        std::cout<<"\nplus one digits of ";
        printVector(vi, -1);
        std::cout<<" = ";
        vir = arrays_easy::plusOne(vi);
        printVector(vir, -1);

        //move zeroes
        vi = {0,1,0,3,12,0};
        std::cout<<"\nmove zeroes of ";
        printVector(vi, -1);
        std::cout<<" = ";
        arrays_easy::moveZeroes(vi);
        printVector(vi, -1);

        //twosum
        vi = {2, 7, 11, 15};
        int target = 9;
        std::cout<<"\ntwo sum of ";
        printVector(vi, -1);
        std::cout<<" with target "<<target<<" = ";
        vir = arrays_easy::twoSum(vi, target);
        printVector( vir, -1);

        //sudoku validity check
        std::vector<std::vector<char>> board = {
            {'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
            };
        std::cout<<"\nThe following Sudoku\n";
        for (int i = 0; i < board.size(); i++){
            printVector(board[i], -1);
            std::cout<<"\n";
        }
        std::string result;
        arrays_easy::isValidSudoku(board)?result="is valid":result="is invalid";
        std::cout<<result<<"\n";

        //rotate square matrix 90 degrees
        std::cout<<"\nRotated the following matrix 90 degrees\n";
        std::vector<std::vector<int>> matrix = {
                {5, 1, 9,11},
                {2, 4, 8,10},
                {13, 3, 6, 7},
                {15,14,12,16}
            };
        for (int i = 0; i < matrix.size(); i++){
            printVector(matrix[i], -1);
            std::cout<<"\n";
        }
        arrays_easy::rotateMatrix90(matrix);
        std::cout<<"result = \n";
        for (int i = 0; i < matrix.size(); i++){
            printVector(matrix[i], -1);
            std::cout<<"\n";
        }
    
    #pragma endregion
    #endif

    //Strings
    #ifdef STRINGS
    #pragma region 
    
    std::vector<char> str = {'h','e','l','l','o'};
    std::cout<<"\nReversed ";
    printVector(str,-1);
    strings_easy::reverseString(str);
    std::cout<<" and got ";
    printVector(str,-1);
    int input = 1534236469;
    std::cout<<"\nReversed "<<input<<" to "<<strings_easy::reverse(input);
    
    #pragma endregion
    #endif


}