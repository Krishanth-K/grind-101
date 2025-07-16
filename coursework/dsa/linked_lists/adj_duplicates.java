 class Node
{
    int value;
    Node next;

    Node(int value)
    {
        this.value = value;
        this.next = null;
    }

    public static Node removeAdjacentDuplicates(Node node)
    {
        if (node.next == null || node == null)
        {
            return node;
        }

        Node save = node;
        Node current = node.next;

        while (current != null) 
        {
            if (current.value != save.value)
            {
                save.next = current;
                save = current;
            }

            current = current.next;
        }

        save.next = null;

        return node;
    }

    public static void printList(Node node)
    {
        if (node == null)
        {
            System.out.println("null");
        }

        while (node != null)
        {
            System.out.print(node.value + " ");
            node = node.next;
        }
        System.out.println();
    }
}


public class adj_duplicates {

    public static void main(String[] args) {
        Node node = new Node (1);
        node.next = new Node(1);
        node.next.next = new Node(3);
        node.next.next.next = new Node(3);
        node.next.next.next.next = new Node(2);

        Node.printList(node);
        Node.removeAdjacentDuplicates(node);
        Node.printList(node);

    }
}