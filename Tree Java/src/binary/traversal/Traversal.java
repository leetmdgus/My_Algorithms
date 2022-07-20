package binary.traversal;

import binary.Node;

public interface Traversal {
    abstract void preOrder(Node node);
    abstract void inOrder(Node node);
    abstract void postOrder(Node node);
}
