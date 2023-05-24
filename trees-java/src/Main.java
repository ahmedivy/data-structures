import Trees.AVLTree;

public class Main {
    public static void main(String[] args) {
        AVLTree tree = new AVLTree(20);
        tree.add(30);
        tree.add(40);
        tree.add(50);
        tree.add(25);
        System.out.println(tree);
        tree.remove(30);
        System.out.println(tree);
    }
}