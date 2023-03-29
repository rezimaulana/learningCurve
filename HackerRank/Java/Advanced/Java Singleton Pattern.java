import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.reflect.*;


class Singleton{
	private static Singleton instance; public String str; private Singleton() {}

    public static Singleton getSingleInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}

class Main1 { 
    public static void main(String[] args) { 
        Singleton obj = Singleton.getSingleInstance();
        System.out.println(obj);
    }
}