import java.util.*;
import java.lang.*;
import java.util.Arrays;
import java.util.HashMap;
class Main
{
	
	
	public static boolean Arrays_Validity(String original, String duplicate)
	{
		char a[]=original.toCharArray();
		char b[]=duplicate.toCharArray();
        int flex=0;
		for(int i=0;i<original.length();i++)
		{
			if(a[i]==b[i])
				flex+=1;
		}
		if(original.length()==flex)
			return true;
		else
			return false;
	}


    public static void Output(int value)
	{
		System.out.println(value);
	}
	


	public static String val_To_String(char[] ch)
	{
		String mask="";
		for(char c:ch)
			mask+=c;
		return mask;
	}


	public static void Search(int numbers[],String original)
	{
		String duplicate="";
		char change[]=original.toCharArray();
		int value=1;
		int cycle=0;
		while(cycle==0)
		{
			char[] test_c=new char[numbers.length];
			for(int i=0;i<numbers.length;i++)
			{
				test_c[numbers[i]]=change[i];
			}
			change=test_c;
			duplicate=val_To_String(change);
			
			if(Arrays_Validity(original, duplicate)==true)
				cycle=1;
			else
				value+=1;
		}
		Output(value);
	}



	public static void Changes_char(int[] list)
	{
		int length=list.length;
		char list_val='a';
		char ch[]=new char[length];
		for(int i=0;i<length;i++)
		{
			ch[i]=list_val;
			list_val++;
		}
		Search(list,val_To_String(ch));
	}


	public static void main(String args[])
	{
         
		Scanner scan=new Scanner(System.in);
		int t=scan.nextInt();
		if(t<1 || t>10)
		{
			System.exit(0);
		}
		for(int tc=0;tc<t;tc++)
		{
             
			int n=scan.nextInt();	
			if(n<1 || n>10000)
				System.exit(0);
			int arr[]=new int[n];

			for(int i=0;i<n;i++)
			{
				int x=scan.nextInt();
				if(x<1 || x>n)
					System.exit(0);
				arr[i]=x-1;
			}			
			
			Changes_char(arr);
		}
    
      
	}
}