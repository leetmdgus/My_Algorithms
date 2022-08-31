package binary.traversal;

import tree.binary.Node;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import tree.binary.traversal.IterativeTreeTraversal;

import static org.junit.jupiter.api.Assertions.*;

class IterativeTreeTraversalTest3 {
    public static final Node<Integer> ROOT_NODE = new Node<>(3, null, null, null);
    public static final IterativeTreeTraversal ITERATIVE_TRAVERSAL = new IterativeTreeTraversal();

    @BeforeEach
    void setUp() {
        ROOT_NODE.setLeftChild(new Node<Integer>(1, null, null, ROOT_NODE));
        ROOT_NODE.setRightChild(new Node<Integer>(5, null, null, ROOT_NODE));

        ROOT_NODE.getLeftChild().setRightChild(new Node<Integer>(2, null, null, ROOT_NODE.getLeftChild()));
        ROOT_NODE.getRightChild().setLeftChild(new Node<Integer>(4, null, null, ROOT_NODE.getRightChild()));
    }

    @Test
    void preOrder() {
        ITERATIVE_TRAVERSAL.preOrder(ROOT_NODE);
        assertEquals(ITERATIVE_TRAVERSAL.showTraversalResult(), "3 1 2 5 4 ");
    }
    @Test
    void inOrder() {
        ITERATIVE_TRAVERSAL.inOrder(ROOT_NODE);
        assertEquals(ITERATIVE_TRAVERSAL.showTraversalResult(), "1 2 3 4 5 ");
    }
    @Test
    void postOrder() {
        ITERATIVE_TRAVERSAL.postOrder(ROOT_NODE);
        assertEquals(ITERATIVE_TRAVERSAL.showTraversalResult(), "2 1 4 5 3 ");
    }
}