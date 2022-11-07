#include <iostream>

#ifndef BINARYTREE_H
#define BINARYTREE_H
#endif

#define direction int
#define bool int
#define true 1
#define false 0

#define forward 0
#define left -90
#define right 90
#define backwards -180

#define stop_pin 0      // brake or move
#define fs_pin A0       // forward sensor
#define ls_pin A1       // left sensor
#define rs_pin A2       // right sensor
#define rotation_pin A3 // rotation
#define arrow_pin 11    // arrow area
#define block_pin 12    // block area
#define up_pin 13       // move up in block area


class Node{
  public:
    int data;
    Node* left_child;
    Node* right_child;
  
    // Val is the key or the value that
    // has to be added to the data part
    Node(int val)
    {
        data = val;
  
        // Left and right child for node
        // will be initialized to null
        left_child = 0x0;
        right_child = 0x0;
    }
};
void test()
{
    Node* root = new Node(1);
    root->data=10;
    root->left_child->data=10;
    std::cout << root->left_child->data;
}
int main()
{
    test();
}