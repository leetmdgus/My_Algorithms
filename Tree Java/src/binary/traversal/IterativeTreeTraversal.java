package binary.traversal;

import binary.Node;
import stack.Stack;

public class IterativeTreeTraversal<E> implements Traversal<E> {
    StringBuilder sb = new StringBuilder();

    @Override
    public void preOrder(Node<E> node) {
        Stack<Node<E>> stack = new Stack<>();
        stack.push(node);
        while (!stack.isEmpty()) {
            Node<E> currentNode = stack.pop();
            sb.append(currentNode.getData()).append(" ");
            if (currentNode.getRightChild() != null) {
                stack.push(currentNode.getRightChild());
            }
            if (currentNode.getLeftChild() != null) {
                stack.push(currentNode.getLeftChild());
            }
        }
    }

    @Override
    public void inOrder(Node<E> node) {
        Stack<Node<E>> stack = new Stack<>();
        stack.push(node);

        while (!stack.isEmpty()) {
            while (node != null && (node = node.getLeftChild()) != null) {
                stack.push(node);
            }
            node = stack.pop();
            sb.append(node.getData()).append(" ");
            if ((node = node.getRightChild()) != null) {
                stack.push(node);
            }
        }
    }

    @Override
    public void postOrder(Node<E> node) {
        Stack<Node<E>> stack = new Stack<>();
        stack.push(node);

        Stack<Node<E>> result = new Stack<>();

        while(!stack.isEmpty()) {
            Node<E> currentNode = stack.pop();
            result.push(currentNode);
            if(currentNode.getLeftChild() != null) {
                stack.push(currentNode.getLeftChild());
            }
            if(currentNode.getRightChild() != null) {
                stack.push(currentNode.getRightChild());
            }
        }
        while(!result.isEmpty()) {
            sb.append(result.pop().getData()).append(" ");
        }
    }

    public String showTraversalResult() {
        String str = sb.toString();
        sb.setLength(0);
        return str;
    }
}

