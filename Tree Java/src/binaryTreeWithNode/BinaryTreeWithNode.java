package binaryTreeWithNode;


import java.util.LinkedList;
import java.util.Queue;

class Node {
    char data;
    Node left;
    Node right;
    Node parent;    // 생성자 ctrl shift enter alt shift s

    Node(char data, Node left, Node right, Node parent) {
        this.data = data;
        this.left = left;
        this.right = right;
        this.parent = parent;
    }
}

class BinaryTree {
    private Node root;

    BinaryTree(char[] data) {
        Node[] array = new Node[data.length];
        for (int i = 0; i < data.length; i++) {
            array[i] = new Node(data[i], null, null, null);
        }
        for (int i = 0; i < data.length; i++) {    // A B C D E F G H I J
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < array.length) {
                array[i].left = array[left];
                array[left].parent = array[i];
            }
            if (right < array.length) {
                array[i].right = array[right];
                array[right].parent = array[i];
            }
        }
        root = array[0];
    }

    void preOrder() {
        preOrder(this.root);
    }

    private void preOrder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }

    void inOrder() {
        inOrder(this.root);
    }

    private void inOrder(Node node) {
        if (node == null) {
            return;
        }
        inOrder(node.left);
        System.out.print(node.data + " ");
        inOrder(node.right);
    }

    void postOrder() {
        postOrder(this.root);
    }

    private void postOrder(Node node) {
        if (node == null) {
            return;
        }
        postOrder(node.left);
        postOrder(node.right);

        System.out.print(node.data + " ");
    }

    void levelOrder() {
        Node node = this.root;
        Queue<Node> queue = new LinkedList();   // import문 eclipse ctrl+shift + O
        queue.add(node);
        while (!queue.isEmpty()) {
            Node current = queue.poll();
            System.out.print(current.data + " ");   // alt shift s -> getter setter
            //stringbuffer // threadX -> stringbuild
            if (current.left != null) {
                queue.offer(current.left);
            }
            if (current.right != null) {
                queue.offer(current.right);
            }
        }
        System.out.println();
    }
}

public class BinaryTreeWithNode {
    public static void main(String[] args) {
        char[] arr = new char[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (char) ('A' + i);// a b c d e f g h i j
        }

        BinaryTree bt = new BinaryTree(arr);

        // 순회
        System.out.println("====preOrder====");
        bt.preOrder();
        System.out.println();
        System.out.println("====inOrder====");
        bt.inOrder();
        System.out.println();
        System.out.println("====postOrder====");
        bt.postOrder();
        System.out.println();
        System.out.println("====levelOrder====");
        bt.levelOrder();
        System.out.println();

//        // 사이즈 알아 보기
//        System.out.println("size: " + bt.getSize());
//        // 루트노드 알아보기
//        System.out.println("root: " + bt.getRoot());
//        // 인덱스 알아 보기
//        System.out.println("'A' Index: " + bt.indexOf('A'));
//        System.out.println("'B' Index: " + bt.indexOf('B'));
//        System.out.println("'D' Index: " + bt.indexOf('D'));
//
//        // 부모 노드 알아보기                                                  //              A
//        System.out.println("'A' parent: "+ bt.getParent('A'));         //      B              C
//        System.out.println("'B' parent: "+ bt.getParent('B'));         //  D       E        F  G
//        System.out.println("'F' parent: "+ bt.getParent('F'));         // H I     J
//
//        // 자식 노드 알아보기
//        System.out.println("'A' child:  " + bt.getLeftChild('A') + ", " + bt.getRightChild('A'));
//        System.out.println("'C' child:  " + bt.getLeftChild('C') + ", " + bt.getRightChild('C'));
//        System.out.println("'E' child:  " + bt.getLeftChild('E') + ", " + bt.getRightChild('E'));
//
//        // 인덱스번호로 데이터 찾기
//        System.out.println("index : 1 -> " + bt.getData(1)); // A, B, C, D, E, F, G, H, I, J
//        System.out.println("index : 3 -> " + bt.getData(3));
//        System.out.println("index : 4 -> " + bt.getData(4));
//
//        // 단말 노드 찾기
//        System.out.println("==== leaf node ====");
//        bt.leafNode();
//        // 내부 노드 찾기
//        System.out.println("====internal node ==== ");
//        bt.internalNode();
//        // 깊이 알기
//        System.out.println("==== depth ====");
//        System.out.println("'A' depth: " + bt.getDepth('A'));
//        System.out.println("'F' depth: " + bt.getDepth('F'));
//        System.out.println("'H' depth: " + bt.getDepth('H'));
//
//        // 레벨 알기
//        System.out.println("==== level ====");
//        System.out.println("'A' level: " + bt.getLevel('A'));
//        System.out.println("'B' level: " + bt.getLevel('B'));
//        System.out.println("'H' level: " + bt.getLevel('H'));
//        bt.printSameLevelNode(1);
//        bt.printSameLevelNode(3);
//
//        // 차수 알기
//        System.out.println("==== degree ====");
//        System.out.println("'A' degree: " + bt.getDegree('A'));
//        System.out.println("'E' degree: " + bt.getDegree('E'));
//        System.out.println("'F' degree: " + bt.getDegree('F'));
    }
}
