import Trees.AVLTree;

public class Main {
    public static void main(String[] args) {
        AVLTree tree = new AVLTree(20);
        tree.add(30);
        tree.add(40);
        System.out.println(tree);
    }
}