package tree.binary.traversal;

import tree.binary.Node;

public interface Traversal<E> {
    abstract void preOrder(Node<E> node);
    abstract void inOrder(Node<E> node);
    abstract void postOrder(Node<E> node);
}
