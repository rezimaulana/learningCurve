    import java.util.*;
    public class test {
        public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Deque<Integer> deque = new ArrayDeque<Integer>();
        int n = in.nextInt();
        int m = in.nextInt();
        Set<Integer> hs = new HashSet<Integer>();

        int maxsize = 0;

        int lastsize = 0;
        int newval;
        int poped;
        for (int i = 0; i < n; i++) {
            newval = in.nextInt();
            deque.add(newval);
            hs.add(newval);
            if (i >= m) {

                poped = deque.pollFirst();
                if (!deque.contains(poped))
                    hs.remove(poped);

                lastsize = hs.size();
                if (lastsize == m) {
                    maxsize = m;

                    break;
                } else {
                    maxsize = Math.max(lastsize, maxsize);
                }
            }

        }

        if (n == m) {
            maxsize = (new HashSet<Integer>(deque)).size();
        }
        System.out.println(maxsize);

    }
    }



    import java.util.*;
    public class test {
        public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Deque<Integer> deque = new ArrayDeque<Integer>();
        int n = in.nextInt();
        int m = in.nextInt();
        Set<Integer> hs = new HashSet<Integer>();

        int maxsize = 0;

        int lastsize = 0;
        int newval;
        int poped;
        for (int i = 0; i < n; i++) {
            newval = in.nextInt();
            deque.add(newval);
            hs.add(newval);
            if (i >= m) {

                poped = deque.pollFirst();
                if (!deque.contains(poped))
                    hs.remove(poped);

                lastsize = hs.size();
                if (lastsize == m) {
                    maxsize = m;

                    break;
                } else {
                    maxsize = Math.max(lastsize, maxsize);
                }
            }

        }

        if (n == m) {
            maxsize = (new HashSet<Integer>(deque)).size();
        }
        System.out.println(maxsize);

    }
    }



