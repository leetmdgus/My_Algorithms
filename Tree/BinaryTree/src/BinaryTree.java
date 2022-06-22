class CoudntFindChildException extends RuntimeException {}
class CoudntFindNodeException extends RuntimeException {}

class Node {
	Node(int data) {
		this.data = data;
		this.parent = null;
		this.rightChild = null;
		this.leftChild = null;
	}
	
	int data;
	Node parent;
	Node rightChild;
	Node leftChild;
}


public class BinaryTree<T> {
	BinaryTree(){
		size = 0; 
		root = null;
	}
	void add(int data) {
		size++;
		Node newNode = new Node(data);
		Node node = root;
		if(isEmpty()) {
			root = newNode;
			return;
		}
		while(true) {
			if(data == root.data) {
				return;
			} else if(data > node.data) {
				if(node.rightChild == null) {
					newNode.parent = node;
					node.rightChild = newNode;
					return;
				}
				node = node.rightChild;
			} else if(data < node.data) {
				if(node.leftChild == null) {
					newNode.parent = node;
					node.leftChild = newNode;
					return;
				}
				node = node.leftChild;
			}	
		}
	}
	
	void remove(int data) {
		size--;
		if(isOneNode()) {
			root =null;
		}
		Node node = getNode(data);
		if(isLeafNode(node)) {
			removeLeafNode(node);
		}else if(isRootNode(node)) {
		}else {
		
		}
	}
	
	
	private void removeLeafNode(Node node) {
		if(node.parent.data > node.data) {
			node.parent.leftChild = null;	
		} else if(node.parent.data < node.data) {
			node.parent.rightChild = null;
		}			
		return;
	}
	
	boolean isRootNode(int data) {
		Node node = getNode(data);
		if(node.parent == null) {
			return true;
		}
		return false;
	}
	private boolean isRootNode(Node node) {
		return(node.parent == null) ? true : false;
	}
	boolean isLeafNode(int data) {
		Node node = getNode(data);
		if(node.leftChild == null && node.rightChild == null) {
			return true;
		}
		return false;
	}
	private boolean isLeafNode(Node node) {
		return (node.leftChild == null && node.rightChild == null) ? true: false;
	}
	
	boolean isEmpty() {
		return (root == null) ? true : false;
	}
	
	private int size;
	private Node root;
	
	private boolean isOneNode() {
		return (root.leftChild==null && root.rightChild==null) ? true : false;
	}
	
	private Node getNode(int data) {
		if(isEmpty()) {
			throw new CoudntFindNodeException();
		}
		Node node = root;
			while(data != node.data) {
				if(data == root.data) {
					return node;
				} else if(data > root.data) {
					if(root.rightChild == null) {
						throw new CoudntFindChildException();
					}
					node = root.rightChild;
				} else if(data < root.data) {
					if(root.leftChild == null) {
						throw new CoudntFindChildException();
					}
					node = root.leftChild;
				}
			}
			return node;
	}
}
