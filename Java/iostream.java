import java.io.*;
public class iostream
{
public static void main(String args[]) throws IOException
{
InputStreamReader ir=new InputStreamReader(System.in);
BufferedReader br=new BufferedReader(ir);
System.out.println(" ENTER THE VALUE OF A AND B:");
int a,b,c;
a=Integer.parseInt(br.readLine());
b=Integer.parseInt(br.readLine());
c=a+b;
System.out.println(c);
}
}