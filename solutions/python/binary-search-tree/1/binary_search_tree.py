class TreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        fmt = 'TreeNode(data={}, left={}, right={})'
        return fmt.format(self.data, self.left.__str__(), self.right.__str__())


class BinarySearchTree:
    def __init__(self, tree_data):
        self.btree=[]
        for node_value in tree_data:
           self.add_node(node_value)

    def data(self):
        return self.btree[0]

    def sorted_data(self):
        treenode = self.btree[0]
        sorted_nodes= []
        self.process_node(treenode, sorted_nodes)
        return sorted_nodes 

    def process_node(self, treenode, sorted_nodes):

        if treenode.left != None:
            self.process_node(treenode.left, sorted_nodes)

        sorted_nodes.append(treenode.data)
       
        if treenode.right != None:
            self.process_node(treenode.right, sorted_nodes)

    def add_node(self, node_value):
        if len(self.btree) == 0:
            self.btree.append(TreeNode(node_value,None,None))
            return

        treenode=self.btree[0]
        
        while(True):

            if  node_value <= treenode.data:
                if treenode.left == None:
                    treenode.left = TreeNode(node_value, None, None)
                    return
                else:
                    treenode = treenode.left

            if  node_value > treenode.data:
                if treenode.right == None:
                    treenode.right = TreeNode(node_value, None, None)
                    return
                else:
                    treenode = treenode.right    


