/*
Manuel Pineda.
accepted.

implementation of search binary tree.
*/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {

	public static void main(String[] args) throws Exception {
        SearchBinaryTree tree = new SearchBinaryTree();
        boolean val = false;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String cad;
        LinkedList<String> list= new LinkedList<String>();
        while(true){
            if(val)break;
            list.clear();
            while(true){
                cad = br.readLine();
                if(cad.equals("*"))break;
                if(cad.equals("$")){
                    
                    for (String obj : list) {
                        for(int i=0;i<obj.length();i++){
                            tree.insert(obj.charAt(i));
                        }
                    }
                    tree.preorder(tree.root);
                    System.out.println();
                    val=true;
                    break;
                }
                list.addFirst(cad);
            }
            for (String obj : list) {
                for(int i=0;i<obj.length();i++){
                            tree.insert(obj.charAt(i));
                }
            }
            if(!val){
                tree.preorder(tree.root);
                System.out.println();
                tree = new SearchBinaryTree();
            }
            
        }
    }

    public static class Node implements Comparable{
        private Object info;              
        private Node left, rigth;         
        private Node parent;
        private int factor;

        Node(Object xinfo){
            this.info = xinfo;
            this.left = null;
            this.rigth = null;
            this.factor = 0;
        }

        public Object getInfo(){
            return info;
        }

        public void setInfo(Object info){
            this.info = info;
        }

        public Object getLeft(){
            return left;
        }

        public void setLeft(Node left){
            this.left = left;
            if(left != null)
                left.setParent(this);
        }

        public Object getRigth(){
            return rigth;
        }

        public void setRigth(Node rigth){
            this.rigth = rigth;
            if(rigth != null)
                rigth.setParent(this);
        }

        public Node getParent(){
            return parent;
        }

        public void setParent(Node parent) {
            this.parent = parent;
        }
        //to future AVL implementation. :D
	   public int getFactor() {
            return factor;
        }

        public void setFactor(int factor) {
            this.factor = factor;
        }

        public int compareTo(Object o) {
            return ((Comparable)(this.info)).compareTo(((Node)o).getInfo());
        }

        @Override
        public String toString() {
            super.toString();
            return info.toString();
        }

        public void swap(Node node){
            Object tmp_info = node.getInfo();
            node.setInfo(this.getInfo());
            this.setInfo(tmp_info);
        }
    }

    public static class BinaryTree{
        protected Node root;
        protected Node seek;

        public BinaryTree(){
            this.root = null;
            this.seek = null;
        }

        public Node setRoot(Object info){
            if(this.empty()){
                this.root = new Node(info);
                this.seek = this.root;
            }
            return this.root;
        }

        public void insertLeft(Object info){
            insertLeft(this.seek, info);
        }

        protected void insertLeft(Node subtree, Object info){
            Node tmp;
            if(subtree!=null){
                tmp = new Node(info);
                subtree.setLeft(tmp);
                this.seek = tmp;
            }
        }

        public void insertRigth(Object info){
            insertRigth(this.seek, info);
        }

        protected void insertRigth(Node subtree, Object info){
            Node tmp;
            if(subtree!=null){
                tmp = new Node(info);
                subtree.setRigth(tmp);
                this.seek = tmp;
            }
        }

        public void preorder(){
            if(this.root!=null){
                preorder(this.root);
            }
        }

        public void preorder(Node node){
            if(node != null){
                System.out.print(node);
                preorder((Node)node.getLeft());
                preorder((Node)node.getRigth());
            }
        }

        public void inorder(){
            if(this.root!=null){
                this.inorder(this.root);
            }
        }

        public void inorder(Node node){
            if(node!=null){
                inorder((Node)node.getLeft());
                System.out.print(node);
                inorder((Node)node.getRigth());
            }
        }

        public void postorder(){
            if(this.root!=null){
                this.postorder(this.root);
            }
        }

        public void postorder(Node node){
            if(node!=null){
                postorder((Node)node.getLeft());
                postorder((Node)node.getRigth());
                System.out.print(node);
            }
        }

        protected boolean empty(){
            return root == null;
        }

        public Node getSeek(){
            return seek;
        }

        public Node search(Object info){
            Node find = null;
            Node tmp = this.seek;
            find = search(this.root, new Node(info));
            if(find==null){
               this.seek = tmp;
            }
            return find;
        }

        public Node search(Node subtree, Node node){
            Node find = null;
            if(subtree != null){
                if(node.compareTo(subtree) == 0){
                    find = subtree;
                    this.seek = subtree;
                }else{
                    find = search((Node)subtree.getLeft(), node);
                    find = (find == null)?search((Node)subtree.getRigth(), node):find;
                }
            }
            return find;
        }

        protected boolean isRoot(Node node){
            return node == this.root;
        }

        protected void delLeaf(Node node){
            Node parent = null;
            if(this.isRoot(node)){
                this.setRoot(null);
            }else{
                parent = (Node)node.getParent();
                if(parent.getLeft()==node){
                    parent.setLeft(null);
                }else{
                    parent.setRigth(null);
                }
            }
        }
    }

    public static class SearchBinaryTree extends BinaryTree {

        public SearchBinaryTree() {
            super();
        }

        public void insert(Object info) throws Exception {
            if( this.empty() )
                this.setRoot(info);
            else
                this.insert(root, info);
        }

        private void insert(Node subtree, Object info) throws Exception {
            if(subtree != null)
            {
                if( ((Comparable)info).compareTo(subtree.getInfo()) < 0 )
                {
                    if(subtree.getLeft() == null)
                        insertLeft(subtree, info);
                    else
                        insert((Node) subtree.getLeft(), info);
                }
                else if( ((Comparable)info).compareTo(subtree.getInfo()) > 0 || ((Comparable)info).compareTo(subtree.getInfo()) == 0)
                {
                    if(subtree.getRigth() == null)
                        insertRigth(subtree, info);
                    else
                        insert((Node)subtree.getRigth(), info);
                }
            }
        }

        @Override
        public Node search(Object info) {
            return search(this.root,  info);
        }

        public Node search(Node subtree, Object info) {
            if(subtree != null){
               if(((Comparable)info).compareTo(subtree.getInfo())==0){
                   this.seek = subtree;
                   return this.seek;
               }else{
                  if(((Comparable)info).compareTo(subtree.getInfo())>0){
                       return search((Node)subtree.getRigth(), info);
                  }else{
                       return search((Node)subtree.getLeft(), info);
                  }
               }
            }
            return null;
        }

        private Node maxleft(Node node){
            Node tmp = (Node)node.getLeft();
            if(tmp != null){
                while(tmp.getRigth() != null){
                    tmp = (Node)tmp.getRigth();
                }
            }
            return tmp;
        }

        private Node minusRight(Node node){
            Node tmp = (Node)node.getRigth();
            if(tmp != null){
                while(tmp.getLeft() != null){
                    tmp = (Node)tmp.getLeft();
                }
            }
            return tmp;
        }

        public void delete(Object info){
            Node node = this.search(info);
            Node tmp = null;
            if(node != null){
                tmp = this.maxleft(node);
                if(tmp != null && tmp != node.getLeft()){
                    tmp.swap(node);
                    if(tmp.getLeft() != null)
                        ((Node)tmp.getLeft()).setParent(node.getParent());
                    tmp.getParent().setRigth((Node)tmp.getLeft());
                    return;
                }
                if(tmp != null && tmp == node.getLeft()){
                    tmp.swap(node);
                    node.setLeft((Node)tmp.getLeft());
                    return;
                }
                tmp = this.minusRight(node);
                if(tmp != null && tmp != node.getRigth()){
                    tmp.swap(node);
                    if(tmp.getRigth()!=null)
                        ((Node)tmp.getRigth()).setParent(node.getParent());
                    tmp.getParent().setLeft((Node)tmp.getRigth());
                    return;
                }
                if(tmp != null && tmp == node.getRigth()){
                    tmp.swap(node);
                    node.setRigth((Node)tmp.getRigth());
                    return;
                }
                if(this.isRoot(node)){
                    this.setRoot(null);
                }else{
                    this.delLeaf(node);
                }
            }
        }
    }
}
