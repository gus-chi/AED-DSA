#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "btree.h"

// arvores input professor

BTree* input1 = NULL;
BTree* input2 = NULL;

// arvores minhas de teste

BTree* test1 = NULL;

int* array = NULL;

void setUp(){
    input1 = InstantiateTree(2);
    InitTree(input1, 2);
    InsertOnTree(&input1, 20, 2, &input1);;
    InsertOnTree(&input1, 10, 2, &input1);;
    InsertOnTree(&input1, 40, 2, &input1);;
    InsertOnTree(&input1, 50, 2, &input1);;
    InsertOnTree(&input1, 30, 2, &input1);;
    InsertOnTree(&input1, 55, 2, &input1);;
    InsertOnTree(&input1, 3, 2, &input1);;
    InsertOnTree(&input1, 11, 2, &input1);;
    InsertOnTree(&input1, 4, 2, &input1);;
    InsertOnTree(&input1, 28, 2, &input1);;
    InsertOnTree(&input1, 36, 2, &input1);;
    InsertOnTree(&input1, 33, 2, &input1);;
    InsertOnTree(&input1, 52, 2, &input1);;
    InsertOnTree(&input1, 17, 2, &input1);;
    InsertOnTree(&input1, 25, 2, &input1);;
    InsertOnTree(&input1, 13, 2, &input1);;
    InsertOnTree(&input1, 45, 2, &input1);;
    InsertOnTree(&input1, 9, 2, &input1);;
    InsertOnTree(&input1, 43, 2, &input1);;
    InsertOnTree(&input1, 8, 2, &input1);;
    InsertOnTree(&input1, 48, 2, &input1);;
    

    input2 = InstantiateTree(3);
    InitTree(input2, 3);
    InsertOnTree(&input2, 20, 3, &input2);
    InsertOnTree(&input2, 10, 3, &input2);
    InsertOnTree(&input2, 40, 3, &input2);
    InsertOnTree(&input2, 50, 3, &input2);
    InsertOnTree(&input2, 30, 3, &input2);
    InsertOnTree(&input2, 55, 3, &input2);
    InsertOnTree(&input2, 3, 3, &input2);
    InsertOnTree(&input2, 11, 3, &input2);
    InsertOnTree(&input2, 4, 3, &input2);
    InsertOnTree(&input2, 28, 3, &input2);
    InsertOnTree(&input2, 36, 3, &input2);
    InsertOnTree(&input2, 33, 3, &input2);
    InsertOnTree(&input2, 52, 3, &input2);
    InsertOnTree(&input2, 17, 3, &input2);
    InsertOnTree(&input2, 25, 3, &input2);
    InsertOnTree(&input2, 13, 3, &input2);
    InsertOnTree(&input2, 45, 3, &input2);
    InsertOnTree(&input2, 9, 3, &input2);
    InsertOnTree(&input2, 43, 3, &input2);
    InsertOnTree(&input2, 8, 3, &input2);
    InsertOnTree(&input2, 48, 3, &input2);

    test1 = InstantiateTree(2);
    InitTree(test1, 2);
    InsertOnTree(&test1, 1, 2, &test1);
    InsertOnTree(&test1, 2, 2, &test1);
    InsertOnTree(&test1, 3, 2, &test1);
    InsertOnTree(&test1, 4, 2, &test1);
    InsertOnTree(&test1, 5, 2, &test1);
    array = malloc(5 * sizeof *array);
}
void tearDown(){

}

void testCreation(){
    // tests input 1
    TEST_ASSERT_EQUAL(30, input1->values[0]);
    TEST_ASSERT_EQUAL(10, input1->pointers[0]->values[0]);
    TEST_ASSERT_EQUAL(20, input1->pointers[0]->values[1]);
    TEST_ASSERT_EQUAL(3, input1->pointers[0]->pointers[0]->values[0]);
    TEST_ASSERT_EQUAL(4, input1->pointers[0]->pointers[0]->values[1]);
    TEST_ASSERT_EQUAL(8, input1->pointers[0]->pointers[0]->values[2]);
    TEST_ASSERT_EQUAL(9, input1->pointers[0]->pointers[0]->values[3]);
    TEST_ASSERT_EQUAL(11, input1->pointers[0]->pointers[1]->values[0]);
    TEST_ASSERT_EQUAL(13, input1->pointers[0]->pointers[1]->values[1]);
    TEST_ASSERT_EQUAL(17, input1->pointers[0]->pointers[1]->values[2]);
    TEST_ASSERT_EQUAL(25, input1->pointers[0]->pointers[2]->values[0]);
    TEST_ASSERT_EQUAL(28, input1->pointers[0]->pointers[2]->values[1]);
    TEST_ASSERT_EQUAL(40, input1->pointers[1]->values[0]);
    TEST_ASSERT_EQUAL(50, input1->pointers[1]->values[1]);
    TEST_ASSERT_EQUAL(33, input1->pointers[1]->pointers[0]->values[0]);
    TEST_ASSERT_EQUAL(36, input1->pointers[1]->pointers[0]->values[1]);
    TEST_ASSERT_EQUAL(43, input1->pointers[1]->pointers[1]->values[0]);
    TEST_ASSERT_EQUAL(45, input1->pointers[1]->pointers[1]->values[1]);
    TEST_ASSERT_EQUAL(48, input1->pointers[1]->pointers[1]->values[2]);
    TEST_ASSERT_EQUAL(52, input1->pointers[1]->pointers[2]->values[0]);
    TEST_ASSERT_EQUAL(55, input1->pointers[1]->pointers[2]->values[1]);
    
    // tests input 2

    TEST_ASSERT_EQUAL(11, input2->values[0]);
    TEST_ASSERT_EQUAL(30, input2->values[1]);
    TEST_ASSERT_EQUAL(45, input2->values[2]);
    TEST_ASSERT_EQUAL(3, input2->pointers[0]->values[0]);
    TEST_ASSERT_EQUAL(4, input2->pointers[0]->values[1]);
    TEST_ASSERT_EQUAL(8, input2->pointers[0]->values[2]);
    TEST_ASSERT_EQUAL(9, input2->pointers[0]->values[3]);
    TEST_ASSERT_EQUAL(10, input2->pointers[0]->values[4]);
    TEST_ASSERT_EQUAL(13, input2->pointers[1]->values[0]);
    TEST_ASSERT_EQUAL(17, input2->pointers[1]->values[1]);
    TEST_ASSERT_EQUAL(20, input2->pointers[1]->values[2]);
    TEST_ASSERT_EQUAL(25, input2->pointers[1]->values[3]);
    TEST_ASSERT_EQUAL(28, input2->pointers[1]->values[4]);
    TEST_ASSERT_EQUAL(33, input2->pointers[2]->values[0]);
    TEST_ASSERT_EQUAL(36, input2->pointers[2]->values[1]);
    TEST_ASSERT_EQUAL(40, input2->pointers[2]->values[2]);
    TEST_ASSERT_EQUAL(43, input2->pointers[2]->values[3]);
    TEST_ASSERT_EQUAL(48, input2->pointers[3]->values[0]);
    TEST_ASSERT_EQUAL(50, input2->pointers[3]->values[1]);
    TEST_ASSERT_EQUAL(52, input2->pointers[3]->values[2]);
    TEST_ASSERT_EQUAL(55, input2->pointers[3]->values[3]);


    // test meus testes
    TEST_ASSERT_EQUAL(3, test1->values[0]);
    TEST_ASSERT_EQUAL(1, test1->pointers[0]->values[0]);
    TEST_ASSERT_EQUAL(2, test1->pointers[0]->values[1]);
    TEST_ASSERT_EQUAL(4, test1->pointers[1]->values[0]);
    TEST_ASSERT_EQUAL(5, test1->pointers[1]->values[1]);
}
void testIsLeaf(){
    // test input 1
    TEST_ASSERT_EQUAL(0, IsLeaf(input1));
    TEST_ASSERT_EQUAL(0, IsLeaf(input1->pointers[0]));
    TEST_ASSERT_EQUAL(1, IsLeaf(input1->pointers[0]->pointers[0]));
    TEST_ASSERT_EQUAL(1, IsLeaf(input1->pointers[0]->pointers[1]));
    TEST_ASSERT_EQUAL(1, IsLeaf(input1->pointers[0]->pointers[2]));
    TEST_ASSERT_EQUAL(0, IsLeaf(input1->pointers[1]));
    TEST_ASSERT_EQUAL(1, IsLeaf(input1->pointers[1]->pointers[0]));
    TEST_ASSERT_EQUAL(1, IsLeaf(input1->pointers[1]->pointers[1]));
    TEST_ASSERT_EQUAL(1, IsLeaf(input1->pointers[1]->pointers[2]));
}
void testInsertOnArray(){
    InsertOnArray(array, 0, 1);
    InsertOnArray(array, 1, 2);
    InsertOnArray(array, 2, 3);
    InsertOnArray(array, 3, 5);
    InsertOnArray(array, 4, 4);
    TEST_ASSERT_EQUAL(1, array[0]);
    TEST_ASSERT_EQUAL(2, array[1]);
    TEST_ASSERT_EQUAL(3, array[2]);
    TEST_ASSERT_EQUAL(4, array[3]);
    TEST_ASSERT_EQUAL(5, array[4]);
}

void testSearchNode(){
    TEST_ASSERT_EQUAL(input1->pointers[0]->pointers[0], SearchNode(input1, 3));
    TEST_ASSERT_EQUAL(NULL, SearchNode(input1, 380));
}
void testSearchFather(){
    TEST_ASSERT_EQUAL(test1, SearchFather(test1, 1));
    TEST_ASSERT_EQUAL(test1, SearchFather(test1, 2));
    TEST_ASSERT_EQUAL(test1, SearchFather(test1, 4));
    TEST_ASSERT_EQUAL(test1, SearchFather(test1, 5));
}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testCreation);
    RUN_TEST(testIsLeaf);
    RUN_TEST(testInsertOnArray);
    RUN_TEST(testSearchNode);
    RUN_TEST(testSearchFather);
    UNITY_END();   
    return 0;
}