package BinaryTreeWithArray;

class BinaryTree {
    private char[] array;

    BinaryTree(char[] data) {
        array = data.clone();
    }

    void preOrder() {
        int left = 2 * 0 + 1;
        int right = 2 * 0 + 2;

        System.out.print(array[0]+" ");
        if(left < array.length) {
            preOrder(left);
        }
        if(right < array.length) {
            preOrder(right);
        }
    }
    private void preOrder(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        System.out.print(array[index]+" ");
        if(left < array.length) {
            preOrder(left);
        }
        if(right < array.length) {
            preOrder(right);
        }
    }
    void inOrder() {
        int left = 2 * 0 + 1;
        int right = 2 * 0 + 2;

        if(left < array.length) {
            inOrder(left);
        }
        System.out.print(array[0]+" ");
        if(right < array.length) {
            inOrder(right);
        }
    }
    private void inOrder(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < array.length) {
            inOrder(left);
        }
        System.out.print(array[index]+" ");
        if(right < array.length) {
            inOrder(right);
        }
    }
    void postOrder() {
        int left = 2 * 0 + 1;
        int right = 2 * 0 + 2;

        if(left < array.length) {
            postOrder(left);
        }
        if(right < array.length) {
            postOrder(right);
        }
        System.out.print(array[0]+" ");
    }
    private void postOrder(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < array.length) {
            postOrder(left);
        }
        if(right < array.length) {
            postOrder(right);
        }
        System.out.print(array[index]+" ");
    }
    void levelOrder() {
        for(int i= 0; i<array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }

    int getSize() {
        return array.length;
    }
    Character getRoot() {
        if(array.length != 0) {
            return array[0];
        }
        return null;
    }

    Character getParent(char data) {
        int index = indexOf(data);
        int parent = index/2;
        if(index != parent){
            return array[parent];
        }
        return null;
    }
    Character getLeftChild(char data) {
        int index = indexOf(data);
        int left = 2 * index + 1;

        if(left < array.length) {
            return array[left];
        }
        return null;
    }
    Character getRightChild(char data) {
        int index = indexOf(data);
        int right = 2 * index + 2;

        if(right < array.length) {
            return array[right];
        }
        return null;
    }

    Integer indexOf(char data) {
        for(int i = 0; i<array.length; i++) {
            if(array[i] == data) {
                return i;
            }
        }
        return null;
    }
    Character getData(int index) {
        return array[index];
    }

    void leafNode() {
        for(int i = 0; i<array.length; i++) {
            char nodeData = (char)('A'+i);
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left > array.length && right > array.length) {
                System.out.print(nodeData +" ");
            }
        }
        System.out.println();
    }
    void internalNode() {
        for(int i = 0; i<array.length; i++) {
            char nodeData = (char)('A'+i);
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < array.length || right < array.length) {
                System.out.print(nodeData + " ");
            }
        }
        System.out.println();
    }

    int getDepth(char data) {   // depth == 부모 까지의 간선의 수 == 조상노드의 수
        int location = indexOf(data);
        int count = 0;

        while(location > 0){
            location = (location%2 == 0) ? location/2 -1 : location/2;
            count++;
        }
        return count;
    }

    int getLevel(char data) {
        return getDepth(data)+1;
    }
    void printSameLevelNode(int level) {
        System.out.print(level + " level: ");
        for(int i = 0; i<array.length; i++) {
            char character = (char)('A'+ i);
            int dataLevel = getLevel(character);
            if(dataLevel == level) {
                System.out.print(character + " ");
            }
        }
        System.out.println();
    }

    int getDegree(char data) {
        int location = indexOf(data);
        int left = 2 * location + 1;
        int right = 2 * location + 2;
        int count = 0;
        if(left < array.length) {
            count++;
        }
        if(right < array.length) {
            count++;
        }
        return count;
    }
}

public class BinaryTreeWithArray {
    public static void main(String[] args) {
        char[] arr = new char[10];
        for(int i = 0; i<arr.length; i++) {
            arr[i] = (char)('A' + i);
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
        
        // 사이즈 알아 보기
        System.out.println("size: " + bt.getSize());
        // 루트노드 알아보기
        System.out.println("root: " + bt.getRoot());
        // 인덱스 알아 보기
        System.out.println("'A' Index: " + bt.indexOf('A'));
        System.out.println("'B' Index: " + bt.indexOf('B'));
        System.out.println("'D' Index: " + bt.indexOf('D'));

        // 부모 노드 알아보기                                                  //              A
        System.out.println("'A' parent: "+ bt.getParent('A'));         //      B              C
        System.out.println("'B' parent: "+ bt.getParent('B'));         //  D       E        F  G
        System.out.println("'F' parent: "+ bt.getParent('F'));         // H I     J

        // 자식 노드 알아보기
        System.out.println("'A' child:  " + bt.getLeftChild('A') + ", " + bt.getRightChild('A'));
        System.out.println("'C' child:  " + bt.getLeftChild('C') + ", " + bt.getRightChild('C'));
        System.out.println("'E' child:  " + bt.getLeftChild('E') + ", " + bt.getRightChild('E'));

        // 인덱스번호로 데이터 찾기
        System.out.println("index : 1 -> " + bt.getData(1)); // A, B, C, D, E, F, G, H, I, J
        System.out.println("index : 3 -> " + bt.getData(3));
        System.out.println("index : 4 -> " + bt.getData(4));

        // 단말 노드 찾기
        System.out.println("==== leaf node ====");
        bt.leafNode();
        // 내부 노드 찾기
        System.out.println("====internal node ==== ");
        bt.internalNode();
        // 깊이 알기
        System.out.println("==== depth ====");
        System.out.println("'A' depth: " + bt.getDepth('A'));
        System.out.println("'F' depth: " + bt.getDepth('F'));
        System.out.println("'H' depth: " + bt.getDepth('H'));

        // 레벨 알기
        System.out.println("==== level ====");
        System.out.println("'A' level: " + bt.getLevel('A'));
        System.out.println("'B' level: " + bt.getLevel('B'));
        System.out.println("'H' level: " + bt.getLevel('H'));
        bt.printSameLevelNode(1);
        bt.printSameLevelNode(3);

        // 차수 알기
        System.out.println("==== degree ====");
        System.out.println("'A' degree: " + bt.getDegree('A'));
        System.out.println("'E' degree: " + bt.getDegree('E'));
        System.out.println("'F' degree: " + bt.getDegree('F'));
    }
}
