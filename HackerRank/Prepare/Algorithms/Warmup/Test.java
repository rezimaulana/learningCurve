import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Test {
    
    public static void main(String[] args) {
        String s = "07:05:45PM";
        SimpleDateFormat inputFormat = new SimpleDateFormat("hh:mm:ssa");
        SimpleDateFormat outputFormat = new SimpleDateFormat("HH:mm:ss");
        try {
            Date date = inputFormat.parse(s);
            String formattedTime = outputFormat.format(date);
            System.out.println("Formatted Time: " + formattedTime);
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

}
