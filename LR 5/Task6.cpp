//#include <iostream>
//#include <fstream>
//#include <queue>
//
//using namespace std;
//
//struct TreeNode
//{
//    int data;
//    int count;
//    TreeNode* left;
//    TreeNode* right;
//};
//
//TreeNode* createNode(int value)
//{
//    TreeNode* newNode = new TreeNode;
//    newNode->data = value;
//    newNode->count = 1;
//    newNode->left = nullptr;
//    newNode->right = nullptr;
//    return newNode;
//}
//
//TreeNode* insertValue(TreeNode* root, int value)
//{
//    if (root == nullptr) return createNode(value);
//
//    if (value == root->data) root->count++;
//    else if (value < root->data) root->left = insertValue(root->left, value);
//    else root->right = insertValue(root->right, value);
//
//    return root;
//}
//
//void destroyTree(TreeNode* root)
//{
//    if (root != nullptr)
//    {
//        destroyTree(root->left);
//        destroyTree(root->right);
//        delete root;
//    }
//}
//
//TreeNode* createTree(const string& filename)
//{
//    ifstream ifs(filename);
//    if (!ifs.is_open())
//    {
//        cerr << "Ошибка при открытии файла" << endl;
//    }
//
//    int value;
//    TreeNode* root = nullptr;
//
//    while (ifs >> value)
//    {
//        root = insertValue(root, value);
//    }
//    ifs.close();
//
//    return root;
//}
//
//int findMaxDepth(TreeNode* root)
//{
//    if (root == nullptr)
//    {
//        return 0;
//    }
//
//    int leftHeight = findMaxDepth(root->left);
//    int rightHeight = findMaxDepth(root->right);
//
//    return max(leftHeight, rightHeight) + 1;
//}
//
//void printTree(TreeNode* node, int indent)
//{
//    if (node == nullptr)
//    {
//        return;
//    }
//
//    printTree(node->left, indent - 5);
//
//    for (int i = 0; i < indent; i++)
//    {
//        cout << " ";
//    }
//    cout << node->data << endl;
//
//    printTree(node->right, indent - 5);
//}
//
//void deleteNodesAtLevel(TreeNode*& root, int level) 
//{
//    if (root == nullptr || level < 1) return;
//
//    if (level == 1) 
//    {
//        delete root;
//        root = nullptr;
//        return;
//    }
//
//    queue<TreeNode*> nodeQueue;
//    nodeQueue.push(root);
//    int currentLevel = 1;
//
//    while (!nodeQueue.empty()) 
//    {
//        int nodesCountAtCurrentLevel = nodeQueue.size();
//
//        for (int i = 0; i < nodesCountAtCurrentLevel; i++) 
//        {
//            TreeNode* currentNode = nodeQueue.front();
//            nodeQueue.pop();
//
//            if (currentNode->left != nullptr) 
//            {
//                if (currentLevel + 1 == level) 
//                {
//                    delete currentNode->left;
//                    currentNode->left = nullptr;
//                }
//                else 
//                {
//                    nodeQueue.push(currentNode->left);
//                }
//            }
//
//            if (currentNode->right != nullptr) 
//            {
//                if (currentLevel + 1 == level) 
//                {
//                    delete currentNode->right;
//                    currentNode->right = nullptr;
//                }
//                else 
//                {
//                    nodeQueue.push(currentNode->right);
//                }
//            }
//        }
//
//        currentLevel++;
//
//        if (currentLevel == level) break;
//    }
//}
//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//
//    TreeNode* root = createTree("data6.txt");
//    int depth = findMaxDepth(root);
//    printTree(root, depth * 5);
//    cout << endl << "Высота: " << depth << endl;
//
//    int depthToDel;
//    cout << endl << "Введите уровень дерева" << endl;
//    cin >> depthToDel;
//
//    if (depthToDel > depth)
//    {
//        cerr << "Невозможно удалить несуществующие вершины" << endl;
//        system("pause");
//    }
//
//    deleteNodesAtLevel(root, depthToDel);
//    cout << endl << endl;
//    printTree(root, depth * 5);
//}