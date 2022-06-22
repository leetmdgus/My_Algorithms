//class Node {
//	int data;
//    Node left, right;
//
//void preorder(Node pointer) {
//    if(pointer != null) {
//        //pointer가 null이 아니라면
//        int printData = pointer.data;
//    	System.out.println(printData + ' ');
//            preorder(pointer.left);
//            preorder(pointer.right);
//        }
//    }
// // 중위
//void inorder(Node pointer) {
//    if(pointer != null) {
//    //pointer가 null이 아니라면
//
//    	inorder(pointer.left);
//        int printData = pointer.data;
//     	System.out.println(printData + ' ');
//         	inorder(pointer.right);
//        }
//    }
//
// // 후위
//void postorder(Node pointer) {
//    if(pointer != null) {
//        postorder(pointer.left);
//        postorder(pointer.right);
//        int printData = pointer.data;
//        System.out.println(printData + ' ');
//    }
//}
//
//
//
//
//
//public class BinaryTreeCircuit {
//
//	public static void main(String[] args) {
//		final int NUMBER = 15;
//		Node nodes = new Node();
//		
//		
//	    for(int i = 1; i<=15; i++) {
//	        nodes[i].data = i;
//	        nodes[i].left = null;
//	        nodes[i].right = null;
//	    }
//
//	    for(int i = 2; i<NUMBER; i++) {
//	        if(i%2 == 0) {
//	            nodes[i/2].left = nodes[i];
//	        } else {
//	            nodes[i/2].right = nodes[i];
//	        }
//	    }
//
//	    node.preorder(nodes[1].data);
//	    System.out.println();
//	    inorder(nodes[1].data);
//	    System.out.println();
//	    postorder(nodes[1].data);
//
//	}
//
//}
