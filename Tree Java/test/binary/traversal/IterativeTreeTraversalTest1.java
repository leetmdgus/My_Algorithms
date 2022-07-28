package binary.traversal;

import binary.Node;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class IterativeTreeTraversalTest1 {
    public static final Node<Integer> ROOT_NODE = new Node<>(1, null, null, null);
    public static final IterativeTreeTraversal ITERATIVE_TRAVERSAL = new IterativeTreeTraversal();

    @BeforeEach
    void setUp() {
        ROOT_NODE.setLeftChild(new Node<Integer>(2, null, null, ROOT_NODE));
        ROOT_NODE.setRightChild(new Node<Integer>(3, null, null, ROOT_NODE));

        ROOT_NODE.getLeftChild().setLeftChild(new Node<Integer>(4, null, null, ROOT_NODE.getLeftChild()));
        ROOT_NODE.getLeftChild().setRightChild(new Node<Integer>(5, null, null, ROOT_NODE.getLeftChild()));
        ROOT_NODE.getRightChild().setLeftChild(new Node<Integer>(6, null, null, ROOT_NODE.getRightChild()));
        ROOT_NODE.getRightChild().setRightChild(new Node<Integer>(7, null, null, ROOT_NODE.getRightChild()));
    }

    @Test
    void preOrder() {
        ITERATIVE_TRAVERSAL.preOrder(ROOT_NODE);
        assertEquals(ITERATIVE_TRAVERSAL.showTraversalResult(), "1 2 4 5 3 6 7 ");
    }
    @Test
    void inOrder() {
        ITERATIVE_TRAVERSAL.inOrder(ROOT_NODE);
        assertEquals(ITERATIVE_TRAVERSAL.showTraversalResult(), "4 2 5 1 6 3 7 ");
    }
    @Test
    void postOrder() {
        ITERATIVE_TRAVERSAL.postOrder(ROOT_NODE);
        assertEquals(ITERATIVE_TRAVERSAL.showTraversalResult(), "4 5 2 6 7 3 1 ");
    }
}