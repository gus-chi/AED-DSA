#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "avl_tree.h"

AVL_NODE *tree_created_without_rotation = NULL;
AVL_NODE *tree_created_with_rotation = NULL;
AVL_NODE *tree_test_ll = NULL;
AVL_NODE *tree_test_lr = NULL;
AVL_NODE *tree_test_rr = NULL;
AVL_NODE *tree_test_rl = NULL;

void setUp()
{
    // Arvores para testes de rotações
    
    tree_test_ll = InstantiateAVLNode(30);
    InsertABBNode(tree_test_ll, InstantiateAVLNode(20));
    InsertABBNode(tree_test_ll, InstantiateAVLNode(10));
    
    tree_test_lr = InstantiateAVLNode(30);
    InsertABBNode(tree_test_lr, InstantiateAVLNode(10));
    InsertABBNode(tree_test_lr, InstantiateAVLNode(20));
    
    tree_test_rr = InstantiateAVLNode(10);
    InsertABBNode(tree_test_rr, InstantiateAVLNode(20));
    InsertABBNode(tree_test_rr, InstantiateAVLNode(30));
    
    tree_test_rl = InstantiateAVLNode(10);
    InsertABBNode(tree_test_rl, InstantiateAVLNode(30));
    InsertABBNode(tree_test_rl, InstantiateAVLNode(20));

    // Arvores AVL e BB para teste da função de altura e bf

    tree_created_without_rotation = InstantiateAVLNode(40);
    InsertABBNode(tree_created_without_rotation, InstantiateAVLNode(20));
    InsertABBNode(tree_created_without_rotation, InstantiateAVLNode(10));
    InsertABBNode(tree_created_without_rotation, InstantiateAVLNode(25));
    InsertABBNode(tree_created_without_rotation, InstantiateAVLNode(30));
    InsertABBNode(tree_created_without_rotation, InstantiateAVLNode(22));
    InsertABBNode(tree_created_without_rotation, InstantiateAVLNode(50));
    tree_created_with_rotation = InstantiateAVLNode(40);
    InsertAVLNode(&tree_created_with_rotation, InstantiateAVLNode(20));
    InsertAVLNode(&tree_created_with_rotation, InstantiateAVLNode(10));
    InsertAVLNode(&tree_created_with_rotation, InstantiateAVLNode(25));
    InsertAVLNode(&tree_created_with_rotation, InstantiateAVLNode(30));
    InsertAVLNode(&tree_created_with_rotation, InstantiateAVLNode(22));
    InsertAVLNode(&tree_created_with_rotation, InstantiateAVLNode(50));
}
void testCreation(){
    TEST_ASSERT_EQUAL(30, tree_test_ll->value);
    TEST_ASSERT_EQUAL(20, tree_test_ll->left->value);
    TEST_ASSERT_EQUAL(10, tree_test_ll->left->left->value);

    TEST_ASSERT_EQUAL(30, tree_test_lr->value);
    TEST_ASSERT_EQUAL(10, tree_test_lr->left->value);
    TEST_ASSERT_EQUAL(20, tree_test_lr->left->right->value);

    TEST_ASSERT_EQUAL(10, tree_test_rr->value);
    TEST_ASSERT_EQUAL(20, tree_test_rr->right->value);
    TEST_ASSERT_EQUAL(30, tree_test_rr->right->right->value);
    
    TEST_ASSERT_EQUAL(10, tree_test_rl->value);
    TEST_ASSERT_EQUAL(30, tree_test_rl->right->value);
    TEST_ASSERT_EQUAL(20, tree_test_rl->right->left->value);

    TEST_ASSERT_EQUAL(40, tree_created_without_rotation->value);
    TEST_ASSERT_EQUAL(20, tree_created_without_rotation->left->value);
    TEST_ASSERT_EQUAL(10, tree_created_without_rotation->left->left->value);
    TEST_ASSERT_EQUAL(25, tree_created_without_rotation->left->right->value);
    TEST_ASSERT_EQUAL(22, tree_created_without_rotation->left->right->left->value);
    TEST_ASSERT_EQUAL(30, tree_created_without_rotation->left->right->right->value);
    TEST_ASSERT_EQUAL(50, tree_created_without_rotation->right->value);

    TEST_ASSERT_EQUAL(25, tree_created_with_rotation->value);
    TEST_ASSERT_EQUAL(20, tree_created_with_rotation->left->value);
    TEST_ASSERT_EQUAL(10, tree_created_with_rotation->left->left->value);
    TEST_ASSERT_EQUAL(22, tree_created_with_rotation->left->right->value);
    TEST_ASSERT_EQUAL(40, tree_created_with_rotation->right->value);
    TEST_ASSERT_EQUAL(30, tree_created_with_rotation->right->left->value);
    TEST_ASSERT_EQUAL(50, tree_created_with_rotation->right->right->value);
}
void testLLRotation(){
    tree_test_ll = LL_Rotation(tree_test_ll);
    TEST_ASSERT_EQUAL(20, tree_test_ll->value);
    TEST_ASSERT_EQUAL(10, tree_test_ll->left->value);
    TEST_ASSERT_EQUAL(30, tree_test_ll->right->value);
}
void testLRRotation(){
    tree_test_lr = LR_Rotation(tree_test_lr);
    TEST_ASSERT_EQUAL(20, tree_test_lr->value);
    TEST_ASSERT_EQUAL(10, tree_test_lr->left->value);
    TEST_ASSERT_EQUAL(30, tree_test_lr->right->value);
}

void testRRRotation(){
    tree_test_rr = RR_Rotation(tree_test_rr);
    TEST_ASSERT_EQUAL(20, tree_test_rr->value);
    TEST_ASSERT_EQUAL(10, tree_test_rr->left->value);
    TEST_ASSERT_EQUAL(30, tree_test_rr->right->value);
}

void testRLRotation(){
    tree_test_rl = RL_Rotation(tree_test_rl);
    TEST_ASSERT_EQUAL(20, tree_test_rl->value);
    TEST_ASSERT_EQUAL(10, tree_test_rl->left->value);
    TEST_ASSERT_EQUAL(30, tree_test_rl->right->value);
}

void tearDown(){

}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testCreation);
    RUN_TEST(testLLRotation);
    RUN_TEST(testLRRotation);
    RUN_TEST(testRRRotation);
    RUN_TEST(testRLRotation);
    UNITY_END();
}
// AVL_NODE* tree = NULL;
// AVL_NODE* tree_test = NULL;
// AVL_NODE* tree_test_rotation = NULL;
// void setUp(){
//     tree = InstantiateAVLNode(40);
//     tree_test = InstantiateAVLNode(40);
//     InsertAVLNodeTest(tree, InstantiateAVLNode(20));
//     InsertAVLNodeTest(tree, InstantiateAVLNode(10));
//     InsertAVLNodeTest(tree, InstantiateAVLNode(25));
//     InsertAVLNodeTest(tree, InstantiateAVLNode(30));
//     InsertAVLNodeTest(tree, InstantiateAVLNode(22));
//     InsertAVLNodeTest(tree, InstantiateAVLNode(50));
// }
// void testCreation(){
// // Teste de criação de árvore
// TEST_ASSERT_EQUAL(40, tree->value);
// TEST_ASSERT_EQUAL(20, tree->left->value);
// TEST_ASSERT_EQUAL(10, tree->left->left->value);
// TEST_ASSERT_EQUAL(25, tree->left->right->value);
// TEST_ASSERT_EQUAL(22, tree->left->right->left->value);
// TEST_ASSERT_EQUAL(30, tree->left->right->right->value);
// TEST_ASSERT_EQUAL(50, tree->right->value);
// }
// void testFindHeight(){
//     TEST_ASSERT_EQUAL(3, FindHeight(tree));
//     TEST_ASSERT_EQUAL(2, FindHeight(tree->left));
//     TEST_ASSERT_EQUAL(0, FindHeight(tree->right));
//     TEST_ASSERT_EQUAL(0, FindHeight(tree_test));
// }
// void testBalancementFactor(){
//     TEST_ASSERT_EQUAL(2, tree->bf);
//     TEST_ASSERT_EQUAL(-1, tree->left->bf);
//     TEST_ASSERT_EQUAL(0, tree->left->left->bf);
//     TEST_ASSERT_EQUAL(0, tree->left->right->bf);
//     TEST_ASSERT_EQUAL(0, tree->left->right->left->bf);
//     TEST_ASSERT_EQUAL(0, tree->left->right->right->bf);
//     TEST_ASSERT_EQUAL(0, tree->right->bf);
// }
// void testbf(){
//     TEST_ASSERT_EQUAL(2, tree->bf);
//     TEST_ASSERT_EQUAL(-1, tree->left->bf);
//     TEST_ASSERT_EQUAL(0, tree->left->left->bf);
//     TEST_ASSERT_EQUAL(0, tree->left->right->bf);
//     TEST_ASSERT_EQUAL(0, tree->left->right->left->bf);
//     TEST_ASSERT_EQUAL(0 , tree->left->right->right->bf);
//     TEST_ASSERT_EQUAL(0, tree->right->bf);

// }
// void testLLRotation(){
//     tree_test_rotation = InstantiateAVLNode(30);
//     InsertAVLNode(&tree_test_rotation, InstantiateAVLNode(20));
//     InsertAVLNode(&tree_test_rotation, InstantiateAVLNode(10));
//     TEST_ASSERT_EQUAL(20, tree_test_rotation->value);
//     TEST_ASSERT_EQUAL(10, tree_test_rotation->left->value);
//     TEST_ASSERT_EQUAL(30, tree_test_rotation->right->value);
// }
// void tearDown(){
//     free(tree);
//     free(tree_test);
//     free(tree_test_rotation);
// }
// int main(void){
//     UNITY_BEGIN();
//     RUN_TEST(testCreation);
//     RUN_TEST(testFindHeight);
//     RUN_TEST(testBalancementFactor);
//     RUN_TEST(testbf);
//     RUN_TEST(testLLRotation);
//     UNITY_END();
//     return 0;
// }