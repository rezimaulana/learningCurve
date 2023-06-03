package HackerRank.Prepare.Algorithms.Implementation;

public class Test {
    
    public static void main(String[] args) {
        //kg1 x1 v1
        //kg2 x2 v2
        int x1 = 0;
        int v1 = 3;
        int x2 = 4;
        int v2 = 2;

        int jumps = 10000;
        int kg1 = x1;
        int kg2 = x2;
        String found = "NO";          
        for(int i = 0; i<jumps; i++){
            kg1 += v1;
            kg2 += v2;
            if(kg1 == kg2){
                found = "YES";
                break;
            }
        }
        System.out.println(found);
    }

}
