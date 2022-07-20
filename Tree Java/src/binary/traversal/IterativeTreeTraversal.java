package binary.traversal;

import binary.Node;
import stack.Stack;

public class IterativeTreeTraversal implements Traversal{
    StringBuilder sb = new StringBuilder();
    @Override
    public void preOrder(Node node) {
        Stack<Node> stack = new Stack<Node>();
        stack.push(node);
        while(!stack.isEmpty()) {
            // 스택에 있는 값을 꺼냄
            // 스택의 오른쪽 자식이 있다면 오른쪽 자식 push
            // 스택의 왼쪽 자식이 있다면 왼쪽자식 push

            Node currentNode = stack.pop();
            sb.append(currentNode.getData()).append(" ");
            if(currentNode.getRightChild() != null) {
                stack.push(currentNode.getRightChild());
            }
            if(currentNode.getLeftChild() != null) {
                stack.push(currentNode.getLeftChild());
            }
        }
    }

    @Override
    public void inOrder(Node node) {
        Stack<Node> stack = new Stack<Node>();
        stack.push(node);

        // node자신과 노드의 왼쪽자식이 null 이 아닐때, node push.-> 노드를 왼쪽 끝까지 push 함
        // 노드 pop(); 데이터 가져옴
        // 만약 getRightChild가 null이 아니라면 오른쪽 자식 스택에 넣음
        while(!stack.isEmpty()) {
            while(node != null && (node = node.getLeftChild()) != null) {
                stack.push(node);
            }
            node = stack.pop();
            sb.append(node.getData()).append(" ");
            if((node = node.getRightChild()) != null) {
                stack.push(node);
            }
        }
    }

    @Override
    public void postOrder(Node node) {
        Stack<Node> stack = new Stack<Node>();

        Node currentNode = node;
        stack.push(currentNode);

        // 스택 peek
        // 만약 오른쪽 요소 있다면 push
        // 왼쪽 요소 있다면 push
        // 오른쪽 요소, 왼쪽 요소 둘 다 없다면 pop();

        while(!stack.isEmpty()) {
            currentNode = stack.peek();
            if(currentNode.getRightChild()!=null) {
                stack.push(currentNode.getRightChild());
            }
            if(currentNode.getLeftChild() != null) {
                stack.push(currentNode.getLeftChild());
            }
            if(currentNode.getRightChild() == null && currentNode.getLeftChild() == null) {
                currentNode = stack.pop();
                sb.append(currentNode.getData()).append(" ");
                if(currentNode.getParent() != null) {
                    Node parentNode = currentNode.getParent();
                    parentNode.deleteLeftChild();
                    parentNode.deleteRightChild();
                }
            }
        }
    }

    public String showTraversalResult() {
        String str = sb.toString();
        sb.setLength(0);
        return str;
    }
}

