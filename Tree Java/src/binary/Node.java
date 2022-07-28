package binary;

public class Node<E> {
    private E data;
    private Node<E> left;
    private Node<E> right;
    private Node<E> parent;

    public Node(E data, Node<E> left, Node<E> right, Node<E> parent) {
        this.data = data;
        this.left = left;
        this.right = right;
        this.parent = parent;
    }

    public E getData() {return this.data;}
    public Node<E> getLeftChild() {
        return (this.left != null) ? this.left : null;
    }

    public Node<E> getRightChild() {
        return (this.right != null) ? this.right : null;
    }
    public Node<E> getParent() {
        return (this.parent != null) ? this.parent : null;
    }
    public void setLeftChild(Node<E> node) {
        if(this.left != null) {
            node.left = this.left.left;  //노드가 단일 노드가 들어왔을때를 가정
            node.right = this.left.right;
        }
        this.left = node;
        node.parent = this;
    }
    public void setLeftChild(E data) {
        if(this.left == null) {
            this.left = new Node<E>(data, null, null, this);
        } else {
            this.left.data = data;
        }
    }

    public void setRightChild(Node<E> node) {
        if(this.right != null) {
            node.left = this.right.left;
            node.right = this.right.right;
        }
        this.right = node;
        node.parent = this;
    }

    public void setRightChild(E data) {
        if(this.right == null) {
            this.right = new Node(data, null, null, this);
        } else {
            this.right.data = data;
        }
    }

    public void setParent(Node<E> node) {
        node.left = this;
        this.parent = node;
    }
    public void setParent(E data) {
        if(this.parent == null) {
            this.parent = new Node(data, this, null, null);
        } else {
            this.parent.data = data;
        }
    }

    public void deleteRightChild() {
        right = null;
    }
    public void deleteLeftChild() {
        left = null;
    }
}

