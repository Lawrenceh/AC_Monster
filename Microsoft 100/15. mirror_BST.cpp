BSTreeNode * Mirror_Solution1(BSTreeNode * pRoot) {
	if (pRoot != NULL) {
		BSTreeNode * pRight = pRoot->right;
		BSTreeNode * pLeft = pRoot->left;
		pRoot->left = Mirror_Solution1(pRight);  
		pRoot->right = Mirror_Solution1(pLeft);  
	}
	return pRoot;
}

BSTreeNode *Mirror_Solution2(BSTreeNode * pRoot) {
	if (pRoot != NULL) {
		stack<BSTreeNode *> stk;   
		stk.push(pRoot);          
		while (stk.size()) {
			BSTreeNode *pNode = stk.top();
			BSTreeNode *pLeft = pNode->left;
			BSTreeNode* pRight = pNode->right;
			stk.pop();

			if (pLeft != NULL) stk.push(pLeft);
			if (pRight != NULL) stk.push(pRight);
			pNode->left = pRight;  
			pNode->right = pLeft;
		}
	}
	return pRoot;
}
